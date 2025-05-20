//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define G 6.6743e-11


typedef struct Vector {
    double x, y, z;
} Vector;

typedef struct Body {
    Vector position;
    Vector velocity;
    Vector acceleration;
    double mass;
    char name[20];
    int color[3];
} Body;

// Function to calculate force between two bodies
Vector calculateForce(Body* body1, Body* body2) {
    double distance = sqrt(pow(body2->position.x - body1->position.x, 2)
                         + pow(body2->position.y - body1->position.y, 2)
                         + pow(body2->position.z - body1->position.z, 2));
    double forceMagnitude = G * ((body1->mass * body2->mass) / pow(distance, 2));

    Vector force = {
        .x = forceMagnitude * ((body2->position.x - body1->position.x) / distance),
        .y = forceMagnitude * ((body2->position.y - body1->position.y) / distance),
        .z = forceMagnitude * ((body2->position.z - body1->position.z) / distance)
    };

    return force;
}

// Function to update acceleration, velocity, and position of each body
void updateSystem(Body** system, int numBodies, double timeStep) {
    Vector totalForce = {0, 0, 0};
    Vector force = {0, 0, 0};

    // Update acceleration for each body
    for (int i = 0; i < numBodies; i++) {
        totalForce = (Vector){0, 0, 0};
        for (int j = 0; j < numBodies; j++) {
            if (i != j) {
                force = calculateForce(system[i], system[j]);
                totalForce.x += force.x;
                totalForce.y += force.y;
                totalForce.z += force.z;
            }
        }
        system[i]->acceleration.x = totalForce.x / system[i]->mass;
        system[i]->acceleration.y = totalForce.y / system[i]->mass;
        system[i]->acceleration.z = totalForce.z / system[i]->mass;
    }

    // Update velocity and position for each body
    for (int i = 0; i < numBodies; i++) {
        system[i]->velocity.x += system[i]->acceleration.x * timeStep;
        system[i]->velocity.y += system[i]->acceleration.y * timeStep;
        system[i]->velocity.z += system[i]->acceleration.z * timeStep;

        system[i]->position.x += system[i]->velocity.x * timeStep;
        system[i]->position.y += system[i]->velocity.y * timeStep;
        system[i]->position.z += system[i]->velocity.z * timeStep;
    }
}

// Function to print the current state of the system
void printSystem(Body** system, int numBodies, int time) {
    printf("Time: %d s\n\n", time);
    for (int i = 0; i < numBodies; i++) {
        printf("%s:\n", system[i]->name);
        printf("\tPosition: (%e, %e, %e) m\n", system[i]->position.x, system[i]->position.y, system[i]->position.z);
        printf("\tVelocity: (%e, %e, %e) m/s\n", system[i]->velocity.x, system[i]->velocity.y, system[i]->velocity.z);
        printf("\tAcceleration: (%e, %e, %e) m/s^2\n\n", system[i]->acceleration.x, system[i]->acceleration.y, system[i]->acceleration.z);
    }
}

int main() {
    srand(time(NULL));

    // Initialize the system
    int numBodies = 5;
    Body** system = malloc(sizeof(Body*) * numBodies);
    for (int i = 0; i < numBodies; i++) {
        system[i] = malloc(sizeof(Body));
        system[i]->mass = 1e30 * (rand() % 10 + 1);
        sprintf(system[i]->name, "Body%d", i + 1);
        system[i]->color[0] = rand() % 256;
        system[i]->color[1] = rand() % 256;
        system[i]->color[2] = rand() % 256;

        switch (i) {
            case 0:
                system[i]->position = (Vector){0, 0, 0};
                system[i]->velocity = (Vector){0, 0, 0};
                break;
            case 1:
                system[i]->position = (Vector){149.6e9, 0, 0};
                system[i]->velocity = (Vector){0, 30e3, 0};
                break;
            case 2:
                system[i]->position = (Vector){0, 0, 0.0385 * 149.6e9};
                system[i]->velocity = (Vector){54.7e3, 0, 0};
                break;
            case 3:
                system[i]->position = (Vector){0, 778e9, 0};
                system[i]->velocity = (Vector){13e3, 0, 0};
                break;
            case 4:
                system[i]->position = (Vector){0, 0, -227.9e9};
                system[i]->velocity = (Vector){32.4e3, 0, 0};
                break;
        }
    }

    // Run the simulation
    double timeStep = 3600;
    int numSteps = 8760;
    for (int i = 0; i < numSteps; i++) {
        updateSystem(system, numBodies, timeStep);
        if (i % 100 == 0) {
            printSystem(system, numBodies, i * timeStep);
        }
    }

    // Free the memory allocated for the system
    for (int i = 0; i < numBodies; i++) {
        free(system[i]);
    }
    free(system);

    return 0;
}