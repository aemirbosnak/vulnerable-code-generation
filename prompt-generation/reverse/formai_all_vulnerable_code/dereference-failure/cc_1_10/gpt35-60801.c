//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_SIZE 1024
#define ARGV_SIZE 64
#define ARGV_LEN 16

char cmd[INPUT_SIZE];
char *args[ARGV_SIZE][ARGV_LEN];

int parse_args(char *str, char **argv) {
    int argc = 0;
    while (*str != '\0') {
        while (*str == ' ' || *str == '\t' || *str == '\n') {
            *str++ = '\0';
        }
        *argv++ = str;

        argc++;

        while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n') {
            str++;
        }
    }

    *argv = '\0';

    return argc;
}

int parse_input(char *cmd, char ***args) {
    char *token;
    int i = 0;

    token = strtok(cmd, "|");

    while (token != NULL) {
        int argc = parse_args(token, args[i]);

        // if the command has no arguments, return an error
        if (argc == 0) {
            return -1;
        }

        i++;
        token = strtok(NULL, "|");
    }

    args[i] = '\0';

    return i;
}

int execute(char **argv) {
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("error forking");
        return -1;
    } else if (pid == 0) {
        // child process
        if (execvp(*argv, argv) < 0) {
            perror("error");
            exit(1);
        }
    } else {
        // parent process
        while (wait(&status) != pid) {
            // wait for child process to finish
        }
    }

    return status;
}

int run(char **argv) {
    int p[2];

    // code for piping commands
    if (*argv[1] != '\0') {
        pipe(p);

        if (fork() == 0) {
            // child process
            dup2(p[1], STDOUT_FILENO);
            close(p[0]);
            close(p[1]);

            // execute the first command
            execute(argv[0]);
        } else {
            // parent process
            dup2(p[0], STDIN_FILENO);
            close(p[0]);
            close(p[1]);

            // execute the second command
            execute(argv[1]);
        }
    } else {
        // no piping involved, just execute the command
        execute(argv[0]);
    }

    return 0;
}

int main() {
    printf("Unix-like Shell - Welcome to my program!\n");
    printf("Enter a command followed by any arguments.\n");
    printf("Use '|' to pipe commands.\n");
    printf("Use 'exit' to quit the shell.\n");

    while (1) {
        printf("$ ");

        if (fgets(cmd, INPUT_SIZE, stdin) == NULL) {
            break;
        }

        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            printf("Exiting the shell...\n");
            break;
        }

        int n_args = parse_input(cmd, args);

        if (n_args > 0) {
            run(args);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}