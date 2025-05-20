//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *command;
    char *args[100];
    int i, j, num_args, background;
    pid_t pid;

    printf("\nWelcome to the Super Shell!\n");
    printf("Type 'exit' to quit.\n\n");

    while (1) {
        printf("SUPER-SHELL> ");
        fflush(stdout);

        // Read input command
        command = (char*) malloc(100 * sizeof(char));
        fgets(command, 100, stdin);

        // Remove newline character
        command[strlen(command) - 1] = '\0';

        // Parse command and arguments
        i = 0; j = 0; num_args = 0; background = 0;
        while (command[i] != '\0') {
            if (command[i] == ' ') {
                args[num_args] = (char*) malloc(j * sizeof(char));
                strncpy(args[num_args], &command[i-j], j);
                args[num_args][j] = '\0';
                j = 0;
                num_args++;
            } else if (command[i] == '&') {
                background = 1;
            } else {
                j++;
            }
            i++;
        }
        args[num_args] = (char*) malloc(j * sizeof(char));
        strncpy(args[num_args], &command[i-j], j);
        args[num_args][j] = '\0';
        num_args++;

        // Execute command
        if (strcmp(args[0], "exit") == 0) {
            printf("Bye!\n");
            break;
        } else {
            pid = fork();
            if (pid == -1) {
                printf("Error: Fork failed!\n");
                exit(1);
            } else if (pid == 0) {
                execvp(args[0], args);
                printf("Error: Command not found!\n");
                exit(1);
            } else {
                if (background == 0) {
                    wait(NULL);
                }
            }
        }

        // Free allocated memory
        free(command);
        for (i = 0; i < num_args; i++) {
            free(args[i]);
        }
    }

    return 0;
}