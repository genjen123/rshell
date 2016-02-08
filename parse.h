#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Parse
{
	private:
		string str;		//temp variables
		vector<string> strParts;	
		//vector<string> splitStr(string input, string pattern);	//vector of split strings

	public:
		//default constructors
		Parse(){}; 	
		Parse(string input): str(input){}

		void parseAll(string input)
		{
			input = parseTag(input);
			parseSemi(input);
		}

		string parseTag(string input)	//parses by semi colon and #
		{
			string strEdit;
			int posTag = input.find("#");		//find position of #

			if(posTag != string::npos)			//if found
			{
				strEdit = input.substr(0, posTag);	//cut string to #
				//cout << strEdit << endl;
			}
			return strEdit;
		}

		void parseSemi(string input)
		{
			int posSemi = input.find(";");	//find position of ;
			string strEdit;

			while(posSemi != string::npos)
			{
				strEdit = input.substr(0, posSemi);		//cut str to ;
				
				if(strEdit != " ")
				{
					strParts.push_back(strEdit);		//push part to vector
				}

				//check for spacing later

				input = input.substr(posSemi + 2);		//edit input string
				posSemi = input.find(";");				//find other ; repeats
			}	
			/*
			for(int i = 0; i < strParts.size(); i++)
			{
				cout << strParts.at(i) << endl;
			}
			*/
		}

		string ParseCmd(string input);	//parses by commands (&&, ||, etc.)
};

#endif
