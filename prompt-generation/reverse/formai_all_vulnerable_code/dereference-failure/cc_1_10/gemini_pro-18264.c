//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 1024

// Mutex to protect the shared buffer
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when the buffer is full
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;

// Condition variable to signal when the buffer is empty
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

// Buffer to store the words
char buffer[BUFFER_SIZE];

// Index of the first unread character in the buffer
int buffer_head = 0;

// Index of the first unwritten character in the buffer
int buffer_tail = 0;

// Number of words in the buffer
int buffer_count = 0;

// Thread function to read words from a file
void *reader(void *arg) {
    // Get the file name
    char *file_name = (char *)arg;

    // Open the file
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read words from the file
    while (1) {
        // Lock the buffer
        pthread_mutex_lock(&buffer_mutex);

        // Wait until the buffer is not full
        while (buffer_count == BUFFER_SIZE) {
            pthread_cond_wait(&buffer_full, &buffer_mutex);
        }

        // Read a word from the file
        char word[100];
        int n = fscanf(file, "%s", word);
        if (n == EOF) {
            break;
        }

        // Copy the word to the buffer
        strcpy(&buffer[buffer_tail], word);
        buffer_tail = (buffer_tail + strlen(word) + 1) % BUFFER_SIZE;
        buffer_count++;

        // Signal that the buffer is not empty
        pthread_cond_signal(&buffer_empty);

        // Unlock the buffer
        pthread_mutex_unlock(&buffer_mutex);
    }

    // Close the file
    fclose(file);

    return NULL;
}

// Thread function to count the words in the buffer
void *counter(void *arg) {
    // Get the number of threads
    int num_threads = (int)arg;

    // Count the words in the buffer
    while (1) {
        // Lock the buffer
        pthread_mutex_lock(&buffer_mutex);

        // Wait until the buffer is not empty
        while (buffer_count == 0) {
            pthread_cond_wait(&buffer_empty, &buffer_mutex);
        }

        // Get the next word from the buffer
        char word[100];
        strcpy(word, &buffer[buffer_head]);
        buffer_head = (buffer_head + strlen(word) + 1) % BUFFER_SIZE;
        buffer_count--;

        // Count the number of occurrences of the word
        int count = 0;
        for (int i = 0; i < buffer_tail; i++) {
            if (strcmp(&buffer[i], word) == 0) {
                count++;
            }
        }

        // Print the word and its count
        printf("%s: %d\n", word, count);

        // Signal that the buffer is not full
        pthread_cond_signal(&buffer_full);

        // Unlock the buffer
        pthread_mutex_unlock(&buffer_mutex);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file_name> <num_threads>\n", argv[0]);
        exit(1);
    }

    // Get the file name
    char *file_name = argv[1];

    // Get the number of threads
    int num_threads = atoi(argv[2]);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        fprintf(stderr, "Invalid number of threads: %d\n", num_threads);
        exit(1);
    }

    // Create the reader threads
    pthread_t reader_threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&reader_threads[i], NULL, reader, file_name) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Create the counter threads
    pthread_t counter_threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&counter_threads[i], NULL, counter, (void *)num_threads) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Join the reader threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(reader_threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Join the counter threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(counter_threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Destroy the mutex and condition variables
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&buffer_full);
    pthread_cond_destroy(&buffer_empty);

    return 0;
}