#!/bin/sh

#tests commmands with ;, &&, or ||

ls -a; echo hello; mkdir test2
git status; pwd && echo $PWD || ls -a
pwd; cd .. && ls || mkdir hit