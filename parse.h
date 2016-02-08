#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Parse
{
	private:
		//string str;		//temp variables

	public:
		//default constructors
		Parse(){}; 	

		//returns vector of split strings
		vector<string> split(string input, const string &pattern)
		{
			vector<string> strPart;
			int pos = input.find(pattern);		//position of current pattern
			string tmp;

			while(pos != string::npos)			//loop if pattern is found
			{
				tmp = input.substr(0, pos);	
				strPart.push_back(tmp);			//add part to vector

				input = input.substr(pos + pattern.length());	//new input length
				pos = input.find(pattern);		//find other occurences of pattern
			}
			if(input.length() > 0)				//if string isn't empty
			{ strPart.push_back(input); }

			return strPart;
		}

		string leftTrim(string input, const string &pattern)
		{
			string newStr = "";
			int pos = input.find(pattern);		//position of current pattern

			return (pos != 0) ? input: input.substr(pattern.length());	//if pos is not 0 then return input
		}

		string rightTrim(string input, const string &pattern)
		{
			string newStr;

			//do something here

			return newStr;
		}

};

#endif
