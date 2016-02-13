#!/bin/sh

#tests commmands with ;, &&, or ||

		ls; 		pwd;
ls || cd || pwd
ls -a; echo hello; mkdir test2
git status; pwd && echo $PWD || ls -a
pwd; cd .. && ls || mkdir hit