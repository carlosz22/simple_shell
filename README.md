# 0x16. C - Simple Shell
![logo](./shell.jpeg)
## Description
----
This team project is part of the first year curriculum of Holberton School.
Simple Shell is a UNIX command line interpreter that replicates the **sh** program.

What we learned:
* How a shell works and finds commands
* Creating, forking and working with processes
* Executing a program from another program
* Handling dynamic memory allocation in a large program
* Pair programming and team work
* Building a test suite to check our own code
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates* 

---

## Compile and run
----
1. Git clone all this respository to your local directory.
```
$ git clone https://github.com/carlosz22/test_shell.git
```
2. Compile the program.
```
$ make all
```

* [Makefile](./Makefile)

3. Execute the shell.
```
$ ./shell
```
Note: You can also run this shell in non-interactive mode, by simply piping your desired commands into the shell executable.

## Usage
----
* Prints a prompt and waits for a command from the user
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* To exit: press Ctrl-D or enter "exit" (with or without a status)
* Works also in non interactive mode

## Examples
----
```bash
# Interactive Mode
$ /bin/ls
foo main.c coquille.c README.md tests croissant.c
```
```bash
$ pwd 
/home/vagrant/simple_shell
```
```bash
$ ls -l
total 60
drwxrwxr-x 7 vagrant vagrant  4096 Apr  7 01:48 foo
-rw-rw-r-- 1 vagrant vagrant   148 Apr  7 00:00 main.c
-rwxrw-r-- 1 vagrant vagrant    28 Apr  7 15:35 coquille.c
```
```bash
$ baguette
./shell: No such file or directory
```
```bash
# Non-interactive Mode
$ echo "ls -l" | ./shell

$ ls -l
total 60
drwxrwxr-x 7 vagrant vagrant  4096 Apr  7 01:48 foo
-rw-rw-r-- 1 vagrant vagrant   148 Apr  7 00:00 main.c
-rwxrw-r-- 1 vagrant vagrant    28 Apr  7 15:35 coquille.c
```

## Builtin Commands
----
This shell supports a variety of builtin commands:

`cd` - change directory

`env` - list the current environment variables

`exit` - exit the shell

`help` - display help for a builtin command

*Note:* To read the help information and syntax for a particular builtin command, run the following from the shell prompt:
```
$ help <builtin command>
```

## Files
----
File | Content
---- | -----------
[main.c](./main.c) | entry point, executing function
[shell.h](./shell.h) | function prototypes, standard libraries, structs
[hsh_readline.c](./hsh_readline.c) | read line functions
[hsh_parseline.c](./hsh_parseline.c) | string to tokens parsing functions
[hsh_execute.c](./hsh_execute.c) | functions dealing with the shell builtins and command execution
[hsh_getenv.c ](./hsh_getenv.c ) | functions dealing with environment variable
[hsh_splitpath.c](./path_finder.c) | functions that check the PATH for commands
[hsh_string.c](./helper_funcs.c) | function dealing with string conversion and operations
[more_functions.c](./more_functions.c) | conversion between string and number functions
[man_1_simple_shell](./man_1_simple_shell) | Simple Shell man page (```man ./man_1_simple_shell```)

## Authors
----
* **Cesar Velez** - [cavb.28@gmail.com](https://github.com/cavb28)
* **Carlos Zuluaga** - [carlosez9@hotmail.com](https://github.com/carlosz22)