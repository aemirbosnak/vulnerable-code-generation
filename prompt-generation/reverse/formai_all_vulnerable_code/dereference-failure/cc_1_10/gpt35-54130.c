//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_NUM 64

char* get_input() {
    char* buf = (char*)malloc(MAX_COMMAND_LENGTH*sizeof(char));
    if (buf == NULL) {
        perror("Malloc failed.\n");
        exit(1);
    }
    fgets(buf, MAX_COMMAND_LENGTH, stdin);
    buf[strlen(buf)-1] = '\0'; // Replace '\n' with '\0'
    return buf;
}

char** get_args(char* input) {
    char** args = (char**)malloc(MAX_ARG_NUM*sizeof(char*));
    if (args == NULL) {
        perror("Malloc failed.\n");
        exit(1);
    }
    int i = 0;
    args[i] = strtok(input, " ");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int execute(char** args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) {
            // Error occurred
            perror("Command execution error.\n");
            exit(1);
        }
    }
    else if (pid > 0) {
        // Parent process
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (wait_pid != pid && !WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else {
        // Fork failed
        perror("Fork failed.\n");
        exit(1);
    }
    return 0;
}

int main() {
    char* input = NULL;
    char** args = NULL;

    printf("Linus-style Unix shell example program.\n\n");

    while (1) {
        printf("$ ");
        input = get_input();
        args = get_args(input);
        execute(args);
        free(input);
        free(args);
    }
    return 0;
}