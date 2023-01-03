/**
 * Create a child process using fork(),
 * display parent and child process id.
 * Child process will display the message
 * Hello World and the parent process should display “Hi”.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
        printf("Hello World %d\n", getpid());
    if (pid > 0)
        printf("Hi%d\n", getpid());
}