//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

// Function to split a string into an array of strings
void split(char* str, char* delimiter, char*** result) {
    int count = 0;
    char* token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        char** temp = realloc(*result, sizeof(char*) * count);
        if (*result!= NULL) {
            *result = temp;
        }
        (*result)[count-1] = strdup(token);
        token = strtok(NULL, delimiter);
    }
}

// Function to execute a command and return its output
char* execute_command(char** arguments) {
    pid_t pid;
    int status;
    FILE* pipe;
    char buffer[1024];
    char* result = NULL;

    if (arguments[0] == NULL) {
        return NULL;
    }

    pipe = popen(arguments[0], "r");
    if (pipe == NULL) {
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), pipe)!= NULL) {
        result = realloc(result, strlen(result) + strlen(buffer) + 1);
        strcat(result, buffer);
    }

    pclose(pipe);
    return result;
}

// Function to handle a command
void handle_command(char* input) {
    char* delimiter = " ";
    char** arguments = NULL;
    split(input, delimiter, &arguments);
    char* result = execute_command(arguments);
    printf("%s\n", result);
    free(result);
    for (int i = 0; arguments[i]!= NULL; i++) {
        free(arguments[i]);
    }
    free(arguments);
}

// Function to print the prompt and handle user input
void shell_loop() {
    char input[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input, sizeof(input), stdin);
    handle_command(input);
}

int main() {
    shell_loop();
    return 0;
}