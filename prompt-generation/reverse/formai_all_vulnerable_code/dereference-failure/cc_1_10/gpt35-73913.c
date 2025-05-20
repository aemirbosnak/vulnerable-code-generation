//FormAI DATASET v1.0 Category: Image compression ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
int IMAGE_WIDTH = 640;
int IMAGE_HEIGHT = 480;
int **image_data;
int **compressed_image_data;

// Struct to hold thread arguments
typedef struct {
    int start;
    int end;
} ThreadArgs;

// Function to compress image data
void *compress_image(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *) args;
    int start = thread_args->start;
    int end = thread_args->end;
    for (int row = start; row <= end; row++) {
        for (int col = 0; col < IMAGE_WIDTH; col++) {
            // Compress pixel data
            compressed_image_data[row][col] = image_data[row][col] / 2;
        }
    }
    free(thread_args);
    pthread_exit(NULL);
}

int main() {
    // Allocate memory for image data
    image_data = malloc(IMAGE_HEIGHT * sizeof(int *));
    compressed_image_data = malloc(IMAGE_HEIGHT * sizeof(int *));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        image_data[i] = malloc(IMAGE_WIDTH * sizeof(int));
        compressed_image_data[i] = malloc(IMAGE_WIDTH * sizeof(int));
    }
    
    // Initialize image data
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            image_data[i][j] = rand() % 256;
        }
    }
    
    // Create threads to compress image data
    int num_threads = 4;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        ThreadArgs *args = malloc(sizeof(ThreadArgs));
        args->start = i * (IMAGE_HEIGHT / num_threads);
        args->end = (i + 1) * (IMAGE_HEIGHT / num_threads) - 1;
        pthread_create(&threads[i], NULL, compress_image, (void *) args);
    }
    
    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print compressed image data
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            printf("%d ", compressed_image_data[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        free(image_data[i]);
        free(compressed_image_data[i]);
    }
    free(image_data);
    free(compressed_image_data);
    
    return 0;
}