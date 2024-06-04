#include "receiver.hpp"

Receiver::Receiver(int queue[], Medium *to_recv, Medium *from_recv) {
	this -> queue = queue;
	this -> to_recv = to_recv;
	this -> from_recv = from_recv;
	last_recvd = -1;
}

void Receiver::listen() {
	Frame frame = to_recv -> read();

	if (frame.is_valid and frame.seq == last_recvd + 1) {
		last_recvd++;
		queue[last_recvd] = frame.payload;
	}
}

void Receiver::send() {
	Frame ack = Frame(1, last_recvd, -1);
	from_recv -> write(&ack);
}

