//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARGS 16
#define MAX_THREADS 16

typedef struct {
    char *command;
    char *args[MAX_ARGS];
    int num_args;
} command_t;

typedef struct {
    pthread_t tid;
    command_t *command;
    int status;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(data->command->command, data->command->args);
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        waitpid(pid, &data->status, 0);
    } else {
        perror("fork");
        data->status = 1;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    // Initialize variables
    char command_line[MAX_COMMAND_LEN];
    command_t commands[MAX_THREADS];
    thread_data_t threads[MAX_THREADS];
    int num_commands = 0;
    int num_threads = 0;

    // Main loop
    while (1) {
        // Get the command line
        printf("$> ");
        fgets(command_line, MAX_COMMAND_LEN, stdin);

        // Parse the command line
        char *args[MAX_ARGS];
        int num_args = 0;
        char *token = strtok(command_line, " \n");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " \n");
        }

        // Check for special commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "jobs") == 0) {
            // Print the status of all threads
            for (int i = 0; i < num_threads; i++) {
                printf("[%d] %s (%d)\n", i, threads[i].command->command, threads[i].status);
            }
            continue;
        }

        // Create a new command struct
        commands[num_commands].command = args[0];
        for (int i = 0; i < num_args; i++) {
            commands[num_commands].args[i] = args[i];
        }
        commands[num_commands].num_args = num_args;

        // Create a new thread
        threads[num_threads].command = &commands[num_commands];
        pthread_create(&threads[num_threads].tid, NULL, thread_func, (void *)&threads[num_threads]);
        num_threads++;
        num_commands++;

        // Wait for the threads to finish
        for (int i = 0; i < num_threads; i++) {
            pthread_join(threads[i].tid, NULL);
        }
        num_threads = 0;
    }

    return 0;
}