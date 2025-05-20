//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
struct device {
    char *name;
    char *type;
    int state;
};

// Create an array of smart home devices
struct device devices[] = {
    { "lights", "light", 0 },
    { "fan", "fan", 0 },
    { "music", "music", 0 },
    { "heater", "heater", 0 }
};

// Define the smart home routines
struct routine {
    char *name;
    char **devices;
    int *states;
    int num_devices;
};

// Create an array of smart home routines
struct routine routines[] = {
    { "romantic evening", { "lights", "music" }, { 1, 1 }, 2 },
    { "good night", { "lights", "fan", "heater" }, { 0, 0, 0 }, 3 }
};

// Get the state of a device
int get_device_state(char *name) {
    for (int i = 0; i < sizeof(devices) / sizeof(devices[0]); i++) {
        if (strcmp(devices[i].name, name) == 0) {
            return devices[i].state;
        }
    }

    return -1;
}

// Set the state of a device
void set_device_state(char *name, int state) {
    for (int i = 0; i < sizeof(devices) / sizeof(devices[0]); i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = state;
        }
    }
}

// Run a routine
void run_routine(char *name) {
    for (int i = 0; i < sizeof(routines) / sizeof(routines[0]); i++) {
        if (strcmp(routines[i].name, name) == 0) {
            for (int j = 0; j < routines[i].num_devices; j++) {
                set_device_state(routines[i].devices[j], routines[i].states[j]);
            }
        }
    }
}

// Main function
int main() {
    // Set the initial state of the devices
    set_device_state("lights", 0);
    set_device_state("fan", 0);
    set_device_state("music", 0);
    set_device_state("heater", 0);

    // Run the romantic evening routine
    run_routine("romantic evening");

    // Print the state of the devices
    printf("Lights: %d\n", get_device_state("lights"));
    printf("Fan: %d\n", get_device_state("fan"));
    printf("Music: %d\n", get_device_state("music"));
    printf("Heater: %d\n", get_device_state("heater"));

    return 0;
}