//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS_LENGTH 10
#define MAX_PATH_LENGTH 50
#define MAX_PATHS 10

char *get_path(char *env[]);
void tokenize_command(char *command, char *args[]);
void execute_command(char *args[], char *path);

int main(int argc, char const *argv[])
{
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS_LENGTH];
    char *path, *env[] = {NULL};

    while (1)
    {
        printf("sh > ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(command, "exit\n") == 0)
            break;

        tokenize_command(command, args);
        path = get_path(env);
        execute_command(args, path);

        free(path);
    }

    return 0;
}

char *get_path(char *env[])
{
    char *path = malloc(MAX_PATH_LENGTH);
    char *path_token;
    int i = 0;

    while (env[i] != NULL)
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            path_token = strtok(env[i], "=");
            path_token = strtok(NULL, "=");
            strcpy(path, path_token);
            break;
        }

        i++;
    }

    return path;
}

void tokenize_command(char *command, char *args[])
{
    int i = 0;
    char *token;

    token = strtok(command, " ");
    while (token != NULL)
    {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    args[i] = NULL;
}

void execute_command(char *args[], char *path)
{
    pid_t pid;
    int status;
    char command[MAX_PATH_LENGTH];

    for (int i = 0; i < MAX_PATHS; i++)
    {
        if (i == 0)
            strcpy(command, args[0]);
        else
            sprintf(command, "%s/%s", path, args[0]);

        if (access(command, X_OK) == 0)
        {
            args[0] = command;

            pid = fork();
            if (pid == 0)
            {
                execv(args[0], args);
                exit(0);
            }
            else
            {
                wait(&status);
                break;
            }
        }

        if (i == MAX_PATHS - 1)
            printf("Command not found\n");
    }
}