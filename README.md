## Simple Shell Project

**A simple Unix Project that execute command interpreter**
![shell](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

---

## Table of contents

- **Background of shell**
- **key function of a shell**
- **Essential Functionalities of the Simple Shell**
- **File description**
- **List of allowed functions and system calls for this project**
- **Installation**
- **Usage**
- **Contributions**
- **Contact**

---

## Background of shell

- A shell is a command-line interface (CLI) program that provides a text-based interface for interacting with an operating system or executing commands. Shells are an essential part of Unix-like operating systems, including Linux, macOS, and various Unix distributions, and they also exist in Windows systems in the form of the Command Prompt and PowerShell.

## Key function of a shell

- Command Interpretation: A shell interprets and executes user-entered commands. Users can type commands directly into the shell, which then processes the commands and interacts with the operating system to perform tasks.

- Text-Based Interface: Shells typically provide a text-based interface, meaning users interact with the system by typing text commands and receiving text-based output. However, some modern shells, like PowerShell, also support graphical elements.

- Scripting: Shells are scripting languages themselves. Users can write scripts, which are sequences of shell commands, to automate tasks, create custom functions, and perform complex operations.
- Environment Configuration: Shells manage the environment in which commands and programs run. This includes managing environment variables, setting up paths, and defining aliases.

- Redirection and Pipes: Shells support input and output redirection, allowing users to redirect the output of a command to a file or to another command. Pipes (|) enable users to chain multiple commands together, passing the output of one command as input to another.

## Essential Functionalities of the Simple Shell:

> Displays a prompt "#cisfun$ " and waits for user input.\
> Runs all commands of type "executable program" (ls and /bin/ls).\
> Runs the following build_in commands: **exit**, **env**, **setenv** and **unsetenv**.\
> Handles commands with arguments.\
> Handles the PATH global variable.\
> Handles The EOF (End Of File) condition.\
> Handles the Ctrl + C signal -> It doesn't exit the shell

## Files description

- **AUTHORS** -> List of contributors to this repository
- **man_1_simple_shell** -> Manual page for the simple_shell
- **shell.h** -> Header file
- **shell.c** -> main function
  - **sig_handler** -> handles the Ctrl + C signal
  - **\_EOF** -> handles the End Of File condition
- **string.c**
  - **\_putchar** -> prints a character
  - **\_puts** -> prints a string
  - **\_strlen** -> gives the length of a string
  - **\_strdup** -> copies a string in a newly allocated memory
  - **concat_all** -> concatenates 3 strings in a newly allocated memory
- **line_exec.c**
  - **splitstring** -> splits a string into an array of words
  - **execute** -> executes a command using execve
  - **realloc** -> reallocates a memory block
  - **freearv** -> frees a 2 dimensional array
- **linkpath.c**
  - **\_getenv** -> returns the value of a global variable
  - **add_node_end** -> adds a node in a singly linked list
  - **linkpath** -> creates a singly linked list for PATH directories
  - **\_which** -> finds the pathname of a command
  - **free_list** -> frees the linked list of PATH value
- **checkbuild.c**
  - **checkbuild** -> checks if a command is a build-in command
- **buildin.c**
  - **exitt** -> handles the exit buildin command
  - **\_atoi** -> converts a string into an integer
  - **env** -> prints the current environment
  - **\_setenv** -> Initialize a new global variable, or modify an existing one
  - **\_unsetenv** -> remove a global variable

---

## List of allowed functions and system calls for this project

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- \_exit (man 2 \_exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (\_\_xstat) (man 2 stat)
- lstat (\_\_lxstat) (man 2 lstat)
- fstat (\_\_fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

---

## Installation

This repository requires you to have these necessary installations to function appropriately.

- The latest version of UBUNTU
- A compiler ( GCC - GNU Compiler Collection )
- Betty Linter (also known as "Betty Style," refers to a coding style guide and linter for the C programming language.)
- **Refer To This Link To Install The Betty Linter:**
  *https://github.com/alx-tools/Betty#readme*

## Usage

- This repository and all of its contents are for learning purposes.
- Some of these files contain basic concepts on how to achieve certain results.

## Contributions

- This repository and all of its contents are works/solutions that we came up with for the tasks assigned to us as learners of the C language.
- Contributions were made by my project partner [dgamee](https://github.com/dgamee)
- With that being said please let us know if we missed something.
- We are up for suggestions..

## Contact

You can contact us via these handles.

| [Teeclever](https://github.com/teeclever) | [dgamee](https://github.com/dgamee) |
| ----------------------------------------- | ----------------------------------- |
| ----                                      | ----                                |

## Github Stats

<img height="180em" src="https://github-readme-stats.vercel.app/api?username=teeclever&show_icons=true&hide_border=true&&count_private=true&include_all_commits=true" />

<img height="180em" src="https://github-readme-stats.vercel.app/api?username=dgamee&show_icons=true&hide_border=true&&count_private=true&include_all_commits=true"/>

