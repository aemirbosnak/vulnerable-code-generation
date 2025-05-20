//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Smart home device enums
enum device_type {
    LIGHT,
    FAN,
    THERMOSTAT
};

// Smart home device struct
struct device {
    enum device_type type;
    char *name;
    int state; // 0 for off, 1 for on
};

// Create a new smart home device
struct device *create_device(enum device_type type, char *name) {
    struct device *device = malloc(sizeof(struct device));
    device->type = type;
    device->name = name;
    device->state = 0;
    return device;
}

// Turn a smart home device on or off
void set_device_state(struct device *device, int state) {
    device->state = state;
}

// Print the status of a smart home device
void print_device_status(struct device *device) {
    printf("%s is ", device->name);
    if (device->state == 0) {
        printf("off\n");
    } else {
        printf("on\n");
    }
}

// Main function
int main() {
    // Create a smart home light
    struct device *light = create_device(LIGHT, "Living Room Light");

    // Turn on the light
    set_device_state(light, 1);

    // Print the status of the light
    print_device_status(light);

    // Create a smart home fan
    struct device *fan = create_device(FAN, "Ceiling Fan");

    // Turn on the fan
    set_device_state(fan, 1);

    // Print the status of the fan
    print_device_status(fan);

    // Create a smart home thermostat
    struct device *thermostat = create_device(THERMOSTAT, "Thermostat");

    // Set the thermostat to 72 degrees Fahrenheit
    set_device_state(thermostat, 72);

    // Print the status of the thermostat
    print_device_status(thermostat);

    // Free the memory allocated for the smart home devices
    free(light);
    free(fan);
    free(thermostat);

    return 0;
}