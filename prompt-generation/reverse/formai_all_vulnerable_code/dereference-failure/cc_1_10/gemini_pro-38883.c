//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of devices and the maximum number of events per device
#define NUM_DEVICES 5
#define MAX_EVENTS 10

// Define the types of events
typedef enum {
    EVENT_TYPE_ON,
    EVENT_TYPE_OFF,
    EVENT_TYPE_SET_TEMPERATURE,
    EVENT_TYPE_SET_BRIGHTNESS
} event_type_t;

// Define the device struct
typedef struct {
    char *name;
    event_type_t events[MAX_EVENTS];
    int num_events;
} device_t;

// Define the smart home struct
typedef struct {
    device_t devices[NUM_DEVICES];
    int num_devices;
} smart_home_t;

// Create a new smart home
smart_home_t *create_smart_home() {
    smart_home_t *smart_home = malloc(sizeof(smart_home_t));
    if (smart_home == NULL) {
        return NULL;
    }

    smart_home->num_devices = 0;

    return smart_home;
}

// Add a device to the smart home
int add_device(smart_home_t *smart_home, char *name) {
    if (smart_home->num_devices == NUM_DEVICES) {
        return -1;
    }

    device_t *device = &smart_home->devices[smart_home->num_devices];
    device->name = malloc(strlen(name) + 1);
    if (device->name == NULL) {
        return -1;
    }
    strcpy(device->name, name);
    device->num_events = 0;

    smart_home->num_devices++;

    return 0;
}

// Add an event to a device
int add_event(device_t *device, event_type_t event_type) {
    if (device->num_events == MAX_EVENTS) {
        return -1;
    }

    device->events[device->num_events] = event_type;
    device->num_events++;

    return 0;
}

// Print the smart home
void print_smart_home(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_t *device = &smart_home->devices[i];

        printf("Device: %s\n", device->name);
        for (int j = 0; j < device->num_events; j++) {
            event_type_t event_type = device->events[j];

            switch (event_type) {
                case EVENT_TYPE_ON:
                    printf("  ON\n");
                    break;
                case EVENT_TYPE_OFF:
                    printf("  OFF\n");
                    break;
                case EVENT_TYPE_SET_TEMPERATURE:
                    printf("  SET_TEMPERATURE\n");
                    break;
                case EVENT_TYPE_SET_BRIGHTNESS:
                    printf("  SET_BRIGHTNESS\n");
                    break;
            }
        }
    }
}

// Free the smart home
void free_smart_home(smart_home_t *smart_home) {
    for (int i = 0; i < smart_home->num_devices; i++) {
        device_t *device = &smart_home->devices[i];

        free(device->name);
    }

    free(smart_home);
}

// Main function
int main() {
    // Create a new smart home
    smart_home_t *smart_home = create_smart_home();

    // Add some devices to the smart home
    add_device(smart_home, "Light 1");
    add_device(smart_home, "Light 2");
    add_device(smart_home, "Thermostat");

    // Add some events to the devices
    add_event(&smart_home->devices[0], EVENT_TYPE_ON);
    add_event(&smart_home->devices[0], EVENT_TYPE_OFF);
    add_event(&smart_home->devices[1], EVENT_TYPE_SET_BRIGHTNESS);
    add_event(&smart_home->devices[2], EVENT_TYPE_SET_TEMPERATURE);

    // Print the smart home
    print_smart_home(smart_home);

    // Free the smart home
    free_smart_home(smart_home);

    return 0;
}