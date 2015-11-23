
CC          = gcc
CLINKER     = gcc
CCC         = g++
CCLINKER    = $(CCC)
INCLUDE_DIR = 
CFLAGS      = $(INCLUDE_DIR)
CCFLAGS     = $(CFLAGS)
OPTFLAGS    = -g
LIB_PATH    =
LIB_LIST    = -lm
LIBS        = $(LIB_PATH) $(LIB_LIST)

EXEC        = btree
objects     = tree.o interface.o main.o

default: $(EXEC)

$(EXEC): $(objects)
	g++ -g -o $(EXEC) $(objects)

tree.o : tree.cc tree.h
	g++ -c tree.cc -o tree.o

interface.o : interface.cc interface.h tree.h
	g++ -c interface.cc -o interface.o -w

main.o : main.cc tree.h interface.h
	g++ -c main.cc -o main.o

clean :
	rm *.o
	rm $(EXEC)



