//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Smart Home Device Types
typedef enum {
    LIGHT,
    FAN,
    AC,
    HEATER,
    TV,
    DOOR
} device_type_t;

// Device States
typedef enum {
    ON,
    OFF,
    OPEN,
    CLOSED
} device_state_t;

// Device Structure
typedef struct {
    char name[32];
    device_type_t type;
    device_state_t state;
} device_t;

// Create a new device
device_t *create_device(char *name, device_type_t type, device_state_t state) {
    device_t *device = malloc(sizeof(device_t));
    strcpy(device->name, name);
    device->type = type;
    device->state = state;
    return device;
}

// Toggle the state of a device
void toggle_device(device_t *device) {
    switch (device->type) {
        case LIGHT:
        case FAN:
        case AC:
        case HEATER:
            device->state = (device->state == ON) ? OFF : ON;
            break;
        case TV:
            device->state = (device->state == ON) ? OFF : ON;
            break;
        case DOOR:
            device->state = (device->state == OPEN) ? CLOSED : OPEN;
            break;
    }
}

// Print the status of a device
void print_device_status(device_t *device) {
    char *state_str;
    switch (device->state) {
        case ON:
            state_str = "ON";
            break;
        case OFF:
            state_str = "OFF";
            break;
        case OPEN:
            state_str = "OPEN";
            break;
        case CLOSED:
            state_str = "CLOSED";
            break;
    }
    printf("%s: %s\n", device->name, state_str);
}

// Smart Home Automation System
int main() {
    // Create a list of devices
    device_t *devices[] = {
        create_device("Living Room Light", LIGHT, OFF),
        create_device("Bedroom Fan", FAN, OFF),
        create_device("Kitchen AC", AC, OFF),
        create_device("Garage Door", DOOR, OPEN),
        create_device("Living Room TV", TV, OFF)
    };

    // Create a smart home automation system
    char *commands[] = {
        "Turn on the Living Room Light",
        "Turn off the Bedroom Fan",
        "Turn on the Kitchen AC",
        "Close the Garage Door",
        "Turn on the Living Room TV"
    };

    // Process the commands
    for (int i = 0; i < 5; i++) {
        char *command = commands[i];
        char *device_name = strtok(command, " ");
        char *action = strtok(NULL, " ");

        // Find the device
        device_t *device = NULL;
        for (int j = 0; j < 5; j++) {
            if (strcmp(devices[j]->name, device_name) == 0) {
                device = devices[j];
                break;
            }
        }

        // Perform the action
        if (device != NULL) {
            if (strcmp(action, "Turn") == 0) {
                char *state = strtok(NULL, " ");
                if (strcmp(state, "on") == 0) {
                    toggle_device(device);
                } else if (strcmp(state, "off") == 0) {
                    toggle_device(device);
                }
            } else if (strcmp(action, "Close") == 0) {
                toggle_device(device);
            }
        }
    }

    // Print the status of all devices
    for (int i = 0; i < 5; i++) {
        print_device_status(devices[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < 5; i++) {
        free(devices[i]);
    }

    return 0;
}