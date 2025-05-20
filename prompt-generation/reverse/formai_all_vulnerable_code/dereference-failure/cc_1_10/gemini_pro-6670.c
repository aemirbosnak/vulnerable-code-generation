//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: scientific
/*
 * Celestial Body Simulator
 *
 * This program simulates the motion of celestial bodies in a gravitational field.
 * The program takes as input a list of celestial bodies, each with its mass, position, and velocity.
 * The program then simulates the motion of the celestial bodies over a period of time, calculating the gravitational force between each pair of bodies and updating their positions and velocities accordingly.
 * The program outputs the positions and velocities of the celestial bodies at the end of the simulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Structure to represent a celestial body.
 */
typedef struct celestial_body {
    double mass; /* Mass of the body in kilograms. */
    double position[3]; /* Position of the body in meters. */
    double velocity[3]; /* Velocity of the body in meters per second. */
} celestial_body;

/*
 * Function to calculate the gravitational force between two celestial bodies.
 */
void calculate_gravitational_force(celestial_body *body1, celestial_body *body2,
                                   double *force)
{
    /* Calculate the distance between the two bodies. */
    double dx = body2->position[0] - body1->position[0];
    double dy = body2->position[1] - body1->position[1];
    double dz = body2->position[2] - body1->position[2];
    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    /* Calculate the gravitational force. */
    *force = (6.67408e-11) * body1->mass * body2->mass / (distance * distance);
}

/*
 * Function to update the position and velocity of a celestial body.
 */
void update_celestial_body(celestial_body *body, double force, double dt)
{
    /* Calculate the acceleration of the body. */
    double acceleration = force / body->mass;

    /* Update the position of the body. */
    body->position[0] += body->velocity[0] * dt + 0.5 * acceleration * dt * dt;
    body->position[1] += body->velocity[1] * dt + 0.5 * acceleration * dt * dt;
    body->position[2] += body->velocity[2] * dt + 0.5 * acceleration * dt * dt;

    /* Update the velocity of the body. */
    body->velocity[0] += acceleration * dt;
    body->velocity[1] += acceleration * dt;
    body->velocity[2] += acceleration * dt;
}

/*
 * Main function.
 */
int main(int argc, char **argv)
{
    /* Check if the user has provided enough arguments. */
    if (argc < 2) {
        printf("Usage: %s number_of_bodies\n", argv[0]);
        return 1;
    }

    /* Get the number of bodies from the user. */
    int nbodies = atoi(argv[1]);

    /* Create an array of celestial bodies. */
    celestial_body bodies[nbodies];

    /* Initialize the celestial bodies. */
    for (int i = 0; i < nbodies; i++) {
        /* Get the mass of the body from the user. */
        printf("Enter the mass of body %d (in kilograms): ", i + 1);
        scanf("%lf", &bodies[i].mass);

        /* Get the position of the body from the user. */
        printf("Enter the position of body %d (in meters): ", i + 1);
        scanf("%lf %lf %lf", &bodies[i].position[0], &bodies[i].position[1], &bodies[i].position[2]);

        /* Get the velocity of the body from the user. */
        printf("Enter the velocity of body %d (in meters per second): ", i + 1);
        scanf("%lf %lf %lf", &bodies[i].velocity[0], &bodies[i].velocity[1], &bodies[i].velocity[2]);
    }

    /* Simulate the motion of the celestial bodies over a period of time. */
    double dt = 0.001; /* Time step in seconds. */
    double time = 0.0; /* Total time in seconds. */
    while (time < 100.0) {
        /* Calculate the gravitational force between each pair of bodies. */
        for (int i = 0; i < nbodies; i++) {
            for (int j = i + 1; j < nbodies; j++) {
                double force;
                calculate_gravitational_force(&bodies[i], &bodies[j], &force);

                /* Update the position and velocity of the bodies. */
                update_celestial_body(&bodies[i], force, dt);
                update_celestial_body(&bodies[j], -force, dt);
            }
        }

        /* Update the time. */
        time += dt;
    }

    /* Output the positions and velocities of the celestial bodies. */
    printf("Positions and velocities of the celestial bodies at the end of the simulation:\n");
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d:\n", i + 1);
        printf("Position: (%lf, %lf, %lf) meters\n", bodies[i].position[0], bodies[i].position[1], bodies[i].position[2]);
        printf("Velocity: (%lf, %lf, %lf) meters per second\n", bodies[i].velocity[0], bodies[i].velocity[1], bodies[i].velocity[2]);
    }

    return 0;
}