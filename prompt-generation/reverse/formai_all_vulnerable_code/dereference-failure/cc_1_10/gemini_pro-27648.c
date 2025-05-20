//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67408e-11
#define DT 0.001
#define MASS_SCALE 1e24

typedef struct {
    double x, y, z;
    double mass;
    double vx, vy, vz;
} Planet;

typedef struct {
    int num_planets;
    Planet *planets;
} SolarSystem;

SolarSystem create_solar_system(int num_planets) {
    SolarSystem ss;
    ss.num_planets = num_planets;
    ss.planets = malloc(sizeof(Planet) * num_planets);

    for (int i = 0; i < num_planets; i++) {
        ss.planets[i].x = rand() % 10000;
        ss.planets[i].y = rand() % 10000;
        ss.planets[i].z = rand() % 10000;
        ss.planets[i].mass = (rand() % 1000000) * MASS_SCALE;
        ss.planets[i].vx = 0;
        ss.planets[i].vy = 0;
        ss.planets[i].vz = 0;
    }

    return ss;
}

void update_solar_system(SolarSystem *ss) {
    for (int i = 0; i < ss->num_planets; i++) {
        double fx = 0, fy = 0, fz = 0;
        for (int j = 0; j < ss->num_planets; j++) {
            if (i == j) continue;
            double dx = ss->planets[j].x - ss->planets[i].x;
            double dy = ss->planets[j].y - ss->planets[i].y;
            double dz = ss->planets[j].z - ss->planets[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * ss->planets[i].mass * ss->planets[j].mass / (r * r * r);
            fx += f * dx / r;
            fy += f * dy / r;
            fz += f * dz / r;
        }

        ss->planets[i].vx += fx * DT;
        ss->planets[i].vy += fy * DT;
        ss->planets[i].vz += fz * DT;
        ss->planets[i].x += ss->planets[i].vx * DT;
        ss->planets[i].y += ss->planets[i].vy * DT;
        ss->planets[i].z += ss->planets[i].vz * DT;
    }
}

void draw_solar_system(SolarSystem *ss) {
    for (int i = 0; i < ss->num_planets; i++) {
        printf("%.2f %.2f %.2f\n", ss->planets[i].x, ss->planets[i].y, ss->planets[i].z);
    }
    printf("\n");
}

int main() {
    SolarSystem ss = create_solar_system(3);

    for (int i = 0; i < 10000; i++) {
        update_solar_system(&ss);
        draw_solar_system(&ss);
    }

    return 0;
}