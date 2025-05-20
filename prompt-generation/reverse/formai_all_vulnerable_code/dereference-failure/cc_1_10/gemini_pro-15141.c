//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_THREADS 4

typedef struct {
    char *text;
    int width;
    int height;
    char **ascii;
} TextToAsciiArgs;

void *text_to_ascii(void *args) {
    TextToAsciiArgs *a = (TextToAsciiArgs *)args;
    int i, j;

    for (i = 0; i < a->height; i++) {
        for (j = 0; j < a->width; j++) {
            a->ascii[i][j] = '.';
        }
    }

    for (i = 0; i < strlen(a->text); i++) {
        int x = i % a->width;
        int y = i / a->width;
        a->ascii[y][x] = a->text[i];
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    int width = strlen(text);
    int height = 1;
    char **ascii;

    // Allocate memory for the ASCII art
    ascii = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii[i] = malloc(width * sizeof(char));
    }

    // Create the thread pool
    pthread_t threads[NUM_THREADS];
    TextToAsciiArgs args[NUM_THREADS];

    // Divide the work among the threads
    int num_threads = NUM_THREADS;
    int chunk_size = (height * width) / num_threads;
    for (int i = 0; i < num_threads; i++) {
        args[i].text = text;
        args[i].width = width;
        args[i].height = height;
        args[i].ascii = ascii;

        // Create the thread
        pthread_create(&threads[i], NULL, text_to_ascii, &args[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < height; i++) {
        free(ascii[i]);
    }
    free(ascii);

    return EXIT_SUCCESS;
}