//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include<stdio.h>
#include<math.h>

#define G 6.67           // Universal Gravitational Constant

struct planet {          // Planet structure to store planet details
    float x, y;          // x and y coordinates for the planet
    float mass;          // mass of the planet
    float vx, vy;        // velocity components of the planet
    float ax, ay;        // acceleration components of the planet
};

typedef struct planet Planet;

float distance(Planet A, Planet B) {        // function to calculate distance between two planets using Pythagorean theorem
    float dist;
    dist = sqrt(pow((B.x-A.x), 2) + pow((B.y-A.y), 2));
    return dist;
}

float force(Planet A, Planet B) {           // function to calculate the force between two planets
    float F;
    F = G * ((A.mass * B.mass) / pow(distance(A, B), 2));
    return F;
}

void update_velocity(Planet *A, Planet B, float dt) {     // function to update the velocity component of a planet
    float F = force(*A, B);
    float ang = atan2((B.y - A->y), (B.x - A->x));
    A->vx += (F * cos(ang) / A->mass) * dt;
    A->vy += (F * sin(ang) / A->mass) * dt;
}

void update_acceleration(Planet *A, Planet B) {           // function to update the acceleration component of a planet
    float F = force(*A, B);
    float ang = atan2((B.y - A->y), (B.x - A->x));
    A->ax = (F * cos(ang) / A->mass);
    A->ay = (F * sin(ang) / A->mass);
}

void update_position(Planet *A, float dt) {              // function to update the position of a planet
    A->x += A->vx * dt;
    A->y += A->vy * dt;
}

void simulate(float dt, int n, Planet planets[]) {        // function to simulate the motion of n-planet system
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j) {
                update_acceleration(&planets[i], planets[j]);
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j) {
                update_velocity(&planets[i], planets[j], dt);
            }
        }
    }
    for(i=0; i<n; i++) {
        update_position(&planets[i], dt);
    }
}

int main() {
    int n, i;
    float dt;
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    Planet planets[n];
    for(i=0; i<n; i++) {            // loop to create planets and initialize their details
        printf("\nEnter the details for planet %d:", i+1);
        printf("\nMass: ");
        scanf("%f", &planets[i].mass);
        printf("x coordinate: ");
        scanf("%f", &planets[i].x);
        printf("y coordinate: ");
        scanf("%f", &planets[i].y);
        printf("vx: ");
        scanf("%f", &planets[i].vx);
        printf("vy: ");
        scanf("%f", &planets[i].vy);
    }
    printf("\nEnter the time step: ");
    scanf("%f", &dt);
    int t;
    printf("\nEnter the number of time steps: ");
    scanf("%d", &t);
    for(i=0; i<t; i++) {            // loop to simulate the motion of n-planet system for t time steps
        printf("\n\nTime Step: %d", i+1);
        simulate(dt, n, planets);
        for(int j=0; j<n; j++) {    // loop to print the updated position of each planet for the current time step
            printf("\nPlanet %d's location: (%f, %f)", j+1, planets[j].x, planets[j].y);
        }
    }
    return 0;
}