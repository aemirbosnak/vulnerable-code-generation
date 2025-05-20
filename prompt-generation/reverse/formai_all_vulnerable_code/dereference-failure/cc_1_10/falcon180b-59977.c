//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_POINTS 100

struct point {
    int x;
    int y;
};

struct thread_data {
    int id;
    struct point *points;
};

void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int id = data->id;
    struct point *points = data->points;

    printf("Thread %d started.\n", id);

    for (int i = 0; i < MAX_POINTS; i++) {
        points[i].x = i;
        points[i].y = i * 2;
    }

    printf("Thread %d finished.\n", id);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].points = (struct point *) malloc(MAX_POINTS * sizeof(struct point));

        for (int j = 0; j < MAX_POINTS; j++) {
            data[i].points[j].x = 0;
            data[i].points[j].y = 0;
        }

        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}