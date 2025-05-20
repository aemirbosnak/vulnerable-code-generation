//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Struct for passing data to threads
struct v {
    int x;
    int y;
    int color;
};

void *runner(void *param); // Prototype for thread function

int main() {
    pthread_t threads[WIDTH * HEIGHT]; // Create an array of threads
    int x, y, color;

    // Initialize random seed
    srand(time(NULL));

    // Loop through each pixel and create a thread for it
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Set random color for pixel
            color = rand() % 256;

            // Create struct with pixel coordinates and color
            struct v *data = (struct v *) malloc(sizeof(struct v));
            data->x = x;
            data->y = y;
            data->color = color;

            // Create thread and pass data to it
            pthread_create(&threads[y * WIDTH + x], NULL, runner, data);
        }
    }

    // Join all threads
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            pthread_join(threads[y * WIDTH + x], NULL);
        }
    }

    return 0;
}

// Thread function to set pixel color
void *runner(void *param) {
    struct v *data = (struct v *) param;

    // Set pixel color
    printf("Setting pixel (%d, %d) to color %d\n", data->x, data->y, data->color);

    // Free memory used by struct
    free(data);

    return NULL;
}