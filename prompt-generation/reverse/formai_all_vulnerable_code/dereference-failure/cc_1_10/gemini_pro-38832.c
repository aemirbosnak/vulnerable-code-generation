//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DEVICES 10

struct device {
    char name[32];
    char type[16];
    int state; // 0 = off, 1 = on
};

struct room {
    char name[32];
    int num_devices;
    struct device* devices[MAX_DEVICES];
};

struct home {
    char name[32];
    int num_rooms;
    struct room* rooms[MAX_DEVICES];
};

// Create a new home
struct home* create_home(char* name) {
    struct home* home = malloc(sizeof(struct home));
    strcpy(home->name, name);
    home->num_rooms = 0;
    return home;
}

// Create a new room
struct room* create_room(char* name) {
    struct room* room = malloc(sizeof(struct room));
    strcpy(room->name, name);
    room->num_devices = 0;
    return room;
}

// Create a new device
struct device* create_device(char* name, char* type) {
    struct device* device = malloc(sizeof(struct device));
    strcpy(device->name, name);
    strcpy(device->type, type);
    device->state = 0;
    return device;
}

// Add a room to a home
void add_room_to_home(struct home* home, struct room* room) {
    home->rooms[home->num_rooms++] = room;
}

// Add a device to a room
void add_device_to_room(struct room* room, struct device* device) {
    room->devices[room->num_devices++] = device;
}

// Turn on a device
void turn_on_device(struct device* device) {
    device->state = 1;
}

// Turn off a device
void turn_off_device(struct device* device) {
    device->state = 0;
}

// Get the state of a device
int get_device_state(struct device* device) {
    return device->state;
}

// Print the state of all devices in a room
void print_room_devices(struct room* room) {
    for (int i = 0; i < room->num_devices; i++) {
        printf("%s: %s\n", room->devices[i]->name, room->devices[i]->state ? "on" : "off");
    }
}

// Print the state of all rooms in a home
void print_home_rooms(struct home* home) {
    for (int i = 0; i < home->num_rooms; i++) {
        printf("%s:\n", home->rooms[i]->name);
        print_room_devices(home->rooms[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new home
    struct home* home = create_home("My Home");

    // Create a new living room
    struct room* living_room = create_room("Living Room");

    // Add the living room to the home
    add_room_to_home(home, living_room);

    // Create a new TV device
    struct device* tv = create_device("TV", "TV");

    // Add the TV to the living room
    add_device_to_room(living_room, tv);

    // Create a new lamp device
    struct device* lamp = create_device("Lamp", "Lamp");

    // Add the lamp to the living room
    add_device_to_room(living_room, lamp);

    // Turn on the TV
    turn_on_device(tv);

    // Turn off the lamp
    turn_off_device(lamp);

    // Print the state of all devices in the living room
    printf("Living Room Devices:\n");
    print_room_devices(living_room);

    // Print the state of all rooms in the home
    printf("\nHome Rooms:\n");
    print_home_rooms(home);

    return 0;
}