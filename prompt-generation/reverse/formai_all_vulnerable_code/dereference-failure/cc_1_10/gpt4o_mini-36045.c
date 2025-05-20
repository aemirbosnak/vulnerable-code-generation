//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <jpeglib.h>

#define NUM_CLASSES 2
#define IMAGE_SIZE 64

typedef struct {
    char *filename;
    int class_id;
} image_t;

typedef struct {
    image_t *images;
    int num_images;
    int thread_id;
} thread_data_t;

// Prototype for the image classifier function
void *classify_images(void *arg);
void load_images(char *directory, image_t **images, int *num_images);
void process_image(char *filename, int *class_id);
void print_classificationResult(int class_id, char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image_t *images = NULL;
    int num_images = 0;
    
    // Load images from directory
    load_images(argv[1], &images, &num_images);

    int num_threads = 4;
    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];

    // Create worker threads for classification
    for (int i = 0; i < num_threads; ++i) {
        thread_data[i].images = images + (i * num_images / num_threads);
        thread_data[i].num_images = (i == num_threads - 1) ? 
                    (num_images - i * num_images / num_threads) : 
                    (num_images / num_threads);
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, classify_images, &thread_data[i]);
    }

    // Join threads after classification
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Free allocated memory
    for (int j = 0; j < num_images; j++) {
        free(images[j].filename);
    }
    free(images);

    return EXIT_SUCCESS;
}

void load_images(char *directory, image_t **images, int *num_images) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) { // Only files
                (*num_images)++;
                *images = realloc(*images, (*num_images) * sizeof(image_t));
                (*images)[*num_images - 1].filename = strdup(ent->d_name);
                (*images)[*num_images - 1].class_id = -1; // Not yet classified
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
}

void *classify_images(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    for (int i = 0; i < data->num_images; i++) {
        process_image(data->images[i].filename, &data->images[i].class_id);
        print_classificationResult(data->images[i].class_id, data->images[i].filename);
    }
    return NULL;
}

void process_image(char *filename, int *class_id) {
    // Placeholder for image processing logic
    // You should extract pixels and run over a classifier model.
    // Simulated classification based on filename length
    int length = strlen(filename);
    if (length % 2 == 0) {
        *class_id = 0; // Class A
    } else {
        *class_id = 1; // Class B
    }
}

void print_classificationResult(int class_id, char *filename) {
    const char *class_names[NUM_CLASSES] = {"Class A", "Class B"};
    printf("Image: %s classified as %s\n", filename, class_names[class_id]);
}