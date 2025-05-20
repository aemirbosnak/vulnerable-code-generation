//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 8

typedef struct {
    char *text;
    int width;
    int height;
    char **art;
} text_art_t;

void *generate_art(void *arg) {
    text_art_t *ta = (text_art_t *)arg;

    // Create the ASCII art representation of the text
    ta->art = (char **)malloc(ta->height * sizeof(char *));
    for (int i = 0; i < ta->height; i++) {
        ta->art[i] = (char *)malloc(ta->width * sizeof(char));
        memset(ta->art[i], ' ', ta->width);
    }

    int x = 0, y = 0;
    for (int i = 0; i < strlen(ta->text); i++) {
        char c = ta->text[i];

        // Print the character to the ASCII art representation
        if (c == '\n') {
            y++;
            x = 0;
        } else if (c == '\t') {
            x += 4;
        } else {
            ta->art[y][x++] = c;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return -1;
    }

    // Create the text art structure
    text_art_t ta;
    ta.text = argv[1];
    ta.width = 80;
    ta.height = 25;

    // Create the thread pool
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_art, &ta);
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the ASCII art representation of the text
    for (int i = 0; i < ta.height; i++) {
        printf("%s\n", ta.art[i]);
        free(ta.art[i]);
    }
    free(ta.art);

    return 0;
}