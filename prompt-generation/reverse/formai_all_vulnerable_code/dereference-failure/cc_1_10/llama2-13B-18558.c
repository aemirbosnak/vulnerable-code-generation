//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x;
    int y;
    int speedX;
    int speedY;
} Particle;

typedef struct {
    Particle particles[100];
    int numParticles;
} Simulation;

Simulation *initSimulation(void) {
    Simulation *simulation = (Simulation *)malloc(sizeof(Simulation));
    for (int i = 0; i < 100; i++) {
        simulation->particles[i].x = rand() % WIDTH;
        simulation->particles[i].y = rand() % HEIGHT;
        simulation->particles[i].speedX = rand() % 2 - 1;
        simulation->particles[i].speedY = rand() % 2 - 1;
    }
    simulation->numParticles = 100;
    return simulation;
}

void updateSimulation(Simulation *simulation) {
    for (int i = 0; i < simulation->numParticles; i++) {
        simulation->particles[i].x += simulation->particles[i].speedX;
        simulation->particles[i].y += simulation->particles[i].speedY;
        if (simulation->particles[i].x >= WIDTH || simulation->particles[i].x < 0 ||
                simulation->particles[i].y >= HEIGHT || simulation->particles[i].y < 0) {
            simulation->particles[i].speedX = -simulation->particles[i].speedX;
            simulation->particles[i].speedY = -simulation->particles[i].speedY;
        }
    }
}

void drawSimulation(Simulation *simulation) {
    for (int i = 0; i < simulation->numParticles; i++) {
        printf("(%d, %d) ", simulation->particles[i].x, simulation->particles[i].y);
    }
    printf("\n");
}

int main(void) {
    Simulation *simulation = initSimulation();
    for (int i = 0; i < 1000; i++) {
        updateSimulation(simulation);
        drawSimulation(simulation);
    }
    return 0;
}