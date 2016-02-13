#!/bin/sh

#tests commands with comments
make all
echo -e "#do not print\necho output\n#exit\nexit\n" | bin/rshell
