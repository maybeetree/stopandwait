/*
 * medium.hpp
 *
 */
#pragma once
#include <optional>
#include "frame.hpp"

class Medium {
	public:
		Medium (double prob);

		double prob;

		void write(Frame *frame);
		Frame read();
		bool has_data();

		Frame* cur_frame;
};

