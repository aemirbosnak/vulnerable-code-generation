//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 //Gravitational constant

struct Body {
    char name[20];
    double mass;
    double px, py, pz; //position coordinates
    double vx, vy, vz; //velocity components
    double ax, ay, az; //acceleration components
};

struct Simulation {
    int n_bodies; //number of bodies
    double time_step; //time step for each iteration
    struct Body *bodies; //array of bodies
};

void compute_acceleration(struct Simulation *sim, struct Body *b1, struct Body *b2) {
    double dx = b2->px - b1->px;
    double dy = b2->py - b1->py;
    double dz = b2->pz - b1->pz;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double F = G * b1->mass * b2->mass / (r*r);
    double ax = F * dx / r / b1->mass;
    double ay = F * dy / r / b1->mass;
    double az = F * dz / r / b1->mass;
    b1->ax += ax;
    b1->ay += ay;
    b1->az += az;
    b2->ax -= ax;
    b2->ay -= ay;
    b2->az -= az;
}

void simulate_step(struct Simulation *sim) {
    int i, j;
    //Compute accelerations for each body
    for (i = 0; i < sim->n_bodies; i++) {
        sim->bodies[i].ax = sim->bodies[i].ay = sim->bodies[i].az = 0;
        for (j = 0; j < sim->n_bodies; j++) {
            if (i != j) {
                compute_acceleration(sim, &sim->bodies[i], &sim->bodies[j]);
            }
        }
    }
    //Update positions and velocities for each body
    for (i = 0; i < sim->n_bodies; i++) {
        sim->bodies[i].px += sim->bodies[i].vx * sim->time_step + 0.5 * sim->bodies[i].ax * sim->time_step * sim->time_step;
        sim->bodies[i].py += sim->bodies[i].vy * sim->time_step + 0.5 * sim->bodies[i].ay * sim->time_step * sim->time_step;
        sim->bodies[i].pz += sim->bodies[i].vz * sim->time_step + 0.5 * sim->bodies[i].az * sim->time_step * sim->time_step;
        sim->bodies[i].vx += sim->bodies[i].ax * sim->time_step;
        sim->bodies[i].vy += sim->bodies[i].ay * sim->time_step;
        sim->bodies[i].vz += sim->bodies[i].az * sim->time_step;
    }
}

void print_body(struct Body *b) {
    printf("%-20s %8.3e %8.3e %8.3e    %8.3e %8.3e %8.3e\n", b->name, b->mass, b->px, b->py, b->pz, b->vx, b->vy, b->vz);
}

void print_simulation(struct Simulation *sim) {
    int i;
    printf("Simulation with %d bodies, time step = %f\n", sim->n_bodies, sim->time_step);
    printf("Body                Mass             Position (x,y,z)             Velocity (x,y,z)\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < sim->n_bodies; i++) {
        print_body(&sim->bodies[i]);
    }
}

int main() {
    struct Simulation sim;
    sim.n_bodies = 3;
    sim.time_step = 3600;
    sim.bodies = (struct Body*) malloc(sim.n_bodies * sizeof(struct Body));
    //Set initial conditions for each body
    strcpy(sim.bodies[0].name, "Sun");
    sim.bodies[0].mass = 1.989e30;
    sim.bodies[0].px = 0;
    sim.bodies[0].py = 0;
    sim.bodies[0].pz = 0;
    sim.bodies[0].vx = 0;
    sim.bodies[0].vy = 0;
    sim.bodies[0].vz = 0;
    strcpy(sim.bodies[1].name, "Earth");
    sim.bodies[1].mass = 5.97e24;
    sim.bodies[1].px = 1.496e11;
    sim.bodies[1].py = 0;
    sim.bodies[1].pz = 0;
    sim.bodies[1].vx = 0;
    sim.bodies[1].vy = 2.98e4;
    sim.bodies[1].vz = 0;
    strcpy(sim.bodies[2].name, "Moon");
    sim.bodies[2].mass = 7.342e22;
    sim.bodies[2].px = 1.496e11 + 3.844e8;
    sim.bodies[2].py = 0;
    sim.bodies[2].pz = 0;
    sim.bodies[2].vx = 0;
    sim.bodies[2].vy = 2.98e4 + 1.022e3;
    sim.bodies[2].vz = 0;
    //Run simulation for 1 year
    int steps = 365 * 24 * 3600 / sim.time_step;
    int i;
    for (i = 0; i < steps; i++) {
        simulate_step(&sim);
    }
    print_simulation(&sim);
    free(sim.bodies);
    return 0;
}