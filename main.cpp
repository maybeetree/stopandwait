
#include <cstdlib>
#include <time.h>
#include <stdio.h>

#include "frame.hpp"
#include "medium.hpp"
#include "sender.hpp"

int main() {
	/*
	Frame frame = Frame(1, 2, 3);
	printf("%i %i %i\n", frame.is_valid, frame.seq, frame.payload);

	Medium medium = Medium(0.5);
	for (int i = 0; i < 20; i++) {
		Frame frame = Frame(1, 2, 3);
		medium.write(&frame);
		Frame read = medium.read();
		printf("%i %i\n", frame.is_valid, read.is_valid);
	}
	*/

	std::srand(time(0));

	Medium to_recv = Medium(0.5);
	Medium from_recv = Medium(0.5);
	int data[] = {5, 4, 3, 2, 1};

	Sender sender = Sender(data, &to_recv, &from_recv);
	while (sender.last_sent < 4) {
		sender.send();
		Frame frame = to_recv.read();
		printf("%i %i %i\n", frame.is_valid, frame.payload, frame.seq);

		frame = Frame(1, frame.seq, -1);
		from_recv.write(&frame);
		sender.listen();
	}
	return 0;
}

