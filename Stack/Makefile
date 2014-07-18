#variables

COMPILER = g++
LINKER = g++
OPTIONS = -c -g
EXE = program


#rules

$(EXE) : main.o stack.o
	$(LINKER) main.o stack.o -o $(EXE)
main.o : main.cpp stack.h
	$(COMPILER) $(OPTIONS) main.cpp
stack.o : stack.cpp stack.h
	$(COMPILER) $(OPTIONS) stack.cpp
clean :
	-rm -rf *.o $(EXE)


