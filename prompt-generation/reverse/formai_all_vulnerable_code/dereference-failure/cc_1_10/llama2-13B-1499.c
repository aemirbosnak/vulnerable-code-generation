//LLAMA2-13B DATASET v1.0 Category: Game ; Style: visionary
// The Visionary's Journey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int size;
    char color;
} Particle;

typedef struct {
    Particle *particles;
    int num_particles;
} System;

System *create_system(int size) {
    System *sys = (System *) malloc(sizeof(System));
    sys->particles = (Particle *) malloc(size * sizeof(Particle));
    sys->num_particles = size;
    for (int i = 0; i < size; i++) {
        sys->particles[i].x = rand() % WIDTH;
        sys->particles[i].y = rand() % HEIGHT;
        sys->particles[i].size = 10 + (rand() % 20);
        sys->particles[i].color = (rand() % 2) ? 1 : 0;
    }
    return sys;
}

void update_system(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *p = &sys->particles[i];
        p->x += (rand() % 2) - (rand() % 2);
        p->y += (rand() % 2) - (rand() % 2);
        p->size += (rand() % 5) - (rand() % 5);
        if (p->x < 0 || p->x >= WIDTH || p->y < 0 || p->y >= HEIGHT) {
            p->x = WIDTH / 2;
            p->y = HEIGHT / 2;
            p->size = 10 + (rand() % 20);
        }
    }
}

void render_system(System *sys) {
    for (int i = 0; i < sys->num_particles; i++) {
        Particle *p = &sys->particles[i];
        printf("[%d, %d] %d\n", p->x, p->y, p->size);
    }
}

int main() {
    System *sys = create_system(1000);
    update_system(sys);
    render_system(sys);
    return 0;
}