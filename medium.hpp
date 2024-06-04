/*
 * medium.hpp
 *
 */
#pragma once
#include "frame.hpp"

class Medium {
	public:
		Medium (double prob);

		double prob;

		void write(Frame *frame);
		Frame read();

		Frame* cur_frame;
};

