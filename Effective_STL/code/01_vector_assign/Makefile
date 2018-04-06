CXX = g++
CXX_FLAGS = -Wall -Wextra -g -std=c++14
CXX_LINK_FLAGS = -pthread

EXEC=assign

all: ${EXEC}

${EXEC}: ${EXEC}.cpp
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXEC)
