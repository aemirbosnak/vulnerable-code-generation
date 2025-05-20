//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11
#define TIME_STEP 3600.0
#define TOTAL_TIME 31556952.0

typedef struct Body {
    char* name;
    double mass;
    double radius;
    double position[3];
    double velocity[3];
} Body;

void update_acceleration(Body* bodies, int num_bodies, double** accelerations) {
    for (int i = 0; i < num_bodies; i++) {
        double acceleration[3] = {0};

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }

            double distance_vector[3] = {
                bodies[j].position[0] - bodies[i].position[0],
                bodies[j].position[1] - bodies[i].position[1],
                bodies[j].position[2] - bodies[i].position[2]
            };

            double distance = sqrt(
                pow(distance_vector[0], 2) +
                pow(distance_vector[1], 2) +
                pow(distance_vector[2], 2)
            );

            double force_magnitude = G * bodies[i].mass * bodies[j].mass / pow(distance, 2);
            double force_vector[3] = {
                force_magnitude * distance_vector[0] / distance,
                force_magnitude * distance_vector[1] / distance,
                force_magnitude * distance_vector[2] / distance
            };

            acceleration[0] += force_vector[0] / bodies[i].mass;
            acceleration[1] += force_vector[1] / bodies[i].mass;
            acceleration[2] += force_vector[2] / bodies[i].mass;
        }

        accelerations[i][0] = acceleration[0];
        accelerations[i][1] = acceleration[1];
        accelerations[i][2] = acceleration[2];
    }
}

void update_velocity(Body* bodies, int num_bodies, double** accelerations, double time_step) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].velocity[0] += accelerations[i][0] * time_step;
        bodies[i].velocity[1] += accelerations[i][1] * time_step;
        bodies[i].velocity[2] += accelerations[i][2] * time_step;
    }
}

void update_position(Body* bodies, int num_bodies, double time_step) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position[0] += bodies[i].velocity[0] * time_step;
        bodies[i].position[1] += bodies[i].velocity[1] * time_step;
        bodies[i].position[2] += bodies[i].velocity[2] * time_step;
    }
}

void simulate(Body* bodies, int num_bodies) {
    double** accelerations = malloc(num_bodies * sizeof(double*));

    for (int i = 0; i < num_bodies; i++) {
        accelerations[i] = malloc(3 * sizeof(double));
    }

    double time_elapsed = 0.0;

    while (time_elapsed < TOTAL_TIME) {
        update_acceleration(bodies, num_bodies, accelerations);
        update_velocity(bodies, num_bodies, accelerations, TIME_STEP);
        update_position(bodies, num_bodies, TIME_STEP);

        time_elapsed += TIME_STEP;

        printf("Time elapsed: %f seconds\n", time_elapsed);
        printf("---------------\n");

        for (int i = 0; i < num_bodies; i++) {
            printf("%s position: [%f, %f, %f]\n", bodies[i].name, bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
        }

        printf("\n");
    }

    for (int i = 0; i < num_bodies; i++) {
        free(accelerations[i]);
    }

    free(accelerations);
}

int main() {
    Body sun = {"Sun", 1.989e30, 696340000, {0, 0, 0}, {0, 0, 0}};
    Body earth = {"Earth", 5.972e24, 6371000, {147095000000, 0, 0}, {0, 30290, 0}};
    Body moon = {"Moon", 7.342e22, 1737400, {147095000000 + 384400000, 0, 0}, {0, 30290 + 1022, 0}};

    Body bodies[] = {sun, earth, moon};
    int num_bodies = sizeof(bodies) / sizeof(bodies[0]);

    simulate(bodies, num_bodies);

    return 0;
}