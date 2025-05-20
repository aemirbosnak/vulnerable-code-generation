//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <pthread.h>

#define NUM_THREADS 2

typedef struct {
    uint8_t* data;
    size_t size;
} Image;

typedef struct {
    Image* input;
    Image* output;
    double brightness;
    double contrast;
} Task;

void flipImage(Image* image) {
    uint8_t* buffer = malloc(image->size);

    for (size_t i = 0; i < image->size; ++i) {
        buffer[i] = image->data[image->size - i - 1];
    }

    free(image->data);
    image->data = buffer;
}

void adjustBrightnessContrast(Image* image, double brightness, double contrast) {
    for (size_t i = 0; i < image->size; ++i) {
        double pixel = image->data[i];

        // Adjust brightness: add a constant value to each pixel
        pixel += brightness;

        // Adjust contrast: scale the pixel values to spread them over the full range
        pixel = (pixel - 128) * contrast + 128;

        // Clamp the resulting pixel value to the valid range
        if (pixel < 0) {
            pixel = 0;
        } else if (pixel > 255) {
            pixel = 255;
        }

        image->data[i] = (uint8_t) pixel;
    }
}

void* processImage(void* arg) {
    Task* task = (Task*) arg;

    flipImage(task->input);
    adjustBrightnessContrast(task->input, task->brightness, task->contrast);
    task->output = task->input;

    return NULL;
}

int main(void) {
    Image image = {
        .data = (uint8_t[]) { 1, 2, 3, 4, 5 },
        .size = 5
    };
    double brightness = 20;
    double contrast = 1.5;

    Task tasks[NUM_THREADS] = {
        { .input = &image, .brightness = brightness, .contrast = contrast },
        { .input = &image, .brightness = -brightness, .contrast = 1 / contrast }
    };
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_create(&threads[i], NULL, processImage, &tasks[i]) != 0) {
            fprintf(stderr, "Error: pthread_create failed\n");
            return 1;
        }
    }

    Image* output[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error: pthread_join failed\n");
            return 1;
        }
        output[i] = tasks[i].output;
    }

    assert(output[0] == output[1]);

    Image* result = output[0];

    for (size_t i = 0; i < result->size; ++i) {
        printf("%u ", result->data[i]);
    }

    printf("\n");

    free(image.data);

    return 0;
}