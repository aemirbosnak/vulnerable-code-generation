//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define THREAD_COUNT 4

struct color_code {
    char *name;
    char *hex;
};

struct color_code colors[] = {
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"},
    {"black", "#000000"},
    {"white", "#FFFFFF"},
};

pthread_t threads[THREAD_COUNT];
sem_t semaphore;

void *color_code_converter(void *arg) {
    int index = *(int *)arg;

    sem_wait(&semaphore);

    printf("%s: %s\n", colors[index].name, colors[index].hex);

    sem_post(&semaphore);

    return NULL;
}

int main(void) {
    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < THREAD_COUNT; i++) {
        int *index = malloc(sizeof(int));
        *index = i;
        pthread_create(&threads[i], NULL, color_code_converter, index);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return EXIT_SUCCESS;
}