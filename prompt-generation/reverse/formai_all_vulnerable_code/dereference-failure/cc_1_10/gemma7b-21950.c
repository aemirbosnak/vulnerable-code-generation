//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char buf[1024];
    char *argv[1024];
    int argc;
    int i;
    pid_t pid;

    printf("$ ");
    fgets(buf, 1024, stdin);

    // Parse the input into arguments
    argc = 0;
    argv[0] = strdup("/bin/shell");
    i = 0;
    while (buf[i] != '\0')
    {
        if (buf[i] != ' ')
        {
            argv[argc++] = strdup(&buf[i]);
        }
        else
        {
            argv[argc++] = NULL;
        }
        i++;
    }

    // Fork the shell process
    pid = fork();

    // If the fork is successful, the parent process continues
    if (pid == 0)
    {
        execvp("/bin/shell", argv);
    }

    // Wait for the child process to complete
    wait(NULL);

    printf("Shell exited.\n");

    return 0;
}