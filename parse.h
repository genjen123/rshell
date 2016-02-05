#ifndef PARSE_H
#define PARSE_H
#include<iostream>
#include<stdlib.h>
#include<istream>

using namespace std;

class Parse
{
	private:
		//string before;		//temp variables
		//string after;
		//vector<string> split(string str_input, string pattern);	//vector of split strings
    char line[256];

	public:
		Parse(){}; 	//constructor
        void readLine()
        {

            
            char line[286];
            cin.getline(line,286);
                
                
            for(int i = 0; i < 3; ++i)
            {
                cout << line[i];
            }
                
            return;
                
                
        }
		//string ParseSemi(string);	//parses by semi colon and #
		//string ParseCmd(string);	//parses by commands (&&, ||, etc.)
};

#endif