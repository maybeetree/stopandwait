CXX=g++
CFLAGS=-pedantic-errors --std=c++98 -g -Wfatal-errors

default:
	${CXX} ${CFLAGS} main.cpp medium.cpp random.cpp sender.cpp receiver.cpp -o snw

