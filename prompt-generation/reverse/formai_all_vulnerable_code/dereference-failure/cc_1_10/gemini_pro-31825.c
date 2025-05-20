//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants for the smart home devices
#define LIGHT_ON 1
#define LIGHT_OFF 0
#define DOOR_LOCKED 1
#define DOOR_UNLOCKED 0
#define WINDOW_OPEN 1
#define WINDOW_CLOSED 0

// Define a structure to represent a smart home device
typedef struct {
    char *name;
    int state;
} smart_device;

// Create an array of smart home devices
smart_device devices[] = {
    {"Light", LIGHT_OFF},
    {"Door", DOOR_UNLOCKED},
    {"Window", WINDOW_CLOSED}
};

// Define a function to print the state of a smart home device
void print_device_state(smart_device *device) {
    printf("%s is %s\n", device->name, device->state == 1 ? "on" : "off");
}

// Define a function to toggle the state of a smart home device
void toggle_device_state(smart_device *device) {
    device->state = !device->state;
}

// Define a function to handle user input
void handle_user_input() {
    char input[100];
    printf("Enter a command (e.g., \"turn on light\"): ");
    fgets(input, 100, stdin);

    // Parse the user input
    char *command = strtok(input, " ");
    char *device_name = strtok(NULL, " ");

    // Find the matching smart home device
    smart_device *device = NULL;
    for (int i = 0; i < sizeof(devices) / sizeof(smart_device); i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            device = &devices[i];
            break;
        }
    }

    // Handle the command
    if (strcmp(command, "turn on") == 0) {
        toggle_device_state(device);
    } else if (strcmp(command, "turn off") == 0) {
        toggle_device_state(device);
    } else {
        printf("Invalid command\n");
    }
}

// Main function
int main() {
    // Print the initial state of all smart home devices
    for (int i = 0; i < sizeof(devices) / sizeof(smart_device); i++) {
        print_device_state(&devices[i]);
    }

    // Handle user input until the user enters "quit"
    while (1) {
        handle_user_input();
        printf("\n");

        // Print the updated state of all smart home devices
        for (int i = 0; i < sizeof(devices) / sizeof(smart_device); i++) {
            print_device_state(&devices[i]);
        }
    }

    return 0;
}