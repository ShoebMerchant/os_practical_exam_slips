/**
 * Creating a child process using the command exec().
 * Note down process ids of the parent and the child processes,
 * check whether the control is given back to the
 * parent after the child process terminates.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
        printf("\nHello I am child process");
        printf("\nMy pid is %d", getpid());
    }
    else
    {
        wait(NULL);
        printf("\nHello I am parent process");
        printf("\nMy pid is %d", getpid());
        printf("\nChild Complete");
    }
}