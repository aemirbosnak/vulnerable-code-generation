//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char **arguments;
    int argument_count;
} command_t;

command_t commands[MAX_COMMANDS];
int command_count = 0;

void execute_command(command_t *command) {
    pid_t pid = fork();

    if (pid == 0) {
        char *args[MAX_ARGUMENTS];
        int i = 0;
        args[i++] = command->arguments[0];

        for (int j = 1; j < command->argument_count; j++) {
            args[i++] = command->arguments[j];
        }
        args[i] = NULL;

        execvp(args[0], args);
        perror("execvp");
        exit(1);
    } else {
        wait(NULL);
    }
}

void add_command(char *command_str) {
    char *token = strtok(command_str, " ");
    commands[command_count].arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    commands[command_count].argument_count = 0;

    while (token!= NULL) {
        commands[command_count].arguments[commands[command_count].argument_count++] = token;
        token = strtok(NULL, " ");
    }

    commands[command_count].argument_count++;
    command_count++;
}

void *shell_loop(void *arg) {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        add_command(input);
    }
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, shell_loop, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}