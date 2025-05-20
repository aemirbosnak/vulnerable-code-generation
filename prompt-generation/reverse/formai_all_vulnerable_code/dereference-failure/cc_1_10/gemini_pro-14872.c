//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define the smart home device types
#define LIGHT 1
#define FAN 2
#define AC 3

// Define the smart home device states
#define ON 1
#define OFF 0

// Define the maximum number of devices
#define MAX_DEVICES 10

// Create a struct to represent a smart home device
typedef struct smart_home_device {
    int type;
    int state;
    char name[32];
} smart_home_device;

// Create an array to store the smart home devices
smart_home_device devices[MAX_DEVICES];

// Initialize the smart home devices
void init_devices() {
    devices[0] = (smart_home_device) {LIGHT, OFF, "Living Room Light"};
    devices[1] = (smart_home_device) {FAN, OFF, "Bedroom Fan"};
    devices[2] = (smart_home_device) {AC, OFF, "Kitchen AC"};
}

// Print the smart home devices
void print_devices() {
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%s: ", devices[i].name);
        switch (devices[i].type) {
            case LIGHT:
                printf("Light");
                break;
            case FAN:
                printf("Fan");
                break;
            case AC:
                printf("AC");
                break;
        }
        printf(", State: ");
        switch (devices[i].state) {
            case ON:
                printf("On");
                break;
            case OFF:
                printf("Off");
                break;
        }
        printf("\n");
    }
}

// Turn on a smart home device
void turn_on_device(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        devices[index].state = ON;
        printf("%s turned on.\n", devices[index].name);
    } else {
        printf("Invalid device index.\n");
    }
}

// Turn off a smart home device
void turn_off_device(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        devices[index].state = OFF;
        printf("%s turned off.\n", devices[index].name);
    } else {
        printf("Invalid device index.\n");
    }
}

// Toggle the state of a smart home device
void toggle_device(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        devices[index].state = !devices[index].state;
        printf("%s %s.\n", devices[index].name, devices[index].state ? "turned on" : "turned off");
    } else {
        printf("Invalid device index.\n");
    }
}

// Get the state of a smart home device
int get_device_state(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        return devices[index].state;
    } else {
        return -1;
    }
}

// Simulate a smart home routine
void simulate_routine() {
    // Turn on the living room light at 7:00 AM
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    if (tm->tm_hour == 7 && tm->tm_min == 0) {
        turn_on_device(0);
    }

    // Turn off the bedroom fan at 10:00 PM
    if (tm->tm_hour == 22 && tm->tm_min == 0) {
        turn_off_device(1);
    }

    // Turn on the kitchen AC at 1:00 PM
    if (tm->tm_hour == 13 && tm->tm_min == 0) {
        turn_on_device(2);
    }

    // Turn off the kitchen AC at 4:00 PM
    if (tm->tm_hour == 16 && tm->tm_min == 0) {
        turn_off_device(2);
    }
}

int main() {
    // Initialize the smart home devices
    init_devices();

    // Print the smart home devices
    print_devices();

    // Simulate a smart home routine
    simulate_routine();

    return 0;
}