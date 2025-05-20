//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

char **commands;
int num_commands;

void execute_command(char **command);
void handle_signal(int signal);

int main() {
    commands = (char **)malloc(MAX_COMMANDS * sizeof(char *));
    num_commands = 0;

    signal(SIGINT, handle_signal);

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        if (strlen(buffer) > 0 && buffer[0]!= '#') {
            char *command = strdup(buffer);
            commands[num_commands] = command;
            num_commands++;

            if (num_commands == MAX_COMMANDS) {
                execute_command(commands);
                num_commands = 0;
            }
        }
    }

    execute_command(commands);

    free(commands);
    return 0;
}

void execute_command(char **command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error forking\n");
        return;
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signal) {
    execute_command(commands);
}