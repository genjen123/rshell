#ifndef CONNECTOR_H
#define CONNECTOR_H

//#include <iostream>
#include <string>
using namespace std;

class Connector
{
	private:
		string connector_type;	//gets connector type (&&, ||, etc.)
	
	public:
		string getType()	//returns type of the connector
		{	return connector_type; }
};



#endif