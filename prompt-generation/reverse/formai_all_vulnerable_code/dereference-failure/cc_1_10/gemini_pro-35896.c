//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 8
#define MAX_CHAR_WIDTH 10
#define MAX_CHAR_HEIGHT 10

typedef struct {
    char *text;
    int width;
    int height;
    char **ascii_art;
} TextToAsciiArtArgs;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int thread_count = 0;
int completed_threads = 0;
bool done = false;

void *generate_ascii_art(void *args) {
    TextToAsciiArtArgs *a = (TextToAsciiArtArgs *)args;
    int i, j;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Increment the thread count
    thread_count++;

    // Allocate memory for the ASCII art
    a->ascii_art = (char **)malloc(sizeof(char *) * a->height);
    for (i = 0; i < a->height; i++) {
        a->ascii_art[i] = (char *)malloc(sizeof(char) * (a->width + 1));
    }

    // Set all the ASCII art characters to spaces
    for (i = 0; i < a->height; i++) {
        for (j = 0; j < a->width; j++) {
            a->ascii_art[i][j] = ' ';
        }
        a->ascii_art[i][a->width] = '\0';
    }

    // Generate the ASCII art
    int char_width = a->width / strlen(a->text);
    int char_height = a->height / strlen(a->text);
    int char_x, char_y;
    for (i = 0; i < strlen(a->text); i++) {
        char_x = i * char_width;
        char_y = 0;
        for (j = 0; j < 8; j++) {
            int bit = (a->text[i] >> j) & 1;
            if (bit) {
                int k, l;
                for (k = 0; k < char_width; k++) {
                    for (l = 0; l < char_height; l++) {
                        a->ascii_art[char_y + l][char_x + k] = '*';
                    }
                }
            }
            char_y += char_height;
        }
    }

    // Increment the completed thread count
    completed_threads++;

    // Signal all waiting threads
    pthread_cond_broadcast(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Get the text from the command line
    char *text = argv[1];

    // Calculate the width and height of the ASCII art
    int width = strlen(text) * MAX_CHAR_WIDTH;
    int height = strlen(text) * MAX_CHAR_HEIGHT;

    // Create an array of thread arguments
    TextToAsciiArtArgs args[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        args[i].text = text;
        args[i].width = width;
        args[i].height = height;
    }

    // Create the threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_ascii_art, &args[i]);
    }

    // Wait for all the threads to complete
    while (!done) {
        pthread_mutex_lock(&mutex);
        if (completed_threads == MAX_THREADS) {
            done = true;
            pthread_cond_broadcast(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", args[0].ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < height; i++) {
        free(args[0].ascii_art[i]);
    }
    free(args[0].ascii_art);

    // Exit the program
    return 0;
}