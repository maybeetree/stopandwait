#include "medium.hpp"

class Sender {
	public:
		Sender(int queue[], Medium *to_recv, Medium *from_recv);

		void loop();
		void send();
		void listen();

		Medium *to_recv, *from_recv;
		int *queue;
		int last_sent;
};

