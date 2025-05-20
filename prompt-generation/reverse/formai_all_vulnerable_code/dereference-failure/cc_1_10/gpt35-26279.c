//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_IMAGE_WIDTH 1024
#define MAX_IMAGE_HEIGHT 768
#define MAX_PIXEL_VALUE 255

// Struct to hold a pixel's RGB values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Global variables for image width, height, and pixel array
int image_width = 0;
int image_height = 0;
pixel image[MAX_IMAGE_HEIGHT][MAX_IMAGE_WIDTH];

// Function to generate random RGB values for a pixel
void random_pixel(pixel *p) {
    p->r = rand() % (MAX_PIXEL_VALUE + 1);
    p->g = rand() % (MAX_PIXEL_VALUE + 1);
    p->b = rand() % (MAX_PIXEL_VALUE + 1);
}

// Thread function to generate pixels for a portion of the image, specified by row_start and row_end
void *generate_pixels(void *arg) {
    int row_start = *((int *) arg);
    int row_end = row_start + (image_height / 4); // Divide image into 4 equal parts
    for (int i = row_start; i < row_end; i++) {
        for (int j = 0; j < image_width; j++) {
            random_pixel(&image[i][j]); // Generate random pixel for each position in the portion of the image
        }
    }
    free(arg); // Free memory allocated for argument
    pthread_exit(NULL); // Exit thread
}

int main(int argc, char **argv) {
    // Parse command line arguments for image dimensions
    if (argc != 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }
    image_width = atoi(argv[1]);
    image_height = atoi(argv[2]);

    if (image_width > MAX_IMAGE_WIDTH || image_height > MAX_IMAGE_HEIGHT) {
        printf("Image dimensions too large\n");
        return 1;
    }

    srand(time(NULL)); // Seed random number generator with current time

    pthread_t threads[4]; // Array to hold thread IDs
    int *thread_args[4]; // Array to hold argument pointers for each thread

    // Create threads to generate pixels for each portion of the image
    int row_start = 0;
    for (int i = 0; i < 4; i++) {
        int *arg = malloc(sizeof(int)); // Allocate memory for argument pointer
        if (arg == NULL) {
            printf("Error: could not allocate memory for thread argument\n");
            return 1;
        }        
        *arg = row_start;
        thread_args[i] = arg;
        int rc = pthread_create(&threads[i], NULL, generate_pixels, arg);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            return 1;
        }
        row_start += image_height / 4; // Increment row_start for next portion of image
    }

    // Wait for threads to finish
    for (int i = 0; i < 4; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            return 1;
        }
    }

    // Write image to file
    FILE *file = fopen("image.ppm", "w");
    if (file == NULL) {
        printf("Error: could not open output file\n");
        return 1;
    }
    fprintf(file, "P3\n%d %d\n%d\n", image_width, image_height, MAX_PIXEL_VALUE);
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            fprintf(file, "%d %d %d ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Image generated successfully\n");
    return 0;
}