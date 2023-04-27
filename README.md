# SIMPLE SHELL

This is a simple shell project developed in C, which emulates the basic functionality of a shell. It allows the user to run commands and operating system programs, and offers some additional functionality, such as running in the background and input and output redirection.

## FUNCTIONALITIES

The simple shell has the following basic functionalities:

1. Execution of operating system commands (for example, ls, pwd, etc.)
2. Execution of external programs (for example, a compiled C program)
3. Running in the background using the "&" operator
4. Input and output redirection using the "<" and ">" operators

## REQUIEREMENTS

This project was developed and tested on a Linux operating system (Ubuntu 20.04 LTS) and requires the following tools and libraries:

1. GCC (to compile the source code)
2. C standard library (stdlib.h)
3. Input/Output Library (stdio.h)
4. Script library (unistd.h)
5. String library (string.h)

## HOW TO USE

To compile the project, the following command must be executed in the terminal:

gcc -o simple_shell simple_shell.c

Once compiled, you can run the simple shell with the following command:

./simple_shell

Once the simple shell is started, you can run operating system commands or external programs as you normally would in the terminal. To exit the simple shell, you can use the "exit" command.
## AUTHORS

This project was developed by Giselle Nieves and Fabiana Tellechea.
If you have any questions or comments, please contact me at my email

Fabiana Tellechea <fabianagtellechea@gmail.com>

Giselle Nieves <anatanonamewanamedesuka2@gmail.com>
