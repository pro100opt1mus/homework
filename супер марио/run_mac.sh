#!/bin/sh
# Сборка и запуск игры на macOS.
# На macOS используется та же консольная версия, что и для Linux (ncurses),
# поэтому исходный код не меняется — меняется только способ запуска.

cd "$(dirname "$0")" || exit 1

BUILD_FOLDER="build_mac"
SOURCE_FOLDER="src"
GAME_TYPE="LinuxConsole"

# Размер карты в игре: 30 строк x 200 столбцов (см. src/main.cpp)
MAP_HEIGHT=30
MAP_WIDTH=200

if ! command -v cmake >/dev/null 2>&1; then
	echo "Не найден cmake. Установите: brew install cmake"
	exit 1
fi

if command -v ninja >/dev/null 2>&1; then
	GENERATOR="Ninja"
else
	GENERATOR="Unix Makefiles"
fi

cmake -S "${SOURCE_FOLDER}" -B "${BUILD_FOLDER}" -G "${GENERATOR}" -DGAME_TYPE="${GAME_TYPE}" || exit 1
cmake --build "${BUILD_FOLDER}" || exit 1

# Растягиваем окно терминала под размер карты (работает в Terminal.app)
printf '\033[8;%d;%dt' "${MAP_HEIGHT}" "${MAP_WIDTH}"
sleep 0.3

if [ "$(tput lines)" -lt "${MAP_HEIGHT}" ] || [ "$(tput cols)" -lt "${MAP_WIDTH}" ]; then
	echo "Окно терминала меньше ${MAP_WIDTH}x${MAP_HEIGHT} (сейчас $(tput cols)x$(tput lines))."
	echo "Разверните окно на весь экран или уменьшите шрифт (Cmd -), затем нажмите Enter."
	read -r _
fi

"./${BUILD_FOLDER}/super_mario"

# Игра не восстанавливает терминал при выходе — делаем это здесь
stty sane
tput cnorm
clear
