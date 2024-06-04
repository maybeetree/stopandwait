#include "random.hpp"
#include <cstdlib>
#include <time.h>

double rand01() {
	return ((double)std::rand()) / RAND_MAX;
}

