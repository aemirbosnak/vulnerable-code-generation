//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 5
#define BUF_SIZE 1024

// Image structure
typedef struct {
    int width;
    int height;
    int numChannels;
    int pixelSize;
    unsigned char* data;
} Image;

// Global variables
Image* image;
pthread_mutex_t mutex;
int numThreads = 0;

// Function prototypes
void* imageThread(void* arg);
int getInput(char* prompt);
void printImage(Image* image);
void* imageThread(void* arg) {
    int threadId = *(int*)arg;
    int start = threadId * image->width / numThreads;
    int end = (threadId + 1) * image->width / numThreads;
    unsigned char* buffer = (unsigned char*)malloc(image->width * image->pixelSize);
    memset(buffer, 0, image->width * image->pixelSize);
    pthread_mutex_lock(&mutex);
    int totalPixels = 0;
    while (start < image->width && end < image->width) {
        int pixel = getInput("Enter pixel value: ");
        if (pixel > 255 || pixel < 0) {
            printf("Invalid pixel value\n");
            continue;
        }
        memcpy(&buffer[totalPixels * image->pixelSize], &pixel, image->pixelSize);
        totalPixels++;
        start++;
        end++;
    }
    pthread_mutex_unlock(&mutex);
    free(buffer);
    return NULL;
}

int getInput(char* prompt) {
    printf("%s", prompt);
    fflush(stdout);
    return getchar();
}

void printImage(Image* image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%d", image->data[i * image->width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Initialize global variables
    image = (Image*)malloc(sizeof(Image));
    image->width = 640;
    image->height = 480;
    image->numChannels = 3;
    image->pixelSize = image->width * image->numChannels;
    image->data = (unsigned char*)malloc(image->width * image->height * image->numChannels);

    // Create mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize threads
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, imageThread, &i);
    }

    // Wait for all threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the modified image
    printImage(image);

    // Clean up
    free(image->data);
    pthread_mutex_destroy(&mutex);
    return 0;
}