//Falcon-180B DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command)
{
    int buf_size = strlen(command) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, command);
    char **tokens = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL)
    {
        tokens[num_tokens] = strdup(token);
        num_tokens++;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    free(buf);
    return tokens;
}

pid_t fork_and_exec(char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(1);
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
    return pid;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
        return 1;
    }

    char **args = split_command(argv[1]);
    pid_t pid = fork_and_exec(args);

    waitpid(pid, NULL, 0);
    return 0;
}