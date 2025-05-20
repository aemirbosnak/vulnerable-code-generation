//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define max(a,b) ((a) > (b)? (a) : (b))

struct planet {
    char name[50];
    float mass;
    float x, y, z;
    float vx, vy, vz;
    float ax, ay, az;
    int num_satellites;
    struct planet **satellites;
};

struct satellite {
    char name[50];
    float mass;
    float x, y, z;
    float vx, vy, vz;
    float ax, ay, az;
    struct planet *planet;
};

struct planet *create_planet(char *name, float mass, float x, float y, float z, float vx, float vy, float vz) {
    struct planet *p = (struct planet *)malloc(sizeof(struct planet));
    strcpy(p->name, name);
    p->mass = mass;
    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
    p->num_satellites = 0;
    p->satellites = NULL;
    return p;
}

struct satellite *create_satellite(char *name, float mass, float x, float y, float z, float vx, float vy, float vz, struct planet *planet) {
    struct satellite *s = (struct satellite *)malloc(sizeof(struct satellite));
    strcpy(s->name, name);
    s->mass = mass;
    s->x = x;
    s->y = y;
    s->z = z;
    s->vx = vx;
    s->vy = vy;
    s->vz = vz;
    s->ax = 0;
    s->ay = 0;
    s->az = 0;
    s->planet = planet;
    return s;
}

void add_satellite(struct planet *p, struct satellite *s) {
    p->num_satellites++;
    p->satellites = (struct planet **)realloc(p->satellites, sizeof(struct planet *) * p->num_satellites);
    p->satellites[p->num_satellites-1] = s;
}

void update_position(struct planet *p, float dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void update_velocity(struct planet *p, float dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_acceleration(struct planet *p, float dt) {
    float G = 6.6743e-11;
    float a = G * p->mass / sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
    p->ax += a * p->x / p->mass;
    p->ay += a * p->y / p->mass;
    p->az += a * p->z / p->mass;
}

int main() {
    struct planet *sun = create_planet("Sun", 1.989e30, 0, 0, 0, 0, 0, 0);
    struct satellite *earth = create_satellite("Earth", 5.972e24, 0, 0, 0, 0, 0, 0, sun);
    add_satellite(sun, earth);

    while (1) {
        update_position(sun, 1);
        update_position(earth, 1);
        update_velocity(sun, 1);
        update_velocity(earth, 1);
        update_acceleration(sun, 1);
        update_acceleration(earth, 1);

        printf("Sun: (%f, %f, %f), Earth: (%f, %f, %f)\n", sun->x, sun->y, sun->z, earth->x, earth->y, earth->z);
        printf("Sun: (%f, %f, %f), Earth: (%f, %f, %f)\n", sun->vx, sun->vy, sun->vz, earth->vx, earth->vy, earth->vz);
        printf("Sun: (%f, %f, %f), Earth: (%f, %f, %f)\n", sun->ax, sun->ay, sun->az, earth->ax, earth->ay, earth->az);

        sleep(1);
    }

    return 0;
}