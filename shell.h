#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdio.h>
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
		
		bool execute(const CommandNode &cn)
		{
			bool returnStatus = false;
			cout << cn << endl;
			return returnStatus;
		}

		void initialize()	//start shell
		{
			start();

			while(status)	//user input and parse commands
			{
				//initializing variables
				string input, command;
				Parse str;				
		
				//generate username (extra credit)
				char username[1024] = {0};
				int getUsername_resp = getlogin_r(username, sizeof(username) - 1);

				char hostName[1024] = {0};
				int getHostName_resp = gethostname(hostName, sizeof(hostName) - 1);

				if((getHostName_resp == 0) && (getUsername_resp == 0))
				{ printf("%s@%s", username, hostName); }

				cout << "$ ";

				getline(cin, input);	//get line input
				//cout << input << endl;
	
				if(input != "exit")
				{
					string parseTag = str.split(input, "#").at(0);	//parse #

					vector<string> parseCom = str.split(parseTag, ";");	//parse ;
					
					//go through command parts and create list of commandNodes
					vector<CommandNode> commandList;
					for(unsigned int i = 0; i < parseCom.size(); i++)
					{
						command = parseCom.at(i);	//separate commands

						//initializing variables
						string temp = "";
						string connector = "";

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
								if(orCon < andCon)
								{
									first = orCon;
									connector = "||";
								}
								else if(orCon > andCon)
								{
									first = andCon;
									connector = "&&";
								}
							}
							else if((orCon != string::npos) && (andCon == string::npos))	//if only || is found
							{ 
								first = orCon; 
								connector = "||";
							}
							else if((orCon == string::npos) && (andCon != string::npos))	//if only && is found
							{ 
								first = andCon; 
								connector = "&&";
							}

							temp = command.substr(0, first);	//get parsed string
							commandList.push_back(CommandNode(temp, connector));
							command = command.substr(first + connector.length());
							orCon = command.find("||");			//find repeat ||
							andCon = command.find("&&");		//find repeat &&
						}

						if(command.length() > 0)				//if string isn't empty
						{ commandList.push_back(CommandNode(command, ";")); }

						//go through each command and execute them
						bool prevReturnStat = false;
						bool currentReturnStat = false;

						for(int j = 0; j < commandList.size(); j++)
						{
							//cout << i + 1 << ") [" << j + 1 << "/" << parseCon.size()
							//	 << "]" << str.leftTrim(parseCon.at(j), " ") << endl;
							
							currentReturnStat = execute(commandList.at(i));
							prevReturnStat = currentReturnStat;
							
							if(!prevReturnStat)
							{
								//do something here
							}
							
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

