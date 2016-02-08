#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <vector>
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
				//initializing variables
				string input, command;
				Parse str;				

				getline(cin, input);	//get line input
				//cout << input << endl;
	
				if(input != "exit")
				{
					string parseTag = str.split(input, "#").at(0);	//parse #

					vector<string> parseCom = str.split(parseTag, ";");	//parse ;

					//start parsing commands and connectors
					for(unsigned int i = 0; i < parseCom.size(); i++)
					{
						command = parseCom.at(i);	//separate commands

						//initializing variables
						string temp = "";
						vector<string> parseCon; 

						//setting positions for || and &&
						int orCon = command.find("||");
						int andCon = command.find("&&");

						//if || or && is found
						while((orCon != string::npos) || (andCon != string::npos))
						{
							int first = 0;	//position temp variable

							if((orCon != string::npos) && (andCon != string::npos))		//if both are found
							{
								//orCon < andCon then first = orCon else first = andCon
								first = (orCon < andCon) ? orCon : andCon;
							}
							else if((orCon != string::npos) && andCon == string::npos)	//if only || is found
							{ first = orCon; }
							else if((orCon == string::npos) && (andCon != string::npos))	//if only && is found
							{ first = andCon; }

							temp = command.substr(0, first);	//get parsed string
							parseCon.push_back(temp);
							command = command.substr(first + 2);
							orCon = command.find("||");			//find repeat ||
							andCon = command.find("&&");		//find repeat &&
						}

						if(command.length() > 0)				//if string isn't empty
						{ parseCon.push_back(command); }

						for(int j = 0; j < parseCon.size(); j++)
						{
							cout << i + 1 << ") [" << j + 1 << "/" << parseCon.size()
								 << "]" << str.leftTrim(parseCon.at(j), " ") << endl;
						}
					}
				}
				else
				{ break; }	//if user input is exit then break loop and exit
			}
			
			finish();
		}
};




#endif
