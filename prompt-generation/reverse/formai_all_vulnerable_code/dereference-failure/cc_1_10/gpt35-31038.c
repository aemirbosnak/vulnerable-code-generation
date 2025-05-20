//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 20
#define MAX_LENGTH 80

int main() {
    char input[MAX_LENGTH];
    char *arg_array[MAX_ARGS];

    while(1) {
        printf("\nWhoa! You're in a Unix-like shell environment! Try typing a command!\n\n");
        printf("> ");
        fgets(input, MAX_LENGTH, stdin);

        int i = 0;
        char *arg = strtok(input, " \n");

        while (arg != NULL && i < MAX_ARGS - 1) {
            arg_array[i] = arg;
            arg = strtok(NULL, " \n");
            i++;
        }
        arg_array[i] = NULL;

        if (strcmp(arg_array[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else if (strcmp(arg_array[0], "surprise") == 0) {
            printf("\nSURPRISE!!!\n");
        } else {
            pid_t pid = fork();

            if (pid == -1) {
                printf("Failed to fork child process\n");
                continue;
            } else if (pid == 0) {
                execvp(arg_array[0], arg_array);
                printf("Command not found: %s\n", arg_array[0]);
                exit(0);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}