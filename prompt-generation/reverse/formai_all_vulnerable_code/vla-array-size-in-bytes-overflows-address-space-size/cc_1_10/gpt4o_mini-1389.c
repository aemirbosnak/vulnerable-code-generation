//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

// Dimensions of the fractal image
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct {
    double min_real;
    double max_real;
    double min_imag;
    double max_imag;
    int thread_id;
} player_data;

void *generate_fractal(void *arg) {
    player_data *data = (player_data *)arg;
    int thread_id = data->thread_id;
    uint8_t *img = (uint8_t *)malloc(WIDTH * HEIGHT * 3); // RGB Image

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double real = data->min_real + (data->max_real - data->min_real) * x / (WIDTH - 1);
            double imag = data->min_imag + (data->max_imag - data->min_imag) * y / (HEIGHT - 1);
            double c_real = real;
            double c_imag = imag;
            int iteration = 0;

            while (iteration < MAX_ITER) {
                double new_real = c_real * c_real - c_imag * c_imag + real;
                double new_imag = 2 * c_real * c_imag + imag;
                c_real = new_real;
                c_imag = new_imag;

                if (c_real * c_real + c_imag * c_imag > 4.0) break;
                iteration++;
            }

            // Color the pixel based on the number of iterations
            int pixel_index = (y * WIDTH + x) * 3;
            if (iteration == MAX_ITER) {
                img[pixel_index + 0] = 0; // R
                img[pixel_index + 1] = 0; // G
                img[pixel_index + 2] = 0; // B
            } else {
                img[pixel_index + 0] = iteration % 256; // R
                img[pixel_index + 1] = (iteration * 2) % 256; // G
                img[pixel_index + 2] = (iteration * 3) % 256; // B
            }
        }
    }

    // Save the generated fractal to a PPM file
    char filename[30];
    sprintf(filename, "fractal_%d.ppm", thread_id);
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(img, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    free(img);
    return NULL;
}

int main() {
    int player_count;
    printf("Enter the number of players (threads): ");
    scanf("%d", &player_count);

    pthread_t threads[player_count];
    player_data players[player_count];
    
    for (int i = 0; i < player_count; i++) {
        printf("Player %d, enter min real, max real, min imag, max imag:\n", i + 1);
        scanf("%lf %lf %lf %lf", &players[i].min_real, &players[i].max_real, &players[i].min_imag, &players[i].max_imag);
        players[i].thread_id = i + 1; // Keep track of the thread ID
        pthread_create(&threads[i], NULL, generate_fractal, (void *)&players[i]);
    }

    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Fractal images generated for all players.\n");
    return 0;
}