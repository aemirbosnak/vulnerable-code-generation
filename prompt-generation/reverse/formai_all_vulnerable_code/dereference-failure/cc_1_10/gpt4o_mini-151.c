//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define MAX_HISTORY 20

char *history[MAX_HISTORY];
int history_count = 0;

void add_to_history(char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(cmd);
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

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }
    
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        }
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {  // Child process
        execvp(args[0], args);
        perror("exec");
        exit(EXIT_FAILURE); // Exit if exec fails
    } else if (pid < 0) { // Fork failed
        perror("fork");
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to complete
    }
    return 1;
}

void parse_input(char *input, char **args) {
    while (*input) {
        while (*input == ' ') {
            input++;
        }
        if (*input) {
            *args++ = input;
        }
        while (*input && *input != ' ') {
            input++;
        }
        if (*input) {
            *input++ = '\0';
        }
    }
    *args = NULL;
}

int main() {
    char input[MAX_CMD_LEN];
    char *args[MAX_ARGS];

    while (1) {
        printf("myshell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Break on EOF or error
        }
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline

        add_to_history(input);
        
        parse_input(input, args);
        if (execute_command(args) == 0) {
            break; // Exit command
        }
    }

    printf("History of commands:\n");
    print_history();
    free_history();
    
    return 0;
}