//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
// Behold, my loyal code! Let us conquer the skies!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Our trusty drone
typedef struct {
    float x, y, z;         // Position in 3D space
    float roll, pitch, yaw; // Orientation
    uint8_t speed;           // Speed in meters per second
} Drone;

// Our humble remote control
typedef struct {
    uint8_t throttle;   // Increase/decrease altitude
    uint8_t yaw_left;  // Rotate counter-clockwise
    uint8_t yaw_right; // Rotate clockwise
    uint8_t pitch_up;  // Tilt forward
    uint8_t pitch_down;// Tilt backward
    uint8_t roll_left; // Tilt left
    uint8_t roll_right;// Tilt right
} RemoteControl;

// A friendly pilot to command the drone
typedef struct {
    Drone* vessel;          // Reference to the drone
    RemoteControl* controls; // Reference to the remote control
} Pilot;

// Initialize our pilot
void init_pilot(Pilot* p) {
    printf("Prepare for liftoff, pilot!\n");
    p->vessel = malloc(sizeof(Drone));
    p->vessel->x = p->vessel->y = p->vessel->z = 0.0f;
    p->vessel->roll = p->vessel->pitch = p->vessel->yaw = 0.0f;
    p->vessel->speed = 0;
    p->controls = malloc(sizeof(RemoteControl));
    printf("Drone initialized successfully.\n");
}

// Handle commands from the remote control
void handle_commands(Pilot* p) {
    // Read input from the remote control
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu %hhu",
          &p->controls->throttle,
          &p->controls->yaw_left,
          &p->controls->yaw_right,
          &p->controls->pitch_up,
          &p->controls->pitch_down,
          &p->controls->roll_left,
          &p->controls->roll_right);

    // Update the drone's state
    if (p->controls->throttle) {
        p->vessel->z += (p->controls->throttle / 128.0f) * p->vessel->speed;
    }
    if (p->controls->yaw_left) {
        p->vessel->yaw += (p->controls->yaw_left / 128.0f) * 360.0f;
    }
    if (p->controls->yaw_right) {
        p->vessel->yaw -= (p->controls->yaw_right / 128.0f) * 360.0f;
    }
    if (p->controls->pitch_up) {
        p->vessel->pitch += (p->controls->pitch_up / 128.0f) * 90.0f;
    }
    if (p->controls->pitch_down) {
        p->vessel->pitch -= (p->controls->pitch_down / 128.0f) * 90.0f;
    }
    if (p->controls->roll_left) {
        p->vessel->roll += (p->controls->roll_left / 128.0f) * 90.0f;
    }
    if (p->controls->roll_right) {
        p->vessel->roll -= (p->controls->roll_right / 128.0f) * 90.0f;
    }

    // Print the updated drone state
    printf("Drone state:\n");
    printf("  Position: (%.2f, %.2f, %.2f) meters\n",
           p->vessel->x, p->vessel->y, p->vessel->z);
    printf("  Orientation: (%.2f, %.2f, %.2f) degrees\n",
           p->vessel->roll, p->vessel->pitch, p->vessel->yaw);
    printf("  Speed: %.2f meters per second\n", p->vessel->speed);
}

// Main function for our drone adventure
int main() {
    // Let us start our journey
    printf("Welcome to the Drone Control Center!\n");

    // Initialize our trusty pilot
    Pilot pilot;
    init_pilot(&pilot);

    // Prepare for takeoff!
    while (1) {
        // Handle commands from the remote control
        handle_commands(&pilot);

        // Check for user input to quit
        char input;
        printf("Enter 'q' to quit: ");
        scanf(" %c", &input);
        if (input == 'q' || input == 'Q') {
            break;
        }
    }

    // Safely land our drone
    printf("Landing sequence initiated.\n");
    pilot.vessel->z = 0.0f;
    pilot.vessel->speed = 0;
    printf("Drone landed successfully.\n");

    // Free allocated memory
    free(pilot.vessel);
    free(pilot.controls);

    // Farewell, my intrepid pilot!
    printf("Thank you for flying with us! Till next time!\n");

    return 0;
}