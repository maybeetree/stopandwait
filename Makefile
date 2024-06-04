CXX=g++
CFLAGS=-pedantic-errors --std=c++98

default:
	${CXX} ${CFLAGS} main.cpp -o snw

