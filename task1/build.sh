#!/bin/bash

# Получаем абсолютный путь к директории скрипта
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SRC_DIR="$SCRIPT_DIR/src"
BUILD_DIR="$SCRIPT_DIR/build"

# Создаём папку build, если её нет
mkdir -p "$BUILD_DIR"

# Переходим в директорию сборки
cd "$BUILD_DIR"

# Компилируем с явными путями
clang++ -std=c++17 -Wall -Wextra \
    "$SRC_DIR/main.cpp" \
    "$SRC_DIR/expression_calculations.cpp" \
    -o calculator

# Проверяем успешность сборки
if [ $? -eq 0 ]; then
    echo "✓ Сборка успешна!"
    echo "Исполняемый файл: $BUILD_DIR/calculator"
else
    echo "✗ Ошибка сборки!"
    exit 1
fi


