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

	// copy frame from receiver "intp the cable"
	cur_frame = new Frame(*frame);
}

Frame Medium::read() {
	assert(cur_frame != 0);

	// take the frame "out of the cable"
	Frame frame = *cur_frame;
	delete cur_frame;
	cur_frame = 0;


	if (rand01() <= prob) {
		frame.is_valid = 0;
	}

	return frame;
}

bool Medium::has_data() {
	return (cur_frame != 0);
}
