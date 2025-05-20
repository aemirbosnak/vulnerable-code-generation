//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 20
#define G 9.81
#define BALL_RADIUS 1.0
#define BORDER 1.5

typedef struct {
    double x, y, vx, vy;
} particle;

void init_particles(particle *p, int num) {
    int i;
    for (i = 0; i < num; ++i) {
        p[i].x = WIDTH / 2 + rand() % (WIDTH - 1);
        p[i].y = HEIGHT - 2 - rand() % 4;
        p[i].vx = (rand() % 2 == 0) ? -1 : 1;
        p[i].vy = -10;
    }
}

void wall_collision(particle *p, double width, double height) {
    if (p->x < 0) p->x = -p->x;
    if (p->x > width) p->x = 2 * width - p->x;
    if (p->y < 0) {
        p->y = -p->y;
        p->vy = -p->vy;
    }
    if (p->y > height) {
        p->y = 2 * height - p->y;
        p->vy = -G - 2 * BORDER;
    }
}

void update_particles(particle *p, int num, double dt) {
    int i;
    for (i = 0; i < num; ++i) {
        particle old = p[i];
        p[i].x += p[i].vx * dt;
        p[i].y += p[i].vy * dt;

        wall_collision(&p[i], WIDTH, HEIGHT);

        p[i].x += 0.5 * p[i].vx * dt;
        p[i].y += 0.5 * p[i].vy * dt;
        wall_collision(&p[i], WIDTH, HEIGHT);

        p[i].x = old.x + 0.5 * (p[i].vx + old.vx) * dt;
        p[i].y = old.y + 0.5 * (p[i].vy + old.vy) * dt;
        wall_collision(&p[i], WIDTH, HEIGHT);

        p[i].vx += 0.5 * dt * (p[i].vy + old.vy);
        p[i].vy += G * dt;
    }
}

int main() {
    srand(time(NULL));
    int num_particles = 50;
    particle *particles = calloc(num_particles, sizeof(particle));

    init_particles(particles, num_particles);

    double dt = 0.01;
    int frame_count = 0;

    while (1) {
        double elapsed = 0.0;
        while (elapsed < dt) {
            update_particles(particles, num_particles, dt);
            elapsed += 0.001;
        }
        frame_count++;

        if (frame_count % 100 == 0) {
            printf("Frame %d: ", frame_count);
            int i;
            for (i = 0; i < num_particles; ++i) {
                printf("(%lf, %lf) ", particles[i].x, particles[i].y);
            }
            printf("\n");
        }
    }

    free(particles);
    return 0;
}