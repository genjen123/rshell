#include <iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string>

using namespace std;



/*
 Basiclly, for our assignment
 
    we need to check what does the previous one return,if it return 1 that means that's pretty much what my function in the main doing.The way we use execvp it's in the main function.
 
 Back to the logic part, so we check whwat previous one return and then we decide are we gonna run the second or not, 
 
 if our connector is && we are only gonna run the second command when it returns 0.
 
 If our connector is ||, we are only gonna run the next command when the first one return a non zero exit status.
 
 If our connector is ;, we don't care if the previou one is  success or not, we will just run the second command.
 
 That's the three logic I find.
 
*/

int main()
{
    char* amazing[3];
    string ls = "er";
    string dash_l = "-a";
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
        if(execvp(amazing[0], amazing))
        {
            //only get here if exec failed
            perror("execve failerd");
            
            //exit
            exit(1);

        }
           
           
    }
    else if(c_pid >0)
    {
        //parent: The return of fork() is the process of id of the child
               
        //waiting for child to terminate
        int data;
        if((pid = wait(&status)) < 0)
        {
            perror("wait");
            exit(1);
        }
               
        //pid = wait(&status);
               
        
        cout << "parent: I am the parent " << c_pid << endl;
    }
    else
    {
        //error:The return of the fork() is negative
    
        perror("fork failed");//print a system error message
        exit(1);//exit failuer, hard
    
    }



    return 0;

}

/*shell
 1 logic for command1 && command2
 
 if the left one return 0 the right will be executed
 2 logic for ||
 command1 || command2
 if the left command return 1 (when it's wrong), the right command2 will be executed.
 
 
 for the assginemt
 we need to make sure we have && not this &
 and || but not this|
 
 If previous command failed with ; the second one will run.
 
 But with && the second one will not run.
 
 then we run it
 
 Commands separate by ; are executed sequentially regardless of their completion status.
 
 command1 && command2
 command2 is executed if, and only if, command1 returns an exit status of zero.
 
 An OR list has the form
 
 command1 || command2
 command2 is executed if, and only if, command1 returns a non-zero exit status.
 
 ignore this part,
 some background material
 */
