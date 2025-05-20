//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NUM_THREADS 4
#define MAX_NUM_SEQUENCES 100

int num_threads = 0;
int num_sequences = 0;
int* fib_sequence = NULL;
int* sequence_length = NULL;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* generate_fibonacci_sequence(void* arg) {
    int thread_id = *((int*) arg);
    int sequence_length = *((int*) (arg + 1));
    int* sequence = (int*) (arg + 2);

    int fib_num = 0;
    int prev_fib = 0;
    int next_fib = 1;

    for (int i = 0; i < sequence_length; i++) {
        sequence[i] = next_fib;
        if (i >= 2) {
            next_fib = prev_fib + next_fib;
            prev_fib = next_fib - prev_fib;
        }
        if (thread_id == num_threads - 1) {
            pthread_mutex_lock(&mutex);
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    num_sequences = MAX_NUM_SEQUENCES;
    sequence_length = malloc(sizeof(int) * num_sequences);
    fib_sequence = malloc(sizeof(int) * MAX_NUM_SEQUENCES);

    int i = 0;
    int j = 0;

    for (i = 0; i < num_sequences; i++) {
        sequence_length[i] = rand() % MAX_NUM_SEQUENCES;
        fib_sequence[i] = sequence_length[i];
        while (j < sequence_length[i]) {
            fib_sequence[i] = fib_sequence[i] % MAX_NUM_SEQUENCES;
            j++;
        }
    }

    pthread_t threads[MAX_NUM_THREADS];
    int* args[MAX_NUM_THREADS];

    for (int k = 0; k < MAX_NUM_THREADS; k++) {
        args[k] = malloc(sizeof(int) * 3);
        args[k][0] = k;
        args[k][1] = sequence_length[i];
        args[k][2] = &fib_sequence[i];

        pthread_create(&threads[k], NULL, generate_fibonacci_sequence, args[k]);
    }

    for (int l = 0; l < MAX_NUM_THREADS; l++) {
        pthread_join(threads[l], NULL);
    }

    free(sequence_length);
    free(fib_sequence);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}