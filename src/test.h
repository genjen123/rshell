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
		int runTest(const string &exe, const string &cn)
		{
			if(exe == "[]")
			{ return 1; }		//quit immediately

			//set variables and values
			Parse p;
			string arg = " ";
			bool stat;
			string exeTrim = p.ltrim(exe, "[");
			string add, cnTrim;

			if(exe != "test")				//if [] then add to cn and parse ]
			{ 
				add = exeTrim + " " + cn; 
				cnTrim = p.rtrim(add, "]");
				cnTrim = p.ltrim(cnTrim, " ");
			}
			else
			{ cnTrim = p.rtrim(cn, "]"); }

			vector<string> tmp = p.split(cnTrim, " ");		//split flag and directory
			cout << "exe: " << exeTrim << " cn: " << cnTrim << endl;
			cout << "tmp size: " << tmp.size() << endl;

			if(cnTrim.back() != ' ')
			{
				if((exe == "test" || exeTrim == "]" || exeTrim.empty()) && cnTrim.empty()) 
				{ return 1; } 			//if test doesn't have any arguments or flag 
				else if(tmp.size() <= 1 && cn.at(0) == '-')
				{ return 0; }			//if test has no arguments but has flag
			}

			if(tmp.size() > 1)			//if flag and argument
			{
				curr_flag = tmp.at(0);
				arg = tmp.at(1);
			}
			else if(tmp.size() == 1 && cnTrim.at(0) == '-')		//if flag only
			{ return 0; }
			else						//if argument only
			{ 
				curr_flag = "-e";
				arg = tmp.at(0); 
				arg = p.rtrim(arg, "]");
			}

			cout << "flag: " << curr_flag << endl << "arg: " << arg << endl;
			if(curr_flag == arg)		//if no file directory then return
			{ return 0; }		
			
			stat = fExits(curr_flag);		//check if flag is correct

			//start logic of test (0 is success & 1 is error)
			if(stat)
			{
				//struct stat sb;				//stat variable for stat() command
				//struct dirent *ent;			//for directory stream
				//DIR *dir; 

				//checking w/ flags
				if(curr_flag == "-e")		//check if file/directory exists
				{

				}
				else if(curr_flag == "-f")	//check if file/directory is regular file
				{
					//implement S_ISREG
				}
				else if(curr_flag == "-d")	//check if file/directory is a directory
				{
					//implement S_ISDIR
				}



				return 0;				//return success 
			}
			else	
			{ return -1; }				//-1 for nonexisting flag
		}
};

#endif
