//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float m, x, y, vx, vy;
} particle;

particle* init_particles(int n) {
    particle* p = malloc(sizeof(particle) * n);
    for (int i = 0; i < n; i++) {
        p[i].m = rand() % 10 + 1;
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
        p[i].vx = (rand() % 100 - 50) / 10.0;
        p[i].vy = (rand() % 100 - 50) / 10.0;
    }
    return p;
}

void update_particles(particle* p, int n, float dt) {
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].vx * dt;
        p[i].y += p[i].vy * dt;
    }
}

void collide_particles(particle* p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dx = p[i].x - p[j].x;
            float dy = p[i].y - p[j].y;
            float dist = sqrt(dx * dx + dy * dy);
            if (dist < p[i].m + p[j].m) {
                float nx = dx / dist;
                float ny = dy / dist;
                float tx = p[j].vx - p[i].vx;
                float ty = p[j].vy - p[i].vy;
                float dot = nx * tx + ny * ty;
                if (dot > 0) {
                    float impulse = (2 * dot) / (p[i].m + p[j].m);
                    p[i].vx -= impulse * nx;
                    p[i].vy -= impulse * ny;
                    p[j].vx += impulse * nx;
                    p[j].vy += impulse * ny;
                }
            }
        }
    }
}

void draw_particles(particle* p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Particle %d: (%f, %f)\n", i, p[i].x, p[i].y);
    }
}

int main() {
    int n = 10;
    float dt = 0.1;
    particle* p = init_particles(n);
    for (int i = 0; i < 1000; i++) {
        update_particles(p, n, dt);
        collide_particles(p, n);
    }
    draw_particles(p, n);
    free(p);
    return 0;
}