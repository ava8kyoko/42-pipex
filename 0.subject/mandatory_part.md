# Mandatory part

|                                  |                                                           |
| -------------------------------- | --------------------------------------------------------- |
| **Program name**                 | pipex
| **Files**                        | Makefile, \*.h, \*.c 
| **Makefile**                     | NAME, all, clean, fclean, re
| **Arguments**                    | file1 cmd1 cmd2 file2
| **External fonctions autorised** | <ul><li>open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid </li> <li>ft_printf or any equivalent YOU coded</li></ul>
| **Libft autorised**              | Yes
| **Description**                  | This project is about handling pipes


## Makefile

| Mandatory                        |                                                        |
| -------------------------------- | ------------------------------------------------------ |
| **NAME**                         | Path of every source files
| **all**                          | Compile \*.c, i.e. every source code files
| **clean**                        | Delete every \*.o, i.e. every object files 
| **fclean**                       | Same as clean, but delete a.out, i.e. executable, too
| **re**                           | fclean + all


| My own rules                     |                                                        |
| -------------------------------- | ------------------------------------------------------ |
| **leaks**                        |	
| **test**                         |	
|                                  |


## Arguments

It must take 4 arguments:
- file1 and file2 are file names.
- cmd1 and cmd2 are shell commands with their parameters.

#### What is an argument ?

Arguments are parameters/arguments supplied to the program when it is invoked. They are used to control program from outside instead of hard coding those values inside the code. They are passed to main() function. 

- `int main(int argc, char **argv) { /* ... */ }`
- argc (ARGument Count) is int and stores number of argument + the name (name = 1, arguments >= 2). Should be non negative.
- argv (ARGument Vector) is array of character pointers listing all the arguments.
- If argc > 0, the array elements from argv[0] to argv[argc-1] (because ) will contain pointers to strings.
- argv[0] holds the name of the program
- argv[1] points to the first command line argument and argv[argc-1] points last argument.
- argv[argc] is a NULL pointer.

Note : You pass all the command line arguments separated by a space, but if argument itself has a space then you can pass such arguments by putting them inside double quotes `" "` or single quotes `' '`.

#### What is a shell command ?

A shell is a computer program that presents a command line interface which allows you to control your computer using commands entered with a keyboard instead of controlling graphical user interfaces (GUIs) with a mouse/keyboard/touchscreen combination.

### Programme execution
`./pipex file1 cmd1 cmd2 file2` <br>
<br>
Votre programme doit se comporter exactement comme la commande shell suivante : <br>
`$> < file1 cmd1 | cmd2 > file2`

#### Examples
`$> ./pipex infile "ls -l" "wc -l" outfile` <br>
Devrait être identique à < infile ls -l | wc -l > outfile <br>
<br>
`$> ./pipex infile "grep a1" "wc -w" outfile` <br>
Devrait être identique à < infile grep a1 | wc -w > outfile

## External fonctions autorised 

| Fonctions | Descriptions                   | Libraries                      | Prototypes                                | Link |
| --------- | ------------------------------ | ------------------------------ | ----------------------------------------- | ---- |
| open      | open and possibly create a file | fcntl.h |  | [x](https://man7.org/linux/man-pages/man2/open.2.html)
| close     | close a file descriptor | unistd.h | int close(int fd); | [x](https://man7.org/linux/man-pages/man2/close.2.html)
| read      | read from a file descriptor | unistd.h | ssize_t read(int fd, void \*buf, size_t count); | [x](https://man7.org/linux/man-pages/man2/read.2.html)
| write     | write to a file descriptor | unistd.h | ssize_t write(int fd, const void \*buf, size_t count); | [x](https://man7.org/linux/man-pages/man2/write.2.html)
| malloc    | allocate dynamic memory | stdlib.h | void \*malloc(size_t size); | [x](https://man7.org/linux/man-pages/man3/malloc.3.html)
| free      | free dynamic memory | stdlib.h | void free(void \*ptr); | [x](https://man7.org/linux/man-pages/man3/malloc.3.html)
| perror    | print a system error message | stdio.h | void perror(const char \*s); | [x](https://man7.org/linux/man-pages/man3/perror.3.html)
| strerror  | return string describing error number | string.h || [x](https://man7.org/linux/man-pages/man3/strerror.3.html)
| access    | check user's permissions for a file |  |  | [x](https://man7.org/linux/man-pages/man2/access.2.html)
| dup       | duplicate a file descriptor | unistd.h | int dup(int oldfd); | [x](https://man7.org/linux/man-pages/man2/dup.2.html)
| dup2      | duplicate a file descriptor | unistd.h | int dup2(int oldfd, int newfd); | [x](https://man7.org/linux/man-pages/man2/dup.2.html)
| execve    | execute program | unistd.h | int execve(const char *pathname, char *const argv[], char *const envp[]); | [x](https://man7.org/linux/man-pages/man2/execve.2.html)
| exit      | cause normal process termination | stdlib.h | noreturn void exit(int status); | [x](https://man7.org/linux/man-pages/man3/exit.3.html) / https://en.cppreference.com/w/c/program/EXIT_status
| fork      | create a child process | unistd.h | pid_t fork(void); | [x](https://man7.org/linux/man-pages/man2/fork.2.html)
| pipe      | create pipe | unistd.h | int pipe(int pipefd[2]); | [x](https://man7.org/linux/man-pages/man2/pipe.2.html)
| unlink    | delete a name and possibly the file it refers to | unistd.h | int unlink(const char *pathname); | [x](https://man7.org/linux/man-pages/man2/unlink.2.html)
| wait      | wait for process to change state | sys/wait.h | pid_t wait(int *wstatus); | [x](https://man7.org/linux/man-pages/man2/wait.2.html)
| waitpid   | wait for process to change state | sys/wait.h | pid_t waitpid(pid_t pid, int *wstatus, int options); | [x](https://man7.org/linux/man-pages/man2/wait.2.html)
| ft_printf | Basic printf |  |  | [x](https://github.com/ava8kyoko/42-ft_printf/tree/master/NOBONUS_printf)

## Description

### Notes taken while reading [:link:](https://github.com/ava8kyoko/42-Pipex/blob/master/subject/notes_references.md)


## References

- [Command line arguments](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
- [Introduction to command shell](https://datacarpentry.org/shell-genomics/01-introduction/)
