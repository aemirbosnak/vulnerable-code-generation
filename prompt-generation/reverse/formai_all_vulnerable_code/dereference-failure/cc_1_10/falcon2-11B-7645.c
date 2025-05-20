//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);
    if (n < 0)
    {
        printf("Factorial of a negative number is undefined.\n");
        exit(1);
    }

    int total = 1;
    int factor = 1;
    pid_t pid;
    int status;

    for (int i = 2; i <= n; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            int count = 0;
            for (int j = i; j <= n; j++)
            {
                count++;
                factor *= j;
            }
            printf("%d: %d\n", getpid(), factor);
            exit(0);
        }

        wait(&status);
        total += factor;
        factor = 1;
    }

    printf("%d: %d\n", getpid(), total);
    exit(0);
}