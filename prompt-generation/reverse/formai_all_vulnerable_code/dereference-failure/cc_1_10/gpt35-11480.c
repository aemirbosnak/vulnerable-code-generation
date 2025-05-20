//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/* Image dimensions */
#define WIDTH 800
#define HEIGHT 600

/* Pixel data struct */
typedef struct {
    unsigned char r, g, b;
} Pixel;

/* Image struct */
typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

/* Thread arguments struct */
typedef struct {
    Image *image;
    int start;
    int end;
} ThreadArgs;

/* Image editing function */
void *editImage(void *args) {
    /* Extract arguments */
    ThreadArgs *threadArgs = (ThreadArgs *)args;
    Image *image = threadArgs->image;
    int start = threadArgs->start;
    int end = threadArgs->end;
    
    /* Apply filter to pixels in range */
    for (int i = start; i < end; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        Pixel *p = &image->pixels[i];
        p->r = (255 - p->r);
        p->g = (255 - p->g);
        p->b = (255 - p->b);
    }
    
    /* Free arguments */
    free(threadArgs);
    
    /* Return a success status */
    return NULL;
}

/* Main function */
int main() {
    /* Allocate image */
    Image *image = (Image *)malloc(sizeof(Image));
    
    /* Initialize pixels */
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        Pixel *p = &image->pixels[i];
        p->r = (255 * x) / WIDTH;
        p->g = (255 * y) / HEIGHT;
        p->b = 0;
    }
    
    /* Create threads */
    pthread_t thread1, thread2;
    int half = WIDTH * HEIGHT / 2;
    ThreadArgs *args1 = (ThreadArgs *)malloc(sizeof(ThreadArgs));
    args1->image = image;
    args1->start = 0;
    args1->end = half;
    ThreadArgs *args2 = (ThreadArgs *)malloc(sizeof(ThreadArgs));
    args2->image = image;
    args2->start = half;
    args2->end = WIDTH * HEIGHT;
    pthread_create(&thread1, NULL, editImage, args1);
    pthread_create(&thread2, NULL, editImage, args2);
    
    /* Wait for threads */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    /* Save the image */
    FILE *file = fopen("output.ppm", "wb");
    fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image->pixels, sizeof(Pixel), WIDTH * HEIGHT, file);
    fclose(file);
    
    /* Free image */
    free(image);
    
    /* Exit */
    return 0;
}