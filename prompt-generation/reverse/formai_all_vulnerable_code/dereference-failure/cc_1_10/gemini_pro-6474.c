//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_ARGS 10

char* parse_line(char* line) {
    char* tokens[MAX_ARGS];
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens[0];
}

int execute_line(char* line) {
    char* tokens[MAX_ARGS];
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    if (strcmp(tokens[0], "exit") == 0) {
        return 1;
    } else {
        int pid = fork();
        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}

int main() {
    char line[1024];
    while (1) {
        printf("$ ");
        fgets(line, 1024, stdin);
        if (strlen(line) > 0) {
            if (execute_line(line)) {
                break;
            }
        }
    }
    return 0;
}