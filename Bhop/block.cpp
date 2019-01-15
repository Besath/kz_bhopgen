#include "block.h"

// calculate new distance between blocks in X and Y axis (top view in Hammer)
void Block::set_distance()
{
	distance_x = new_distance(min_distance, max_distance);
	distance_y = new_distance(min_distance, max_distance);
}

int Block::new_distance(int min, int max)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

void Block::calculate_sides()
{
	// left and right always increase for the subsequent blocks
	// top and bottom can increase or decrease depending on the direction from the previous block
	// i.e. is the next block higher or lower on the Y axis
	left = right + distance_x;
	right = left + width;
	switch (direction)
	{
	case 0:
		if (distance_y > 0)
		{
			distance_y = -distance_y;
		}
		else if (distance_y < 0)
		{
			distance_y = distance_y;
		}
		top = bottom + distance_y;
		bottom = top - width;
		break;
	case 1:
		if (distance_y > 0)
		{
			distance_y = distance_y;
		}
		else if (distance_y < 0)
		{
			distance_y = -distance_y;
		}
		bottom = top + distance_y;
		top = bottom + width;
		break;
	}
}

// Will the next block be higher or lower on the Y axis from the previous one (top view)? 0 = lower, 1 = higher
bool Block::random_bool()
{
	std::random_device random_device;
	std::mt19937 random_engine{ random_device() };
	std::bernoulli_distribution distribution{ 0.5 };
	return distribution(random_engine);
}

void Block::set_direction()
{
	direction = random_bool();
}