//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 32
#define HEIGHT 32
#define MAX_COLOR 255

unsigned char image[WIDTH][HEIGHT][3];

struct Pixel{
    int x;
    int y;
};

void* fill_pixel(void* argument){
    struct Pixel* pixel = (struct Pixel*) argument;
    int x = pixel->x;
    int y = pixel->y;

    // Fill pixel with random colors
    image[x][y][0] = rand() % (MAX_COLOR+1);
    image[x][y][1] = rand() % (MAX_COLOR+1);
    image[x][y][2] = rand() % (MAX_COLOR+1);

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[WIDTH][HEIGHT];

    // Create threads to fill pixels
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            struct Pixel* pixel = malloc(sizeof(struct Pixel));
            pixel->x = x;
            pixel->y = y;
            pthread_create(&threads[x][y], NULL, fill_pixel, (void*) pixel);
        }
    }

    // Wait for all threads to finish
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            pthread_join(threads[x][y], NULL);
        }
    }

    // Output image
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            printf(" %02x%02x%02x", image[x][y][0], image[x][y][1], image[x][y][2]);
        }
        printf("\n");
    }

    return 0;
}