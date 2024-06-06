#include "medium.hpp"

class Receiver {
	public:
		Receiver(Payload queue[], Medium *to_recv, Medium *from_recv);

		void listen();
		void send();

		Medium *to_recv, *from_recv;
		Payload *queue;
		int last_recvd;
};

