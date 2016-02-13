#!/bin/sh

#tests exit and commands with exit
make all
echo -e "cd .. || exit\n#exit\nexit\n" | bin/rshell

