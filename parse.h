#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
using namespace std;

class Parse
{
	private:
		string before;		//temp variables
		string after;	
		vector<string> split(string str_input, string pattern);	//vector of split strings

	public:
		Parse(){}; 	//constructor
		string ParseSemi(string);	//parses by semi colon and #
		string ParseCmd(string);	//parses by commands (&&, ||, etc.)
};

#endif