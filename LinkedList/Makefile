#variables

COMPILER = g++
LINKER = g++
OPTIONS = -c -g
EXE = program

#rules

$(EXE) : main.o links.o
	$(LINKER) main.o links.o -o $(EXE)
main.o : main.cpp links.h
	$(COMPILER) $(OPTIONS) main.cpp
links.o : links.cpp links.h
	$(COMPILER) $(OPTIONS) links.cpp
clean :
	-rm -rf *.o $(EXE)