//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

char prompt[] = "$ ";

void parse_cmd(char *cmd) {
    char **argv = NULL;
    char *arg = NULL;
    int argc = 0;

    // Tokenize the command
    arg = strtok(cmd, " ");
    while (arg) {
        argv = realloc(argv, (argc + 1) * sizeof(char *));
        argv[argc++] = arg;
        arg = strtok(NULL, " ");
    }

    // Set the null terminator
    argv[argc] = NULL;

    // Execute the command
    execvp(argv[0], argv);
}

int main() {
    char cmd[MAX_CMD_LEN];

    // Print the prompt
    printf("%s", prompt);

    // Get the command
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Parse the command
    parse_cmd(cmd);

    // Wait for the child process to complete
    wait(NULL);

    // Print a new prompt
    printf("%s", prompt);

    return 0;
}