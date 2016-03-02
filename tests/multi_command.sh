#!/bin/sh

#tests commmands with ;, &&, or ||
make all
echo -e "ls;		pwd;\nexit\n" | bin/rshell
echo
echo -e "ls || cd || pwd\nexit\n" | bin/rshell
echo
echo -e "ls -a; echo hello;\nexit\n" | bin/rshell
echo
echo -e "echo a || echo b\nexit\n" | bin/rshell
echo
echo -e "ls -j && echo A\nexit\n" | bin/rshell
echo
echo -e "ls -j && echo A || echo B\nexit\n" | bin/rshell
echo
echo -e "echo A || echo B && echo C\nexit\n" | bin/rshell
echo
echo -e "echo A || echo B || echo C\nexit\n" | bin/rshell 
echo
echo -e "ls -j && echo A; pwd || echo B && echo C\nexit\n" | bin/rshell