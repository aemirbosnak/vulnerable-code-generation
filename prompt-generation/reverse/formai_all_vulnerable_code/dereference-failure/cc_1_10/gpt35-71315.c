//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 480
#define HEIGHT 360
#define MAX_VALUE 255
#define NUM_THREADS 4

// Define a single pixel
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Define an image
typedef struct {
    Pixel *pixels;
    unsigned int width;
    unsigned int height;
} Image;

// Allocate memory for a new Image and its Pixels.
Image *new_image(unsigned int width, unsigned int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    return image;
}

// Free memory for a given Image.
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Flip an Image horizontally.
void flip_horizontal(Image *image) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width / 2; x++) {
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[y * image->width + (image->width - 1 - x)];
            image->pixels[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

// Adjust the brightness of an Image by a given factor.
void adjust_brightness(Image *image, float factor) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            image->pixels[y * image->width + x].r = (unsigned char)(image->pixels[y * image->width + x].r * factor);
            image->pixels[y * image->width + x].g = (unsigned char)(image->pixels[y * image->width + x].g * factor);
            image->pixels[y * image->width + x].b = (unsigned char)(image->pixels[y * image->width + x].b * factor);
        }
    }
}

// Adjust the contrast of an Image by a given factor.
void adjust_contrast(Image *image, float factor) {
    int x, y;
    for (y = 0; y < image->height; y++) {
        for (x = 0; x < image->width; x++) {
            float r = (float)image->pixels[y * image->width + x].r / MAX_VALUE;
            float g = (float)image->pixels[y * image->width + x].g / MAX_VALUE;
            float b = (float)image->pixels[y * image->width + x].b / MAX_VALUE;
            r = (r - 0.5) * factor + 0.5;
            g = (g - 0.5) * factor + 0.5;
            b = (b - 0.5) * factor + 0.5;
            if (r < 0) r = 0; else if (r > 1) r = 1;
            if (g < 0) g = 0; else if (g > 1) g = 1;
            if (b < 0) b = 0; else if (b > 1) b = 1;
            image->pixels[y * image->width + x].r = (unsigned char)(r * MAX_VALUE);
            image->pixels[y * image->width + x].g = (unsigned char)(g * MAX_VALUE);
            image->pixels[y * image->width + x].b = (unsigned char)(b * MAX_VALUE);
        }
    }
}

// Define an argument structure for the thread function.
typedef struct {
    Image *image;
    float factor;
} ThreadArgs;

// Thread function to adjust brightness or contrast of an Image.
void *adjust_image(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *)args;
    adjust_brightness(thread_args->image, thread_args->factor);
    adjust_contrast(thread_args->image, thread_args->factor);
    return NULL;
}

int main() {
    unsigned int x, y;
    Image *image = new_image(WIDTH, HEIGHT);

    // Generate a random test image.
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image->pixels[y * WIDTH + x].r = rand() % (MAX_VALUE + 1);
            image->pixels[y * WIDTH + x].g = rand() % (MAX_VALUE + 1);
            image->pixels[y * WIDTH + x].b = rand() % (MAX_VALUE + 1);
        }
    }

    // Flip the image horizontally.
    flip_horizontal(image);

    // Create threads to adjust the brightness and contrast of the image.
    pthread_t threads[NUM_THREADS];
    ThreadArgs args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].image = image;
        args[i].factor = ((float)i + 1) / 2;
        pthread_create(&threads[i], NULL, adjust_image, (void *)&args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory for the image and its pixels.
    free_image(image);

    return 0;
}