//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define HISTORY_SIZE 20

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]); // Remove oldest
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void clean_up_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;
    
    if ((pid = fork()) == -1) {
        perror("fork");
    } else if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec");
        }
        exit(EXIT_FAILURE);
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_input(char *input, char **args) {
    char *token = strtok(input, " \n");
    int index = 0;
    
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL; // Null terminate the argument list
}

int main() {
    char *input = (char *)malloc(MAX_INPUT_SIZE);
    char **args = (char **)malloc(MAX_ARG_SIZE * sizeof(char *));
    char command_prefix[] = "shell$ ";
    int should_run = 1;

    while (should_run) {
        printf("%s", command_prefix);
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            perror("fgets failed");
            continue;
        }

        add_to_history(input);

        if (strcmp(input, "exit\n") == 0) {
            should_run = 0;
        } else if (strcmp(input, "history\n") == 0) {
            print_history();
        } else {
            parse_input(input, args);
            execute_command(args);
        }
    }

    clean_up_history();
    free(input);
    free(args);

    return 0;
}