#include <cassert>
#include "medium.hpp"
#include "random.hpp"

Medium::Medium(double prob) {
	assert(prob <= 1 && prob >= 0);
	this -> prob = prob;
	cur_frame = 0;
}

void Medium::write(Frame *frame) {
	assert(cur_frame == 0);

	cur_frame = frame;
}

Frame Medium::read() {
	assert(cur_frame != 0);

	Frame frame = *cur_frame;
	cur_frame = 0;


	if (rand01() <= prob) {
		frame.is_valid = 0;
	}

	return frame;
}

