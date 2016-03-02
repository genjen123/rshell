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

		string ParseCmd(string input);
		
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

    
        vector<string> parenthesis(string input)
        {
            vector<string>values;
            int found1 = input.find("(");
            int found2 = 0;
            int temp1 = 0;
            int temp2 = 0;
            int start = 0;
            string part = "";
            //cout << "hi" << endl;
            
            while(int(found1) != int(string::npos))
            {
                if(start < found1)
                {
                    part = input.substr(start, found1 - start);
                    if(part.size() != 0)
                    {
                        values.push_back(part);
                    }
                    
                    //cout << "input" << input << endl;
                }
                found2 = input.find(")");
                
                if(int(found2) == int(string::npos))
                {
                    cout << "broken parenthesis,dude enter a new one" << endl;
                }
                if(int(found2) != int(string::npos))
                {
                    part = input.substr(found1 + 1, found2 - found1 - 1);
                    input = input.substr(found2 + 1);

                    cout << "I am the input 1 " << input << endl;
                    temp1 = input.find("&");
                    temp2 = input.find("|");
                    cout << "temp1 " << temp1 << endl;
                    cout << "temp2 " << temp2 << endl;

                    if((int(temp1) != int(string::npos))|| (int(temp2) != int(string::npos)))
                    {
                        cout << "hi I am here" << endl;
                        if((temp1 < temp2) && (temp1 != -1))
                        {
                            temp1++;
                            if(input.at(temp1) == '&')
                            {
                                part += "&&";
                                input = input.substr(temp1 + 1);
                            }
                            
                        }
                        else if((temp2 < temp1) && (temp2 != -1))
                        {
                            temp2++;
                            if(input.at(temp2) == '|')
                            {
                                part += "||";
                                input = input.substr(temp2 + 1);
                            }
                        }
                        else if (temp1 != -1)
                        {
                            temp1++;
                            if(input.at(temp1) == '&')
                            {
                                part += "&&";
                                input = input.substr(temp1 + 1);

                            }
                        }
                        else if(temp2 != -1)
                        {
                            
                            temp2++;
                            if(input.at(temp1) == '|')
                            {
                                part += "||";
                                input = input.substr(temp2 + 1);
                            }
                        }
                        
                    }
                    
                    if(part.size() != 0)
                    {
                        values.push_back(part);
                    }
                }
                
                
                
                found1 = input.find("(");
            
            }
            
            if(input.size() != 0)
            {
                values.push_back(input);
            }
            
            
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

		string rtrim(string input, const string &pattern)
		{
			string newString = "";
			return newString;
		}
};

#endif
