CXX=g++
CFLAGS=-pedantic-errors --std=c++98 -g -Wfatal-errors -Wall -Wextra -Werror
SPATH=./src
OPATH=./bin
ONAME=snw

default:
	${CXX} ${CFLAGS} ${SPATH}/* -o ${OPATH}/${ONAME}

