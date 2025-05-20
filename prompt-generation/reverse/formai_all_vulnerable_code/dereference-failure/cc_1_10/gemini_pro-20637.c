//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to control a specific device
void control_device(char *device, char *action) {
    printf("Controlling device %s to perform action %s\n", device, action);
}

// Function to check if a device is on or off
int is_device_on(char *device) {
    printf("Checking if device %s is on\n", device);
    return 1; // Dummy value, replace with actual logic
}

// Function to recursively control the smart home
void control_smart_home(char *input) {
    // Base case: if input is empty, return
    if (*input == '\0') {
        return;
    }

    // Split the input into device and action
    char *device = strtok(input, " ");
    char *action = strtok(NULL, " ");

    // Check if the device is on or off
    int is_on = is_device_on(device);

    // Control the device based on the action
    if (strcmp(action, "on") == 0) {
        if (!is_on) {
            control_device(device, "on");
        } else {
            printf("Device %s is already on\n", device);
        }
    } else if (strcmp(action, "off") == 0) {
        if (is_on) {
            control_device(device, "off");
        } else {
            printf("Device %s is already off\n", device);
        }
    } else if (strcmp(action, "status") == 0) {
        if (is_on) {
            printf("Device %s is on\n", device);
        } else {
            printf("Device %s is off\n", device);
        }
    } else {
        printf("Invalid action %s for device %s\n", action, device);
    }

    // Recursively control the remaining devices
    control_smart_home(input + strlen(device) + strlen(action) + 2);
}

int main() {
    // Sample input: "light on, fan on, AC off, light status"
    char *input = "light on, fan on, AC off, light status";

    // Control the smart home
    control_smart_home(input);

    return 0;
}