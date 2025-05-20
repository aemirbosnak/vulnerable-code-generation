//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the device types
enum device_type {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_FAN,
    DEVICE_TYPE_THERMOSTAT
};

// Define the device states
enum device_state {
    DEVICE_STATE_OFF,
    DEVICE_STATE_ON
};

// Define the device structure
struct device {
    char *name;
    enum device_type type;
    enum device_state state;
};

// Define the smart home structure
struct smart_home {
    struct device devices[MAX_DEVICES];
    int num_devices;
};

// Create a new smart home
struct smart_home *smart_home_new() {
    struct smart_home *smart_home = malloc(sizeof(struct smart_home));
    if (smart_home == NULL) {
        return NULL;
    }
    smart_home->num_devices = 0;
    return smart_home;
}

// Destroy a smart home
void smart_home_destroy(struct smart_home *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        free(smart_home->devices[i].name);
    }
    free(smart_home);
}

// Add a device to a smart home
int smart_home_add_device(struct smart_home *smart_home, char *name, enum device_type type) {
    if (smart_home->num_devices >= MAX_DEVICES) {
        return -1;
    }
    struct device *device = &smart_home->devices[smart_home->num_devices++];
    device->name = strdup(name);
    device->type = type;
    device->state = DEVICE_STATE_OFF;
    return 0;
}

// Get the device by name
struct device *smart_home_get_device_by_name(struct smart_home *smart_home, char *name) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        if (strcmp(smart_home->devices[i].name, name) == 0) {
            return &smart_home->devices[i];
        }
    }
    return NULL;
}

// Turn on a device
int smart_home_turn_on_device(struct smart_home *smart_home, char *name) {
    struct device *device = smart_home_get_device_by_name(smart_home, name);
    if (device == NULL) {
        return -1;
    }
    device->state = DEVICE_STATE_ON;
    return 0;
}

// Turn off a device
int smart_home_turn_off_device(struct smart_home *smart_home, char *name) {
    struct device *device = smart_home_get_device_by_name(smart_home, name);
    if (device == NULL) {
        return -1;
    }
    device->state = DEVICE_STATE_OFF;
    return 0;
}

// Print the status of a smart home
void smart_home_print_status(struct smart_home *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        struct device *device = &smart_home->devices[i];
        printf("%s: ", device->name);
        switch (device->state) {
            case DEVICE_STATE_OFF:
                printf("off\n");
                break;
            case DEVICE_STATE_ON:
                printf("on\n");
                break;
        }
    }
}

// Main function
int main() {
    // Create a new smart home
    struct smart_home *smart_home = smart_home_new();

    // Add some devices to the smart home
    smart_home_add_device(smart_home, "light1", DEVICE_TYPE_LIGHT);
    smart_home_add_device(smart_home, "fan1", DEVICE_TYPE_FAN);
    smart_home_add_device(smart_home, "thermostat1", DEVICE_TYPE_THERMOSTAT);

    // Turn on the light1
    smart_home_turn_on_device(smart_home, "light1");

    // Turn on the fan1
    smart_home_turn_on_device(smart_home, "fan1");

    // Set the thermostat1 to 72 degrees
    smart_home_turn_on_device(smart_home, "thermostat1");

    // Print the status of the smart home
    smart_home_print_status(smart_home);

    // Destroy the smart home
    smart_home_destroy(smart_home);

    return 0;
}