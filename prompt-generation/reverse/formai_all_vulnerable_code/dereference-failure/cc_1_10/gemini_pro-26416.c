//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

#define WIDTH 1024
#define HEIGHT 768
#define THREAD_COUNT 8

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

typedef struct {
    Pixel **pixels;
    int width;
    int height;
} Image;

Image *image;
pthread_mutex_t image_mutex;
bool done;

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;

    while (!done) {
        pthread_mutex_lock(&image_mutex);

        int x = rand() % image->width;
        int y = rand() % image->height;
        image->pixels[y][x].color = rand() % 0xffffff;

        pthread_mutex_unlock(&image_mutex);

        usleep(10000);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    image = malloc(sizeof(Image));
    image->pixels = malloc(sizeof(Pixel *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        image->pixels[i] = malloc(sizeof(Pixel) * WIDTH);
    }
    image->width = WIDTH;
    image->height = HEIGHT;

    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];

    pthread_mutex_init(&image_mutex, NULL);

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    getchar();

    done = true;

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&image_mutex);

    for (int i = 0; i < HEIGHT; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);

    return 0;
}