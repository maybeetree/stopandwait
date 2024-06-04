#include "stdio.h"

#include "frame.hpp"

int main() {
	Frame frame = Frame(1, 2, 3);
	printf("%i %i %i\n", frame.is_valid, frame.seq, frame.payload);
	return 0;
}

