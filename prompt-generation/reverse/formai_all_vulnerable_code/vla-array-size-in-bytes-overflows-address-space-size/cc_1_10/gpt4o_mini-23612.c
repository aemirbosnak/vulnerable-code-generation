//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct {
    int id;
    int startY;
    int endY;
    unsigned char* image;
    double zoom;
    double offsetX;
    double offsetY;
} FractalData;

void* generateFractal(void* arg) {
    FractalData* data = (FractalData*)arg;
    int id = data->id;
    int startY = data->startY;
    int endY = data->endY;
    unsigned char* image = data->image;
    double zoom = data->zoom;
    double offsetX = data->offsetX;
    double offsetY = data->offsetY;

    for (int y = startY; y < endY; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + offsetX;
            double zy = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + offsetY;
            int i;
            for (i = 0; i < MAX_ITER; i++) {
                double tmp = zx * zx - zy * zy + (offsetX);
                zy = 2.0 * zx * zy + (offsetY);
                zx = tmp;
                if (zx * zx + zy * zy > 4.0)
                    break;
            }
            int color = (i == MAX_ITER) ? 0 : (i % 256);
            image[(y * WIDTH + x) * 3 + 0] = color; // Red
            image[(y * WIDTH + x) * 3 + 1] = color; // Green
            image[(y * WIDTH + x) * 3 + 2] = color; // Blue
        }
    }
    printf("Player %d finished processing from row %d to %d\n", id, startY, endY);
    return NULL;
}

void saveImage(const char* filename, unsigned char* image) {
    FILE* f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 1, WIDTH * HEIGHT * 3, f);
    fclose(f);
}

int main() {
    unsigned char* image = malloc(WIDTH * HEIGHT * 3);
    if (!image) {
        fprintf(stderr, "Failed to allocate memory for image\n");
        return 1;
    }

    int numPlayers;
    printf("Enter number of players (threads) for fractal generation: ");
    scanf("%d", &numPlayers);

    pthread_t threads[numPlayers];
    FractalData threadData[numPlayers];

    double zoom = 1.0, offsetX = -0.5, offsetY = 0;
    printf("Using zoom: %f, offsetX: %f, offsetY: %f\n", zoom, offsetX, offsetY);

    int rowsPerPlayer = HEIGHT / numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        threadData[i].id = i;
        threadData[i].startY = i * rowsPerPlayer;
        threadData[i].endY = (i + 1) * rowsPerPlayer;
        if (i == numPlayers - 1) {
            threadData[i].endY = HEIGHT; // Handle remaining rows for last player
        }
        threadData[i].image = image;
        threadData[i].zoom = zoom;
        threadData[i].offsetX = offsetX;
        threadData[i].offsetY = offsetY;

        pthread_create(&threads[i], NULL, generateFractal, &threadData[i]);
    }

    for (int i = 0; i < numPlayers; i++) {
        pthread_join(threads[i], NULL);
    }

    saveImage("fractal.ppm", image);
    free(image);
    printf("Fractal generated and saved as fractal.ppm\n");
    return 0;
}