#ifndef PARSE_H
#define PARSE_H
#include<iostream>
#include<stdlib.h>
#include<istream>
#define MAXLENGTH 100

using namespace std;

class Parse
{
	private:
		//string before;		//temp variables
		//string after;
		//vector<string> split(string str_input, string pattern);	//vector of split strings
        char line[MAXLENGTH];

	public:
		Parse(){}; 	//constructor
        void readLine()
        {

            
     
            cin.getline(line,MAXLENGTH);
                
//                
//            for(int i = 0; i < sizeof(line); ++i)
//            {
//                cout << line[i];
//            }
//                
            return;
                
                
        }
    
        char** parseLine()
        {
            //char pointer array
            int specialSize, position = 0;
            char* wonderful[MAXLENGTH];
            char* token;
            
            while(token != NULL)
            {
                wonderful[position] = token;
                position++;
                
            }
            cout << "this is for the parseLine" << endl;
//            for(int i = 0; i < 1; ++i)
//            {
//                for(int j = 0; j < 1; ++j)
//                {
//                
//                    cout << wonderful[i][j];
//                }
//            }
            return wonderful;
            
            
        
        }
    
    
};

#endif