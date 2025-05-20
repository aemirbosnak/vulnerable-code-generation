//Falcon-180B DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command)
{
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS)
    {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

pid_t launch_shell(char **arguments)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    return pid;
}

int main(int argc, char **argv)
{
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t shell_pid;

    printf("Enter commands to execute:\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL)
    {
        arguments = split_command(input_buffer);
        shell_pid = launch_shell(arguments);

        waitpid(shell_pid, NULL, 0);
    }

    return EXIT_SUCCESS;
}