//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11  // The universal gravitational constant
#define DT 1000.0     // The time step

typedef struct{
    double px, py;
    double vx, vy;
    double mass;
} planet;

void update_velocity(planet *a, planet *b, double dt) {
    double dx = b->px - a->px;
    double dy = b->py - a->py;

    double F = G * a->mass * b->mass / (dx*dx + dy*dy);

    double dax = F*a->mass*dx / sqrt(dx*dx + dy*dy);
    double day = F*a->mass*dy / sqrt(dx*dx + dy*dy);

    double dbx = -dax;
    double dby = -day;

    a->vx += dax*dt / a->mass;
    a->vy += day*dt / a->mass;

    b->vx += dbx*dt / b->mass;
    b->vy += dby*dt / b->mass;

}

void update_position(planet *a, double dt) {
    a->px += a->vx*dt;
    a->py += a->vy*dt;
}

void print_planet(planet p) {
    printf("x = %f; y = %f; vx = %f; vy = %f; mass = %f\n", p.px, p.py, p.vx, p.vy, p.mass);
}

planet* create_random_planet(double max_x, double max_y, double max_v, double max_mass) {
    planet* p = (planet*) malloc(sizeof(planet));
    p->px = ((double)rand() / RAND_MAX) * max_x;
    p->py = ((double)rand() / RAND_MAX) * max_y;
    p->vx = (((double)rand() / RAND_MAX) * 2 - 1) * max_v;
    p->vy = (((double)rand() / RAND_MAX) * 2 - 1) * max_v;
    p->mass = ((double)rand() / RAND_MAX) * max_mass;
    return p;
}

int main() {
    srand(time(NULL));

    planet** planets = malloc(10 * sizeof(planet*));
    for(int i=0; i<10; i++){
        planets[i] = create_random_planet(1000, 1000, 10, 1000);
        print_planet(*planets[i]);
    }

    for(double t=0; t<1e9; t+=DT){

        for(int i=0; i<10; i++){
            for(int j=i+1; j<10; j++){
                update_velocity(planets[i], planets[j], DT);
            }
        }

        for(int i=0; i<10; i++){
            update_position(planets[i], DT);
        }
    }

    printf("Simulation complete!\n");

    for(int i=0; i<10; i++){
        free(planets[i]);
    }
    free(planets);

    return 0;
}