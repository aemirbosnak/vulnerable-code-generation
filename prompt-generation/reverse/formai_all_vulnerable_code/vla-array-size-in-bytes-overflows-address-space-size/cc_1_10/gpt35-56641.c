//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <math.h>
#define G 6.67430e-11 // Universal gravitational constant

typedef struct 
{
    double x, y;
} Vector2D;

typedef struct 
{
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body;

int main()
{
    int numBodies;
    printf("Enter number of bodies in the system: ");
    scanf("%d", &numBodies); // get number of bodies from user

    Body bodies[numBodies];
    
    // get values for each body
    for (int i = 0; i < numBodies; i++)
    {
        printf("\nBody %d\n", i+1);
        printf("Enter x coordinate of position: ");
        scanf("%lf", &bodies[i].position.x);
        printf("Enter y coordinate of position: ");
        scanf("%lf", &bodies[i].position.y);
        printf("Enter x component of velocity: ");
        scanf("%lf", &bodies[i].velocity.x);
        printf("Enter y component of velocity: ");
        scanf("%lf", &bodies[i].velocity.y);
        printf("Enter mass of the body (in kg): ");
        scanf("%lf", &bodies[i].mass);
    }

    double timeStep;
    printf("\nEnter time step: ");
    scanf("%lf", &timeStep);

    int numSteps;
    printf("Enter number of steps to simulate: ");
    scanf("%d", &numSteps);

    // simulate the system
    for (int step = 0; step < numSteps; step++)
    {
        // update velocities
        for (int i = 0; i < numBodies; i++)
        {
            Vector2D acceleration = {0, 0};
            for (int j = 0; j < numBodies; j++)
            {
                if (i == j) continue;

                Vector2D direction;
                direction.x = bodies[j].position.x - bodies[i].position.x;
                direction.y = bodies[j].position.y - bodies[i].position.y;

                double distance = sqrt(direction.x * direction.x + direction.y * direction.y);
                double force = (G * bodies[i].mass * bodies[j].mass) / (distance * distance);

                acceleration.x += force * direction.x / (bodies[i].mass * distance);
                acceleration.y += force * direction.y / (bodies[i].mass * distance);
            }

            bodies[i].velocity.x += acceleration.x * timeStep;
            bodies[i].velocity.y += acceleration.y * timeStep;
        }

        // update positions
        for (int i = 0; i < numBodies; i++)
        {
            bodies[i].position.x += bodies[i].velocity.x * timeStep;
            bodies[i].position.y += bodies[i].velocity.y * timeStep;
        }

        // print the positions of each body at this step
        printf("\nStep %d:\n", step+1);
        for (int i = 0; i < numBodies; i++)
        {
            printf("Body %d Position: (%.2lf, %.2lf)\n", i+1, bodies[i].position.x, bodies[i].position.y);
        }
    }

    return 0;
}