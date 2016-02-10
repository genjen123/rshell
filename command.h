#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>
#include <vector>
#include "parse.h"
using namespace std;

class Command
{
	private:
		vector<string> argList;	//argument list
		string executable;	//executable of the command (ls, echo, etc.)
	
	public:
		//default constructor
		Command(){};
		Command(string command)
		{
			Parse p;		//parse object
			
			command = p.ltrim(command, " ");
			vector<string> tmp = p.split(command, " ");		//parse found executable into vector
			executable = p.ltrim(tmp.at(0), " ");	

			if(tmp.size() > 1)		
			{
				for(unsigned int i = 1; i < tmp.size(); i++)
				{
					string argVal = tmp.at(i);
					argList.push_back(p.ltrim(argVal, " "));
				}
			}
		}

		string getExec() const					//get executable
		{ return executable; }

		vector<string> getArgList() const		//get argList
		{ return argList; }

		string getArgListStr() const			//get string of argList vector
		{
			string newStr = "";

			for(unsigned int i = 0; i < argList.size(); i++)
			{
				if(i != 0)
				{ newStr += " "; }				//increment spaces
				
				newStr += argList.at(i);
			}
			return newStr;
		}

		string getCommand_c_str()
		{
			string commandStr = "";
			return commandStr;
		}

		friend ostream& operator <<(ostream& os, const Command c);
};

ostream& operator <<(ostream& os, const Command c)
{
	if(c.getArgListStr().length() > 0)
	{
		os << c.getExec() << " " << c.getArgListStr();
	}
	else
	{ os << c.getExec(); }

	return os;
}

#endif

