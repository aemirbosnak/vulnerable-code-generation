//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_THREADS 4

// A structure to hold image data
typedef struct {
    int width;
    int height;
    char** data;
} Image;

// A structure to hold the arguments required by each thread
typedef struct {
    Image* image;
    int start_row;
    int end_row;
    char** ascii;
} ThreadArgs;

// Function to load an image from a file
Image* LoadImage(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char buffer[15];
    fgets(buffer, 15, file);
    if (buffer[0] != 'P' || buffer[1] != '3') {
        printf("Error: invalid file format\n");
        exit(1);
    }

    int width, height, max_value;
    fscanf(file, "%d %d %d\n", &width, &height, &max_value);

    char** data = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        data[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            int r, g, b;
            fscanf(file, "%d %d %d ", &r, &g, &b);
            data[i][j] = (char)(((r + g + b) / 3.0) / (max_value / 10.0));
        }
    }

    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    fclose(file);

    return image;
}

// Function to free image data from memory
void FreeImage(Image* image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

// Function for each thread to generate a section of ascii art
void* GenerateAscii(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    Image* image = args->image;
    int start_row = args->start_row;
    int end_row = args->end_row;
    char** ascii = args->ascii;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < image->width; j++) {
            int pixel = image->data[i][j];
            if (pixel == 0) {
                ascii[i][j] = ' ';
            } else if (pixel == 1) {
                ascii[i][j] = '.';
            } else if (pixel == 2) {
                ascii[i][j] = ':';
            } else if (pixel == 3) {
                ascii[i][j] = 'o';
            } else if (pixel == 4) {
                ascii[i][j] = '&';
            } else if (pixel == 5) {
                ascii[i][j] = '8';
            } else if (pixel == 6) {
                ascii[i][j] = '#';
            } else if (pixel == 7) {
                ascii[i][j] = '@';
            } else {
                ascii[i][j] = '%';
            }
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <image>\n", argv[0]);
        exit(1);
    }

    Image* image = LoadImage(argv[1]);

    char** ascii = malloc(HEIGHT * sizeof(char*));
    for (int i = 0; i < HEIGHT; i++) {
        ascii[i] = malloc(WIDTH * sizeof(char));
        for (int j = 0; j < WIDTH; j++) {
            ascii[i][j] = ' ';
        }
    }

    int rows_per_thread = image->height / MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    ThreadArgs thread_args[MAX_THREADS];
    int start_row = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        int end_row = start_row + rows_per_thread;
        if (i == MAX_THREADS - 1) {
            end_row = image->height;
        }
        thread_args[i].image = image;
        thread_args[i].start_row = start_row;
        thread_args[i].end_row = end_row;
        thread_args[i].ascii = ascii;
        pthread_create(&threads[i], NULL, GenerateAscii, (void*)&thread_args[i]);
        start_row = end_row;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(ascii[i][j]);
        }
        putchar('\n');
    }

    FreeImage(image);
    for (int i = 0; i < HEIGHT; i++) {
        free(ascii[i]);
    }
    free(ascii);

    return 0;
}