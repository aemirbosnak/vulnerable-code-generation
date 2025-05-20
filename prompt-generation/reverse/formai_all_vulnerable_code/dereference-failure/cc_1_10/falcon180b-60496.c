//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_SIZE 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char *builtins[] = {
    "cd",
    "pwd",
    "exit",
    NULL
};

int is_builtin(char *command) {
    int i = 0;
    while (builtins[i]!= NULL) {
        if (strcmp(command, builtins[i]) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

int launch_shell(char **environ) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execve("/bin/sh", NULL, environ) == -1) {
            fprintf(stderr, "Error executing shell\n");
            return 1;
        }
        return 0;
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
        return WEXITSTATUS(status);
    }
}

int execute_command(char **args, char **environ) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: command not found\n");
        return 1;
    }

    if (is_builtin(args[0])) {
        switch (args[0][0]) {
            case 'c':
                if (args[1] == NULL) {
                    fprintf(stderr, "Error: missing argument for 'cd'\n");
                    return 1;
                }
                if (chdir(args[1]) == -1) {
                    fprintf(stderr, "Error changing directory\n");
                    return 1;
                }
                break;
            case 'p':
                printf("Current working directory: %s\n", getcwd(NULL, 0));
                break;
            case 'e':
                return 0;
            default:
                fprintf(stderr, "Error: unknown builtin command\n");
                return 1;
        }
    } else {
        pid = launch_shell(environ);
        if (pid == -1) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_LINE_SIZE];
    char *args[MAX_ARGUMENTS];
    char **environ = NULL;

    if (getenv("PATH") == NULL) {
        environ = malloc(sizeof(char *));
        environ[0] = strdup("/bin:/usr/bin");
    }

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_SIZE, stdin);

        int i = 0;
        args[i] = strtok(input, DELIM);
        while (args[i]!= NULL && i < MAX_ARGUMENTS - 1) {
            i++;
            args[i] = strtok(NULL, DELIM);
        }
        args[i] = NULL;

        execute_command(args, environ);
    }

    return 0;
}