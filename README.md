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
![Flowchart](https://i.ibb.co/sP6XXCw/Capture-d-cran-2023-12-21-14-43-07.png)

# File usage 📂
| Name file      | Description |
| ----------- | ----------- |
| .gitignore      | File used for ignore some file when whe push into GitHub.       |
| main.h   | Header File. Lists the standard libraries used and integrates the prototypes we need to run the program properly. If one. If a necessary library or a used prototyp is missing in the file, the program will not be able to compile and therefore will not be executed.        |
| main.c | Creates an infinit loop which displays a prompt and reads the input typed by the user.The shell will behave differently depending on what the user types: exit: the shell exits. An existing command (e.g. ls, pwd), the shell executes it and returns to the beginning of the loop. The path of an existing command (e.g. /bin/ls), the shell executes the command and returns to the start of the loop. The command does not exist, the shell displays an error message |
| execute command.c | Text |
| free.c | Text | 
| getPATH.c | Text |
| handle_input.c | Text |
| tokenize_input.c | Text |
