//Falcon-180B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 80
#define MAX_ARGUMENTS 10
#define DELIM " "

// Function to execute a command
void execute_command(char* command) {
    char* token = strtok(command, DELIM);
    int argc = 0;
    char** argv = malloc(MAX_ARGUMENTS * sizeof(char*));

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }

    if (strcmp(argv[0], "mkdir") == 0) {
        mkdir(argv[1], 0777);
    } else if (strcmp(argv[0], "touch") == 0) {
        FILE* file = fopen(argv[1], "w");
        if (file!= NULL) {
            fclose(file);
        }
    } else if (strcmp(argv[0], "rm") == 0) {
        remove(argv[1]);
    } else if (strcmp(argv[0], "cd") == 0) {
        chdir(argv[1]);
    } else {
        printf("Invalid command.\n");
    }

    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

// Function to get user input
char* get_input(char* prompt) {
    char input[MAX_COMMAND_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    return strdup(input);
}

int main() {
    char* input;
    char* command;

    while (1) {
        printf("> ");
        input = get_input("");
        command = strtok(input, DELIM);

        if (strcmp(command, "exit") == 0) {
            break;
        } else {
            execute_command(input);
        }
    }

    return 0;
}