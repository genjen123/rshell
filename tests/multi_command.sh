#!/bin/sh

#tests commmands with ;, &&, or ||
make all
echo -e "ls;		pwd;\nls || cd || pwd\nls -a; echo hello; mkdir test2\npwd && echo pwd || ls -a\npwd; cd .. && ls || mkdir hit\nexit\n" | bin/rshell
