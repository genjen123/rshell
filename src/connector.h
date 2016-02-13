#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <string>
#include "parse.h"
using namespace std;

class Connector
{
	private:
		string connector_type;	//gets connector type (&&, ||, etc.)
	
	public:
		//default constructors
		Connector(){};			
		Connector(const string &connector)
		{ connector_type = connector; }

		ostream& operator <<(ostream& os, const Connector c);

		string getType() const		//returns type of the connector
		{ return connector_type; }
};

ostream& operator <<(ostream& os, const Connector c)
{
	os << c.getType();
	return os;
}



#endif
