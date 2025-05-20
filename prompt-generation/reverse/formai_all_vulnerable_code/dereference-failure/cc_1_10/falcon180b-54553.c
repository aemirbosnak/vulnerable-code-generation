//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_THREADS 4
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    bool is_running;
    pthread_t thread_id;
} ThreadData;

void *run_command(void *data) {
    ThreadData *thread_data = (ThreadData *)data;

    if (system(thread_data->command)!= 0) {
        fprintf(stderr, "Error running command: %s\n", thread_data->command);
    }

    thread_data->is_running = false;
    return NULL;
}

int main() {
    char **commands = NULL;
    int num_commands = 0;

    printf("Enter commands to run (enter 'done' when finished):\n");
    while (true) {
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        if (num_commands >= MAX_COMMAND_LENGTH) {
            fprintf(stderr, "Maximum number of commands reached.\n");
            exit(1);
        }

        commands[num_commands] = strdup(input);
        num_commands++;
    }

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].is_running = true;
        pthread_create(&threads[i], NULL, run_command, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_commands; i++) {
        free(commands[i]);
    }
    free(commands);

    return 0;
}