//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define YEAR 31557600 // year in seconds

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct body {
    char name[30];
    double mass;
    vector velocity;
    vector position;
    vector acceleration;
} body;

void update_accelerations(body* all_bodies, int num_bodies) {
    for(int i=0; i<num_bodies; i++) {
        all_bodies[i].acceleration.x = 0;
        all_bodies[i].acceleration.y = 0;
        all_bodies[i].acceleration.z = 0;

        for(int j=0; j<num_bodies; j++) {
            if(i != j) {
                double delta_x = all_bodies[j].position.x - all_bodies[i].position.x;
                double delta_y = all_bodies[j].position.y - all_bodies[i].position.y;
                double delta_z = all_bodies[j].position.z - all_bodies[i].position.z;

                double distance = sqrt(delta_x*delta_x + delta_y*delta_y + delta_z*delta_z);

                double force = G * all_bodies[i].mass * all_bodies[j].mass / (distance * distance);

                all_bodies[i].acceleration.x += force * delta_x / distance / all_bodies[i].mass;
                all_bodies[i].acceleration.y += force * delta_y / distance / all_bodies[i].mass;
                all_bodies[i].acceleration.z += force * delta_z / distance / all_bodies[i].mass;
            }
        }
    }
}

void update_positions_velocities(body* all_bodies, int num_bodies, double time) {
    for(int i=0; i<num_bodies; i++) {
        all_bodies[i].velocity.x += all_bodies[i].acceleration.x * time;
        all_bodies[i].velocity.y += all_bodies[i].acceleration.y * time;
        all_bodies[i].velocity.z += all_bodies[i].acceleration.z * time;

        all_bodies[i].position.x += all_bodies[i].velocity.x * time;
        all_bodies[i].position.y += all_bodies[i].velocity.y * time;
        all_bodies[i].position.z += all_bodies[i].velocity.z * time;
    }
}

int main() {
    body sun = {"Sun", 1.989e30, {0,0,0}, {0,0,0}, {0,0,0}};
    body mercury = {"Mercury", 3.285e23, {0,0,47870}, {5.79e10,0,0}, {0,0,0}};
    body venus = {"Venus", 4.867e24, {0,0,35020}, {0,1.082e11,0}, {0,0,0}};
    body earth = {"Earth", 5.972e24, {0,0,29800}, {0,-1.496e11,0}, {0,0,0}};
    body mars = {"Mars", 6.39e23, {0,0,24130}, {-2.279e11,0,0}, {0,0,0}};

    int num_bodies = 5;
    body* all_bodies = malloc(num_bodies * sizeof(body));
    all_bodies[0] = sun;
    all_bodies[1] = mercury;
    all_bodies[2] = venus;
    all_bodies[3] = earth;
    all_bodies[4] = mars;

    double time_step = YEAR / 10000;
    double time = 0;

    while(1) {
        update_accelerations(all_bodies, num_bodies);
        update_positions_velocities(all_bodies, num_bodies, time_step);

        printf("Time: %.2f years\n", time/YEAR);
        for(int i=0; i<num_bodies; i++) {
            printf("%s\n", all_bodies[i].name);
            printf("Position: (%.2f, %.2f, %.2f)\n", all_bodies[i].position.x, all_bodies[i].position.y, all_bodies[i].position.z);
            printf("Velocity: (%.2f, %.2f, %.2f)\n\n", all_bodies[i].velocity.x, all_bodies[i].velocity.y, all_bodies[i].velocity.z);
        }

        time += time_step;
        if(time > YEAR * 10) {
            break;
        }
    }

    free(all_bodies);
    return 0;
}