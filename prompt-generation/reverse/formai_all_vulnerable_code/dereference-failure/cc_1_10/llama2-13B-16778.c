//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

typedef struct {
    int x;
    int y;
    int speedX;
    int speedY;
} Particle;

typedef struct {
    Particle *particles;
    int numParticles;
} Weather;

Weather *createWeather(int numParticles) {
    Weather *w = malloc(sizeof(Weather));
    w->particles = malloc(numParticles * sizeof(Particle));
    w->numParticles = numParticles;

    for (int i = 0; i < numParticles; i++) {
        Particle *p = &w->particles[i];
        p->x = rand() % WINDOW_WIDTH;
        p->y = rand() % WINDOW_HEIGHT;
        p->speedX = rand() % 2 - 1;
        p->speedY = rand() % 2 - 1;
    }

    return w;
}

void updateWeather(Weather *w) {
    for (int i = 0; i < w->numParticles; i++) {
        Particle *p = &w->particles[i];
        p->x += p->speedX;
        p->y += p->speedY;

        if (p->x < 0 || p->x >= WINDOW_WIDTH) {
            p->speedX = -p->speedX;
        }
        if (p->y < 0 || p->y >= WINDOW_HEIGHT) {
            p->speedY = -p->speedY;
        }
    }
}

void drawWeather(Weather *w, int x, int y) {
    for (int i = 0; i < w->numParticles; i++) {
        Particle *p = &w->particles[i];
        printf("%d, %d", p->x + x, p->y + y);
    }
}

int main() {
    Weather *w = createWeather(100);
    int x = 0;
    int y = 0;

    for (int i = 0; i < 1000; i++) {
        updateWeather(w);
        drawWeather(w, x, y);
        printf("\n");
    }

    return 0;
}