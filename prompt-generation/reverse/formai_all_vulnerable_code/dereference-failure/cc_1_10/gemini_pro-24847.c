//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the structure of a device
typedef struct {
    char *name;
    char *type;
    int state;
} device;

// Define the array of devices
device devices[MAX_DEVICES];

// Define the function to add a device
void add_device(char *name, char *type, int state) {
    // Find an empty slot in the array of devices
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].name == NULL) {
            break;
        }
    }

    // If there is no empty slot, return an error
    if (i == MAX_DEVICES) {
        printf("Error: no more devices can be added.\n");
        return;
    }

    // Allocate memory for the device's name and type
    devices[i].name = malloc(strlen(name) + 1);
    devices[i].type = malloc(strlen(type) + 1);

    // Copy the device's name and type into the array
    strcpy(devices[i].name, name);
    strcpy(devices[i].type, type);

    // Set the device's state
    devices[i].state = state;
}

// Define the function to get the state of a device
int get_device_state(char *name) {
    // Find the device in the array of devices
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            break;
        }
    }

    // If the device was not found, return an error
    if (i == MAX_DEVICES) {
        printf("Error: no such device.\n");
        return -1;
    }

    // Return the device's state
    return devices[i].state;
}

// Define the function to set the state of a device
int set_device_state(char *name, int state) {
    // Find the device in the array of devices
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            break;
        }
    }

    // If the device was not found, return an error
    if (i == MAX_DEVICES) {
        printf("Error: no such device.\n");
        return -1;
    }

    // Set the device's state
    devices[i].state = state;

    // Return success
    return 0;
}

// Define the main function
int main() {
    // Add some devices to the array
    add_device("Light 1", "light", 0);
    add_device("Light 2", "light", 0);
    add_device("Thermostat", "thermostat", 72);

    // Get the state of a device
    int state = get_device_state("Light 1");
    if (state == -1) {
        return -1;
    }

    // Set the state of a device
    int result = set_device_state("Light 1", 1);
    if (result == -1) {
        return -1;
    }

    // Print the state of the device
    printf("The state of Light 1 is %d.\n", state);

    // Return success
    return 0;
}