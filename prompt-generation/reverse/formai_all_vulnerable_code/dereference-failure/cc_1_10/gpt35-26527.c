//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>

#define G 6.6743e-11 //Gravitational constant
#define TIMESTEP 10 //Simulation timestep

typedef struct {
    double x, y, z; //Position
    double vx, vy, vz; //Velocity
    double ax, ay, az; //Acceleration
    double mass; //Mass
} body;

void update_acceleration(body* b1, body b2) {
    //Calculate acceleration on b1 due to b2
    double dx = b2.x - b1->x;
    double dy = b2.y - b1->y;
    double dz = b2.z - b1->z;
    double dist_sq = dx*dx + dy*dy + dz*dz + 1e-6;
    double dist_cubed = dist_sq * sqrt(dist_sq);
    double acc = G * b2.mass / dist_cubed;
    b1->ax += dx * acc;
    b1->ay += dy * acc;
    b1->az += dz * acc;
}

void update_velocity(body* b) {
    //Update velocity using acceleration
    b->vx += b->ax * TIMESTEP;
    b->vy += b->ay * TIMESTEP;
    b->vz += b->az * TIMESTEP;
}

void update_position(body* b) {
    //Update position using velocity
    b->x += b->vx * TIMESTEP;
    b->y += b->vy * TIMESTEP;
    b->z += b->vz * TIMESTEP;
}

void simulate(body* bodies, int num_bodies) {
    int i, j;
    //Update all accelerations
    for (i = 0; i < num_bodies; i++) {
        bodies[i].ax = 0;
        bodies[i].ay = 0;
        bodies[i].az = 0;
        for (j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            update_acceleration(&bodies[i], bodies[j]);
        }
    }
    //Update all velocities and positions
    for (i = 0; i < num_bodies; i++) {
        update_velocity(&bodies[i]);
        update_position(&bodies[i]);
    }
}

void print_body(body b) {
    printf("Position: (%lf, %lf, %lf), Velocity: (%lf, %lf, %lf)\n",
           b.x, b.y, b.z, b.vx, b.vy, b.vz);
}

void print_bodies(body* bodies, int num_bodies) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        printf("Body %d:\n", i);
        print_body(bodies[i]);
    }
}

int main(void) {
    //Initialize bodies
    body earth = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 5.97e24 };
    body mars = { 2.279e11, 0, 0, 0, 24077, 0, 0, 0, 0, 6.39e23 };
    body moon = { 3.844e8, 0, 0, 0, 1022, 0, 0, 0, 0, 7.34e22 };
    body* bodies[] = {&earth, &mars, &moon};

    int num_bodies = sizeof(bodies)/sizeof(*bodies);

    //Simulate for 1000 timesteps
    int i;
    for (i = 0; i < 1000; i++) {
        simulate(bodies, num_bodies);
        if (i % 100 == 0) {
            printf("Timestep %d:\n", i);
            print_bodies(bodies, num_bodies);
        }
    }

    return 0;
}