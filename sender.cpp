#include "sender.hpp"

Sender::Sender(int queue[], Medium *to_recv, Medium *from_recv) {
	this -> queue = queue;
	this -> to_recv = to_recv;
	this -> from_recv = from_recv;
	last_sent = -1;
}

void Sender::loop() {
	send();

	if (last_sent == -1) {
		last_sent = 0;
		return;
	}

	//if (! (from_recv -> has_data())) return;

	Frame ack = from_recv -> read();

	//if (! (ack.is_valid)) return;
	//if (! (ack.seq == last_sent)) return;

	if (ack.is_valid and ack.seq == last_sent) {
		last_sent++;
	}
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

