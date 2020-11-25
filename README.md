## Shellplayground
We built a simple shell program in C language as students at Holberton Tulsa.
Our shell will have the same output as /bin/sh.\


## Motivation
We are building our shell to deepen our understanding of how the shell reads,
interprets, and executes commands given by a us\
er.

## Build status :: Features
Our shell program is a command-line interpreter that takes user input commands
with multiple arguments and executes them. There is an ineractive mode and a
non-interactive mode. When a command is executed, by forking, a child process
is created to perform the command. Once the child process is killed, the command
line will be ready again to take in user input.

Accepts builtin commands: exit, help, and env.
Handles basic commands stored in the PATH.
Executes by forking a child process.

## Code Example

## Credits
