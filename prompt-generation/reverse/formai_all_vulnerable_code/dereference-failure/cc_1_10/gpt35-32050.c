//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 10

int main(void)
{
    char* line = NULL;
    ssize_t line_size = 0;
    char* args[MAX_NUM_ARGUMENTS];
    char* token;
    int status, i;

    while (1)
    {
        printf("mysh> ");
        fflush(stdout);
        line_size = getline(&line, &line_size, stdin);

        if (line_size <= 1)
            continue;

        token = strtok(line, " \n");
        i = 0;

        while (token != NULL)
        {
            args[i] = token;
            i++;

            if (i >= MAX_NUM_ARGUMENTS)
            {
                printf("Too many arguments.\n");
                break;
            }

            token = strtok(NULL, " \n");
        }

        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0)
            break;

        pid_t pid = fork();

        if (pid == 0)
        {
            execvp(args[0], args);
            printf("%s: command not found\n", args[0]);
            exit(1);
        }
        else
        {
            waitpid(pid, &status, 0);
        }
    }

    free(line);
    line = NULL;

    return 0;
}