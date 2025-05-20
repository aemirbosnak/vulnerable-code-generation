//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_STOCKS 10
#define NUM_THREADS 5

typedef struct {
    char name[20];
    float price;
} Stock;

Stock stocks[NUM_STOCKS] = {
    {"AAPL", 150.0},
    {"GOOG", 1000.0},
    {"AMZN", 2000.0},
    {"FB", 250.0},
    {"TSLA", 600.0},
    {"MSFT", 300.0},
    {"NFLX", 500.0},
    {"TWTR", 50.0},
    {"SNAP", 30.0},
    {"UBER", 40.0}
};

int thread_ids[NUM_THREADS];
pthread_t threads[NUM_THREADS];

sem_t mutex;

void* thread_func(void* arg) {
    int id = *(int*)arg;
    float total_price = 0.0;

    for (int i = 0; i < NUM_STOCKS; i++) {
        sem_wait(&mutex);
        total_price += stocks[i].price;
        sem_post(&mutex);
    }

    printf("Thread %d calculated total stock price: $%.2f\n", id, total_price);

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}