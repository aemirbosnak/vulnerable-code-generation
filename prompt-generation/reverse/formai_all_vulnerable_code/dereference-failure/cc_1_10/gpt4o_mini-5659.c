//GPT-4o-mini DATASET v1.0 Category: Pixel Art Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16
#define MAX_COLORS 6

typedef struct {
    int row;
    int col;
    char color;
} Pixel;

char colors[MAX_COLORS] = {' ', '.', ':', '-', '=', '#', '@'};

void *draw_pixel(void *arg) {
    Pixel *pixel = (Pixel *)arg;
    printf("\033[%d;%dH%c", pixel->row + 1, pixel->col + 1, pixel->color);
    fflush(stdout);
    free(pixel);
    return NULL;
}

char get_random_color() {
    return colors[rand() % MAX_COLORS];
}

int main() {
    srand(time(NULL));
    pthread_t threads[WIDTH * HEIGHT];

    printf("\033[2J"); // Clear screen
    printf("\033[0;0H"); // Move cursor to the top-left corner

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            Pixel *pixel = (Pixel *)malloc(sizeof(Pixel));
            pixel->row = row;
            pixel->col = col;
            pixel->color = get_random_color();

            if (pthread_create(&threads[row * WIDTH + col], NULL, draw_pixel, pixel) != 0) {
                fprintf(stderr, "Error creating thread\n");
                return 1;
            }

            usleep(10000); // Sleep for 10 milliseconds to simulate asynchronous behavior
        }
    }

    // Waiting for all threads to finish
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\033[%d;%dH", HEIGHT + 2, 1); // Move cursor down for final message
    printf("Pixel art generation completed! Press ENTER to exit...");
    getchar();

    return 0;
}