//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    int thread_id, start, end;
    Pixel *pixels;
} ThreadArgs;

void *greyscale(void *thread_args) {
    ThreadArgs *args = (ThreadArgs*) thread_args;
    for (int i = args->start; i < args->end; i++) {
        unsigned char grey = (args->pixels[i].red + args->pixels[i].green + args->pixels[i].blue) / 3;
        args->pixels[i].red = grey;
        args->pixels[i].green = grey;
        args->pixels[i].blue = grey;
    }
    printf("Thread %d finished processing pixels %d to %d\n", args->thread_id, args->start, args->end);
    return NULL;
}

void save_image(char *filename, Pixel *pixels) {
    FILE *fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Error: unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(&pixels[i].red, 1, 1, fp);
        fwrite(&pixels[i].green, 1, 1, fp);
        fwrite(&pixels[i].blue, 1, 1, fp);
    }
    fclose(fp);
    printf("Image saved as %s\n", filename);
}

int main() {
    Pixel *pixels = (Pixel*) malloc(sizeof(Pixel) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].red = rand() % 256;
        pixels[i].green = rand() % 256;
        pixels[i].blue = rand() % 256;
    }
    int num_threads = 4;
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].thread_id = i;
        thread_args[i].start = i * WIDTH * HEIGHT / num_threads;
        thread_args[i].end = (i + 1) * WIDTH * HEIGHT / num_threads;
        thread_args[i].pixels = pixels;
        pthread_create(&threads[i], NULL, greyscale, (void*) &thread_args[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    save_image("output.ppm", pixels);
    free(pixels);
    return 0;
}