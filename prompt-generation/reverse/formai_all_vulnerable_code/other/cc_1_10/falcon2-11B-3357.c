//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the data structure for the drone
typedef struct {
    int x;
    int y;
    int z;
} Drone;

// Function to move the drone
void moveDrone(Drone* drone, int direction) {
    switch (direction) {
        case 1:
            drone->x += 1;
            break;
        case 2:
            drone->y += 1;
            break;
        case 3:
            drone->z += 1;
            break;
        default:
            break;
    }
}

// Function to start the drone
void startDrone(Drone* drone) {
    // Start the threads
    pthread_t thread1, thread2, thread3;

    // Create the threads
    pthread_create(&thread1, NULL, moveDrone, drone);
    pthread_create(&thread2, NULL, moveDrone, drone);
    pthread_create(&thread3, NULL, moveDrone, drone);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
}

int main() {
    // Create the drone
    Drone drone;
    drone.x = 0;
    drone.y = 0;
    drone.z = 0;

    // Start the drone
    startDrone(&drone);

    // Print the final position of the drone
    printf("Drone position: (%d, %d, %d)\n", drone.x, drone.y, drone.z);

    return 0;
}