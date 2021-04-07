
#ENTRY=main
ENTRY=example
APPNAME=main
CC ?=gcc
CC=g++
LIBDIR=./lib
INCLUDEDIR=./include

	
all: cbuild cppbuild
	@echo "MAKE CC > $(CC)"
#	ccpbuild
	
cbuild: cppbuild
#	@echo checking CC
ifeq ($(CC),gcc)
	@echo "make gcc"
	$(CC) $(ENTRY).c -o $(APPNAME) -I $(INCLUDEDIR) -L $(LIBDIR) -lmingw32 -lwinmm -lSDL2main -lSDL2 
else
	@echo "NOT MATCH gcc"
endif

cppbuild:
ifeq ($(CC),g++)
	@echo "make g++"
	$(CC) -W -Wall -Wextra -pedantic -o $(APPNAME) ./include/*.cpp $(ENTRY).cpp  -I $(INCLUDEDIR) -L $(LIBDIR) -lmingw32 -lSDL2main -lSDL2
else
	@echo "NOT MATCH g++"
endif


#default:
#	g++ -W -Wall -Wextra -pedantic -o main main.cpp -I ./include/ -L ./lib/ -lmingw32 -lSDL2main -lSDL2
#	g++ -W -Wall -Wextra -pedantic -o main main.cpp -I ./include/ -L ./lib/ -lmingw32 -lSDL2 -lSDL2main -lpthread -lwinmm
#	g++ -o main main.cpp -I ./include/ -L ./lib/ -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2
#	gcc -W -Wall -Wextra -pedantic -o main main.c -I ./include/ -L ./lib/ -lpthread -Llib -lSDL2 -lSDL2main
#	gcc main.c -o main -I $(INCLUDEDIR) -L $(LIBDIR) -lmingw32 -lwinmm -Wimplicit-function-declaration -lSDL2main -lSDL2 
