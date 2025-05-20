//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct {
    int start_row;
    int end_row;
    unsigned char *image;
} ThreadData;

void *compute_row(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    unsigned char *image = data->image;
    
    for (int y = data->start_row; y < data->end_row; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            double zy = (y - HEIGHT / 2) / (0.5 * HEIGHT);
            int iter = 0;

            while (zx * zx + zy * zy < 4 && iter < MAX_ITER) {
                double tmp = zx * zx - zy * zy + -0.70176;  // Change these values for different fractals
                zy = 2.0 * zx * zy + 0.3842;  // Change these values for different fractals
                zx = tmp;
                iter++;
            }

            int pixel_index = (y * WIDTH + x) * 3;
            if (iter == MAX_ITER) {
                image[pixel_index] = 0;        // R
                image[pixel_index + 1] = 0;    // G
                image[pixel_index + 2] = 0;    // B
            } else {
                image[pixel_index] = (iter % 256);         // R
                image[pixel_index + 1] = (iter * 2 % 256); // G
                image[pixel_index + 2] = (iter * 4 % 256); // B
            }
        }
    }
    return NULL;
}

int main() {
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
    pthread_t threads[4];
    ThreadData threadData[4];

    int rows_per_thread = HEIGHT / 4;

    for (int i = 0; i < 4; i++) {
        threadData[i].start_row = i * rows_per_thread;
        threadData[i].end_row = (i + 1) * rows_per_thread;
        threadData[i].image = image;
        pthread_create(&threads[i], NULL, compute_row, (void *)&threadData[i]);
    }

    // Join all threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write image to a PPM file
    FILE *f = fopen("fractal.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);
    fclose(f);

    printf("Fractal generated and saved to fractal.ppm\n");

    free(image);
    return 0;
}