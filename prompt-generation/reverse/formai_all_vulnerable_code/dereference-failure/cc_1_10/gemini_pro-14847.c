//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct particle {
    double m;
    double x;
    double y;
    double vx;
    double vy;
};

struct system {
    int n;
    struct particle *p;
};

void init_system(struct system *s, int n) {
    s->n = n;
    s->p = malloc(n * sizeof(struct particle));
    for (int i = 0; i < n; i++) {
        s->p[i].m = 1;
        s->p[i].x = 0;
        s->p[i].y = 0;
        s->p[i].vx = 0;
        s->p[i].vy = 0;
    }
}

void free_system(struct system *s) {
    free(s->p);
}

void update(struct system *s, double dt) {
    for (int i = 0; i < s->n; i++) {
        for (int j = 0; j < s->n; j++) {
            if (i != j) {
                double dx = s->p[i].x - s->p[j].x;
                double dy = s->p[i].y - s->p[j].y;
                double r = sqrt(dx * dx + dy * dy);
                double F = (s->p[i].m * s->p[j].m) / (r * r);
                double ax = F * dx / r;
                double ay = F * dy / r;
                s->p[i].vx += ax * dt;
                s->p[i].vy += ay * dt;
            }
        }
    }

    for (int i = 0; i < s->n; i++) {
        s->p[i].x += s->p[i].vx * dt;
        s->p[i].y += s->p[i].vy * dt;
    }
}

int main() {
    struct system s;
    init_system(&s, 100);
    for (int i = 0; i < 1000; i++) {
        update(&s, 0.01);
    }
    free_system(&s);
    return 0;
}