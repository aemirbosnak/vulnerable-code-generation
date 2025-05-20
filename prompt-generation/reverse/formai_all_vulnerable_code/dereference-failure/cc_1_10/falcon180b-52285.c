//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_COLORS 8

int num_threads = 0;
pthread_t threads[MAX_THREADS];

struct thread_data {
    int id;
    int color;
};

void *draw_fibonacci(void *arg) {
    struct thread_data *data = arg;
    int id = data->id;
    int color = data->color;

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, dx = 1, dy = 0;
    int count = 0;

    while (count < 100) {
        if (x1 >= 800 || y1 >= 600 || x1 < 0 || y1 < 0) {
            dx = -dx;
            dy = -dy;
        }

        x1 += dx;
        y1 += dy;
        x2 = x1 - dy;
        y2 = y1 + dx;

        int c = count % 8;
        if (c == 0 || c == 4) {
            c = 7;
        }

        if (color == 0) {
            color = c;
        }

        if (color == 7) {
            color = 0;
        }

        count++;

        if (color == 0) {
            printf("\033[2J");
            for (int i = 0; i < 600; i++) {
                for (int j = 0; j < 800; j++) {
                    printf("\033[2;%d;%dm ", i / 25, j / 25);
                }
            }
        }

        printf("\033[%d;%dH%c", y1, x1, 219);
        fflush(stdout);

        usleep(50000);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_THREADS; i++) {
        int color = rand() % MAX_COLORS;
        pthread_create(&threads[i], NULL, draw_fibonacci, (void *)&(struct thread_data){.id = i,.color = color});
        num_threads++;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}