//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define NUM_ROUNDS 5
#define NUM_CARDS 8
#define NUM_PAIRS 4
#define MAX_DELAY 100

typedef struct {
    int id;
    int round;
} thread_data_t;

typedef struct {
    int round;
    int card1;
    int card2;
} card_data_t;

int cards[NUM_CARDS] = {1, 2, 3, 4, 5, 6, 7, 8};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

void* thread_func(void* arg) {
    thread_data_t* data = arg;
    int id = data->id;
    int round = data->round;

    printf("Thread %d starting round %d\n", id, round);

    pthread_mutex_lock(&mutex);
    int card1 = cards[round * 2];
    int card2 = cards[round * 2 + 1];
    cards[round * 2] = -1;
    cards[round * 2 + 1] = -1;
    pthread_mutex_unlock(&mutex);

    printf("Thread %d got cards %d and %d\n", id, card1, card2);

    sem_post(&sem);

    pthread_mutex_lock(&mutex);
    if (cards[round * 2] == -1 && cards[round * 2 + 1] == -1) {
        printf("Thread %d won round %d\n", id, round);
        return NULL;
    }
    pthread_mutex_unlock(&mutex);

    int delay = rand() % MAX_DELAY;
    usleep(delay * 1000);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].id = i + 1;
        data[i].round = 0;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}