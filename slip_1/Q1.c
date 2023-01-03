/**
 * Write a program that demonstrates
 * the use of nice() system call.
 * After a child process is started using fork(),
 * assign higher priority to the
 * child using nice() system call.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid, n;
    printf("Press DEL to stop process \n");
    pid = fork();
    for (;;)
    {
        if (pid == 0)
        {
            n = nice(-5);
            printf("child gets higher priority %d\n", n);
            sleep(3);
        }
        else
        {
            n = nice(4);
            printf("Parent gets lower CPU priority %d\n", n);
            sleep(3);
        }
    }
    return 0;
}