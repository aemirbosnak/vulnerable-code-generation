//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define NUM_THREADS 3

char *buffer;
sem_t sem;

void *read_lines(void *arg) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open file");
        pthread_exit(NULL);
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        sem_post(&sem);
        usleep(100000); // Simulate processing delay
    }

    fclose(file);
    return NULL;
}

void *process_lines(void *arg) {
    while (1) {
        sem_wait(&sem);
        
        if (strlen(buffer) == 0) {
            pthread_exit(NULL); // Exit if no more lines to process
        }

        // Process the line (simple example: convert to uppercase)
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }

        printf("Processed: %s", buffer);
        memset(buffer, 0, MAX_LINE_LENGTH); // Clear the buffer
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    buffer = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));

    sem_init(&sem, 0, 0); // Initialize semaphore

    // Create the line reader thread
    pthread_create(&threads[0], NULL, read_lines, NULL);

    // Create processing threads
    for (int i = 1; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, process_lines, NULL);
    }

    // Wait for the reader thread to finish
    pthread_join(threads[0], NULL);

    // Signal the processing threads to finish
    for (int i = 1; i < NUM_THREADS; i++) {
        sem_post(&sem); // Ensure they exit
    }

    // Wait for processing threads to complete
    for (int i = 1; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    sem_destroy(&sem);
    free(buffer);

    return 0;
}