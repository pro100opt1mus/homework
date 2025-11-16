#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SRC_DIR="$SCRIPT_DIR/src"
BUILD_DIR="$SCRIPT_DIR/build"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
clang++ -std=c++17 -Wall -Wextra \
    "$SRC_DIR/main.cpp" \
    "$SRC_DIR/expression_calculations.cpp" \
    -o calculator
if [ $? -eq 0 ]; then
    echo "✓ Сборка успешна!"
    echo "Исполняемый файл: $BUILD_DIR/calculator"
else
    echo "✗ Ошибка сборки!"
    exit 1
fi


