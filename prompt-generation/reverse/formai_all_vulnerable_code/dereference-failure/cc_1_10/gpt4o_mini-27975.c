//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>

#define MAX_IMAGES 100
#define IMAGE_SIZE 256 // Simulated image size
#define NUM_CATEGORIES 3

typedef struct {
    char imagePath[256];
    int category;
} Image;

Image images[MAX_IMAGES];
int imageCount = 0;
pthread_mutex_t lock;

void* classify_image(void* arg) {
    Image* img = (Image*)arg;

    // Simulated image processing and classification
    FILE* file = fopen(img->imagePath, "rb");
    if (!file) {
        printf("Cannot open image file: %s\n", img->imagePath);
        return NULL;
    }

    // Simulate reading image data
    char buffer[IMAGE_SIZE];
    fread(buffer, sizeof(char), IMAGE_SIZE, file);
    fclose(file);

    // Simple classification logic based on the sum of pixel values
    int sum = 0;
    for(int i = 0; i < IMAGE_SIZE; i++) {
        sum += (unsigned char)buffer[i]; // Cast to unsigned char for pixel value
    }

    img->category = sum % NUM_CATEGORIES; // Classify based on sum mod number of categories

    pthread_mutex_lock(&lock);
    printf("Classified image %s into category %d\n", img->imagePath, img->category);
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void load_images(const char* directory) {
    DIR* dir = opendir(directory);
    struct dirent* entry;
    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_REG) { // Regular file
                snprintf(images[imageCount].imagePath, 256, "%s/%s", directory, entry->d_name);
                images[imageCount].category = -1; // Unknown category
                imageCount++;
            }
            if (imageCount >= MAX_IMAGES) break; // Safety limit
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
    }
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <image_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_images(argv[1]);
    pthread_t threads[MAX_IMAGES];
    pthread_mutex_init(&lock, NULL);

    // Create threads for image classification
    for(int i = 0; i < imageCount; i++) {
        if(pthread_create(&threads[i], NULL, classify_image, (void*)&images[i]) != 0) {
            perror("Failed to create thread");
        }
    }

    // Wait for all threads to finish
    for(int i = 0; i < imageCount; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    
    printf("Image classification complete!\n");
    return EXIT_SUCCESS;
}