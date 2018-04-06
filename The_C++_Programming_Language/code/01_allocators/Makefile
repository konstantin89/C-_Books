CXX = g++
CXX_FLAGS = -Wall -Wextra -g -std=c++14
CXX_LINK_FLAGS = -pthread

EXEC=main

all: ${EXEC}

${EXEC}: ${EXEC}.cpp allocator.h object_traits.h heap.h
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXEC)
