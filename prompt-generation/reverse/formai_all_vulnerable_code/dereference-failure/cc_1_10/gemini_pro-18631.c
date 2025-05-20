//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the "parrot" drone simulator
struct Parrot {
    int x, y, z; // Coordinates in 3D space
    int roll, pitch, yaw; // Rotation angles
    int speed; // Speed in meters per second
    int battery; // Battery level in percentage
};

// Create a new parrot drone
struct Parrot *parrot_create() {
    struct Parrot *parrot = malloc(sizeof(struct Parrot));
    parrot->x = 0;
    parrot->y = 0;
    parrot->z = 0;
    parrot->roll = 0;
    parrot->pitch = 0;
    parrot->yaw = 0;
    parrot->speed = 0;
    parrot->battery = 100;
    return parrot;
}

// Destroy a parrot drone
void parrot_destroy(struct Parrot *parrot) {
    free(parrot);
}

// Print the current state of the parrot drone
void parrot_print_state(struct Parrot *parrot) {
    printf("Position: (%d, %d, %d)\n", parrot->x, parrot->y, parrot->z);
    printf("Rotation: (%d, %d, %d)\n", parrot->roll, parrot->pitch, parrot->yaw);
    printf("Speed: %d m/s\n", parrot->speed);
    printf("Battery: %d%%\n", parrot->battery);
}

// Control the parrot drone
void parrot_control(struct Parrot *parrot, char command) {
    switch (command) {
        case 'w': // Move forward
            parrot->x += parrot->speed;
            break;
        case 's': // Move backward
            parrot->x -= parrot->speed;
            break;
        case 'a': // Move left
            parrot->y -= parrot->speed;
            break;
        case 'd': // Move right
            parrot->y += parrot->speed;
            break;
        case 'q': // Move up
            parrot->z += parrot->speed;
            break;
        case 'e': // Move down
            parrot->z -= parrot->speed;
            break;
        case 'r': // Roll left
            parrot->roll -= 10;
            break;
        case 'f': // Roll right
            parrot->roll += 10;
            break;
        case 't': // Pitch up
            parrot->pitch -= 10;
            break;
        case 'g': // Pitch down
            parrot->pitch += 10;
            break;
        case 'y': // Yaw left
            parrot->yaw -= 10;
            break;
        case 'h': // Yaw right
            parrot->yaw += 10;
            break;
        case 'j': // Increase speed
            parrot->speed += 1;
            break;
        case 'k': // Decrease speed
            parrot->speed -= 1;
            break;
        case 'l': // Land
            parrot->z = 0;
            parrot->speed = 0;
            break;
        case 'p': // Take off
            parrot->z = 1;
            parrot->speed = 1;
            break;
        case 'b': // Battery boost
            parrot->battery += 10;
            if (parrot->battery > 100) {
                parrot->battery = 100;
            }
            break;
        case 'x': // Exit
            parrot_destroy(parrot);
            exit(0);
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
}

int main() {
    // Create a new parrot drone
    struct Parrot *parrot = parrot_create();

    // Print a welcome message
    printf("Welcome to the Parrot Drone Remote Control Simulator!\n");
    printf("Use the following commands to control the drone:\n");
    printf("w: Move forward\n");
    printf("s: Move backward\n");
    printf("a: Move left\n");
    printf("d: Move right\n");
    printf("q: Move up\n");
    printf("e: Move down\n");
    printf("r: Roll left\n");
    printf("f: Roll right\n");
    printf("t: Pitch up\n");
    printf("g: Pitch down\n");
    printf("y: Yaw left\n");
    printf("h: Yaw right\n");
    printf("j: Increase speed\n");
    printf("k: Decrease speed\n");
    printf("l: Land\n");
    printf("p: Take off\n");
    printf("b: Battery boost\n");
    printf("x: Exit\n");

    // Control the drone until the user exits
    while (1) {
        // Get a command from the user
        char command = getchar();

        // Control the drone
        parrot_control(parrot, command);

        // Print the current state of the drone
        parrot_print_state(parrot);
    }

    return 0;
}