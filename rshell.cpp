#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include "shell.h"
#include "parse.h"
using namespace std;


int main()
{
    
    Shell a;
    Parse b;
    a.start();
    b.readLine();
    b.parseSim();
	return 0;
}
