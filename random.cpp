#include "random.hpp"
#include <cstdlib>

double rand01() {
	return ((double)std::rand()) / RAND_MAX;
}

