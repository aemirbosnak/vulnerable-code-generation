//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define maximum length of commands
#define MAX_COMMAND_LENGTH 1024

// Function to read user input command
char* read_command() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';
    char* command = strdup(input);
    return command;
}

// Function to execute user command
void execute_command(char* command) {
    char* cmd = strtok(command, " ");
    char* args[MAX_COMMAND_LENGTH/2];
    int i = 0;
    while (cmd != NULL) {
        args[i] = cmd;
        cmd = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    if (strcmp(args[0], "ls") == 0) {
        execvp(args[0], args);
    } else if (strcmp(args[0], "mkdir") == 0) {
        mkdir(args[1], 0777);
    } else if (strcmp(args[0], "rm") == 0) {
        remove(args[1]);
    } else {
        printf("Command not found: %s\n", args[0]);
    }
}

// Main function
int main() {
    char* command;
    do {
        command = read_command();
        execute_command(command);
        free(command);
    } while (1);
    return 0;
}