//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

// Image data structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Semaphore to synchronize access to the image data
sem_t image_sem;

// Function to flip an image vertically
void *flip_vertical(void *arg) {
    Image *image = (Image *)arg;

    // Acquire the semaphore to prevent other threads from accessing the image data
    sem_wait(&image_sem);

    // Loop through each row of the image
    for (int y = 0; y < image->height / 2; y++) {
        // Swap the pixels in each row
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }

    // Release the semaphore to allow other threads to access the image data
    sem_post(&image_sem);

    return NULL;
}

// Function to flip an image horizontally
void *flip_horizontal(void *arg) {
    Image *image = (Image *)arg;

    // Acquire the semaphore to prevent other threads from accessing the image data
    sem_wait(&image_sem);

    // Loop through each column of the image
    for (int x = 0; x < image->width / 2; x++) {
        // Swap the pixels in each column
        for (int y = 0; y < image->height; y++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - x - 1)];
            image->data[y * image->width + (image->width - x - 1)] = temp;
        }
    }

    // Release the semaphore to allow other threads to access the image data
    sem_post(&image_sem);

    return NULL;
}

// Function to change the brightness of an image
void *change_brightness(void *arg) {
    Image *image = (Image *)arg;

    // Acquire the semaphore to prevent other threads from accessing the image data
    sem_wait(&image_sem);

    // Get the brightness value from the user
    int brightness;
    printf("Enter the brightness value (0-255): ");
    scanf("%d", &brightness);

    // Loop through each pixel in the image
    for (int i = 0; i < image->width * image->height; i++) {
        // Adjust the pixel value by the brightness value
        image->data[i] = image->data[i] + brightness;

        // Clamp the pixel value to the range 0-255
        if (image->data[i] < 0) {
            image->data[i] = 0;
        }
        if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }

    // Release the semaphore to allow other threads to access the image data
    sem_post(&image_sem);

    return NULL;
}

// Function to change the contrast of an image
void *change_contrast(void *arg) {
    Image *image = (Image *)arg;

    // Acquire the semaphore to prevent other threads from accessing the image data
    sem_wait(&image_sem);

    // Get the contrast value from the user
    double contrast;
    printf("Enter the contrast value (0-10): ");
    scanf("%lf", &contrast);

    // Loop through each pixel in the image
    for (int i = 0; i < image->width * image->height; i++) {
        // Adjust the pixel value by the contrast value
        image->data[i] = ((image->data[i] - 127.5) * contrast) + 127.5;

        // Clamp the pixel value to the range 0-255
        if (image->data[i] < 0) {
            image->data[i] = 0;
        }
        if (image->data[i] > 255) {
            image->data[i] = 255;
        }
    }

    // Release the semaphore to allow other threads to access the image data
    sem_post(&image_sem);

    return NULL;
}

int main() {
    // Read the image from a file
    Image image;
    FILE *file = fopen("image.bmp", "rb");
    fread(&image.width, sizeof(int), 1, file);
    fread(&image.height, sizeof(int), 1, file);
    image.data = malloc(image.width * image.height);
    fread(image.data, 1, image.width * image.height, file);
    fclose(file);

    // Initialize the semaphore
    sem_init(&image_sem, 0, 1);

    // Create the threads
    pthread_t flip_vertical_thread;
    pthread_t flip_horizontal_thread;
    pthread_t change_brightness_thread;
    pthread_t change_contrast_thread;

    // Create the threads
    pthread_create(&flip_vertical_thread, NULL, flip_vertical, &image);
    pthread_create(&flip_horizontal_thread, NULL, flip_horizontal, &image);
    pthread_create(&change_brightness_thread, NULL, change_brightness, &image);
    pthread_create(&change_contrast_thread, NULL, change_contrast, &image);

    // Join the threads
    pthread_join(flip_vertical_thread, NULL);
    pthread_join(flip_horizontal_thread, NULL);
    pthread_join(change_brightness_thread, NULL);
    pthread_join(change_contrast_thread, NULL);

    // Write the image to a file
    file = fopen("output.bmp", "wb");
    fwrite(&image.width, sizeof(int), 1, file);
    fwrite(&image.height, sizeof(int), 1, file);
    fwrite(image.data, 1, image.width * image.height, file);
    fclose(file);

    // Destroy the semaphore
    sem_destroy(&image_sem);

    // Free the image data
    free(image.data);

    return 0;
}