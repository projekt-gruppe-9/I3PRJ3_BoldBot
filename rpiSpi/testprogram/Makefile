SOURCES=test.c
OBJECTS=${SOURCES:.c=.o}
EXE=test_exe
CXX=arm-rpizw-gcc
CXXFLAGS=-ggdb -I.

%.o: %.c
	${CXX} -c -o $@ $^ ${CXXFLAGS}

${EXE}: ${OBJECTS}
	${CXX} -o $@ $^

clean:
	rm ${OBJECTS} test_exe
