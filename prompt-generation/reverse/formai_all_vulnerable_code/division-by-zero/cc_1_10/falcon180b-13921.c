//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <omp.h>

#define MAX_THREADS 8
#define MAX_PIXELS 1000000

int image[MAX_PIXELS];
int image_width, image_height;
int num_threads;
pthread_t threads[MAX_THREADS];

void *thread_func(void *arg) {
    int start = *(int *) arg;
    int end = start + (int) ceil((double) image_width / num_threads);
    for (int i = start; i < end; i++) {
        if (i < 0 || i >= image_width) continue;
        for (int j = 0; j < image_height; j++) {
            int index = j * image_width + i;
            image[index] = 0;
        }
    }
    return NULL;
}

int main() {
    printf("Enter image width: ");
    scanf("%d", &image_width);
    printf("Enter image height: ");
    scanf("%d", &image_height);
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];
    int chunk_size = image_width / num_threads;

    for (int i = 0; i < num_threads; i++) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1)? image_width : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, thread_func, (void *) &start);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Image editing completed!\n");
    return 0;
}