//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 100

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Shell error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Shell error");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void change_directory(char *path) {
    if (path == NULL || strcmp(path, "") == 0) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }
    if (chdir(path) != 0) {
        perror("cd error");
    }
}

char **parse_input(char *input) {
    char **args = malloc(MAX_ARG_SIZE * sizeof(char *));
    char *token = strtok(input, " \n");
    int position = 0;

    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " \n");
    }
    args[position] = NULL; // NULL-terminate the array
    return args;
}

int main() {
    char input[MAX_CMD_SIZE];
    
    while (1) {
        printf("simple-shell> ");
        if (!fgets(input, sizeof(input), stdin)) {
            perror("Shell input error");
            continue;
        }
        
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        char **args = parse_input(input);
        
        if (args[0] == NULL) {
            free(args);
            continue; // No command entered
        }

        if (strcmp(args[0], "cd") == 0) {
            change_directory(args[1]);
        } else {
            execute_command(args);
        }
        
        free(args);
    }
    
    return 0;
}