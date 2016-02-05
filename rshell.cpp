#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include "shell.h"
#include "parse.h"
using namespace std;

int main()
{
    pid_t c_pid,pid;
    c_pid = fork();//duplicate
    
    if(c_pid == 0)
    {
        pid = getpid();
        
        //child:The return of fork() is zero
        cout << "I am the child" << c_pid << endl;
    }
    else if(c_pid >0)
    {
        //parent: The return of fork() is the process of id of the child
        
        cout << "parent: I am the parent" << c_pid << endl;
    }
    else
    {
        //error:The return of the fork() is negative
        
        perror("fork failed");//print a system error message
        _exit(2);//exit failuer, hard
        
    }
    
	return 0;
}
