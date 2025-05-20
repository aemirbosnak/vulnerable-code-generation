//FormAI DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_MSG_LEN 100
#define MAX_FILE_NAME_LEN 50
#define MAX_PIXELS 480000

pthread_mutex_t mutex;

// Structure for each pixel in the image
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

// Structure for the image
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_PIXELS];
} Image;

// Function to read image from file
void read_image(char file_name[], Image *image) {
    FILE *file;
    char format[3];
    int max_value;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fgets(format, 3, file);
    if (strcmp(format, "P3")) {
        printf("Invalid file format.\n");
        exit(1);
    }

    fscanf(file, "%d %d %d\n", &image->width, &image->height, &max_value);

    int i;
    for (i = 0; i < image->width * image->height; i++) {
        fscanf(file, "%d %d %d", &image->pixels[i].red, &image->pixels[i].green, &image->pixels[i].blue);
    }

    fclose(file);
}

// Function to write image to file
void write_image(char file_name[], Image *image) {
    FILE *file;

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");

    int i;
    for (i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d %d %d ", image->pixels[i].red, image->pixels[i].green, image->pixels[i].blue);
    }

    fclose(file);
}

// Function to hide message in image
void* hide_message(void *args) {
    char message[MAX_MSG_LEN];
    char* file_name;
    Image *image = (Image *) args;

    printf("Enter message to hide: ");
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = 0;

    pthread_mutex_lock(&mutex);
    int message_length = strlen(message);

    int i;
    for (i = 0; i < message_length; i++) {
        image->pixels[i].red = (image->pixels[i].red & ~1) | ((message[i] >> 7) & 1);
        image->pixels[i].green = (image->pixels[i].green & ~1) | ((message[i] >> 6) & 1);
        image->pixels[i].blue = (image->pixels[i].blue & ~3) | ((message[i] >> 4) & 3);
    }

    file_name = (char *) malloc(MAX_FILE_NAME_LEN * sizeof(char));
    printf("Enter file name to save steganographed image: ");
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = 0;
    write_image(file_name, image);
    free(file_name);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

// Function to retrieve message from image
void* retrieve_message(void *args) {
    char message[MAX_MSG_LEN] = {0};
    Image *image = (Image *) args;

    pthread_mutex_lock(&mutex);
    int i;
    for (i = 0; i < MAX_MSG_LEN; i++) {
        message[i] |= ((image->pixels[i].red & 1) << 7);
        message[i] |= ((image->pixels[i].green & 1) << 6);
        message[i] |= ((image->pixels[i].blue & 3) << 4);

        if (message[i] == '\0') break;
    }

    printf("Retrieved message: %s\n", message);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    Image image;
    char file_name[MAX_FILE_NAME_LEN];
    pthread_t hide_thread, retrieve_thread;
    int thread_exit_status;

    // Read image from file
    printf("Enter image file name: ");
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = 0;
    read_image(file_name, &image);

    // Create hide message thread
    thread_exit_status = pthread_create(&hide_thread, NULL, hide_message, (void *) &image);
    if (thread_exit_status != 0) {
        printf("Error creating thread.\n");
        exit(1);
    }

    // Create retrieve message thread
    thread_exit_status = pthread_create(&retrieve_thread, NULL, retrieve_message, (void *) &image);
    if (thread_exit_status != 0) {
        printf("Error creating thread.\n");
        exit(1);
    }

    // Wait for threads to finish
    pthread_join(hide_thread, NULL);
    pthread_join(retrieve_thread, NULL);

    return 0;
}