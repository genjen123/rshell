CXX = g++
CXXFLAGS = -Wall -Werror -ansi -pedantic 
#CXXFLAGS = -g

OBJECTS =
MAIN = rshell.cpp
EXE = rshell
HEADERS = shell.h parse.h connector.h command.h commandnode.h 
CPP = 
TAR = rshell.tar
TARLIST = rshell.cpp $(CPP) $(HEADERS) $(DICTLIST) $(EXE)
EXEDIR=bin
#createDIR :=$(bash mkdir -p $(EXEDIR))

all: $(HEADERS) $(MAIN)
	#Figure out a better way to do this
	mkdir -p $(EXEDIR)
	$(CXX) $(CXXFLAGS) -o $(EXEDIR)/$(EXE) $(MAIN)

compress:
	tar -czvf $(TAR) $(TARLIST) $(EXE) makefile

uncompress:
	tar -xzvf $(TAR)

run:
	make clean
	make all
	$(EXEDIR)/$(EXE) 

clear:
	clear
	clear
	clear	

# remove unnecessary files
clean:
	rm -rf *~ *.o a.out $(EXEDIR)/* $(EXEDIR) $(EXE)
