//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY_CONSTANT 6.67430e-11
#define DT 0.01
#define NUM_PLANETS 5

typedef struct {
    char name[20];
    double mass; // in kilograms
    double x;    // position x in meters
    double y;    // position y in meters
    double vx;   // velocity x in m/s
    double vy;   // velocity y in m/s
} Planet;

void initialize_planets(Planet *p) {
    strcpy(p[0].name, "Mercury");
    p[0].mass = 3.285e23; p[0].x = 5.791e10; p[0].y = 0; p[0].vx = 0; p[0].vy = 47.87e3;
    
    strcpy(p[1].name, "Venus");
    p[1].mass = 4.867e24; p[1].x = 1.082e11; p[1].y = 0; p[1].vx = 0; p[1].vy = 35.02e3;
    
    strcpy(p[2].name, "Earth");
    p[2].mass = 5.972e24; p[2].x = 1.496e11; p[2].y = 0; p[2].vx = 0; p[2].vy = 29.78e3;
    
    strcpy(p[3].name, "Mars");
    p[3].mass = 6.417e23; p[3].x = 2.279e11; p[3].y = 0; p[3].vx = 0; p[3].vy = 24.07e3;
    
    strcpy(p[4].name, "Jupiter");
    p[4].mass = 1.898e27; p[4].x = 7.785e11; p[4].y = 0; p[4].vx = 0; p[4].vy = 13.07e3;
}

void update_velocities(Planet *p, int n) {
    for (int i = 0; i < n; i++) {
        double fx = 0, fy = 0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = p[j].x - p[i].x;
                double dy = p[j].y - p[i].y;
                double distance = sqrt(dx*dx + dy*dy);
                double force = (GRAVITY_CONSTANT * p[i].mass * p[j].mass) / (distance * distance);
                
                fx += force * (dx / distance);
                fy += force * (dy / distance);
            }
        }

        p[i].vx += (fx / p[i].mass) * DT;
        p[i].vy += (fy / p[i].mass) * DT;
    }
}

void update_positions(Planet *p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].vx * DT;
        p[i].y += p[i].vy * DT;
    }
}

void print_positions(Planet *p, int n) {
    printf("Time: %.2f s\n", (float)(clock())/CLOCKS_PER_SEC);
    for (int i = 0; i < n; i++) {
        printf("%s -> Position: (%.2e, %.2e) m, Velocity: (%.2e, %.2e) m/s\n", 
                p[i].name, p[i].x, p[i].y, p[i].vx, p[i].vy);
    }
    printf("\n");
}

int main() {
    Planet *planets = malloc(sizeof(Planet) * NUM_PLANETS);
    initialize_planets(planets);

    int time_steps = 1000;
    for (int t = 0; t < time_steps; t++) {
        update_velocities(planets, NUM_PLANETS);
        update_positions(planets, NUM_PLANETS);
        print_positions(planets, NUM_PLANETS);
        
        // Simulate time delay for real-time visualization
        struct timespec req = {0, 100000000}; // 100 ms
        nanosleep(&req, NULL);
    }

    free(planets);
    return 0;
}