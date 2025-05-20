//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 1024

char **split_line(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(line, " \t\r\n");
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, " \t\r\n");
    }
    argv[argc] = NULL;
    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;
    if (argv[0] == NULL) {
        return;
    }
    if (strcmp(argv[0], "exit") == 0) {
        exit(0);
    }
    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL) {
            fprintf(stderr, "Usage: cd [directory]\n");
        } else {
            if (chdir(argv[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();
        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[MAX_LINE_LENGTH];
    char **argv;
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        argv = split_line(input);
        execute_command(argv);
    }
}

int main(void) {
    loop();
    return 0;
}