//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

char **commands;
int num_commands;
char input_buffer[BUFFER_SIZE];

void execute_command(char **command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) { // child process
        if (execvp(command[0], command) == -1) {
            fprintf(stderr, "Error executing command: %s\n", command[0]);
            exit(1);
        }
    } else if (pid < 0) { // error forking
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else { // parent process
        waitpid(pid, &status, 0);
    }
}

void handle_sigint(int signum) {
    printf("\nExiting...\n");
    exit(0);
}

int main() {
    commands = malloc(MAX_COMMANDS * sizeof(char *));
    num_commands = 0;

    signal(SIGINT, handle_sigint);

    while (1) {
        printf("> ");
        fgets(input_buffer, BUFFER_SIZE, stdin);

        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            if (num_commands >= MAX_COMMANDS) {
                fprintf(stderr, "Maximum number of commands reached\n");
                break;
            }

            commands[num_commands] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(commands[num_commands], token);
            num_commands++;

            token = strtok(NULL, " ");
        }
    }

    return 0;
}