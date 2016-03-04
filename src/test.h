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
#include <dirent.h>
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

		//get flag for error purposes
		string getFlag()
		{ return curr_flag; }

		//return true if proper flag exists
		bool fExits(const string flag)
		{
			if(flag == "-e" || flag == "-f" || flag == "-d")
			{ return true; }

			return false;
		}

		//run test command
		int runTest(const string &cn)
		{
			cout << "current: " << cn << endl;
			if(cn.empty())
			{ return -2; } 			//if test doesn't have any arguments

			//set variables and values
			Parse p;
			string arg = " ";
			bool stat;
			vector<string> tmp = p.split(cn, " ");		//split flag and directory
			
			if(tmp.size() > 1)
			{
				curr_flag = tmp.at(0);
				arg = tmp.at(1);
			}
			else
			{ 
				curr_flag = "-e";
				arg = tmp.at(0); 
			}

			cout << "flag: " << curr_flag << endl << "arg: " << arg << endl;
			stat = fExits(curr_flag);		//check if flag is correct

			//start logic of test (0 is success & -1 is error)
			if(stat)
			{
				struct stat sb;				//stat variable for stat() command



				return 0;
			}
			else	
			{ return -1; }
		}
};

#endif
