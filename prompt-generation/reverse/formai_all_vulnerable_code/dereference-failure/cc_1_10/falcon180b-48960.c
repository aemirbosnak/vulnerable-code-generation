//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Linus Torvalds Shell\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_string(input);
        int status = execute_command(args);

        if(status == 1) {
            printf("Child process terminated abnormally\n");
        }

        free(args);
    }

    return 0;
}

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, DELIM);

    while(token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if(pid < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) &&!WIFSIGNALED(status));
    }

    return 0;
}

void handle_signal(int signum) {
    switch(signum) {
        case SIGINT:
        case SIGTERM:
            printf("\nExiting Linus Torvalds Shell\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Unknown signal received\n");
    }
}