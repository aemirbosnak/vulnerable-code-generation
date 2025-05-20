//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <openssl/sha.h>

// Data structures for home automation devices
typedef struct device {
    char* name;
    char* type;
    bool state;
} device;

typedef struct home {
    char* name;
    size_t num_devices;
    device** devices;
} home;

// Function prototypes
void init_home(home* h);
void add_device(home* h, device* d);
void remove_device(home* h, device* d);
void toggle_device(home* h, device* d);
void print_home(home* h);

// Main function
int main() {
    // Create a new home
    home h;
    init_home(&h);

    // Add some devices to the home
    device d1 = {"Lamp", "Light", false};
    add_device(&h, &d1);

    device d2 = {"Thermostat", "Temperature", false};
    add_device(&h, &d2);

    device d3 = {"Door", "Security", false};
    add_device(&h, &d3);

    // Print the home
    print_home(&h);

    // Toggle a device
    toggle_device(&h, &d1);

    // Print the home again
    print_home(&h);

    // Remove a device
    remove_device(&h, &d2);

    // Print the home one last time
    print_home(&h);

    return 0;
}

// Function definitions
void init_home(home* h) {
    h->name = NULL;
    h->num_devices = 0;
    h->devices = NULL;
}

void add_device(home* h, device* d) {
    h->devices = realloc(h->devices, sizeof(device*) * (h->num_devices + 1));
    h->devices[h->num_devices++] = d;
}

void remove_device(home* h, device* d) {
    for (size_t i = 0; i < h->num_devices; i++) {
        if (h->devices[i] == d) {
            for (size_t j = i + 1; j < h->num_devices; j++) {
                h->devices[j - 1] = h->devices[j];
            }
            h->num_devices--;
            break;
        }
    }
}

void toggle_device(home* h, device* d) {
    d->state = !d->state;
}

void print_home(home* h) {
    printf("Home: %s\n", h->name);
    printf("Number of devices: %zu\n", h->num_devices);
    for (size_t i = 0; i < h->num_devices; i++) {
        printf("Device %zu:\n", i);
        printf("  Name: %s\n", h->devices[i]->name);
        printf("  Type: %s\n", h->devices[i]->type);
        printf("  State: %s\n", h->devices[i]->state ? "On" : "Off");
    }
}