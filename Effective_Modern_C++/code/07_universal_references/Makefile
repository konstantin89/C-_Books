CXX = g++
CXX_FLAGS = -Wall -Wextra -g -std=c++14
CXX_LINK_FLAGS = -pthread

EXEC=uni_refs

all: ${EXEC}

${EXEC}: ${EXEC}.cpp ${EXEC}.h
	${CXX} ${CXX_FLAGS} ${CXX_LINK_FLAGS} -o $@ $<

clean:
	rm -rf $(EXEC)
