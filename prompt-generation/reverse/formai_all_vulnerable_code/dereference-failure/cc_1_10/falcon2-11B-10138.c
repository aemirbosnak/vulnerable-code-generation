//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359
#define MASS 1.0
#define DENSITY 1.0
#define GRAVITY 1.0
#define TIME_STEP 0.1

int main() {
    int num_particles = 1000;
    double *positions = (double *) malloc(sizeof(double) * num_particles * 3);
    double *velocities = (double *) malloc(sizeof(double) * num_particles * 3);
    double *forces = (double *) malloc(sizeof(double) * num_particles);

    for (int i = 0; i < num_particles; i++) {
        positions[i * 3 + 0] = (double) rand() / RAND_MAX;
        positions[i * 3 + 1] = (double) rand() / RAND_MAX;
        positions[i * 3 + 2] = (double) rand() / RAND_MAX;
        velocities[i * 3 + 0] = 0.0;
        velocities[i * 3 + 1] = 0.0;
        velocities[i * 3 + 2] = 0.0;
        forces[i] = 0.0;
    }

    srand(time(NULL));

    double dt = 0.0;
    double time = 0.0;

    while (time < 1000.0) {
        for (int i = 0; i < num_particles; i++) {
            double x = positions[i * 3 + 0];
            double y = positions[i * 3 + 1];
            double z = positions[i * 3 + 2];

            double forcex = 0.0;
            double forcey = 0.0;
            double forcez = 0.0;

            for (int j = 0; j < num_particles; j++) {
                double dx = positions[j * 3 + 0] - x;
                double dy = positions[j * 3 + 1] - y;
                double dz = positions[j * 3 + 2] - z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);

                if (r > 0.0) {
                    forcex += -MASS * GRAVITY / r * dx;
                    forcey += -MASS * GRAVITY / r * dy;
                    forcez += -MASS * GRAVITY / r * dz;
                }
            }

            double vx = velocities[i * 3 + 0];
            double vy = velocities[i * 3 + 1];
            double vz = velocities[i * 3 + 2];

            double newvx = vx + forcex * dt;
            double newvy = vy + forcey * dt;
            double newvz = vz + forcez * dt;

            double newx = x + (newvx + vx) * dt / 2.0;
            double newy = y + (newvy + vy) * dt / 2.0;
            double newz = z + (newvz + vz) * dt / 2.0;

            velocities[i * 3 + 0] = newvx;
            velocities[i * 3 + 1] = newvy;
            velocities[i * 3 + 2] = newvz;
            positions[i * 3 + 0] = newx;
            positions[i * 3 + 1] = newy;
            positions[i * 3 + 2] = newz;

            forces[i] += (newvx + vx) * (newvx + vx) + (newvy + vy) * (newvy + vy) + (newvz + vz) * (newvz + vz);
        }

        dt += TIME_STEP;
        time += TIME_STEP;
    }

    for (int i = 0; i < num_particles; i++) {
        printf("%f %f %f %f %f %f\n", positions[i * 3 + 0], positions[i * 3 + 1], positions[i * 3 + 2], velocities[i * 3 + 0], velocities[i * 3 + 1], velocities[i * 3 + 2]);
    }

    free(positions);
    free(velocities);
    free(forces);

    return 0;
}