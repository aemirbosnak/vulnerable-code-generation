//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    int width;
    int height;
    unsigned char** image;
} Image;

void* invert(void* imageVoidPtr) {
    Image* image = (Image*) imageVoidPtr;
    int i, j;
    for(i=0; i<image->height; i++) {
        for(j=0; j<image->width; j++) {
            image->image[i][j] = ~image->image[i][j]; //invert pixel_value using bitwise NOT operator
        }
    }
    pthread_exit(NULL);
}

void* grayscale(void* imageVoidPtr) {
    Image* image = (Image*) imageVoidPtr;
    int i, j, avg;
    for(i=0; i<image->height; i++) {
        for(j=0; j<image->width; j++) {
            avg = (image->image[i][j] & 0xff) + ((image->image[i][j] >> 8) & 0xff) + ((image->image[i][j] >> 16) & 0xff); //split pixel_value into R, G, B components and calculate average
            avg /= 3;
            image->image[i][j] = (avg << 16) | (avg << 8) | avg; //combine grayscale value into a single pixel_value
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    int i, j, numThreads = 0;
    Image* image = malloc(sizeof(Image));
    FILE* file = fopen(argv[1], "rb");
    unsigned char header[54];

    fread(header, sizeof(unsigned char), 54, file); //read header information
    image->width = *(int*)&header[18];
    image->height = *(int*)&header[22];
    int padding = (4 - (image->width * 3) % 4) % 4; //calculate padding for image

    for(i=0; i<image->height; i++) {
        image->image[i] = malloc((image->width * 3) * sizeof(unsigned char)); //allocate memory for image pixels
        fread(image->image[i], sizeof(unsigned char), image->width * 3, file); //read row of pixels
        fseek(file, padding, SEEK_CUR); //skip padding bytes
    }

    fclose(file); //close image file

    pthread_t* threads = malloc(argc * sizeof(pthread_t)); //allocate memory for thread ids

    for(i=2; i<argc; i++) {
        if(strcmp(argv[i], "invert") == 0) {
            pthread_create(&threads[numThreads], NULL, invert, (void*) image); //create invert thread
            numThreads++;
        } else if(strcmp(argv[i], "grayscale") == 0) {
            pthread_create(&threads[numThreads], NULL, grayscale, (void*) image); //create grayscale thread
            numThreads++;
        }
    }

    void* status;
    for(i=0; i<numThreads; i++) {
        pthread_join(threads[i], &status); //wait for threads to finish
    }

    file = fopen(argv[2], "wb");
    fwrite(header, sizeof(unsigned char), 54, file); //write header information

    for(i=0; i<image->height; i++) {
        fwrite(image->image[i], sizeof(unsigned char), image->width * 3, file); //write row of pixels
        fwrite(0, sizeof(unsigned char), padding, file); //write padding bytes
        free(image->image[i]); //free memory for row of pixels
    }

    fclose(file); //close output file
    free(image); //free memory for image
    free(threads); //free memory for thread ids

    return 0;
}