!#/bin/sh 

#tests single commands 
make all
echo -e "ls -a\nls\nmkdr file\n      echo    hello\nmkdir\nmv\necho some\nerror\nexit\n" | bin/rshell
