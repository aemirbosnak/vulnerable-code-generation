//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define MAX_CMDS 10

typedef struct {
    char *command;
} thread_data_t;

void *execute_command(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    char *cmd = data->command;
    char *args[MAX_ARGS];

    // Parse command into arguments
    char *token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Fork a process to run the command
    pid_t pid = fork();
    if (pid == 0) {
        // We are in the child process
        if (execvp(args[0], args) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork failed");
    } else {
        // We are in the parent process
        int status;
        waitpid(pid, &status, 0);
    }
    return NULL;
}

void free_thread_data(thread_data_t *data) {
    free(data->command);
    free(data);
}

int main() {
    char input[MAX_CMD_LEN];
    pthread_t threads[MAX_CMDS];
    int thread_count = 0;

    printf("Welcome to My Multi-threaded Shell! Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        if (!fgets(input, MAX_CMD_LEN, stdin)) {
            break; // Exit on EOF
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit shell if user types "exit"
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Create thread data structure
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->command = strdup(input);

        // Create a new thread to execute the command
        if (pthread_create(&threads[thread_count], NULL, execute_command, data) != 0) {
            perror("Failed to create thread");
            free_thread_data(data);
            continue;
        }

        thread_count++;
        // Limit the number of concurrent threads
        if (thread_count >= MAX_CMDS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for the next batch of commands
        }
    }

    // Clean up any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Exiting shell. Goodbye!\n");
    return 0;
}