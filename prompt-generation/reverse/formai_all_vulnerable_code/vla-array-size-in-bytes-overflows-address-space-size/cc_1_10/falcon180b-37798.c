//Falcon-180B DATASET v1.0 Category: Text processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFF_SIZE 1000

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    char *text;
    int thread_id;
} thread_data;

void *process_text(void *arg) {
    thread_data *data = (thread_data *) arg;
    char *text = data->text;
    int thread_id = data->thread_id;

    // Do some text processing here
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
        }
    }

    // Print the processed text along with thread ID
    printf("Thread %d processed text: %s\n", thread_id, text);

    pthread_exit(0);
}

int main() {
    char input_text[BUFF_SIZE];
    int num_threads;

    // Get input text from user
    printf("Enter input text: ");
    fgets(input_text, BUFF_SIZE, stdin);

    // Remove newline character from input text
    input_text[strcspn(input_text, "\n")] = '\0';

    // Get number of threads from user
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    // Create an array of thread data
    thread_data data[num_threads];

    // Initialize thread data
    for (int i = 0; i < num_threads; i++) {
        data[i].text = input_text;
        data[i].thread_id = i + 1; // Thread IDs start from 1
    }

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, process_text, &data[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}