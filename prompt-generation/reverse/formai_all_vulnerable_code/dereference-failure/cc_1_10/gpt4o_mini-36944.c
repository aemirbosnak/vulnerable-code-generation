//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_COMMANDS 100
#define MAX_HISTORY 10

char *history[MAX_HISTORY];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_NUM_COMMANDS];
    
    while (1) {
        printf("myshell> ");
        fflush(stdout);
        
        if (!fgets(command, sizeof(command), stdin)) {
            break; // Exit on EOF
        }
        
        command[strcspn(command, "\n")] = 0; // Remove the newline character
        
        if (strcmp(command, "exit") == 0) {
            break; // Exit shell
        }
        
        if (strcmp(command, "history") == 0) {
            print_history();
            continue;
        }
        
        add_to_history(command);
        
        pid_t pid = fork();
        
        if (pid == 0) { // Child process
            int i = 0;
            args[i] = strtok(command, " ");
            while (args[i] != NULL) {
                i++;
                args[i] = strtok(NULL, " ");
            }
            execvp(args[0], args);
            perror("execvp failed"); // execvp only returns on failure
            exit(1);
        } else if (pid > 0) { // Parent process
            wait(NULL); // Wait for child to finish
        } else {
            perror("fork failed");
        }
    }
    
    free_history();
    return 0;
}