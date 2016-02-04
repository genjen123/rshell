CXX = g++
#CXXFLAGS = -g -Wall -W -Werror -ansi -pedantic
CXXFLAGS = -g

OBJECTS =
MAIN = rshell.cpp
EXE = a.out
HEADERS = shell.h parse.h connector.h command.h commandnode.h 
CPP = 
TAR = rshell.tar
TARLIST = rshell.cpp $(CPP) $(HEADERS) $(DICTLIST) $(EXE)

all: $(HEADERS) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(MAIN) $(HEADERS)

compress:
	tar -czvf $(TAR) $(TARLIST) $(EXE) makefile

uncompress:
	tar -xzvf $(TAR)

run:
	make clean
	make all
	./$(EXE) 

clear:
	clear
	clear
	clear	

# remove unnecessary files
clean:
	rm -rf *~ *.o a.out
