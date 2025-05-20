//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH  800
#define HEIGHT 600

typedef struct {
    int x, y;
    int size;
    int speed;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
    int max_particles;
} System;

System *init_system(int max_particles) {
    System *sys = malloc(sizeof(System));
    sys->particles = malloc(max_particles * sizeof(Particle));
    sys->num_particles = 0;
    sys->max_particles = max_particles;
    return sys;
}

void update_system(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *p = &sys->particles[i];
        p->x += p->speed;
        if (p->x >= WIDTH) {
            p->x = 0;
            p->y += p->speed;
        }
        if (p->y >= HEIGHT) {
            p->y = 0;
            p->speed = random() % 20 - 10;
        }
    }
}

void draw_system(System *sys, int x, int y) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *p = &sys->particles[i];
        printf("%d, %d, %d, %d\n", p->x, p->y, p->size, p->speed);
    }
}

int main() {
    System *sys = init_system(100);
    for (int i = 0; i < 100; i++) {
        Particle p = {random() % WIDTH, random() % HEIGHT, random() % 10 + 1, random() % 20 - 10};
        sys->particles[sys->num_particles++] = p;
    }
    update_system(sys);
    draw_system(sys, 0, 0);
    return 0;
}