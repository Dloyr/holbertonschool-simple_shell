# holbertonschool-simple_shell
## Synopsis :
This is a humble and simple implementation of a UNIX command line interpreter.

## Description :
Custom version UNIX command language interpreter built as a project for Holberton School. This mini shell reads commands from either interactive  mode and non-interactive mode.

## Requirements:
# General:

* Allowed editors: ```vi```, ```vim```, ```emacs```
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to 
* Authorized functions and system calls:
## All functions from string.h
	*  ```access ``` (man 2 access)
	*  ```chdir ``` (man 2 chdir)
	*  ```close ``` (man 2 close)
	*  ```closedir ``` (man 3 closedir)
	*  ```execve ``` (man 2 execve)
	*  ```exit ``` (man 3 exit)
	*  ```_exit ``` (man 2 _exit)
	*  ```fflush ``` (man 3 fflush)
	*  ```fork ``` (man 2 fork)
	*  ```free ``` (man 3 free)
	*  ```getcwd ``` (man 3 getcwd)
	*  ```getline ``` (man 3 getline)
	*  ```getpid ``` (man 2 getpid)
	*  ```isatty ``` (man 3 isatty)
	*  ```kill ``` (man 2 kill)
	*  ```malloc ``` (man 3 malloc)
	*  ```open ``` (man 2 open)
	*  ```opendir ``` (man 3 opendir)
	*  ```perror ``` (man 3 perror)
	*  ```printf ``` (man 3 printf)
	*  ```fprintf ``` (man 3 fprintf)
	*  ```vfprintf ``` (man 3 vfprintf)
	*  ```sprintf ``` (man 3 sprintf)
	*  ```putchar ``` (man 3 putchar)
	*  ```read ``` (man 2 read)
	*  ```readdir ``` (man 3 readdir)
	*  ```signal ``` (man 2 signal)
	*  ```stat ``` (__xstat) (man 2 stat)
	*  ```lstat ``` (__lxstat) (man 2 lstat)
	*  ```fstat ``` (__fxstat) (man 2 fstat)
	*  ```strtok ``` (man 3 strtok)
	*  ```wait ``` (man 2 wait)
	*  ```waitpid ``` (man 2 waitpid)
	*  ```wait3 ``` (man 2 wait3)
	*  ```wait4 ``` (man 2 wait4)
	*  ```write ``` (man 2 write)

## Quick start :runner:
Git clone the repository:

```
git clone https://github.com/Dloyr/holbertonschool-simple_shell.git
```

## Usage :computer:
All the files are to be compiled on an Ubuntu  20.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Once compiled, to start the program, run:
```./hsh```

To exit the program, run:
```$ exit```

You can use the same syntax for running commands in other shells:
```
<command> <flags or options> <argument 1> <argument 2> ...
```

In non-interactive mode:
```
<command> | ./hsh
```
## Authors :
* ** Dimitri Loyer [Github] (https://github.com/Dloyr)
* ** Laeticia Beles [Github] (https://github.com/laetitiabeles)
* ** Yohan Mayot [Github] (https://github.com/CrackBoy974)

## Bugs :
No knows bugs.

## Acknowledgements :
Thanks to all the software engineers, peers from different cohorts of the Holberton School, for all the learning that we have been able to acquire in this academic period culminating in this shell emulation. 

For more information about Holberton, visit this [link](https://www.holbertonschool.com/).

<p align="center">
<img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>
