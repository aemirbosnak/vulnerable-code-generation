//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
// Sample Traffic Flow Simulation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_VEHICLES 100
#define MAX_SPEED 20.0
#define MAX_ACCEL 2.0

typedef struct Vehicle {
    float x; // x position on road
    float v; // velocity
    float a; // acceleration
    int lane; // current lane
} Vehicle;

typedef struct RoadGraph {
    int num_lanes;
    int num_intersections;
    int **adj_mat;
    float **dist_mat;
} RoadGraph;

// Initialize road graph
RoadGraph* init_road_graph() {
    RoadGraph *r = (RoadGraph*) malloc(sizeof(RoadGraph));
    r->num_lanes = 2;
    r->num_intersections = 5;

    // Adjacency matrix
    r->adj_mat = (int**) malloc(r->num_intersections * sizeof(int*));
    for (int i = 0; i < r->num_intersections; i++) {
        r->adj_mat[i] = (int*) calloc(r->num_intersections, sizeof(int));
    }
    r->adj_mat[0][1] = 1;
    r->adj_mat[1][2] = 1;
    r->adj_mat[1][3] = 1;
    r->adj_mat[3][4] = 1;

    // Distance matrix
    r->dist_mat = (float**) malloc(r->num_intersections * sizeof(float*));
    for (int i = 0; i < r->num_intersections; i++) {
        r->dist_mat[i] = (float*) malloc(r->num_intersections * sizeof(float));
        for (int j = 0; j < r->num_intersections; j++) {
            if (r->adj_mat[i][j]) {
                r->dist_mat[i][j] = 50.0; // arbitrary distance
            } else {
                r->dist_mat[i][j] = INFINITY;
            }
        }
    }
    return r;
}

// Initialize vehicles
void init_vehicles(Vehicle *vehicles, int num_vehicles) {
    for (int i = 0; i < num_vehicles; i++) {
        vehicles[i].x = (i % 10) * 10.0; // lane position
        vehicles[i].v = MAX_SPEED * ((float) rand() / RAND_MAX);
        vehicles[i].a = 0;
        vehicles[i].lane = i % 2;
    }
}

// Apply vehicle physics
void update_vehicle(Vehicle *v, float dt) {
    // Velocity: v = v0 + at
    v->v += v->a * dt;

    // Position: x = x0 + vt + 0.5at^2
    v->x += v->v * dt + 0.5 * v->a * pow(dt, 2);

    // Acceleration: a = dv/dt
    if (v->v < MAX_SPEED) {
        v->a = MAX_ACCEL * ((float) rand() / RAND_MAX);
    } else {
        v->a = 0;
    }
}

// Main program
int main() {
    RoadGraph *road = init_road_graph();

    Vehicle vehicles[NUM_VEHICLES];
    init_vehicles(vehicles, NUM_VEHICLES);

    float sim_time = 100.0; // seconds
    float dt = 0.1; // seconds

    for (float t = 0; t < sim_time; t += dt) {
        for (int i = 0; i < NUM_VEHICLES; i++) {
            update_vehicle(&vehicles[i], dt);
        }
    }

    free(road);
    return 0;
}