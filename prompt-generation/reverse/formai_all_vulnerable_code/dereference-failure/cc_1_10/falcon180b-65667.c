//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CLUSTERS 4
#define NUM_POINTS 100

typedef struct {
    int id;
    int cluster;
    double *point;
} Point;

Point *points = NULL;
int num_points = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int thread_id = *(int *)arg;

    srand(time(NULL) + thread_id);

    for (int i = 0; i < 10; i++) {
        Point *new_point = malloc(sizeof(Point));
        new_point->id = num_points++;
        new_point->cluster = rand() % NUM_CLUSTERS;

        double x = rand() % 100;
        double y = rand() % 100;

        new_point->point = malloc(sizeof(double) * 2);
        new_point->point[0] = x;
        new_point->point[1] = y;

        pthread_mutex_lock(&mutex);
        points = realloc(points, sizeof(Point) * num_points);
        points[new_point->id] = *new_point;
        pthread_mutex_unlock(&mutex);

        free(new_point->point);
        free(new_point);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_CLUSTERS];

    srand(time(NULL));

    points = malloc(sizeof(Point) * NUM_POINTS);

    for (int i = 0; i < NUM_CLUSTERS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &i);
    }

    for (int i = 0; i < NUM_CLUSTERS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Number of points: %d\n", num_points);

    return 0;
}