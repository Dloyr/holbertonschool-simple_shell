# Holberton School: Simple-Shell 💻

# Description
The HSH (Holberton School Simple-Shell) is our second group project of the trimester. 

It consists of build a C language program, used as a Linux command line interpreter.

A shell is a command-line interface that allows users to interact with an operating system by executing commands and managing system resources.

# Project Requirements ✔️

## General
- Allowed editors: vi, vim, emacs

- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options ``-Wall -Werror -Wextra -pedantic -std=gnu89``

- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory

- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

- Your shell should not have any memory leaks
    No more than 5 functions per file

- All your header files should be include guarded
    Use system calls only when you need to.


## About the Shell ⚠️

- Display a prompt and wait for the user to type a command. 

- A command line always ends with a new line.

- The prompt is displayed again each time a command has been executed.

- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

- The command lines are made only of one word. No arguments will be passed to programs.

- If an executable cannot be found, print an error message and display the prompt again.

- Handle errors.

- You have to handle the “end of file” condition ``(Ctrl+D)``

- Handle command lines with arguments

- Handle the ``PATH``

- ``fork`` must not be called if the command doesn’t exist
- Implement the ``exit`` built-in, that exits the shell

- Usage: ``exit``

- You don’t have to handle any argument to the built-in ``exit``

- Implement the ``env`` built-in, that prints the current environment

# Flowchart 🧠
![Flowchart](https://i.ibb.co/dcLHHt2/Capture-d-cran-2023-12-21-14-43-07.png)

# File usage 📂
| Name file      | Description |
| ----------- | ----------- |
| .gitignore      | File used for ignore some file when whe push into GitHub.       |
| main.h   | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If one. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed.        |
| main.c | The `main` function initializes the shell environment. It establishes an infinite loop that presents a prompt, captures user input, and directs the shell's behavior accordingly: if the user types "exit," the shell terminates; for an existing command (e.g., ls, pwd), the shell executes it and resumes the loop; when entering the path of an existing command (e.g., /bin/ls), the shell runs the command and restarts the loop; in the case of a non-existent command, the shell prompts an error message.|
| execute command.c | Responsible for running a given command in a child process. The function takes the full path of the command and an array containing the command and its arguments. It returns 0 on success and 1 on failure.|
| free.c | Freeing the memory allocated for an array. The function takes the array and its index as parameters. This function facilitates the proper deallocation of memory for arrays, ensuring that allocated memory is released to prevent memory leaks in the shell program. | 
| getPATH.c | This function obtains the full path of a command based on the user's input. The function takes the input command as a parameter and returns the full path on success or NULL on failure. |
| handle_input.c | Responsible for processing user input, tokenizing it, obtaining the full path of the command, and executing the command. The function takes the user input (line), an array to store tokens (array), and a pointer to store the full path of the command (full_path). It returns the index. |
| tokenize_input.c | This function facilitates the tokenization of user input, ensuring that each token is stored in the provided array. The return type indicates the number of tokens processed during the tokenization process. |

# Compilation ⚙️

You can compile your program using the following command :

``gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh``

# Man page

You can access at our man page using the following command :

``man ./man_1_simple_shell``

# Memory check

You can check memory leaks using the following command :

``valgrind ./hsh``

```
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./hsh
```

# Testing the program
## Interactive mode 
```
$ ls
README.md               free.c                  handle_input.c          hsh.dSYM                main.h
execute_command.c       getPATH.c               hsh                     main.c                  tokenize_input.c
```

```
$ ls -l
total 144
-rw-r--r--  1 laetitiabeles  staff   4712 Dec 21 15:15 README.md
-rw-r--r--  1 laetitiabeles  staff    705 Dec 21 00:47 execute_command.c
-rw-r--r--  1 laetitiabeles  staff    218 Dec 21 10:59 free.c
-rw-r--r--  1 laetitiabeles  staff    793 Dec 21 10:59 getPATH.c
-rw-r--r--  1 laetitiabeles  staff    709 Dec 21 00:47 handle_input.c
-rwxr-xr-x  1 laetitiabeles  staff  34592 Dec 21 15:18 hsh
drwxr-xr-x  3 laetitiabeles  staff     96 Dec 20 15:59 hsh.dSYM
-rw-r--r--  1 laetitiabeles  staff    828 Dec 21 10:59 main.c
-rw-r--r--  1 laetitiabeles  staff    429 Dec 21 00:47 main.h
-rw-r--r--  1 laetitiabeles  staff    520 Dec 20 17:31 tokenize_input.c
```

```
$ pwd
/Users/laetitiabeles/holbertonschool-simple_shell
```

```
$ /bin/ls
README.md               free.c                  handle_input.c          hsh.dSYM                main.h
execute_command.c       getPATH.c               hsh                     main.c                  tokenize_input.c
```

```
$ exit
laetitiabeles@Air-de-Laetitia holbertonschool-simple_shell % 
```