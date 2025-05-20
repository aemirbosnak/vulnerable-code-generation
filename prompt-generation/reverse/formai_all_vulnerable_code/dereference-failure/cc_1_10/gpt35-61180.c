//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

// Structure for passing arguments to threads
typedef struct {
    int thread_id;
    int **image;
    int rows;
    int cols;
} ThreadArgs;

// Function for flipping image horizontally
void *flipHorizontal(void *thread_args) {
    ThreadArgs *args = (ThreadArgs *) thread_args;
    int **image = args->image;
    int rows = args->rows;
    int cols = args->cols;
    
    // Flip each row horizontally
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
    
    pthread_exit(NULL);
}

// Function for adjusting brightness and contrast of image
void *brightnessContrast(void *thread_args) {
    ThreadArgs *args = (ThreadArgs *) thread_args;
    int **image = args->image;
    int rows = args->rows;
    int cols = args->cols;
    
    // Adjust brightness and contrast for each pixel
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int pixel = image[i][j];
            int new_pixel = (pixel * 2) + 20;
            if (new_pixel > 255) {
                new_pixel = 255;
            }
            image[i][j] = new_pixel;
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    int rows = 3;
    int cols = 3;
    int **image = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        image[i] = (int *) malloc(cols * sizeof(int));
    }
    // Initialize image with random pixel values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = rand() % 256;
        }
    }
    
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    
    // Initialize thread arguments and create threads
    thread_args[0].thread_id = 0;
    thread_args[0].image = image;
    thread_args[0].rows = rows;
    thread_args[0].cols = cols;
    pthread_create(&threads[0], NULL, flipHorizontal, (void *) &thread_args[0]);
    
    thread_args[1].thread_id = 1;
    thread_args[1].image = image;
    thread_args[1].rows = rows;
    thread_args[1].cols = cols;
    pthread_create(&threads[1], NULL, brightnessContrast, (void *) &thread_args[1]);
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print resulting image
    printf("Resulting image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}