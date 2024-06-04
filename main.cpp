#include "stdio.h"

#include "frame.hpp"
#include "medium.hpp"

int main() {
	Frame frame = Frame(1, 2, 3);
	printf("%i %i %i\n", frame.is_valid, frame.seq, frame.payload);

	Medium medium = Medium(0.5);
	for (int i = 0; i < 20; i++) {
		Frame frame = Frame(1, 2, 3);
		medium.write(&frame);
		Frame read = medium.read();
		printf("%i %i\n", frame.is_valid, read.is_valid);
	}
	return 0;
}

