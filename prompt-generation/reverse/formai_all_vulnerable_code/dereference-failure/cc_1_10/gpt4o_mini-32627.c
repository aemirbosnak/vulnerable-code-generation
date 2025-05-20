//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_HISTORY 100

void print_welcome() {
    printf("--------------------------------------------------\n");
    printf("Welcome to HolmesShell!\n");
    printf("I shall deduce your commands with great precision.\n");
    printf("Type 'exit' to depart from my company.\n");
    printf("--------------------------------------------------\n");
}

void execute_command(char* cmd) {
    char* args[MAX_CMD_LEN / 2 + 1]; // Command line arguments
    pid_t pid, wpid;
    int status;

    // Tokenize input command into arguments
    char* token = strtok(cmd, " \n");
    int i = 0;
    while (token != NULL && i < (MAX_CMD_LEN / 2)) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // Null terminate the arguments array

    // If the user wants to perform an inquest into the world of programs
    if (strcmp(args[0], "exit") == 0) {
        printf("The game is afoot! Until next time.\n");
        exit(0);
    }

    pid = fork(); // Create a child process
    if (pid == 0) {
        // In the child process
        if (execvp(args[0], args) == -1) {
            perror("HolmesShell: Command not found");
        }
        exit(EXIT_FAILURE); // Exit the child process
    } else if (pid < 0) {
        perror("HolmesShell: Fork failed");
    } else {
        // In the parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED); // Wait for the child process
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char command[MAX_CMD_LEN];
    char* history[MAX_HISTORY];
    int history_count = 0;

    print_welcome();

    while (1) {
        printf("HolmesShell> ");
        // Get command from user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // Exit on EOF
        }

        // Store the command in history
        if (history_count < MAX_HISTORY) {
            history[history_count] = strdup(command);
            history_count++;
        } else {
            free(history[0]);
            for (int j = 1; j < MAX_HISTORY; j++) {
                history[j - 1] = history[j];
            }
            history[MAX_HISTORY - 1] = strdup(command);
        }

        execute_command(command);

        // Print command history
        printf("Command History:\n");
        for (int j = 0; j < history_count; j++) {
            printf("%d: %s", j + 1, history[j]);
        }
    }

    // Free command history memory
    for (int j = 0; j < history_count; j++) {
        free(history[j]);
    }

    return 0;
}