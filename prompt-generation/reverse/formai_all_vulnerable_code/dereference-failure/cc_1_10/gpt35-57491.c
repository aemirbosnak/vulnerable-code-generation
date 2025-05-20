//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_THREADS 8

typedef struct {
    char pixels[HEIGHT][WIDTH];
} Image;

char ascii_chars[] = {' ', '.', '\'', ':', 'o', '&', '8', '#', '@'};

void convert_to_ascii(Image *image, int start_x, int start_y, int end_x, int end_y) {
    for (int i = start_y; i < end_y; i++) {
        for (int j = start_x; j < end_x; j++) {
            int shade = ((int)image->pixels[i][j] * 9) / 255;
            printf("%c", ascii_chars[shade]);
        }
        printf("\n");
    }
}

void *thread_func(void *arg) {
    int *params = (int *)arg;
    int start_x = params[0];
    int start_y = params[1];
    int end_x = params[2];
    int end_y = params[3];
    convert_to_ascii((Image *)params[4], start_x, start_y, end_x, end_y);
    pthread_exit(NULL);
}

int main() {
    Image *image = malloc(sizeof(Image));
    char test_pixels[HEIGHT][WIDTH] = {
        {0, 64, 64, 128, 255},
        {0, 20, 46, 90, 132},
        {0, 23, 56, 99, 143},
        {0, 26, 62, 110, 165},
        {0, 29, 69, 121, 181},
        {0, 31, 76, 132, 198}
    };
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image->pixels[i][j] = test_pixels[i][j];
        }
    }

    pthread_t threads[MAX_THREADS];
    int x_step = WIDTH / MAX_THREADS;
    int params[MAX_THREADS][5];
    for (int i = 0; i < MAX_THREADS; i++) {
        params[i][0] = x_step * i;
        params[i][1] = 0;
        params[i][2] = x_step * (i + 1);
        params[i][3] = HEIGHT;
        params[i][4] = (int)image;
        pthread_create(&threads[i], NULL, thread_func, (void *)&params[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}