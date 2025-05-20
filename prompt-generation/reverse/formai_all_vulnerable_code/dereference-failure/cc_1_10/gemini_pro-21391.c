//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 8

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

typedef struct {
    Image *image;
    int start;
    int end;
} ThreadArgs;

void *thread_func(void *args) {
    ThreadArgs *ta = (ThreadArgs *)args;
    Image *image = ta->image;

    for (int i = ta->start; i < ta->end; i++) {
        for (int j = 0; j < image->width; j++) {
            int index = i * image->width + j;
            image->data[index] = 255 - image->data[index];
        }
    }

    return NULL;
}

int main() {
    // Read the image from a file
    FILE *fp = fopen("input.jpg", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return EXIT_FAILURE;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    // Parse the image header
    int width, height;
    if (strncmp((char *)data, "\xFF\xD8", 2) != 0) {
        fprintf(stderr, "Invalid JPEG file\n");
        return EXIT_FAILURE;
    }

    data += 2;

    while (1) {
        // Read the marker
        unsigned char marker = *data++;
        if (marker == 0xFF) {
            // End of header
            break;
        }

        // Read the marker length
        unsigned short length = *data++ << 8;
        length |= *data++;

        // Read the marker data
        data += length - 2;
    }

    // Read the width and height
    width = *data++ << 8;
    width |= *data++;
    height = *data++ << 8;
    height |= *data++;

    // Create an image struct
    Image image;
    image.width = width;
    image.height = height;
    image.data = data;

    // Create the thread pool
    pthread_t threads[MAX_THREADS];
    ThreadArgs args[MAX_THREADS];

    int num_threads = MAX_THREADS;
    if (num_threads > image.height) {
        num_threads = image.height;
    }

    int chunk_size = image.height / num_threads;

    for (int i = 0; i < num_threads; i++) {
        args[i].image = &image;
        args[i].start = i * chunk_size;
        args[i].end = (i + 1) * chunk_size;

        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write the inverted image to a file
    fp = fopen("output.jpg", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return EXIT_FAILURE;
    }

    fwrite(image.data, 1, size, fp);
    fclose(fp);

    return EXIT_SUCCESS;
}