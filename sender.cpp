#include "sender.hpp"

Sender::Sender(Payload queue[], Medium *to_recv, Medium *from_recv) {
	this -> queue = queue;
	this -> to_recv = to_recv;
	this -> from_recv = from_recv;
	last_sent = -1;
}

void Sender::send() {
	Frame new_frame = Frame(1, last_sent + 1, queue[last_sent + 1]);
	to_recv -> write(&new_frame);
}

void Sender::listen() {
	Frame ack = from_recv -> read();

	if (ack.is_valid and ack.seq == last_sent + 1) {
		last_sent++;
	}
}

