//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 4 // Number of threads
#define NUM_IMAGES 20 // Total number of images
#define IMAGE_SIZE 1000 // Simulated image size

typedef struct {
    int thread_id;
    int *images;
    int num_images;
} thread_data_t;

// Simulated image classification function
const char* classify_image(int image) {
    // Simulate different classifications
    switch (image % 5) {
        case 0: return "Cat";
        case 1: return "Dog";
        case 2: return "Car";
        case 3: return "Tree";
        case 4: return "House";
        default: return "Unknown";
    }
}

// The thread function for classifying images
void* classify_images(void* threadarg) {
    thread_data_t *data = (thread_data_t *) threadarg;
    int start_index = (data->num_images / NUM_THREADS) * data->thread_id;
    int end_index = (data->num_images / NUM_THREADS) * (data->thread_id + 1);
    
    printf("Thread %d is classifying images from index %d to %d:\n", 
           data->thread_id, start_index, end_index - 1);
    
    for (int i = start_index; i < end_index; i++) {
        const char* classification = classify_image(data->images[i]);
        printf("Image %d classified as: %s\n", i, classification);
        usleep(100000); // Simulate processing time
    }
    
    pthread_exit(NULL);
}

int main() {
    int *images = malloc(NUM_IMAGES * sizeof(int));
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    
    // Initialize image data
    for (int i = 0; i < NUM_IMAGES; i++) {
        images[i] = rand() % IMAGE_SIZE; // Mock image representation
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].images = images;
        thread_data[i].num_images = NUM_IMAGES;
        int rc = pthread_create(&threads[i], NULL, classify_images, (void*)&thread_data[i]);
        
        if (rc) {
            fprintf(stderr, "Error: Unable to create thread %d. %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(images);
    printf("All images classified successfully.\n");

    pthread_exit(NULL);
}