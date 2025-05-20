//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Define the thread data struct
typedef struct {
    Image *image;
    int start_row;
    int end_row;
} ThreadData;

// Define the ASCII characters to use
static char ascii_chars[] = " .,-~:;=!*#$@";

// Convert an image to ASCII art
void *convert_to_ascii(void *arg) {
    // Get the thread data
    ThreadData *data = (ThreadData *)arg;

    // Convert the image to ASCII art
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < data->image->width; j++) {
            // Get the pixel value
            unsigned char pixel = data->image->data[i * data->image->width + j];

            // Convert the pixel value to an ASCII character
            int index = (int)((float)pixel / 255 * (sizeof(ascii_chars) - 1));
            char ascii_char = ascii_chars[index];

            // Print the ASCII character
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    // Load the image
    Image image;
    image.width = 1000;
    image.height = 1000;
    image.data = malloc(image.width * image.height);
    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i] = rand() % 256;
    }

    // Create the threads
    int num_threads = 4;
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].image = &image;
        thread_data[i].start_row = i * (image.height / num_threads);
        thread_data[i].end_row = (i + 1) * (image.height / num_threads);
        pthread_create(&threads[i], NULL, convert_to_ascii, &thread_data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the image data
    free(image.data);

    return 0;
}