#ifndef PARSE_H
#define PARSE_H
#include<iostream>
#include<stdlib.h>
#include<istream>
#include<vector>
#include<string>
//#define MAXLENGTH 256

using namespace std;

class Parse
{
	private:
		string before;		//temp variables
        //vector<string>beforeV;//i make this because there might be new line
		string after;
        vector<string> split;
        //(string str_input, string pattern);	//vector of split strings
        char line[MAXLENGTH];

	public:
		Parse(){}; 	//constructor
        void readLine()
        {

            getline(cin,before);
            
     
//            cin.getline(line,MAXLENGTH);
//                
//                
//            for(int i = 0; i < sizeof(line); ++i)
//            {
//                cout << line[i];
//            }
            
            
            return;
                
                
        }
        //this function is for parsing the thing by ";" and "#"
        void parseSim()
        {
            
            //char pointer array
            //string
            //strtok function
            
//            int specialSize, position = 0;
//            char wonderful[MAXLENGTH];
//            char* wonderful[MAXLENGTH];
//            char* token;
//            
//            while(token != NULL)
//            {
//                wonderful[position] = token;
//                position++;
//                
//            }
//            cout << "this is for the parseLine" << endl;
//            for(int i = 0; i < 1; ++i)
//            {
//                for(int j = 0; j < 1; ++j)
//                {
//                
//                    cout << wonderful[i][j];
//                }
//            }
//            return wonderful;
            
            //start a new one by using only string
//            for(int i = 0; i < beforeV.size();++i)
//            {
//                for(int j = 0; j < beforeV.at(i).size(); ++j)
//                {
//                    cout << beforeV.at(i).at(j) << endl;
//                }
//            }
            int point1 = 0;
            int point2 = 0;
            int counterV = 0;
            for(int j = 0; j < before.size(); ++j)
            {
                //++point1;
                if(before.at(j) == '#')
                {
                    point1 = j;
//                    cout << "hey dude, I am the j for # xoxo " << j << endl;
//                    cout << "hey dude, I am the point2 for # xoxo " << point2 << endl;
//                    cout << "I am the string that never work " << before.substr(point2,point1 - point2) << endl;
                    split.push_back(before.substr(point2,point1 - point2));
                    break;
                        
                }
                else if(before.at(j) == ';')
                {
                    point1 = j;
                    cout << "j" << point1 << endl;
//                    cout << "hey dude, I am the point2 for ; xoxo " << point2 << endl;
//                    cout << "hey dude, I am the point1 for ; xoxo " << point1 << endl;
//                    cout << "I am the string that never work for ; " << before.substr(point2,point1 - point2) << endl;
                    split.push_back(before.substr(point2,point1 - point2));
                    point2 = j + 1;
                    point1++;
                    cout << "size now " << before.size() << endl;
                }
                else if(j == (before.size() - 1))
                {
                    cout << "check out j " << j << endl;
                    cout << "check out point1 " << point1 << endl;
                    split.push_back(before.substr(point1, j - point1 + 1));
                }
                //cout << before.at(j) << endl;
            }
            cout << "size of the split " << split.size() <<  endl;

            for(int i = 0; i < split.size();++i)
            {
                cout << split.at(i) << endl;
            }

            
            
        
        }
    
        void parseLogic()
        {
        
        }
    
    
};

#endif