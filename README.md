## Shellplayground
We built a simple shell program in C language as students at Holberton Tulsa.
Our shell will have the same output as /bin/sh.

Though it's very simple, looking back on this program a year later, I can see 
how this project set the groundwork for my progress ever since. 


## Motivation
We are building our simple shell to deepen our understanding of how the shell reads,
interprets, and executes commands given by a user. This is one of our first projects
in our 20 month program that applies the skills that we have learned so far. 

## Build status :: Features
Our shell program is a command-line interpreter that takes user input commands
with multiple arguments and executes them. There is an ineractive mode and a
non-interactive mode. When a command is executed, a child process
is created to perform the command. Once the child process is killed, the command
line will be ready again to take in user input.

Accepts builtin commands: exit, help, and env.
Handles basic commands stored in the PATH.
Executes by forking a child process.

## Testing
To test, after cloning this repository, use the following to compile the program.
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

When you run ./hsh you will see a prompt represented by the dollar sign '$' ready
for your command. 
Or for non-interactive mode, after compiling, you can use the following to list
the items in the directory (for example).
echo "/bin/ls" | ./hsh

## Code Example
<img width="639" alt="Code Snippet to display the function that tracks processes in a Simple Shell." src="https://user-images.githubusercontent.com/67158073/151820024-07c32fa3-d72b-416b-995e-3f6d151d831c.png">

Each instance of an executing program has a unique process ID. This code snippet 
shows our executor function that validates an executable or displays the 
appropriate error. 

<img width="748" alt="Code Snippet to display details of the current working environment." src="https://user-images.githubusercontent.com/67158073/151821016-77ae4f29-c3b9-474b-a597-daa29e68b857.png">

This code snippets displays a portion of the details of the current working 
environment of our Simple Shell. The functionality of our command is the same 
as 'printenv' in bash.
