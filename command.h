#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class Command
{
	private:
		string* argList;	//argument list
		string executable;	//executable of the command (ls, echo, etc.)
	
	public:
		string getExec()	//get executable
		{ return executable; }

		string* getArgList();	//get argList

		string* getCommand_c_str();
};




#endif