#include <iostream>
#include <stdlib.h>
#include "shell.h"
#include "parse.h"
using namespace std;

int main()
{
	Shell sh;			//initialize shell object
	bool status;			//check to cont. shell or not

	sh.initialize();		//start shell program
	status = sh.getStatus();
	
	if(status == true)
	{
		//cont. looping shell program
	}
	else 
	{ return 0; }	//end and exit program	

}
