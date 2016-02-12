#!/bin/sh

#tests exit and commands with exit

exit
#exit
pwd && exit
cd .. || exit
mkdir create; pwd && ls -a; echo exit; exit