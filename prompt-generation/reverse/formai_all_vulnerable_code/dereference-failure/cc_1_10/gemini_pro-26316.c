//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define the types of devices in the smart home
typedef enum {
    LIGHT,
    FAN,
    AC,
    HEATER,
    TV
} device_type;

// Define the states of the devices
typedef enum {
    OFF,
    ON
} device_state;

// Define the structure of a device
typedef struct {
    device_type type;
    device_state state;
    char *name;
} device;

// Define the structure of a smart home
typedef struct {
    device *devices;
    int num_devices;
} smart_home;

// Create a new smart home
smart_home *create_smart_home(int num_devices) {
    smart_home *home = malloc(sizeof(smart_home));
    home->devices = malloc(sizeof(device) * num_devices);
    home->num_devices = num_devices;
    return home;
}

// Add a device to the smart home
void add_device(smart_home *home, device *device) {
    home->devices[home->num_devices++] = *device;
}

// Get a device from the smart home by its name
device *get_device(smart_home *home, char *name) {
    for (int i = 0; i < home->num_devices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            return &home->devices[i];
        }
    }
    return NULL;
}

// Turn a device on or off
void set_device_state(device *device, device_state state) {
    device->state = state;
}

// Print the state of the smart home
void print_smart_home(smart_home *home) {
    for (int i = 0; i < home->num_devices; i++) {
        printf("%s is %s\n", home->devices[i].name, home->devices[i].state == ON ? "on" : "off");
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home *home = create_smart_home(5);

    // Add some devices to the smart home
    device light = {LIGHT, OFF, "Light"};
    add_device(home, &light);
    device fan = {FAN, OFF, "Fan"};
    add_device(home, &fan);
    device ac = {AC, OFF, "AC"};
    add_device(home, &ac);
    device heater = {HEATER, OFF, "Heater"};
    add_device(home, &heater);
    device tv = {TV, OFF, "TV"};
    add_device(home, &tv);

    // Turn on the light and the fan
    set_device_state(get_device(home, "Light"), ON);
    set_device_state(get_device(home, "Fan"), ON);

    // Print the state of the smart home
    printf("The smart home is:\n");
    print_smart_home(home);

    return 0;
}