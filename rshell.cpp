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
    //arguments for ls, will run: ls -1/bin
    
    char* amazing[3];
    string ls = "ls";
    string dash_l = "-1";
    amazing[0] = (char*)ls.c_str();
    amazing[1] = (char*)dash_l.c_str();
    amazing[2] = NULL;
    pid_t c_pid,pid;
    c_pid = fork();//duplicate
    int status;
    
    if(c_pid == 0)
    {
        pid = getpid();
        
        //child:The return of fork() is zero
        cout << "I am the child " << c_pid << endl;
        
        //cout << "child sleep for 2 seconds, then exit" << endl;
        execvp(amazing[0], amazing);
        
        //only get here if exec failed
        perror("execve failerd");
        //sleep for 2 seconds
        //sleep(2);
        //exit
    }
    else if(c_pid >0)
    {
        //parent: The return of fork() is the process of id of the child
        
        //waiting for child to terminate
        
        if((pid = wait(&status)) < 0)
        {
            perror("wait");
            _exit(1);
        }
        
        //pid = wait(&status);
        
        cout << "parent: I am the parent " << c_pid << endl;
    }
    else
    {
        //error:The return of the fork() is negative
        
        perror("fork failed");//print a system error message
        _exit(1);//exit failuer, hard
        
    }
    
	return 0;
}
