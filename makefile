CC = g++
CFLAGS=-std=c++17 -Wall
TARGET = TP_execution
TEST_TARGET = test_execution

BUILD_DIR = ./build
CONFIG_DIR = ./Config
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/documentation.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/main.o ${BUILD_DIR}/documentation.o

${BUILD_DIR}/${TEST_TARGET}: ${BUILD_DIR}/documentation_teste.o ${BUILD_DIR}/documentation.o
	${CC} ${CFLAGS} -o ${TEST_TARGET} ${BUILD_DIR}/documentation_teste.o ${BUILD_DIR}/documentation.o

${BUILD_DIR}/documentation.o: ${CONFIG_DIR}/contract.hpp ${CONFIG_DIR}/documentation.cpp
	${CC} ${CFLAGS} -I ${CONFIG_DIR}/ -c ${CONFIG_DIR}/documentation.cpp -o ${BUILD_DIR}/documentation.o

${BUILD_DIR}/main.o: ${CONFIG_DIR}/contract.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${CONFIG_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/documentation_teste.o: ${CONFIG_DIR}/contract.hpp ${CONFIG_DIR}/doctest.h ${CONFIG_DIR}/documentation_teste.cpp
	${CC} ${CFLAGS} -I ${CONFIG_DIR}/ -c ${CONFIG_DIR}/documentation_teste.cpp -o ${BUILD_DIR}/documentation_teste.o

all: ${BUILD_DIR}/${TARGET}

all_test: ${BUILD_DIR}/${TEST_TARGET}

clean:
	rm -f ${BUILD_DIR}/*
