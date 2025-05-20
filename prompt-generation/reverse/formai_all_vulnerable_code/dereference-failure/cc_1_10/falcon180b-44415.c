//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
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

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

char *read_line(int fd) {
    char *line = NULL;
    ssize_t bufsize = 0;
    getline(&line, &bufsize, fd);
    return line;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';
        args = split_command(input);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, WUNTRACED);
        }
    }

    return 0;
}