//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 100
#define HEIGHT 100
#define NUM_THREADS 4

typedef struct {
    int x, y;
    int id;
} pixel_t;

pixel_t *pixels = NULL;

void *thread_func(void *arg) {
    int i, j;
    int row = ((int)arg) * HEIGHT / NUM_THREADS;
    int col = 0;

    for (i = row; i < HEIGHT; i++) {
        for (j = col; j < WIDTH; j++) {
            pixels[(i * WIDTH) + j].id = ((int)arg) + 1;
        }
        col += WIDTH / NUM_THREADS;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    srand(time(NULL));

    pixels = malloc(WIDTH * HEIGHT * sizeof(pixel_t));

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d ", pixels[i].id);
    }

    return 0;
}