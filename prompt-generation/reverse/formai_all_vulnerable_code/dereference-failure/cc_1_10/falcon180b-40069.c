//Falcon-180B DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_ROUNDS 10

int round_counter;
int total_rounds;
int *round_counts;
int max_round_count;

void *thread_func(void *arg) {
    int thread_id = (int) arg;
    int count = 0;

    for (int i = 0; i < NUM_ROUNDS; i++) {
        printf("Thread %d starting round %d\n", thread_id, i);
        sleep(1); // simulate work

        if (count < max_round_count) {
            count++;
        } else {
            printf("Thread %d has reached max round count of %d\n", thread_id, max_round_count);
            break;
        }
    }

    printf("Thread %d finished all %d rounds\n", thread_id, count);
    return NULL;
}

int main() {
    srand(time(NULL));
    total_rounds = rand() % 10 + 1;
    round_counts = malloc(NUM_THREADS * sizeof(int));
    max_round_count = (int) (total_rounds / NUM_THREADS) + (rand() % 2);

    printf("Total rounds: %d\n", total_rounds);
    printf("Max round count: %d\n", max_round_count);

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *count = malloc(sizeof(int));
        *count = 0;
        round_counts[i] = *count;
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(round_counts);
    return 0;
}