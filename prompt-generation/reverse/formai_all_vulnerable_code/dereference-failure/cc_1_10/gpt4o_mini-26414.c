//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

#define MAX_IMAGES 100
#define IMAGE_NAME_LENGTH 256

typedef struct {
    char *image_name;
    int id;
} Image;

typedef struct {
    Image *images[MAX_IMAGES];
    int count;
    pthread_mutex_t mutex;
} ImageQueue;

ImageQueue queue;

void *classify_image(void *arg) {
    Image *image = (Image *)arg;

    // Simulate image classification
    printf("Classifying image: %s\n", image->image_name);
    // Replace this with actual image processing logic
    if (strstr(image->image_name, "cat") != NULL) {
        printf("Image %s classified as: Cat\n", image->image_name);
    } else if (strstr(image->image_name, "dog") != NULL) {
        printf("Image %s classified as: Dog\n", image->image_name);
    } else {
        printf("Image %s classified as: Unknown\n", image->image_name);
    }
    free(image->image_name);
    free(image);
    return NULL;
}

void enqueue_image(const char *filename) {
    pthread_mutex_lock(&queue.mutex);
    
    if (queue.count < MAX_IMAGES) {
        Image *image = (Image *)malloc(sizeof(Image));
        image->image_name = strdup(filename);
        image->id = queue.count;
        queue.images[queue.count++] = image;

        pthread_t thread;
        pthread_create(&thread, NULL, classify_image, (void *)image);
        pthread_detach(thread);
    } else {
        printf("Queue full, cannot add more images!\n");
    }
    
    pthread_mutex_unlock(&queue.mutex);
}

void process_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        fprintf(stderr, "Error opening directory %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            enqueue_image(entry->d_name);
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    queue.count = 0;
    pthread_mutex_init(&queue.mutex, NULL);

    process_directory(argv[1]);

    // Wait for a little while to let threads finish
    sleep(2);

    pthread_mutex_destroy(&queue.mutex);
    return EXIT_SUCCESS;
}