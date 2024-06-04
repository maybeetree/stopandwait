#include "medium.hpp"

class Receiver {
	public:
		Receiver(int queue[], Medium *to_recv, Medium *from_recv);

		void listen();
		void send();

		Medium *to_recv, *from_recv;
		int *queue;
		int last_recvd;
};

