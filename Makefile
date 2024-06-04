CXX=g++
CFLAGS=-pedantic-errors --std=c++98 -g

default:
	${CXX} ${CFLAGS} main.cpp medium.cpp random.cpp -o snw

