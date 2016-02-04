#ifndef COMMANDNODE_H
#define COMMANDNODE_H

#include <iostream>
#include "connector.h"
#include "command.h"
using namespace std;

class CommandNode: public Command, public Connector
{
	private:
		Command c;		//for command
		Connector con; 	//for connector
	
	public:
		string getCommand();		//get command
		string getConnector();	//get connector
};


#endif