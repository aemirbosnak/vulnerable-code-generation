//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "$ ";

void execute_command(char *command) {
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Parse the command into arguments
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(command, " ");
    while (arg) {
        args[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (args[0] == NULL) {
        printf("Error: command not found.\n");
    } else if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else {
        // Execute the command and print the output
        system(args[0]);
        printf("\n");
    }

    // Free the memory allocated for arguments
    free(args);
}

int main() {
    char command[MAX_CMD_LEN];

    // Display the shell prompt
    printf("%s", shell_prompt);

    // Get the user input
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    execute_command(command);

    return 0;
}