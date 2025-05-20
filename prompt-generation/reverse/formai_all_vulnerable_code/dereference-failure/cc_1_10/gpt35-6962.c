//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: brave
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define DT 0.001 // Time step
#define G 6.67430e-11 // Gravitational constant
#define M_SUN 1.9891e30 // Mass of the sun
#define AU 149597870700.0 // Astronomical unit

typedef struct {
    double x, y, vx, vy, ax, ay;
    double mass;
    char name[20];
} body;

void compute_acceleration(body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        bodies[i].ax = 0;
        bodies[i].ay = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dist = sqrt(dx*dx + dy*dy);
            double f = G*bodies[i].mass*bodies[j].mass / (dist*dist);
            double fx = f*dx / dist;
            double fy = f*dy / dist;
            bodies[i].ax += fx / bodies[i].mass;
            bodies[i].ay += fy / bodies[i].mass;
        }
    }
}

void update_velocity(body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].vx += bodies[i].ax*dt;
        bodies[i].vy += bodies[i].ay*dt;
    }
}

void update_position(body *bodies, int n, double dt) {
    for (int i = 0; i < n; i++) {
        bodies[i].x += bodies[i].vx*dt;
        bodies[i].y += bodies[i].vy*dt;
    }
}

void generate_random_bodies(body *bodies, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        sprintf(bodies[i].name, "Body %d", i+1);
        bodies[i].x = (rand() % 401) - 200; // Random position between -200 and 200 AU
        bodies[i].y = (rand() % 401) - 200;
        bodies[i].vx = (rand() % 1001) - 500; // Random velocity between -500 and 500 m/s
        bodies[i].vy = (rand() % 1001) - 500;
        double mass = pow(10, rand() % 16); // Random mass between 1 kg and 10^16 kg
        bodies[i].mass = mass / M_SUN;
    }
}

void print_bodies(body *bodies, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", bodies[i].name);
        printf("Position: (%.2f, %.2f) AU\n", bodies[i].x, bodies[i].y);
        printf("Velocity: (%.2f, %.2f) m/s\n", bodies[i].vx, bodies[i].vy);
        printf("Mass: %.2e kg\n", bodies[i].mass*M_SUN);
        printf("\n");
    }
}

int main() {
    int n = 10; // Number of bodies
    body *bodies = malloc(n*sizeof(body));
    generate_random_bodies(bodies, n);
    printf("Initial state:\n");
    print_bodies(bodies, n);
    for (int i = 0; i < 365*10; i++) { // Run simulation for 10 years
        compute_acceleration(bodies, n);
        update_velocity(bodies, n, DT);
        update_position(bodies, n, DT);
    }
    printf("Final state:\n");
    print_bodies(bodies, n);
    free(bodies);
    return 0;
}