//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 10

// Structure for holding position and velocity vectors of object
typedef struct {
    double x, y, z;
    double vx, vy, vz;
} Vec;

// Dynamic array for holding objects in simulation
Vec* objects;
int numObjects = 0;

// Force calculation function that updates acceleration of each object
void* forceCalculation(void* tid) {
    int i, j;
    int myId = *((int*)tid);
    int objectsPerThread = numObjects / NUM_THREADS;
    int start = myId * objectsPerThread;
    int end = (myId == NUM_THREADS - 1) ? numObjects : start + objectsPerThread;

    for (i = start; i < end; i++) {
        double ax = 0.0, ay = 0.0, az = 0.0;
        for (j = 0; j < numObjects; j++) {
            if (i != j) {
                double dx = objects[j].x - objects[i].x;
                double dy = objects[j].y - objects[i].y;
                double dz = objects[j].z - objects[i].z;
                double distSquared = dx*dx + dy*dy + dz*dz;
                double dist = sqrt(distSquared);
                double distCubed = distSquared*dist;
                double force = 1.0 / distCubed;
                ax += force * dx;
                ay += force * dy;
                az += force * dz;
            }
        }
        objects[i].vx += ax;
        objects[i].vy += ay;
        objects[i].vz += az;
    }
    pthread_exit(NULL);
}

int main() {
    int i, j;
    int tid[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    // Initialization of objects
    objects = (Vec*)calloc(numObjects, sizeof(Vec));
    objects[0].x = 0.0;
    objects[0].y = 0.0;
    objects[0].z = 0.0;

    // Simulation loop
    while (1) {
        // Create threads for force calculation
        for (i = 0; i < NUM_THREADS; i++) {
            tid[i] = i;
            pthread_create(&threads[i], NULL, forceCalculation, (void*)&tid[i]);
        }

        // Wait for threads to finish
        for (i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        // Update positions of objects
        for (i = 0; i < numObjects; i++) {
            objects[i].x += objects[i].vx;
            objects[i].y += objects[i].vy;
            objects[i].z += objects[i].vz;
        }
    }

    free(objects);
    return 0;
}