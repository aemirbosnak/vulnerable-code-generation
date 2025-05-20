//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 800
#define HEIGHT 600
#define THREADS 8

// Pixel data
unsigned char *pixels;

// Mutex for thread synchronization
pthread_mutex_t mutex;

// Function for generating pixel art
void *generate_art(void *arg) {
    int x = *(int*) arg;
    int y = WIDTH / THREADS * (int)pthread_self();
    int index = y * WIDTH + x;

    for (int i = 0; i < HEIGHT; i++) {
        int value = i % 256;
        pixels[index + i * WIDTH] = value;
    }

    return NULL;
}

int main() {
    // Initialize pixel data
    pixels = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    if (!pixels) {
        fprintf(stderr, "Error: Failed to allocate memory for pixel data.\n");
        return 1;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_t threads[THREADS];
    int args[THREADS];
    for (int i = 0; i < THREADS; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, generate_art, &args[i]);
    }

    // Join threads
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Save pixel data to file
    FILE *fp = fopen("pixel_art.raw", "wb");
    if (!fp) {
        fprintf(stderr, "Error: Failed to open file for writing.\n");
        return 1;
    }
    fwrite(pixels, WIDTH * HEIGHT * sizeof(unsigned char), 1, fp);
    fclose(fp);

    return 0;
}