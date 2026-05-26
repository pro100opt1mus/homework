

#pragma once

#include <vector>

#include "BaseObject.hpp"
#include "Mario.hpp"

namespace pav {
	class Map {
	private:
		std::vector<std::vector<char>> map;
		int mapWidth;
		int mapHeight;

	public:
		Map(
			int width,
			int height
		);

		void clear_map();
		void show_map() const;

		void put_score_on_map(int score);

		void put_object_on_map(const BaseObject& obj);
		void put_object_on_map(const Mario& player);

		bool is_pos_in_map(
			const int x,
			const int y
		) const;

		int get_width() const;
		int get_height() const;
	};
}