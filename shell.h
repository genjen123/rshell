#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include "parse.h"
#include "commandnode.h"
using namespace std;

class Shell
{
	private:
		bool status;		//check status of whether shell cont. running or not
	
	public:
		Shell(){};		//constructor
		bool getStatus()
		{ return status; }

		void start()		//start shell program
		{ status = true; }

		void finish()		//shell is done
		{ status = false; }
		
		void initialize()	//start shell
		{
			start();

			while(status == true)	//user input and parse commands
			{
				string input; 
				Parse str;				//parse object

				getline(cin, input);	//get line input
				//cout << input << endl;
	
				if(input != "exit")
				{
					str.parseAll(input);	//parse input
				}
				else
				{ break; }	//if user input is exit then break loop and exit
			}
			
			finish();
		}
};




#endif
