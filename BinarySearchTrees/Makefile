#variables

COMPILER = g++
LINKER = g++
OPTIONS = -c -g
EXE = program

#rules

$(EXE) : main.o
	$(LINKER) main.o -o $(EXE)
main.o : main.cpp bst.h
	$(COMPILER) $(OPTIONS) main.cpp
clean :
	-rm -rf *.o $(EXE)
	