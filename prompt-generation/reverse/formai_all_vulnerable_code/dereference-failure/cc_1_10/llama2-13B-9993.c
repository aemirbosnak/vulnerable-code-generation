//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int size;
} Particle;

typedef struct {
    Particle* particles;
    int num_particles;
} Universe;

void init_universe(Universe* u, int num_particles) {
    u->particles = calloc(num_particles, sizeof(Particle));
    u->num_particles = num_particles;

    for (int i = 0; i < num_particles; i++) {
        Particle* p = &u->particles[i];
        p->x = (rand() % WIDTH) - WIDTH / 2;
        p->y = (rand() % HEIGHT) - HEIGHT / 2;
        p->size = 10 + (rand() % 20);
    }
}

void update_particles(Universe* u) {
    for (int i = 0; i < u->num_particles; i++) {
        Particle* p = &u->particles[i];
        p->x += (rand() % 2) - 1;
        p->y += (rand() % 2) - 1;

        if (p->x < 0 || p->x >= WIDTH || p->y < 0 || p->y >= HEIGHT) {
            p->size *= 2;
        }
    }
}

void draw_particles(Universe* u) {
    for (int i = 0; i < u->num_particles; i++) {
        Particle* p = &u->particles[i];
        printf("%d, %d, %d\n", p->x, p->y, p->size);
    }
}

int main() {
    Universe u;
    init_universe(&u, 100);

    for (int i = 0; i < 100; i++) {
        update_particles(&u);
        draw_particles(&u);
    }

    return 0;
}