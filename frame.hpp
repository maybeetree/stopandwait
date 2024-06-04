#pragma once
#include "consts.hpp"

class Frame {

	public:

		Frame(bool is_valid, int seq, Payload payload) :
			is_valid(is_valid),
			seq(seq),
			payload(payload)
			{};

		bool is_valid;
		int seq;
		Payload payload;
};

