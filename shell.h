#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include "parse.h"
#include "commandnode.h"
using namespace std;

class Shell
{
	private:
		bool status;	//check status of whether shell cont. running or not
	
	public:
		Shell(){};		//constructor
		bool finish();	//check if shell is done
		bool start();	//start shell
};




#endif