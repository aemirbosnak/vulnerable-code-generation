//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = malloc(sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    argv[argc] = NULL;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        if (argv == NULL) {
            fprintf(stderr, "Error: realloc failed\n");
            exit(1);
        }
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    return argv;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();
    if (pid == 0) {
        setsid();
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error: execvp failed\n");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: fork failed\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main_loop() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = split_command(input);
    execute_command(argv);

    free(argv);

    return 0;
}

int main(int argc, char *argv[]) {
    main_loop();

    return 0;
}