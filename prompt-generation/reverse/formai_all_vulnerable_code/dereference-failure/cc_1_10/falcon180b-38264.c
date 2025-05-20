//Falcon-180B DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

char *argv[MAX_ARGS];
int num_args;

void execute_command(char *command) {
    int pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        exit(1);
    } else if (pid == 0) {
        if (execlp(command, command, NULL) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
}

void parse_command(char *command) {
    char *token = strtok(command, " ");
    int i = 0;

    while (token!= NULL) {
        argv[i] = token;
        i++;
        if (i >= MAX_ARGS) {
            break;
        }
        token = strtok(NULL, " ");
    }

    num_args = i;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        parse_command(input);

        if (strcmp(argv[0], "exit") == 0) {
            break;
        } else {
            execute_command(argv[0]);
        }
    }

    return 0;
}