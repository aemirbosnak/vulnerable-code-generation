//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the main structure for a smart home device
typedef struct smart_home_device {
    char *name;
    char *type;
    bool is_on;
    int value;
} smart_home_device;

// Create a new smart home device
smart_home_device *create_device(char *name, char *type, bool is_on, int value) {
    smart_home_device *device = malloc(sizeof(smart_home_device));
    device->name = strdup(name);
    device->type = strdup(type);
    device->is_on = is_on;
    device->value = value;
    return device;
}

// Print the details of a smart home device
void print_device(smart_home_device *device) {
    printf("Name: %s\n", device->name);
    printf("Type: %s\n", device->type);
    printf("Is on: %s\n", device->is_on ? "true" : "false");
    printf("Value: %d\n", device->value);
}

// Turn a smart home device on or off
void set_device_on(smart_home_device *device, bool is_on) {
    device->is_on = is_on;
}

// Set the value of a smart home device
void set_device_value(smart_home_device *device, int value) {
    device->value = value;
}

// Get the name of a smart home device
char *get_device_name(smart_home_device *device) {
    return device->name;
}

// Get the type of a smart home device
char *get_device_type(smart_home_device *device) {
    return device->type;
}

// Get the state of a smart home device
bool is_device_on(smart_home_device *device) {
    return device->is_on;
}

// Get the value of a smart home device
int get_device_value(smart_home_device *device) {
    return device->value;
}

// Main function
int main() {
    // Create a new smart home device
    smart_home_device *device = create_device("Living Room Light", "Light", true, 100);

    // Print the details of the smart home device
    print_device(device);

    // Turn the smart home device off
    set_device_on(device, false);

    // Print the details of the smart home device
    print_device(device);

    // Set the value of the smart home device
    set_device_value(device, 50);

    // Print the details of the smart home device
    print_device(device);

    // Free the memory allocated for the smart home device
    free(device->name);
    free(device->type);
    free(device);

    return 0;
}