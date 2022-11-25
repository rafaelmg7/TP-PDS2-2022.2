CC = g++
CFLAGS=-std=c++11 -Wall
TARGET = TP_execution

CONFIG_DIR = ./Config
SRC_DIR = ./src
BUILD_DIR = ./build

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/documentation.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/documentation.o: ${CONFIG_DIR}/contract.hpp ${CONFIG_DIR}/documentation.cpp
	${CC} ${CFLAGS} -I ${CONFIG_DIR}/ -c ${CONFIG_DIR}/documentation.cpp -o ${BUILD_DIR}/documentation.o

${BUILD_DIR}/main.o: ${CONFIG_DIR}/contract.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${CONFIG_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

all: ${BUILD_DIR}/${TARGET}

clean:
	rm -f ${BUILD_DIR}/*
