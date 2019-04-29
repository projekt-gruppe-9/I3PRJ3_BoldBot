EXX= output
COM = arm-rpizw-gcc
#CXXFLAGS= -I.
#Tager alle .cpp filer
SOURCES= *.c 
#omdanner .cpp til .o
OBJECTS=$(SOURCES: .cpp = .o)
MAIN=sonarinputmain.c

all:output

output: $(OBJECTS)
	$(COM) -o $@ $^

main.o: $(MAIN)
	$(COM) -c $@$^

clean: 
	rm *.o output

	
