//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the device types
typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_FAN,
    DEVICE_TYPE_THERMOSTAT
} device_type_t;

// Define the device states
typedef enum {
    DEVICE_STATE_ON,
    DEVICE_STATE_OFF
} device_state_t;

// Define the device struct
typedef struct {
    device_type_t type;
    char *name;
    device_state_t state;
} device_t;

// Create a new device
device_t *device_new(device_type_t type, char *name) {
    device_t *device = malloc(sizeof(device_t));
    device->type = type;
    device->name = strdup(name);
    device->state = DEVICE_STATE_OFF;
    return device;
}

// Free a device
void device_free(device_t *device) {
    free(device->name);
    free(device);
}

// Turn a device on
void device_on(device_t *device) {
    device->state = DEVICE_STATE_ON;
}

// Turn a device off
void device_off(device_t *device) {
    device->state = DEVICE_STATE_OFF;
}

// Get the state of a device
device_state_t device_get_state(device_t *device) {
    return device->state;
}

// Print the state of a device
void device_print_state(device_t *device) {
    printf("%s is %s\n", device->name, device->state == DEVICE_STATE_ON ? "on" : "off");
}

// Create a new smart home
typedef struct {
    char *name;
    device_t **devices;
    int num_devices;
} smart_home_t;

// Create a new smart home
smart_home_t *smart_home_new(char *name) {
    smart_home_t *smart_home = malloc(sizeof(smart_home_t));
    smart_home->name = strdup(name);
    smart_home->devices = NULL;
    smart_home->num_devices = 0;
    return smart_home;
}

// Free a smart home
void smart_home_free(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_free(smart_home->devices[i]);
    }
    free(smart_home->devices);
    free(smart_home->name);
    free(smart_home);
}

// Add a device to a smart home
void smart_home_add_device(smart_home_t *smart_home, device_t *device) {
    smart_home->devices = realloc(smart_home->devices, (smart_home->num_devices + 1) * sizeof(device_t *));
    smart_home->devices[smart_home->num_devices] = device;
    smart_home->num_devices++;
}

// Turn on all devices in a smart home
void smart_home_turn_on_all(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_on(smart_home->devices[i]);
    }
}

// Turn off all devices in a smart home
void smart_home_turn_off_all(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_off(smart_home->devices[i]);
    }
}

// Print the state of all devices in a smart home
void smart_home_print_state(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_print_state(smart_home->devices[i]);
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t *smart_home = smart_home_new("My Smart Home");

    // Add some devices to the smart home
    device_t *light1 = device_new(DEVICE_TYPE_LIGHT, "Light 1");
    device_t *fan1 = device_new(DEVICE_TYPE_FAN, "Fan 1");
    device_t *thermostat1 = device_new(DEVICE_TYPE_THERMOSTAT, "Thermostat 1");
    smart_home_add_device(smart_home, light1);
    smart_home_add_device(smart_home, fan1);
    smart_home_add_device(smart_home, thermostat1);

    // Turn on all devices in the smart home
    smart_home_turn_on_all(smart_home);

    // Print the state of all devices in the smart home
    smart_home_print_state(smart_home);

    // Turn off all devices in the smart home
    smart_home_turn_off_all(smart_home);

    // Print the state of all devices in the smart home
    smart_home_print_state(smart_home);

    // Free the smart home
    smart_home_free(smart_home);

    return 0;
}