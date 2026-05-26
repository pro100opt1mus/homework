#include "long_number.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

namespace biv {


int LongNumber::get_length(const char* const str) const noexcept {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

LongNumber::LongNumber()
    : numbers(new int[1]{0}), length(1), sign(1) {}

LongNumber::LongNumber(const char* const str)
    : numbers(nullptr), length(0), sign(1) {
    if (!str) {
        numbers = new int[1]{0};
        length = 1;
        sign = 1;
        return;
    }

    int start = 0;
    if (str[0] == '-') {
        sign = -1;
        start = 1;
    } else if (str[0] == '+') {
        sign = 1;
        start = 1;
    }

    while (str[start] == '0') {
        ++start;
    }

    int total = get_length(str);
    int digits = total - start;

    if (digits <= 0) {
        numbers = new int[1]{0};
        length = 1;
        sign = 1;
        return;
    }

    for (int i = start; i < total; ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            numbers = new int[1]{0};
            length = 1;
            sign = 1;
            return;
        }
    }

    length = digits;
    numbers = new int[length];
    for (int i = 0; i < length; ++i) {
        numbers[i] = str[total - 1 - i] - '0';
    }

    trim(*this);
}

LongNumber::LongNumber(const LongNumber& x)
    : numbers(new int[x.length]), length(x.length), sign(x.sign) {
    for (int i = 0; i < length; ++i) {
        numbers[i] = x.numbers[i];
    }
}

LongNumber::LongNumber(LongNumber&& x)
    : numbers(x.numbers), length(x.length), sign(x.sign) {
    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

LongNumber::~LongNumber() {
    delete[] numbers;
    numbers = nullptr;
    length = 0;
    sign = 1;
}


LongNumber& LongNumber::operator=(const char* const str) {
    LongNumber tmp(str);
    *this = std::move(tmp);
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this == &x) {
        return *this;
    }

    int* new_numbers = new int[x.length];
    for (int i = 0; i < x.length; ++i) {
        new_numbers[i] = x.numbers[i];
    }

    delete[] numbers;
    numbers = new_numbers;
    length = x.length;
    sign = x.sign;

    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) {
    if (this == &x) {
        return *this;
    }

    delete[] numbers;

    numbers = x.numbers;
    length = x.length;
    sign = x.sign;

    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;

    return *this;
}


int LongNumber::cmp_abs(const LongNumber& a, const LongNumber& b) noexcept {
    if (a.length != b.length) {
        return (a.length < b.length) ? -1 : 1;
    }

    for (int i = a.length - 1; i >= 0; --i) {
        if (a.numbers[i] != b.numbers[i]) {
            return (a.numbers[i] < b.numbers[i]) ? -1 : 1;
        }
    }

    return 0;
}

bool LongNumber::operator==(const LongNumber& x) const {
    if (sign != x.sign) return false;
    if (length != x.length) return false;

    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator<(const LongNumber& x) const {
    if (sign != x.sign) {
        return sign < x.sign;
    }

    int cmp = cmp_abs(*this, x);
    if (sign > 0) {
        return cmp < 0;
    }
    return cmp > 0;
}

bool LongNumber::operator>(const LongNumber& x) const {
    return x < *this;
}


void LongNumber::trim(LongNumber& a) noexcept {
    while (a.length > 1 && a.numbers[a.length - 1] == 0) {
        --a.length;
    }

    if (a.length == 1 && a.numbers[0] == 0) {
        a.sign = 1;
    }
}

LongNumber LongNumber::add_abs(const LongNumber& a, const LongNumber& b) {
    int max_len = (a.length > b.length) ? a.length : b.length;

    LongNumber res;
    delete[] res.numbers;

    res.numbers = new int[max_len + 1]{0};
    res.length = max_len + 1;
    res.sign = 1;

    int carry = 0;
    for (int i = 0; i < max_len; ++i) {
        int da = (i < a.length) ? a.numbers[i] : 0;
        int db = (i < b.length) ? b.numbers[i] : 0;

        int s = da + db + carry;
        res.numbers[i] = s % 10;
        carry = s / 10;
    }
    res.numbers[max_len] = carry;

    trim(res);
    return res;
}

LongNumber LongNumber::sub_abs(const LongNumber& a, const LongNumber& b) {
    LongNumber res;
    delete[] res.numbers;

    res.numbers = new int[a.length]{0};
    res.length = a.length;
    res.sign = 1;

    int borrow = 0;
    for (int i = 0; i < a.length; ++i) {
        int da = a.numbers[i];
        int db = (i < b.length) ? b.numbers[i] : 0;

        int cur = da - db - borrow;
        if (cur < 0) {
            cur += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.numbers[i] = cur;
    }

    trim(res);
    return res;
}

LongNumber LongNumber::mul_abs(const LongNumber& a, const LongNumber& b) {
    LongNumber res;
    delete[] res.numbers;

    res.length = a.length + b.length;
    res.numbers = new int[res.length]{0};
    res.sign = 1;

    for (int i = 0; i < a.length; ++i) {
        int carry = 0;
        for (int j = 0; j < b.length; ++j) {
            int cur = res.numbers[i + j] + a.numbers[i] * b.numbers[j] + carry;
            res.numbers[i + j] = cur % 10;
            carry = cur / 10;
        }

        int pos = i + b.length;
        while (carry > 0) {
            int cur = res.numbers[pos] + carry;
            res.numbers[pos] = cur % 10;
            carry = cur / 10;
            ++pos;
        }
    }

    trim(res);
    return res;
}

void LongNumber::divmod_abs(const LongNumber& a, const LongNumber& b, LongNumber& q, LongNumber& r) {
    if (b.length == 1 && b.numbers[0] == 0) {
        throw std::runtime_error("division by zero");
    }

    if (cmp_abs(a, b) < 0) {
        q = LongNumber("0");
        r = a;
        return;
    }

    q = LongNumber("0");
    r = LongNumber("0");

    std::string quotient;
    LongNumber current("0");

    for (int i = a.length - 1; i >= 0; --i) {
        std::string current_str;
        {
            std::ostringstream oss;
            oss << current;
            current_str = oss.str();
        }

        if (current_str == "0") {
            current_str = "";
        }

        current_str.push_back(char(a.numbers[i] + '0'));
        current = LongNumber(current_str.c_str());

        int digit = 0;
        while (!(current < b)) {
            current = current - b;
            ++digit;
        }

        quotient.push_back(char(digit + '0'));
    }

    q = LongNumber(quotient.c_str());
    r = current;

    trim(q);
    trim(r);
}


LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign == x.sign) {
        LongNumber res = add_abs(*this, x);
        res.sign = sign;
        trim(res);
        return res;
    }

    int cmp = cmp_abs(*this, x);

    if (cmp == 0) {
        return LongNumber("0");
    }

    if (cmp > 0) {
        LongNumber res = sub_abs(*this, x);
        res.sign = sign;
        trim(res);
        return res;
    } else {
        LongNumber res = sub_abs(x, *this);
        res.sign = x.sign;
        trim(res);
        return res;
    }
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    LongNumber neg_x(x);
    if (!(neg_x.length == 1 && neg_x.numbers[0] == 0)) {
        neg_x.sign = -neg_x.sign;
    }
    return *this + neg_x;
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    LongNumber res = mul_abs(*this, x);

    if (res.length == 1 && res.numbers[0] == 0) {
        res.sign = 1;
    } else {
        res.sign = sign * x.sign;
    }

    trim(res);
    return res;
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    LongNumber abs_a(*this);
    abs_a.sign = 1;

    LongNumber abs_b(x);
    abs_b.sign = 1;

    LongNumber q, r;
    divmod_abs(abs_a, abs_b, q, r);

    if (!(q.length == 1 && q.numbers[0] == 0)) {
        q.sign = sign * x.sign;
    } else {
        q.sign = 1;
    }

    trim(q);
    return q;
}

LongNumber LongNumber::operator%(const LongNumber& x) const {
    LongNumber abs_a(*this);
    abs_a.sign = 1;

    LongNumber abs_b(x);
    abs_b.sign = 1;

    LongNumber q, r;
    divmod_abs(abs_a, abs_b, q, r);

    if (!(r.length == 1 && r.numbers[0] == 0)) {
        r.sign = sign;
    } else {
        r.sign = 1;
    }

    trim(r);
    return r;
}


bool LongNumber::is_negative() const noexcept {
    return sign < 0;
}

std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
    if (x.numbers == nullptr || x.length <= 0) {
        os << "0";
        return os;
    }

    bool is_zero = (x.length == 1 && x.numbers[0] == 0);
    if (!is_zero && x.sign < 0) {
        os << "-";
    }

    for (int i = x.length - 1; i >= 0; --i) {
        os << x.numbers[i];
    }

    return os;
}

} // namespace biv
