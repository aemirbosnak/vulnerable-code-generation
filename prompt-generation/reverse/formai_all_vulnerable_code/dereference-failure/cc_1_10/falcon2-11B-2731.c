//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int num_objects = 5;
double radius = 0.1;
double mass = 1.0;
double gravity_constant = 6.67430e-11;
double planet_mass = 1.9891e30;
double planet_radius = 6.3781e6;

double calc_gravity(double x1, double y1, double z1, double x2, double y2, double z2) {
    double r = sqrt(x1 * x1 + y1 * y1 + z1 * z1);
    double r2 = sqrt(x2 * x2 + y2 * y2 + z2 * z2);
    double g = (gravity_constant * mass * planet_mass) / (r * r2);
    return g;
}

void *calculate_gravity(void *arg) {
    int object_id = *((int*)arg);
    double x, y, z;
    double g = 0.0;

    while (1) {
        printf("Calculating gravity for object %d\n", object_id);
        srand(object_id * time(NULL));
        x = (double)rand() / RAND_MAX * radius;
        y = (double)rand() / RAND_MAX * radius;
        z = (double)rand() / RAND_MAX * radius;
        g = calc_gravity(x, y, z, 0.0, 0.0, 0.0);
        printf("Gravity for object %d: %f\n", object_id, g);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[num_objects];
    int *ids = (int*)malloc(num_objects * sizeof(int));

    for (i = 0; i < num_objects; i++) {
        ids[i] = i;
    }

    for (i = 0; i < num_objects; i++) {
        pthread_create(&threads[i], NULL, calculate_gravity, (void*)&ids[i]);
    }

    for (i = 0; i < num_objects; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}