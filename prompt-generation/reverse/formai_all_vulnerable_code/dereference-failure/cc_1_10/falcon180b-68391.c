//Falcon-180B DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command)
{
    int argc = 0, buf_size = MAX_COMMAND_LENGTH;
    char **argv = malloc(sizeof(char *) * (argc + 1));
    if (argv == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for argv\n");
        exit(1);
    }

    char *buf = malloc(buf_size);
    if (buf == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for buf\n");
        exit(1);
    }

    char *token = strtok(command, DELIM);
    while (token!= NULL)
    {
        if (argc == buf_size)
        {
            buf_size += MAX_COMMAND_LENGTH;
            argv = realloc(argv, sizeof(char *) * (argc + 1));
        }

        argv[argc++] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    free(buf);

    return argv;
}

pid_t launch_shell(char **argv)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Failed to fork\n");
        exit(1);
    }

    if (pid == 0)
    {
        if (execvp(argv[0], argv) == -1)
        {
            fprintf(stderr, "Failed to execute %s: %s\n", argv[0], strerror(errno));
            exit(1);
        }
    }

    return pid;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        exit(1);
    }

    char **split_argv = split_command(argv[1]);
    pid_t shell_pid = launch_shell(split_argv);

    int status;
    waitpid(shell_pid, &status, 0);

    for (int i = 0; split_argv[i]!= NULL; i++)
    {
        free(split_argv[i]);
    }
    free(split_argv);

    return WEXITSTATUS(status);
}