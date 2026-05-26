

#define _XOPEN_SOURCE_EXTENDED 1

#include <algorithm>
#include <cmath>
#include <ncurses.h>
#include <string>

#include "map.hpp"

namespace pav {

Map::Map(
	int width,
	int height
)
	: map(height, std::vector<char>(width + 1, ' ')),
	  mapWidth(width),
	  mapHeight(height) {}

void Map::clear_map() {
	for (auto& row : map) {
		std::fill(row.begin(), row.end() - 1, ' ');
		row.back() = '\0';
	}
}

void Map::show_map() const {
	for (int j = 0; j < mapHeight; ++j) {
		mvprintw(j, 0, "%s", map[j].data());
	}

	refresh();
}

void Map::put_score_on_map(int score) {
	std::string s = "Score: " + std::to_string(score);

	for (std::size_t i = 0;
		i < s.size() && i < static_cast<std::size_t>(mapWidth);
		++i) {
		map[1][i + 5] = s[i];
	}
}

void Map::put_object_on_map(const BaseObject& obj) {
	int left = static_cast<int>(std::round(obj.get_x()));
	int top = static_cast<int>(std::round(obj.get_y()));
	int right = static_cast<int>(std::round(
		obj.get_x() + obj.get_width()
	));
	int bottom = static_cast<int>(std::round(
		obj.get_y() + obj.get_height()
	));

	for (int j = top; j < bottom; ++j) {
		if (j < 0 || j >= mapHeight) {
			continue;
		}

		for (int i = left; i < right; ++i) {
			if (i < 0 || i >= mapWidth) {
				continue;
			}

			map[j][i] = obj.get_type();
		}

		map[j][mapWidth] = '\0';
	}
}

void Map::put_object_on_map(const Mario& player) {
	int left = static_cast<int>(std::round(player.get_x()));
	int top = static_cast<int>(std::round(player.get_y()));
	int right = static_cast<int>(std::round(
		player.get_x() + player.get_width()
	));
	int bottom = static_cast<int>(std::round(
		player.get_y() + player.get_height()
	));

	for (int j = top; j < bottom; ++j) {
		if (j < 0 || j >= mapHeight) {
			continue;
		}

		for (int i = left; i < right; ++i) {
			if (i < 0 || i >= mapWidth) {
				continue;
			}

			map[j][i] = player.get_type();
		}

		map[j][mapWidth] = '\0';
	}
}

bool Map::is_pos_in_map(
	const int x,
	const int y
) const {
	return (x >= 0) &&
		(x < mapWidth) &&
		(y >= 0) &&
		(y < mapHeight);
}

int Map::get_width() const {
	return mapWidth;
}

int Map::get_height() const {
	return mapHeight;
}

} // namespace pav