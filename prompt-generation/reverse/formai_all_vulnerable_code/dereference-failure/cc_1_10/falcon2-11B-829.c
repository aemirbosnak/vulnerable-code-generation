//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_THREADS 4

typedef struct {
    int x;
    int y;
    char color;
} Pixel;

Pixel pixels[WIDTH * HEIGHT];

void* generatePixel(void* arg) {
    int threadId = *(int*)arg;
    int x = threadId % WIDTH;
    int y = threadId / WIDTH;

    pixels[y * WIDTH + x].x = x;
    pixels[y * WIDTH + x].y = y;
    pixels[y * WIDTH + x].color = 'X';

    printf("Pixel at (%d, %d) with color %c\n", x, y, pixels[y * WIDTH + x].color);

    return NULL;
}

int main() {
    int numThreads = (WIDTH * HEIGHT) / MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    int threadIds[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        threadIds[i] = i;
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, generatePixel, &threadIds[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", pixels[i].color);
    }

    return 0;
}