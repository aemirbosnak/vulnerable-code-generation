//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define G 6.67e-11 // gravitational constant
#define MAX_THREADS 10 // maximum number of threads

typedef struct {
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
} Body;

typedef struct {
    int id;
    int num_bodies;
    Body *bodies;
} ThreadArgs;

void *calculate_forces(void *args) {
    ThreadArgs *t_args = (ThreadArgs *)args;
    int i, j;
    double dist, force_mag, force_x, force_y;
    Body *body_i;
    Body *body_j;
    for (i = t_args->id; i < t_args->num_bodies; i += MAX_THREADS) {
        body_i = &(t_args->bodies[i]);
        force_x = 0;
        force_y = 0;
        for (j = 0; j < t_args->num_bodies; j++) {
            if (i != j) {
                body_j = &(t_args->bodies[j]);
                dist = sqrt(pow(body_j->x_pos - body_i->x_pos, 2) + pow(body_j->y_pos - body_i->y_pos, 2));
                force_mag = G * body_i->mass * body_j->mass / pow(dist, 2);
                force_x += force_mag * (body_j->x_pos - body_i->x_pos) / dist;
                force_y += force_mag * (body_j->y_pos - body_i->y_pos) / dist;
            }
        }
        body_i->x_vel += force_x / body_i->mass;
        body_i->y_vel += force_y / body_i->mass;
    }
    return NULL;
}

void update_positions(Body *bodies, int num_bodies, double time_step) {
    int i;
    for (i = 0; i < num_bodies; i++) {
        bodies[i].x_pos += bodies[i].x_vel * time_step;
        bodies[i].y_pos += bodies[i].y_vel * time_step;
    }
}

int main() {
    int num_bodies = 1000;
    double time_step = 1e-6; // time step in seconds
    Body *bodies = (Body *)malloc(num_bodies * sizeof(Body));
    int i;
    pthread_t threads[MAX_THREADS];
    ThreadArgs thread_args[MAX_THREADS];
    for (i = 0; i < num_bodies; i++) {
        bodies[i].mass = 1e+12;
        bodies[i].x_pos = rand() / (double)RAND_MAX - 0.5; // random position between -0.5 and 0.5
        bodies[i].y_pos = rand() / (double)RAND_MAX - 0.5; // random position between -0.5 and 0.5
        bodies[i].x_vel = 0;
        bodies[i].y_vel = 0;
    }
    for (i = 0; i < MAX_THREADS; i++) {
        thread_args[i].id = i;
        thread_args[i].num_bodies = num_bodies;
        thread_args[i].bodies = bodies;
        pthread_create(&threads[i], NULL, calculate_forces, (void *)&thread_args[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    update_positions(bodies, num_bodies, time_step);
    return 0;
}