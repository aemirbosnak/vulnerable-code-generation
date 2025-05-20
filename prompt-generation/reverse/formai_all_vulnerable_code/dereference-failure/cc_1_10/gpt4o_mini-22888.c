//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_NUM_ARGUMENTS 100
#define MAX_HISTORY 10

pthread_mutex_t lock;
char *history[MAX_HISTORY];
int history_count = 0;

void add_to_history(const char *command) {
    pthread_mutex_lock(&lock);
    if (history_count < MAX_HISTORY) {
        history[history_count] = strdup(command);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
    pthread_mutex_unlock(&lock);
}

void print_history() {
    pthread_mutex_lock(&lock);
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
    pthread_mutex_unlock(&lock);
}

void *execute_command(void *command) {
    char *cmd = (char *)command;
    char *args[MAX_NUM_ARGUMENTS];
    char *token = strtok(cmd, " ");
    int i = 0;

    while (token != NULL && i < MAX_NUM_ARGUMENTS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        pthread_exit(NULL);
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("Execution failed");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("Fork failed");
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return NULL;
}

char *read_command() {
    char *line = malloc(MAX_COMMAND_SIZE);
    if (fgets(line, MAX_COMMAND_SIZE, stdin) == NULL) {
        free(line);
        return NULL;
    }
    line[strcspn(line, "\n")] = 0; // Remove newline character
    return line;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    char *command;

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("MyShell> ");
        command = read_command();
        if (command == NULL) {
            break; // Exit on EOF
        }

        if (strlen(command) != 0) {
            add_to_history(command);
            pthread_t thread;
            pthread_create(&thread, NULL, execute_command, command);
            pthread_detach(thread);
        }
        free(command);
    }

    pthread_mutex_destroy(&lock);
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    printf("Exiting MyShell. Goodbye!\n");
    return 0;
}