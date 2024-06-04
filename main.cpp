
#include <cstdlib>
#include <time.h>
#include <stdio.h>

#include "frame.hpp"
#include "medium.hpp"
#include "sender.hpp"
#include "receiver.hpp"

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
	int data_send[] = {5, 4, 3, 2, 1};
	int data_recv[] = {-1, -1, -1, -1, -1};

	Sender sender = Sender(data_send, &to_recv, &from_recv);
	Receiver receiver = Receiver(data_recv, &to_recv, &from_recv);

	while (sender.last_sent < 5) {
		sender.send();
		receiver.listen();
		receiver.send();
		sender.listen();

		for (int i = 0; i < 5; i++) {
			printf("%i\t", data_recv[i]);
		}
		printf("\n");
	}
	return 0;
}

