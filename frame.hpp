#pragma once

class Frame {

	public:

		Frame(bool is_valid, int seq, int payload) :
			is_valid(is_valid),
			seq(seq),
			payload(payload)
			{};

		bool is_valid;
		int seq;
		int payload;
};

