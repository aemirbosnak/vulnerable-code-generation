//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        fprintf(stdout, "Interrupted by user.\n");
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    int background = 0;
    int exit_status;

    signal(SIGINT, signal_handler);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);

        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "bg") == 0) {
            background = 1;
        } else if (strcmp(argv[0], "fg") == 0) {
            background = 0;
        } else if (strcmp(argv[0], "jobs") == 0) {
            system("jobs");
        } else {
            execute_command(argv);
        }
    }

    return 0;
}