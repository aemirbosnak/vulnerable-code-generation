//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data structures
typedef struct {
    char* name;
    bool state;
} Device;

typedef struct {
    char* name;
    Device* devices;
    int num_devices;
} Room;

// Function prototypes
void print_room(Room* room);
void print_device(Device* device);
void turn_on_device(Device* device);
void turn_off_device(Device* device);
void toggle_device(Device* device);

// Main function
int main() {
    // Create a room
    Room bedroom = {
        .name = "Bedroom",
        .devices = NULL,
        .num_devices = 0
    };

    // Add devices to the room
    Device* lamp = malloc(sizeof(Device));
    lamp->name = "Lamp";
    lamp->state = false;

    Device* fan = malloc(sizeof(Device));
    fan->name = "Fan";
    fan->state = false;

    Device* tv = malloc(sizeof(Device));
    tv->name = "TV";
    tv->state = false;

    bedroom.devices = realloc(bedroom.devices, (bedroom.num_devices + 3) * sizeof(Device));
    bedroom.devices[bedroom.num_devices++] = *lamp;
    bedroom.devices[bedroom.num_devices++] = *fan;
    bedroom.devices[bedroom.num_devices++] = *tv;

    // Print the room
    print_room(&bedroom);

    // Turn on the lamp
    turn_on_device(lamp);

    // Turn off the fan
    turn_off_device(fan);

    // Toggle the TV
    toggle_device(tv);

    // Print the room again
    print_room(&bedroom);

    // Free the memory
    free(lamp);
    free(fan);
    free(tv);
    free(bedroom.devices);

    return 0;
}

// Function definitions
void print_room(Room* room) {
    printf("Room: %s\n", room->name);
    for (int i = 0; i < room->num_devices; i++) {
        print_device(&room->devices[i]);
    }
    printf("\n");
}

void print_device(Device* device) {
    printf("Device: %s, State: %s\n", device->name, device->state ? "On" : "Off");
}

void turn_on_device(Device* device) {
    device->state = true;
}

void turn_off_device(Device* device) {
    device->state = false;
}

void toggle_device(Device* device) {
    device->state = !device->state;
}