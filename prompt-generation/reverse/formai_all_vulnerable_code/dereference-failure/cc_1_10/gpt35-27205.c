//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS 100
#define HISTORY_SIZE 10

char *command_history[HISTORY_SIZE];
int history_count = 0;

void display_prompt() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s> ", cwd);
}

void parse_command(char *command, char *args[]) {
    int arg_index = 0;
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[arg_index++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_index] = NULL;
}

void execute_command(char *args[]) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        printf("Error executing command.\n");
        exit(1);
    } else {
        wait(NULL);
    }
}

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        command_history[history_count++] = strdup(command);
    } else {
        free(command_history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            command_history[i - 1] = command_history[i];
        }
        command_history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void display_history() {
    if (history_count == 0) {
        printf("No command history.\n");
    } else {
        printf("Command history:\n");
        for (int i = 0; i < history_count; i++) {
            printf("%d. %s\n", i + 1, command_history[i]);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    while (1) {
        display_prompt();
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character from input
        if (strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        } else if (strcmp(command, "history") == 0) {
            display_history();
        } else if (command[0] == '!' && strlen(command) > 1) {
            int command_index = atoi(&command[1]);
            if (command_index > 0 && command_index <= history_count) {
                strcpy(command, command_history[command_index - 1]);
                printf("Executing command: %s\n", command);
                parse_command(command, args);
                execute_command(args);
            } else {
                printf("Invalid command number.\n");
            }
        } else {
            add_to_history(command);
            parse_command(command, args);
            execute_command(args);
        }
    }
    return 0;
}