//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_THREADS 10

struct element {
    char name[3];
    int atomic_number;
    char symbol[3];
};

struct element elements[MAX_ELEMENTS] = {
    {"H", 1, "H"},
    {"He", 2, "He"},
    {"Li", 3, "Li"},
    {"Be", 4, "Be"},
    {"B", 5, "B"},
    {"C", 6, "C"},
    {"N", 7, "N"},
    {"O", 8, "O"},
    {"F", 9, "F"},
    {"Ne", 10, "Ne"}
};

void *thread_func(void *arg) {
    int i = *(int *) arg;
    printf("Thread %d is printing the periodic table...\n", i);

    for (int j = 0; j < MAX_ELEMENTS; j++) {
        printf("%s %d %s\n", elements[j].name, elements[j].atomic_number, elements[j].symbol);
    }

    pthread_exit(0);
}

int main() {
    srand(time(NULL));
    int num_threads = rand() % MAX_THREADS + 1;
    pthread_t threads[MAX_THREADS];

    printf("Starting %d threads...\n", num_threads);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}