#include "medium.hpp"

class Sender {
	public:
		Sender(Payload queue[], Medium *to_recv, Medium *from_recv);

		void send();
		void listen();

		Medium *to_recv, *from_recv;
		Payload *queue;
		int last_sent;
};

