//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);
void loop(void);

int main(void)
{
    loop();
    return 0;
}

void loop(void)
{
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL)
    {
        input[strcspn(input, "\n")] = '\0';
        char **args = split_string(input);
        int status = execute_command(args);
        if (status == -1)
        {
            printf("Command not found\n");
        }
    }
}

char **split_string(char *str)
{
    int argc = 0;
    int len = strlen(str);
    char **args = malloc(sizeof(char *) * (MAX_ARGUMENTS));
    char *token = strtok(str, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS)
    {
        args[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;
    return args;
}

int execute_command(char **args)
{
    pid_t pid;
    int status;
    if (args[0] == NULL)
    {
        return -1;
    }
    if (strcmp(args[0], "exit") == 0)
    {
        return 0;
    }
    pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("fork");
        return -1;
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            return WEXITSTATUS(status);
        }
        else
        {
            return -1;
        }
    }
}