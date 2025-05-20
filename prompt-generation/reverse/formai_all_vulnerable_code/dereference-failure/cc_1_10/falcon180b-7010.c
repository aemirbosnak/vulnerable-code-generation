//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

struct Particle {
    double x, y, z, vx, vy, vz, ax, ay, az, mass;
};

void calculate_acceleration(struct Particle *p1, struct Particle *p2, double r) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r2 = r * r;
    double r3 = r2 * r;

    p1->ax += G * p2->mass * dx / (r2 * r3);
    p1->ay += G * p2->mass * dy / (r2 * r3);
    p1->az += G * p2->mass * dz / (r2 * r3);

    p2->ax -= G * p1->mass * dx / (r2 * r3);
    p2->ay -= G * p1->mass * dy / (r2 * r3);
    p2->az -= G * p1->mass * dz / (r2 * r3);
}

void update_position(struct Particle *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void update_velocity(struct Particle *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

int main() {
    int num_particles = 1000;
    struct Particle *particles = malloc(num_particles * sizeof(struct Particle));

    for (int i = 0; i < num_particles; i++) {
        particles[i].x = rand() % 1000 - 500;
        particles[i].y = rand() % 1000 - 500;
        particles[i].z = rand() % 1000 - 500;
        particles[i].vx = rand() % 10 - 5;
        particles[i].vy = rand() % 10 - 5;
        particles[i].vz = rand() % 10 - 5;
        particles[i].mass = rand() % 100;
    }

    double dt = 0.01;

    for (int i = 0; i < num_particles; i++) {
        for (int j = i + 1; j < num_particles; j++) {
            double r = sqrt(pow(particles[j].x - particles[i].x, 2) +
                           pow(particles[j].y - particles[i].y, 2) +
                           pow(particles[j].z - particles[i].z, 2));

            if (r < 100) {
                calculate_acceleration(&particles[i], &particles[j], r);
            }
        }

        update_position(&particles[i], dt);
        update_velocity(&particles[i], dt);
    }

    free(particles);

    return 0;
}