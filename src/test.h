#ifndef TEST_H
#define TEST_H

//std included
#include <iostream>
#include <vector>
//syscalls
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
//files included
#include "parse.h"
#include "commandnode.h"
#include "shell.h"
using namespace std;

class Test : public CommandNode
{
	private:
		string curr_flag;		//contain current flag 

	public:
		//default constructor
		Test(){};

		//run test command
		void runTest(string testStr)
		{

		}
};

#endif
