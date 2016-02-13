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
		//default constructors
		CommandNode(){};	
		CommandNode(const string &command, const string &connector)
		{
			c = Command(command);
			con = Connector(connector);
		}

		Command getCommand()		//get command
		{ return c; }

		Connector getConnector()	//get connector
		{ return con; }

		friend ostream& operator <<(ostream& os, const CommandNode cn);
};

ostream& operator <<(ostream& os, const commandNode cn)
{
	os << cn.getCommand() << " " << cn.getConnector();
	return os;
}


#endif