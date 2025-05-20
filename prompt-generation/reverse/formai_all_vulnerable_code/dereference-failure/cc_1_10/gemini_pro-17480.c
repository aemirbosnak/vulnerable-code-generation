//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    int max_colors;
    unsigned char *pixels;
} image_t;

typedef struct {
    sem_t semaphore;
    image_t *image;
} shared_data_t;

typedef struct {
    shared_data_t *shared_data;
    int thread_id;
} thread_data_t;

void *generate_pixel_art(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    shared_data_t *shared_data = data->shared_data;
    int thread_id = data->thread_id;
    
    srand(time(NULL) ^ thread_id);

    for (int y = 0; y < shared_data->image->height; y++) {
        for (int x = 0; x < shared_data->image->width; x++) {
            // Generate a random color for the pixel
            int color = rand() % shared_data->image->max_colors;
            
            // Set the pixel to the generated color
            shared_data->image->pixels[y * shared_data->image->width + x] = color;
        }
    }
    
    sem_post(&shared_data->semaphore);

    return NULL;
}

int main() {
    // Create the shared data structure
    shared_data_t shared_data;
    sem_init(&shared_data.semaphore, 0, 0);

    // Initialize the image
    shared_data.image = malloc(sizeof(image_t));
    shared_data.image->width = MAX_WIDTH;
    shared_data.image->height = MAX_HEIGHT;
    shared_data.image->max_colors = 256;
    shared_data.image->pixels = malloc(shared_data.image->width * shared_data.image->height);

    // Create the threads
    pthread_t threads[8];
    thread_data_t thread_data[8];
    for (int i = 0; i < 8; i++) {
        thread_data[i].shared_data = &shared_data;
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, generate_pixel_art, &thread_data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write the image to a file
    FILE *fp = fopen("pixel_art.ppm", "wb");
    fprintf(fp, "P3\n%d %d\n255\n", shared_data.image->width, shared_data.image->height);
    for (int y = 0; y < shared_data.image->height; y++) {
        for (int x = 0; x < shared_data.image->width; x++) {
            int color = shared_data.image->pixels[y * shared_data.image->width + x];
            fprintf(fp, "%d %d %d ", color, color, color);
        }
    }
    fclose(fp);

    // Free the memory allocated for the image
    free(shared_data.image->pixels);
    free(shared_data.image);
    
    sem_destroy(&shared_data.semaphore);

    return 0;
}