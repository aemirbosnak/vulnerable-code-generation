//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Drone struct
typedef struct {
    char *name;
    int x;
    int y;
    int z;
    int yaw;
    int pitch;
    int roll;
    bool is_flying;
} drone;

// Function to create a new drone
drone *create_drone(char *name) {
    drone *d = malloc(sizeof(drone));
    d->name = strdup(name);
    d->x = 0;
    d->y = 0;
    d->z = 0;
    d->yaw = 0;
    d->pitch = 0;
    d->roll = 0;
    d->is_flying = false;
    return d;
}

// Function to destroy a drone
void destroy_drone(drone *d) {
    free(d->name);
    free(d);
}

// Function to print the drone's status
void print_drone(drone *d) {
    printf("Name: %s\n", d->name);
    printf("Position: (%d, %d, %d)\n", d->x, d->y, d->z);
    printf("Rotation: (%d, %d, %d)\n", d->yaw, d->pitch, d->roll);
    printf("Is flying: %s\n", d->is_flying ? "true" : "false");
}

// Function to take off the drone
void take_off(drone *d) {
    if (!d->is_flying) {
        d->is_flying = true;
        printf("%s has taken off.\n", d->name);
    } else {
        printf("%s is already flying.\n", d->name);
    }
}

// Function to land the drone
void land(drone *d) {
    if (d->is_flying) {
        d->is_flying = false;
        printf("%s has landed.\n", d->name);
    } else {
        printf("%s is already landed.\n", d->name);
    }
}

// Function to move the drone forward
void move_forward(drone *d, int distance) {
    if (d->is_flying) {
        d->y += distance;
        printf("%s has moved forward by %d meters.\n", d->name, distance);
    } else {
        printf("%s must take off before moving.\n", d->name);
    }
}

// Function to move the drone backward
void move_backward(drone *d, int distance) {
    if (d->is_flying) {
        d->y -= distance;
        printf("%s has moved backward by %d meters.\n", d->name, distance);
    } else {
        printf("%s must take off before moving.\n", d->name);
    }
}

// Function to move the drone left
void move_left(drone *d, int distance) {
    if (d->is_flying) {
        d->x -= distance;
        printf("%s has moved left by %d meters.\n", d->name, distance);
    } else {
        printf("%s must take off before moving.\n", d->name);
    }
}

// Function to move the drone right
void move_right(drone *d, int distance) {
    if (d->is_flying) {
        d->x += distance;
        printf("%s has moved right by %d meters.\n", d->name, distance);
    } else {
        printf("%s must take off before moving.\n", d->name);
    }
}

// Function to rotate the drone clockwise
void rotate_clockwise(drone *d, int angle) {
    if (d->is_flying) {
        d->yaw += angle;
        printf("%s has rotated clockwise by %d degrees.\n", d->name, angle);
    } else {
        printf("%s must take off before rotating.\n", d->name);
    }
}

// Function to rotate the drone counter-clockwise
void rotate_counter_clockwise(drone *d, int angle) {
    if (d->is_flying) {
        d->yaw -= angle;
        printf("%s has rotated counter-clockwise by %d degrees.\n", d->name, angle);
    } else {
        printf("%s must take off before rotating.\n", d->name);
    }
}

// Function to flip the drone forward
void flip_forward(drone *d) {
    if (d->is_flying) {
        d->pitch = 90;
        printf("%s has flipped forward.\n", d->name);
    } else {
        printf("%s must take off before flipping.\n", d->name);
    }
}

// Function to flip the drone backward
void flip_backward(drone *d) {
    if (d->is_flying) {
        d->pitch = -90;
        printf("%s has flipped backward.\n", d->name);
    } else {
        printf("%s must take off before flipping.\n", d->name);
    }
}

// Function to flip the drone left
void flip_left(drone *d) {
    if (d->is_flying) {
        d->roll = 90;
        printf("%s has flipped left.\n", d->name);
    } else {
        printf("%s must take off before flipping.\n", d->name);
    }
}

// Function to flip the drone right
void flip_right(drone *d) {
    if (d->is_flying) {
        d->roll = -90;
        printf("%s has flipped right.\n", d->name);
    } else {
        printf("%s must take off before flipping.\n", d->name);
    }
}

int main() {
    // Create a drone
    drone *d = create_drone("My Drone");

    // Print the drone's status
    print_drone(d);

    // Take off the drone
    take_off(d);

    // Move the drone forward
    move_forward(d, 10);

    // Rotate the drone clockwise
    rotate_clockwise(d, 90);

    // Flip the drone forward
    flip_forward(d);

    // Land the drone
    land(d);

    // Destroy the drone
    destroy_drone(d);

    return 0;
}