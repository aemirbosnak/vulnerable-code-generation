//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 256

char current_directory[MAX_INPUT_LENGTH];

void run_command(char command[MAX_INPUT_LENGTH]) {
    char* tokens[MAX_INPUT_LENGTH];
    char* token_buffer;
    int i = 0;

    token_buffer = strtok(command, " ");
    while (token_buffer != NULL) {
        tokens[i] = token_buffer;
        i++;
        token_buffer = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            chdir(getenv("HOME"));
        } else {
            chdir(tokens[1]);
        }
    } else {
        pid_t pid = fork();

        if (pid == 0) {
            execvp(tokens[0], tokens);
        } else {
            wait(NULL);
        }
    }
}

int main() {
    while (1) {
        getcwd(current_directory, MAX_INPUT_LENGTH);
        printf("%s$ ", current_directory);

        char command[MAX_INPUT_LENGTH];
        fgets(command, MAX_INPUT_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;
        run_command(command);
    }
    
    return(0);
}