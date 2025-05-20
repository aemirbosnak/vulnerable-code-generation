//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11

typedef struct {
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
} Body;

int main(int argc, char **argv) {
    int nbodies = 8;
    
    if ((argc > 1) && (atoi(argv[1]) > 0))
        nbodies = atoi(argv[1]);

    const double dt = 1.0 / 600.0;
    
    const double masses[] = { 1.989e30, 5.685e26, 3.725e26, 4.869e24, 6.419e23, 3.302e23, 2.858e22 };
    const double radii[] = { 6.96342e8, 2.44053e7, 7.1492e7, 6.371e6, 1.738e6, 6.027e6, 2.556e6 };
    const double x0[] = { 0.0, 0.0, 5.79e10, 1.082e11, 1.5e11, 2.279e11, 2.793e11, 3.006e11 };
    const double y0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    const double vx0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    const double vy0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

    Body bodies[nbodies];

    for (int i = 0; i < nbodies; i++) {
        bodies[i].mass = masses[i];
        bodies[i].radius = radii[i];
        bodies[i].x = x0[i];
        bodies[i].y = y0[i];
        bodies[i].vx = vx0[i];
        bodies[i].vy = vy0[i];
    }

    FILE *fp = fopen("solar_system.xyz", "w");

    for (int t = 0; t < 10000; t++) {
        for (int i = 0; i < nbodies; i++) {
            double ax = 0.0;
            double ay = 0.0;

            for (int j = 0; j < nbodies; j++) {
                if (i == j)
                    continue;

                double dx = bodies[i].x - bodies[j].x;
                double dy = bodies[i].y - bodies[j].y;
                double r2 = dx * dx + dy * dy;
                double r3 = r2 * sqrt(r2);

                ax -= G * bodies[j].mass * dx / r3;
                ay -= G * bodies[j].mass * dy / r3;
            }

            bodies[i].vx += ax * dt;
            bodies[i].vy += ay * dt;
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
        }

        fprintf(fp, "%d\n", nbodies);
        fprintf(fp, "Solar System\n");

        for (int i = 0; i < nbodies; i++) {
            fprintf(fp, "%.16g %.16g %.16g\n", bodies[i].x, bodies[i].y, bodies[i].radius);
        }
    }

    fclose(fp);

    return 0;
}