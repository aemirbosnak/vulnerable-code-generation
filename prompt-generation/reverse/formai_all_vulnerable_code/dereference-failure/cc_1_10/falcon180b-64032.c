//Falcon-180B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define DELIM " \t\r\n\a"

int main(int argc, char *argv[])
{
    char *command = NULL;
    char **arguments = NULL;
    int num_arguments = 0;
    int status;
    pid_t child_pid;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s command [arguments]\n", argv[0]);
        return 1;
    }

    command = strdup(argv[1]);
    if (command == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        return 1;
    }

    arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    if (arguments == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        free(command);
        return 1;
    }

    num_arguments = parse_arguments(command, arguments);

    if (num_arguments < 0)
    {
        fprintf(stderr, "Error: Invalid command.\n");
        free(command);
        free(arguments);
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1)
    {
        fprintf(stderr, "Error: Unable to fork.\n");
        free(command);
        free(arguments);
        return 1;
    }

    if (child_pid == 0)
    {
        execvp(command, arguments);
        fprintf(stderr, "Error: Unable to execute command.\n");
        exit(1);
    }

    waitpid(child_pid, &status, 0);

    free(command);
    free(arguments);

    return 0;
}

int parse_arguments(char *command, char **arguments)
{
    char *token = NULL;
    int num_arguments = 0;

    token = strtok(command, DELIM);

    while (token!= NULL)
    {
        arguments[num_arguments] = token;
        num_arguments++;

        if (num_arguments >= MAX_ARGUMENTS)
        {
            fprintf(stderr, "Error: Too many arguments.\n");
            return -1;
        }

        token = strtok(NULL, DELIM);
    }

    arguments[num_arguments] = NULL;

    return num_arguments;
}