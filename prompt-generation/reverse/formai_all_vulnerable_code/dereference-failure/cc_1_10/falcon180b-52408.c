//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 100
#define MAX_ARGUMENTS 10
#define MAX_ARG_LENGTH 100

// Function to split a string by a delimiter
void split(char* str, char delimiter, char* result[], int max_results) {
    char* token = strtok(str, delimiter);
    int i = 0;
    while (token!= NULL && i < max_results) {
        result[i] = token;
        i++;
        token = strtok(NULL, delimiter);
    }
}

// Function to execute a command
void execute_command(char* command, char* arguments[]) {
    if (strcmp(command, "ls") == 0) {
        printf("Listing files:\n");
        for (int i = 0; i < MAX_ARGUMENTS; i++) {
            if (arguments[i]!= NULL) {
                printf("%s\n", arguments[i]);
            }
        }
    } else if (strcmp(command, "cd") == 0) {
        printf("Changing directory...\n");
    } else {
        printf("Invalid command: %s\n", command);
    }
}

// Function to read a line of input and execute a command
void read_line(char* input) {
    char* command = strtok(input, " ");
    char arguments[MAX_ARGUMENTS][MAX_ARG_LENGTH];
    int num_arguments = 0;
    split(input, " ", arguments, MAX_ARGUMENTS);
    execute_command(command, arguments);
}

// Main function
int main() {
    char input[MAX_COMMANDS];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMANDS, stdin);
        read_line(input);
    }
    return 0;
}