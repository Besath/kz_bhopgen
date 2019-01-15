#pragma once
#include <functional>
#include <random>


class Block
{
public:
	Block(int num_of_blocks, int initial_width, int initial_height, int distance_min, int distance_max)
		: blocks{num_of_blocks}, width{initial_width}, height{initial_height}, min_distance{distance_min}, max_distance{distance_max}
		{
			right = width;
			top = width;
			ids = 7 * blocks + 2;
		}
		void set_distance();
		int new_distance(int, int);
		void calculate_sides();
		bool random_bool();
		void set_direction();
		int get_left() { return left; }
		int get_right() { return right; }
		int get_top() { return top; }
		int get_bottom() { return bottom; }
		int get_blocks() { return blocks; }
		int get_height() { return height;  }
		int get_base() const { return base; }
		int get_ids_count() { return ids; }
private:
	// top and bottom relative to the Y axis in Hammer (top view)
	int right, top, width, height, distance_x, distance_y, blocks, min_distance, max_distance, ids;
	int left = 0, bottom = 0;
	const int base = 0;
	bool direction = random_bool();
};