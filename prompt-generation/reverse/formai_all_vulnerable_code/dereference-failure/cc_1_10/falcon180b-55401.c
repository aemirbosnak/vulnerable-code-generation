//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_THREADS 4

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

Pixel *image = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    int start_row = thread_id * HEIGHT / NUM_THREADS;
    int end_row = (thread_id + 1) * HEIGHT / NUM_THREADS;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Pixel pixel = {j, i, 0, 0, 0};

            pthread_mutex_lock(&lock);
            image[i * WIDTH + j] = pixel;
            pthread_mutex_unlock(&lock);
        }
    }

    return NULL;
}

int main() {
    image = (Pixel *) malloc(WIDTH * HEIGHT * sizeof(Pixel));

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            Pixel pixel = image[j * WIDTH + i];
            printf("%d %d %d\n", pixel.r, pixel.g, pixel.b);
        }
    }

    return 0;
}