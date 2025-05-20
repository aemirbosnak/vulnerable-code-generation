//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the pixel art struct
typedef struct {
    int width;
    int height;
    char **data;
} PixelArt;

// Define the thread argument struct
typedef struct {
    PixelArt *pixelArt;
    int startRow;
    int endRow;
} ThreadArgs;

// Function to generate a random character
char generateRandomCharacter() {
    int randomNumber = rand() % 26;
    return 'a' + randomNumber;
}

// Function to create a new pixel art struct
PixelArt *createPixelArt(int width, int height) {
    PixelArt *pixelArt = malloc(sizeof(PixelArt));
    pixelArt->width = width;
    pixelArt->height = height;
    pixelArt->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        pixelArt->data[i] = malloc(sizeof(char) * width);
    }
    return pixelArt;
}

// Function to destroy a pixel art struct
void destroyPixelArt(PixelArt *pixelArt) {
    for (int i = 0; i < pixelArt->height; i++) {
        free(pixelArt->data[i]);
    }
    free(pixelArt->data);
    free(pixelArt);
}

// Function to generate the pixel art
void generatePixelArt(PixelArt *pixelArt) {
    for (int i = 0; i < pixelArt->height; i++) {
        for (int j = 0; j < pixelArt->width; j++) {
            pixelArt->data[i][j] = generateRandomCharacter();
        }
    }
}

// Function to print the pixel art
void printPixelArt(PixelArt *pixelArt) {
    for (int i = 0; i < pixelArt->height; i++) {
        for (int j = 0; j < pixelArt->width; j++) {
            printf("%c", pixelArt->data[i][j]);
        }
        printf("\n");
    }
}

// Function to be executed by each thread
void *threadFunction(void *arg) {
    ThreadArgs *threadArgs = (ThreadArgs *)arg;
    PixelArt *pixelArt = threadArgs->pixelArt;
    int startRow = threadArgs->startRow;
    int endRow = threadArgs->endRow;

    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < pixelArt->width; j++) {
            pixelArt->data[i][j] = generateRandomCharacter();
        }
    }

    return NULL;
}

int main() {
    // Create a new pixel art struct
    PixelArt *pixelArt = createPixelArt(500, 500);

    // Create the thread pool
    pthread_t threads[4];

    // Create the thread arguments
    ThreadArgs threadArgs[4];
    for (int i = 0; i < 4; i++) {
        threadArgs[i].pixelArt = pixelArt;
        threadArgs[i].startRow = i * pixelArt->height / 4;
        threadArgs[i].endRow = (i + 1) * pixelArt->height / 4;
    }

    // Create the threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, threadFunction, &threadArgs[i]);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the pixel art
    printPixelArt(pixelArt);

    // Destroy the pixel art struct
    destroyPixelArt(pixelArt);

    return 0;
}