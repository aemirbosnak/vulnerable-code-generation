//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define G 6.673e-11 // gravitational constant
#define WINDOW_X 500 // display window height
#define WINDOW_Y 500 // display window width
#define DELAY 50000 // delay between each simulation update

typedef struct Planet {
    double mass;
    double x; // x coordinate
    double y; // y coordinate
    double vx; // velocity in the x direction
    double vy; // velocity in the y direction
} Planet;

int numPlanets;
Planet *planets;

void updatePosition(int i) {
    double ax = 0;
    double ay = 0;

    // calculate acceleration due to gravity from all other planets
    for (int j = 0; j < numPlanets; j++) {
        if (i == j) { // skip if planet is same as current planet
            continue;
        }

        double dx = planets[j].x - planets[i].x;
        double dy = planets[j].y - planets[i].y;

        double r = sqrt(dx*dx + dy*dy);
        double f = G * planets[i].mass * planets[j].mass / (r*r);

        ax += f * dx / r / planets[i].mass;
        ay += f * dy / r / planets[i].mass;
    }

    // update velocity and position based on acceleration
    planets[i].vx += ax;
    planets[i].vy += ay;
    planets[i].x += planets[i].vx;
    planets[i].y += planets[i].vy;

    // handle boundary conditions (wrap around screen)
    if (planets[i].x >= WINDOW_X) {
        planets[i].x -= WINDOW_X;
    } else if (planets[i].x < 0) {
        planets[i].x += WINDOW_X;
    }

    if (planets[i].y >= WINDOW_Y) {
        planets[i].y -= WINDOW_Y;
    } else if (planets[i].y < 0) {
        planets[i].y += WINDOW_Y;
    }
}

void updatePositions() {
    for (int i = 0; i < numPlanets; i++) {
        updatePosition(i);
    }
}

void drawPlanets() {
    printf("\033[2J"); // clear screen
    for (int i = 0; i < numPlanets; i++) {
        printf("\033[%d;%dH", (int)planets[i].x, (int)planets[i].y); // move cursor to planet location
        printf("O"); // draw planet
    }
    fflush(stdout);
}

void createRandomPlanets(int n) {
    planets = (Planet*) malloc(n * sizeof(Planet));
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        double x = rand() % WINDOW_X; // random x coordinate
        double y = rand() % WINDOW_Y; // random y coordinate
        double mass = rand() % 10 + 1; // random mass between 1 and 10

        double angle = (double) rand() / RAND_MAX * 2 * M_PI;
        double speed = rand() % 5 + 1; // random speed between 1 and 5

        planets[i].x = x;
        planets[i].y = y;
        planets[i].mass = mass;
        planets[i].vx = speed * cos(angle);
        planets[i].vy = speed * sin(angle);
    }

    numPlanets = n;
}

int main() {
    createRandomPlanets(5);

    while (true) {
        drawPlanets();
        updatePositions();
        usleep(DELAY);
    }

    free(planets);
    return 0;
}