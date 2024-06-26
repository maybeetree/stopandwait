
#include <cstdlib>
#include <cassert>
#include <time.h>
#include <stdio.h>

#include "../inc/consts.hpp"
#include "../inc/frame.hpp"
#include "../inc/medium.hpp"
#include "../inc/sender.hpp"
#include "../inc/receiver.hpp"

int main(int argc, char *argv[]) {
	assert(argc == 3);
	double p_fail_dat = std::atof(argv[1]);
	double p_fail_ack = std::atof(argv[2]);

	int len_data = 0;
	Payload data_send[MAX_LEN_DATA];
	Payload data_recv[MAX_LEN_DATA];

	// This is C code lol, std::cin is the c++ way
	// and vectros so you don't need the lngth
	// Also I think they expected you to open the file
	while (scanf("%d", data_send + len_data) > 0) {
		len_data++;
	}

	std::srand(time(0));

	Medium to_recv = Medium(p_fail_dat);
	Medium from_recv = Medium(p_fail_ack);

	Sender sender = Sender(data_send, &to_recv, &from_recv);
	Receiver receiver = Receiver(data_recv, &to_recv, &from_recv);

	while (sender.last_sent < len_data) {
		sender.send();
		receiver.listen();
		receiver.send();
		sender.listen();

		// This is also C, std::cout is the cpp way
		for (int i = 0; i < len_data; i++) {
			printf("%i\t", data_recv[i]);
		}
		printf("\n");
	}
	return 0;
}

