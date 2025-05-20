//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024

char *argv[MAX_ARGS];
int argc;

void split_line(char *line) {
    char *token;
    int i = 0;
    while ((token = strtok(line, " "))!= NULL) {
        argv[i++] = token;
    }
    argv[i] = NULL;
}

int launch_shell() {
    char *shell = "/bin/sh";
    char *args[3];
    args[0] = shell;
    args[1] = NULL;
    return execvp(shell, args);
}

int launch_command(char *command) {
    pid_t pid;
    int status;

    if (command[0] == '/') {
        return system(command);
    } else {
        pid = fork();
        if (pid == 0) {
            execlp(command, command, NULL);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_LINE];
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        input[strcspn(input, "\n")] = '\0';
        split_line(input);

        if (argc == 1) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            break;
        } else if (strcmp(argv[0], "cd") == 0) {
            if (argc > 1) {
                if (chdir(argv[1])!= 0) {
                    perror("chdir");
                }
            } else {
                printf("Usage: cd [directory]\n");
            }
        } else if (strcmp(argv[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL) {
                printf("%s\n", cwd);
            } else {
                perror("getcwd");
            }
        } else {
            launch_command(input);
        }
    }

    return 0;
}