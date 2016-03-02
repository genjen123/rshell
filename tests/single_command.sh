#!/bin/sh 

#tests single commands 
make all
echo -e "ls -a\nexit\n" | bin/rshell
echo
echo -e "&& echo A\nexit\n" | bin/rshell
echo
echo -e "echo A\nexit\n" | bin/rshell
echo
echo -e "cd ..\nexit\n" | bin/rshell
echo
echo -e "pwd\nexit\n" | bin/rshell
echo
echo -e "something false\nexit\n" | bin/rshell
echo
