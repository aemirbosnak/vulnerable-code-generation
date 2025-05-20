//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

typedef struct {
    int x, y;
    int dx, dy;
    int color;
} Particle;

void init(int width, int height) {
    srand(time(NULL));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            printf("%c%c%c", r, g, b);
        }
        printf("\n");
    }
}

void update(Particle *particles, int count, int width, int height) {
    for (int i = 0; i < count; i++) {
        particles[i].x += particles[i].dx;
        particles[i].y += particles[i].dy;

        if (particles[i].x < 0 || particles[i].x >= width) {
            particles[i].dx = -particles[i].dx;
        }

        if (particles[i].y < 0 || particles[i].y >= height) {
            particles[i].dy = -particles[i].dy;
        }
    }
}

void draw(Particle *particles, int count, int width, int height) {
    for (int i = 0; i < count; i++) {
        int x = particles[i].x + (int)(sin(particles[i].dx * M_PI / 180.0) * particles[i].dx);
        int y = particles[i].y + (int)(sin(particles[i].dy * M_PI / 180.0) * particles[i].dy);

        if (x >= 0 && x < width && y >= 0 && y < height) {
            printf("%c%c%c ", particles[i].color >> 16 & 0xFF, particles[i].color >> 8 & 0xFF, particles[i].color & 0xFF);
        }
    }
}

int main() {
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;
    int count = 100;

    Particle *particles = malloc(count * sizeof(Particle));

    for (int i = 0; i < count; i++) {
        particles[i].x = rand() % width;
        particles[i].y = rand() % height;
        particles[i].dx = rand() % 10 - 5;
        particles[i].dy = rand() % 10 - 5;
        particles[i].color = rand() % 0x1000000;
    }

    int delay = 10;

    while (1) {
        init(width, height);
        draw(particles, count, width, height);
        printf("\033[H");
        update(particles, count, width, height);
        usleep(delay * 1000);
    }

    return 0;
}