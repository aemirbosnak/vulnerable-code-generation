//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    printf("\n--------------------------------------\n");
    printf("|   Welcome to the Curious Shell!    |\n");
    printf("--------------------------------------\n");

    char command[100];
    char *args[20];

    while (1)
    {
        printf("\nCuriousShell>> ");
        fgets(command, sizeof(command), stdin);

        // remove newline character from command
        command[strlen(command) - 1] = '\0';

        // split command into arguments
        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL)
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
        {
            printf("Goodbye!\n");
            exit(0);
        }
        else if (strcmp(args[0], "curious") == 0)
        {
            printf("I'm already curious! What else do you want me to do?\n");
        }
        else
        {
            pid_t pid = fork();

            if (pid == 0)
            {
                // child process
                execvp(args[0], args);
                printf("CuriousShell: Command not found\n");
                exit(0);
            }
            else
            {
                // parent process
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}