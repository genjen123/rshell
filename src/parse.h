#ifndef PARSE_H
#define PARSE_H

#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Parse
{
	private:
		string str;					//temp variable
		vector<string> strParts;			
  
	public:
		//default constructors
		Parse(){}; 	
		Parse(string input): str(input){}

		void parseAll(string input)
		{
			input = parseTag(input);
			parseSemi(input);
		}

		string parseTag(string input)	//parses by #
		{
			string strEdit;
			int posTag = input.find("#");			//find position of #

			if(int(posTag) != int(string::npos))	//if found
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

			while(int(posSemi) != int(string::npos))	//if found 
			{
				strEdit = input.substr(0, posSemi);		//cut str to ;

				if(strEdit != " ")						//if !empty push to part to vector
				{ strParts.push_back(strEdit); }

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
		
		vector<string> split(string input, const string &pattern)
		{
			//initialize variables and values
			vector<string> values;    
			int found = input.find(pattern);	//find position of pattern
			string part = "";

			while(int(found) != int(string::npos))	//if found
			{
				part = input.substr(0,found);		//cut string to pattern
				values.push_back(part);				//add string to vector
				input = input.substr(found+pattern.length());	//edit input string
				found = input.find(pattern);		//find other pattern repeats
			}

			if(input.length() > 0)		//if input !empty
			{ values.push_back(input); }
			
			return values;
		}

		string ltrim(string input, const string &pattern)
		{
			string newString = "";
			int found = input.find(pattern);	//find pos of pattern

			//if not found then return input else new input string
			return (found !=  0) ? input : input.substr(pattern.length());
		}

		string ltrimr(string input, const string &pattern)
		{
			string newString = "";
			int found = input.find(pattern);	//find pos of pattern

			if(int(found) != 0)					//if !found then input stays same
			{ return input; }
			
			newString = input;

			while(int(found) != int(string::npos))	//while pattern is found
			{
				newString = newString.substr(pattern.length());
				found = newString.find(pattern);
			}

			return newString;
		}

		/*string rtrim(string input, const string &pattern)
		{
			string newString = "";
			return newString;
		}*/
};

#endif
