//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drone_t {
    char *name;
    int altitude;
    int speed;
    int battery;
    int armament;
} drone_t;

drone_t *create_drone(char *name) {
    drone_t *d = (drone_t *)malloc(sizeof(drone_t));
    d->name = strdup(name);
    d->altitude = 0;
    d->speed = 0;
    d->battery = 100;
    d->armament = 0;
    return d;
}

void destroy_drone(drone_t *d) {
    free(d->name);
    free(d);
}

void fly_drone(drone_t *d, int altitude, int speed) {
    d->altitude = altitude;
    d->speed = speed;
    printf("%s flying at %d feet and %d mph\n", d->name, d->altitude, d->speed);
}

void arm_drone(drone_t *d, int armament) {
    d->armament = armament;
    printf("%s armed with %d strength\n", d->name, d->armament);
}

int main() {
    drone_t *d1 = create_drone("Raven");
    drone_t *d2 = create_drone("Hawk");

    fly_drone(d1, 1000, 50);
    fly_drone(d2, 2000, 100);

    arm_drone(d1, 10);
    arm_drone(d2, 20);

    destroy_drone(d1);
    destroy_drone(d2);

    return 0;
}