//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Smart home devices
typedef enum {
    LIGHT,
    FAN,
    AC,
    TV,
    DOOR,
    WINDOW
} device_type;

typedef struct {
    device_type type;
    char *name;
    int state; // 0 for off, 1 for on
} device;

// Smart home automation system
typedef struct {
    device *devices;
    int num_devices;
} smart_home;

// Create a new smart home
smart_home *create_smart_home() {
    smart_home *home = malloc(sizeof(smart_home));
    home->devices = NULL;
    home->num_devices = 0;
    return home;
}

// Add a new device to the smart home
void add_device(smart_home *home, device_type type, char *name) {
    device *new_device = malloc(sizeof(device));
    new_device->type = type;
    new_device->name = name;
    new_device->state = 0;
    home->devices = realloc(home->devices, (home->num_devices + 1) * sizeof(device));
    home->devices[home->num_devices++] = *new_device;
    free(new_device);
}

// Turn on a device
void turn_on_device(smart_home *home, char *name) {
    for (int i = 0; i < home->num_devices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = 1;
            printf("%s turned on.\n", name);
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

// Turn off a device
void turn_off_device(smart_home *home, char *name) {
    for (int i = 0; i < home->num_devices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = 0;
            printf("%s turned off.\n", name);
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

// Print the status of all devices
void print_status(smart_home *home) {
    printf("Smart home status:\n");
    for (int i = 0; i < home->num_devices; i++) {
        printf("%s: %s\n", home->devices[i].name, home->devices[i].state ? "on" : "off");
    }
}

// Main function
int main() {
    // Create a new smart home
    smart_home *home = create_smart_home();

    // Add some devices to the smart home
    add_device(home, LIGHT, "Living room light");
    add_device(home, FAN, "Bedroom fan");
    add_device(home, AC, "Kitchen AC");
    add_device(home, TV, "Living room TV");
    add_device(home, DOOR, "Front door");
    add_device(home, WINDOW, "Bedroom window");

    // Turn on some devices
    turn_on_device(home, "Living room light");
    turn_on_device(home, "Bedroom fan");
    turn_on_device(home, "Kitchen AC");

    // Turn off some devices
    turn_off_device(home, "Bedroom fan");
    turn_off_device(home, "Kitchen AC");

    // Print the status of all devices
    print_status(home);

    // Free the memory allocated for the smart home
    for (int i = 0; i < home->num_devices; i++) {
        free(home->devices[i].name);
    }
    free(home->devices);
    free(home);

    return 0;
}