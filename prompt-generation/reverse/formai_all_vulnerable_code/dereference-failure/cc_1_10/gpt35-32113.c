//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 100
#define THRESHOLD 0.7

// A struct to hold thread arguments.
struct thread_args {
    char buffer[BUFFER_SIZE];
    double spam_score;
};

// Function to calculate the spam score of a buffer.
void calculate_spam_score(char *buffer, double *spam_score) {
    // Dummy implementation, just counting the number of 'c's in the buffer.
    int num_cs = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == 'c') {
            num_cs++;
        }
    }
    *spam_score = (double)num_cs / strlen(buffer);
}

// Function to spawn a new thread, calculate the spam score and print result.
void *process_buffer(void *args) {
    struct thread_args *t_args = (struct thread_args *)args;

    double spam_score;
    calculate_spam_score(t_args->buffer, &spam_score);

    if (spam_score > THRESHOLD) {
        printf("SPAM DETECTED: %s (score: %f)\n", t_args->buffer, spam_score);
    } else {
        printf("Not spam: %s (score: %f)\n", t_args->buffer, spam_score);
    }
    // Free memory allocated for the thread arguments.
    free(t_args);
}

int main() {
    pthread_t tid;

    while (1) {
        // Read input from command line.
        char input[BUFFER_SIZE];
        fgets(input, BUFFER_SIZE, stdin);

        // Allocate memory for the thread arguments.
        struct thread_args *t_args = malloc(sizeof(struct thread_args));
        strncpy(t_args->buffer, input, BUFFER_SIZE);

        // Spawn thread to process buffer.
        pthread_create(&tid, NULL, process_buffer, (void *)t_args);
    }
    return 0;
}