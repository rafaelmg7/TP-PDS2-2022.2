CC = g++
CFLAGS=-std=c++11 -Wall
TARGET = TP_execution

BUILD_DIR = ./build

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/documentation.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/documentation.o: /contract.hpp /documentation.cpp
	${CC} ${CFLAGS} -I -c /documentation.cpp -o ${BUILD_DIR}/documentation.o

${BUILD_DIR}/main.o: contract.hpp /main.cpp
	${CC} ${CFLAGS} -I -c /main.cpp -o ${BUILD_DIR}/main.o

all: ${BUILD_DIR}/${TARGET}

clean:
	rm -f ${BUILD_DIR}/*
