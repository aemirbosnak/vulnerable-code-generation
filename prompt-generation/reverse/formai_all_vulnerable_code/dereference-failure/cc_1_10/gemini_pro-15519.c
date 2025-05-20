//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elemental, my dear Watson!
typedef struct {
    char *name;
    int state; // 0: off, 1: on
} Device;

// An array of devices, the suspects in our smart home mystery
Device devices[] = {
    { "Lamp A", 0 },
    { "Lamp B", 0 },
    { "TV", 0 },
    { "Fan", 0 },
    { "Coffee Maker", 0 }
};

// The number of devices
int num_devices = sizeof(devices) / sizeof(Device);

// A function to print the status of the devices
void print_status() {
    printf("The current status of the devices is:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state ? "on" : "off");
    }
}

// A function to turn a device on or off
void set_device_state(char *name, int state) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = state;
            break;
        }
    }
}

// The main function, where the investigation begins
int main() {
    // Initialize the devices
    for (int i = 0; i < num_devices; i++) {
        devices[i].name = malloc(strlen(devices[i].name) + 1);
        strcpy(devices[i].name, devices[i].name);
        devices[i].state = 0;
    }

    // Print the initial status
    print_status();

    // Turn on the lamp A
    set_device_state("Lamp A", 1);

    // Turn on the TV
    set_device_state("TV", 1);

    // Print the updated status
    print_status();

    // Turn off the lamp B
    set_device_state("Lamp B", 0);

    // Print the updated status
    print_status();

    // The case is solved!
    printf("Elementary, my dear Watson!\n");
    return 0;
}