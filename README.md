# Program summary:
	
> This project is the creation of a command shell called rshell.
> Main functions of the shell are to print a command prompt (e.g. $), 
> read in a command in one line, and execute each command. 

**Commands will take the form:**

	cmd       = executable [argumentList] [connector cmd]
	connector = || or && or ;

> The program is able to take in a limitless number of commands as
> long as they are chained together. 

**Example:** 

	$ ls -a
			
###### OR
			
	$ ls -a; echo hello; mkdir test
			
###### OR
			
	$ ls -a; echo hello && mkdir test || echo world; git status

####Additional commands/functionality:

**Test:**

> Used to check if a file/directory exists (for this program).
> This command is useful for writing conditions that can be combined with
> && or || to write more complex bash command structures.

**Tests will take the form:**

	$ test -e /test/file/path

######OR
	
	$ [ -e /test/file/path ]

> Currently, it will also work on the following flags:

	-e : checks if the file/directory exists
	-f : checks if the file/directory exists and is a regular file
	-d : checks if the file/directory exists and is a directory

> If a flag is not specified then -e will be used by default. 

**Output**
	
> Test will output a boolean status to the terminal as it is evaluated.

**Example:**

	test -e /test/file/path evaluates to True

######output: (True)

	test -e /test/file/path evaluates to False

######output: (False)

**Precedence Operators:**

> Takes the form of **( )** and are used to change the precedence of the returns of commands, connectors, and chains of connectors. 

**Example:**

	$ echo A && echo B || echo C && echo D

######output: A B D

	$ (echo A && echo B) || (echo C && echo D)

######output: A B

**Basic Program Execution:**

- Execution of the command(s) will use the syscalls *fork*, *execvp*, and *waitpid*.
- A special built-in command of *exit* will exit the rshell. 
- Anything after a *#* will be ignored.
- The *;* is used to break up commands.
- Anything within the *( )* will execute first.
- For now, *test* only has 3 flags so any flag other than -e, -f, or -d will produce an error.  
- Execution of **test** uses the *stat( )* function as well as the *S_ISDIR* and *S_ISREG* macros in order to implement the flags for the program.
- The code will output nothing if nothing is entered. 

**Running the program:**
	
	$ git clone https://github.com/genjen123/rshell.git
	$ cd rshell
	$ git checkout hw2
	$ make
	$ bin/rshell

# Known bugs:

> Below is a table of known bugs that we have recorded during our testings. 
> Note that this table does not reflect all possible errors available in the 
> code. These bugs are based on test cases we have thought of at the moment. 
> The current amount of bugs may or may not be the complete amount. However, 
> that does not mean that the code will function any less than the quality 
> desired. 

Bug | Description
--------------- | ---------------
Space readings | A space before a command will produce an error
Echo output | Needs at least 2 spaces between echo and the string in order for the whole message to be outputted (vary on systems)
ls | ls will work as a command however, ls -a may or may not work (vary on systems)
cd | Works if the command is repeated for a second time but error message stil shows.
[ ] | Works best if there is a space between the arguments and brackets.

**Notes:** 

- Any program that's bash specific may not work for the shell. However, standard cd commands can.
- Some recorded bugs (like ls and echo) are only bugs found when running on our personal work environment. So if the program is normally run on hammer then they are perfectly functional.
- Any commands taken in input from ~ will not be run properly. If it needs to be implemented then it could be substituted for the user's homepath. 
- Unlike an actual terminal, if the number of "(" is not equal to the number of ")", the rshell will output an error message.
