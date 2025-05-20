//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    float speed;
    int angle;
} Velocity;

typedef struct {
    Position position;
    Velocity velocity;
} Drone;

Drone* create_drone(int x, int y, int z, float speed, int angle) {
    Drone* drone = (Drone*)malloc(sizeof(Drone));
    drone->position.x = x;
    drone->position.y = y;
    drone->position.z = z;
    drone->velocity.speed = speed;
    drone->velocity.angle = angle;
    return drone;
}

void destroy_drone(Drone* drone) {
    free(drone);
}

void move_drone(Drone* drone, int dx, int dy, int dz) {
    drone->position.x += dx;
    drone->position.y += dy;
    drone->position.z += dz;
}

void rotate_drone(Drone* drone, int angle) {
    drone->velocity.angle += angle;
}

void takeoff(Drone* drone, int height) {
    move_drone(drone, 0, 0, height);
}

void land(Drone* drone) {
    move_drone(drone, 0, 0, -drone->position.z);
}

void print_drone_status(Drone* drone) {
    printf("Position: (%d, %d, %d)\n", drone->position.x, drone->position.y, drone->position.z);
    printf("Velocity: (%.2f, %d)\n", drone->velocity.speed, drone->velocity.angle);
}

int main() {
    srand(time(NULL));

    // Create a drone
    Drone* drone = create_drone(0, 0, 0, 10.0f, 0);

    // Take off
    takeoff(drone, 100);

    // Fly around
    for (int i = 0; i < 10; i++) {
        // Move the drone
        move_drone(drone, rand() % 10, rand() % 10, rand() % 10);

        // Rotate the drone
        rotate_drone(drone, rand() % 360);

        // Print the drone status
        print_drone_status(drone);

        // Sleep for a bit
        sleep(1);
    }

    // Land
    land(drone);

    // Destroy the drone
    destroy_drone(drone);

    return 0;
}