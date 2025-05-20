//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of devices in the home
#define MAX_DEVICES 10

// Define the data structure for a device
typedef struct device {
    int id;
    char *name;
    int state; // 0 for off, 1 for on
    int power_consumption; // in watts
} device;

// Define the data structure for the home
typedef struct home {
    int num_devices;
    device *devices[MAX_DEVICES];
} home;

// Create a new device
device *new_device(int id, char *name, int power_consumption) {
    device *new_device = (device *)malloc(sizeof(device));
    new_device->id = id;
    new_device->name = name;
    new_device->state = 0;
    new_device->power_consumption = power_consumption;
    return new_device;
}

// Create a new home
home *new_home() {
    home *new_home = (home *)malloc(sizeof(home));
    new_home->num_devices = 0;
    return new_home;
}

// Add a device to the home
void add_device(home *home, device *device) {
    home->devices[home->num_devices] = device;
    home->num_devices++;
}

// Turn on a device
void turn_on(device *device) {
    device->state = 1;
}

// Turn off a device
void turn_off(device *device) {
    device->state = 0;
}

// Get the total power consumption of the home
int get_total_power_consumption(home *home) {
    int total_power_consumption = 0;
    for (int i = 0; i < home->num_devices; i++) {
        total_power_consumption += home->devices[i]->power_consumption * home->devices[i]->state;
    }
    return total_power_consumption;
}

// Print the status of the home
void print_home_status(home *home) {
    printf("Home Status:\n");
    for (int i = 0; i < home->num_devices; i++) {
        printf("Device %d: %s, %s, %d watts\n",
               home->devices[i]->id,
               home->devices[i]->name,
               home->devices[i]->state ? "on" : "off",
               home->devices[i]->power_consumption);
    }
    printf("Total power consumption: %d watts\n", get_total_power_consumption(home));
}

// Main function
int main() {
    // Create a new home
    home *home = new_home();

    // Add some devices to the home
    add_device(home, new_device(1, "Living Room Light", 60));
    add_device(home, new_device(2, "Kitchen Light", 40));
    add_device(home, new_device(3, "Bedroom Light", 30));
    add_device(home, new_device(4, "Bathroom Light", 20));
    add_device(home, new_device(5, "TV", 100));
    add_device(home, new_device(6, "Computer", 80));
    add_device(home, new_device(7, "Refrigerator", 200));
    add_device(home, new_device(8, "Washing Machine", 500));
    add_device(home, new_device(9, "Dryer", 400));
    add_device(home, new_device(10, "Dishwasher", 250));

    // Turn on some devices
    turn_on(home->devices[0]);
    turn_on(home->devices[2]);
    turn_on(home->devices[4]);
    turn_on(home->devices[5]);
    turn_on(home->devices[6]);

    // Print the status of the home
    print_home_status(home);

    return 0;
}