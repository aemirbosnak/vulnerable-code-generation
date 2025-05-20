//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "myshell$ ";

void do_exit(int status) {
    exit(status);
}

void execute_command(char *command) {
    char **args = NULL;
    char *arg = NULL;
    int i = 0;

    // Tokenize the command
    args = malloc(MAX_CMD_LEN * sizeof(char *));
    arg = strtok(command, " ");
    while (arg) {
        args[i++] = strdup(arg);
        arg = strtok(NULL, " ");
    }

    // Execute the command
    if (args[0] == NULL) {
        printf("Error: command not found.\n");
    } else if (fork() == 0) {
        execvp(args[0], args);
    } else {
        wait(NULL);
    }

    // Free the memory
    free(args);
}

int main() {
    char command[MAX_CMD_LEN];

    // Print the shell prompt
    printf("%s", shell_prompt);

    // Get the command
    fgets(command, MAX_CMD_LEN, stdin);

    // Execute the command
    execute_command(command);

    return 0;
}