# 0x16. C - Simple Shell

## Description

This Simple Shell project is a collaboration between Gerald Juwah and Ahmed A. Olawale. Who are Software Engineers studing as students of ALX school. This project consists of developing and making our own UNIX command interpreter (Shell).

This Simple_shell project can be compiled and launched from the command line, where its main function is to execute commands read from the standard input.

## Shell Compilation
	$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
## Shell execute
	./hsh

## Commands on shell process
	cd - Change directory
	env - List the current enviroment variables
	exit - exit the shell
	pwd - Print the absolute pathname

## Files
Description of the files used:

| Files | Description             |
| --------- | ------------------- |
| _calloc.c  | Function that allocates memory |
| _cd.c    | Function that changes to the directory of the process |
| _ex.c    | Function that finds if input is esit, therefore terminates process |
| _fork.c | Function that creates process and executes |
| _getline.c | Function that reads what the user writes |
| _signal.c | Function that handles the SIGINT signal |
| _writerr.c | Function that gets each error |
| checkbin.c | Function that checks if commands exits in the PATH |
| gridfree.c | Function that free an array of arrays |
| parser.c | Function that creates an array of pointers depending on the delimit characters used |
| sshell.c | Main function that starts the shell |
| shell. h | Header file with all the functions prototypes |

## Examples

Some of the examples of this shell working process:

cd:

	#cisfun$ pwd
	/home/vagrant/simple_shell
	#cisfun$ cd
	#cisfun$ pwd
	/home/vagrant
	#cisfun$

cd error:

	#cisfun$ cd hola
	./hsh: 1: cd: can't cd to hola
	#cisfun$

exit:

	#cisfun$ exit 123
	vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo $?
	123

exit error:

	#cisfun$ exit hola
	./hsh: 2: exit: Illegal number: hola
	#cisfun$

## Authors
- `Gerald Juwah` geraldjuwah@gmail.com
- `Ahmed A. Olawale` ayobamyahmed@gmail.com
