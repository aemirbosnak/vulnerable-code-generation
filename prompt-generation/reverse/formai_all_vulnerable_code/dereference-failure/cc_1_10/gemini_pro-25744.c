//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices and rooms
#define MAX_DEVICES 10
#define MAX_ROOMS 10

// Define the device types
enum device_type {
    LIGHT,
    SWITCH,
    SENSOR
};

// Define the room types
enum room_type {
    LIVING_ROOM,
    BEDROOM,
    KITCHEN,
    BATHROOM
};

// Define the device structure
struct device {
    char name[20];
    enum device_type type;
    enum room_type room;
    int state; // 0 = off, 1 = on
};

// Define the room structure
struct room {
    char name[20];
    enum room_type type;
    struct device devices[MAX_DEVICES];
    int num_devices;
};

// Define the smart home structure
struct smart_home {
    struct room rooms[MAX_ROOMS];
    int num_rooms;
};

// Create a new smart home
struct smart_home *create_smart_home() {
    struct smart_home *home = malloc(sizeof(struct smart_home));
    home->num_rooms = 0;
    return home;
}

// Add a new room to the smart home
void add_room(struct smart_home *home, char *name, enum room_type type) {
    if (home->num_rooms < MAX_ROOMS) {
        strcpy(home->rooms[home->num_rooms].name, name);
        home->rooms[home->num_rooms].type = type;
        home->rooms[home->num_rooms].num_devices = 0;
        home->num_rooms++;
    }
}

// Add a new device to a room
void add_device(struct smart_home *home, char *name, enum device_type type, enum room_type room) {
    int i;
    for (i = 0; i < home->num_rooms; i++) {
        if (home->rooms[i].type == room) {
            if (home->rooms[i].num_devices < MAX_DEVICES) {
                strcpy(home->rooms[i].devices[home->rooms[i].num_devices].name, name);
                home->rooms[i].devices[home->rooms[i].num_devices].type = type;
                home->rooms[i].devices[home->rooms[i].num_devices].room = room;
                home->rooms[i].devices[home->rooms[i].num_devices].state = 0;
                home->rooms[i].num_devices++;
                return;
            }
        }
    }
}

// Turn on a device
void turn_on_device(struct smart_home *home, char *name) {
    int i, j;
    for (i = 0; i < home->num_rooms; i++) {
        for (j = 0; j < home->rooms[i].num_devices; j++) {
            if (strcmp(home->rooms[i].devices[j].name, name) == 0) {
                home->rooms[i].devices[j].state = 1;
                return;
            }
        }
    }
}

// Turn off a device
void turn_off_device(struct smart_home *home, char *name) {
    int i, j;
    for (i = 0; i < home->num_rooms; i++) {
        for (j = 0; j < home->rooms[i].num_devices; j++) {
            if (strcmp(home->rooms[i].devices[j].name, name) == 0) {
                home->rooms[i].devices[j].state = 0;
                return;
            }
        }
    }
}

// Print the status of a device
void print_device_status(struct smart_home *home, char *name) {
    int i, j;
    for (i = 0; i < home->num_rooms; i++) {
        for (j = 0; j < home->rooms[i].num_devices; j++) {
            if (strcmp(home->rooms[i].devices[j].name, name) == 0) {
                printf("%s is %s\n", name, home->rooms[i].devices[j].state == 1 ? "on" : "off");
                return;
            }
        }
    }
}

// Print the status of all devices in a room
void print_room_status(struct smart_home *home, char *name) {
    int i, j;
    for (i = 0; i < home->num_rooms; i++) {
        if (strcmp(home->rooms[i].name, name) == 0) {
            printf("Devices in %s:\n", name);
            for (j = 0; j < home->rooms[i].num_devices; j++) {
                printf("  %s is %s\n", home->rooms[i].devices[j].name, home->rooms[i].devices[j].state == 1 ? "on" : "off");
            }
            return;
        }
    }
}

// Print the status of all devices in the smart home
void print_smart_home_status(struct smart_home *home) {
    int i, j;
    for (i = 0; i < home->num_rooms; i++) {
        printf("Devices in %s:\n", home->rooms[i].name);
        for (j = 0; j < home->rooms[i].num_devices; j++) {
            printf("  %s is %s\n", home->rooms[i].devices[j].name, home->rooms[i].devices[j].state == 1 ? "on" : "off");
        }
    }
}

// Main function
int main() {
    // Create a new smart home
    struct smart_home *home = create_smart_home();

    // Add some rooms to the smart home
    add_room(home, "Living Room", LIVING_ROOM);
    add_room(home, "Bedroom", BEDROOM);
    add_room(home, "Kitchen", KITCHEN);
    add_room(home, "Bathroom", BATHROOM);

    // Add some devices to the rooms
    add_device(home, "Lamp", LIGHT, LIVING_ROOM);
    add_device(home, "TV", LIGHT, LIVING_ROOM);
    add_device(home, "Fan", LIGHT, BEDROOM);
    add_device(home, "Light", LIGHT, KITCHEN);
    add_device(home, "Refrigerator", LIGHT, KITCHEN);
    add_device(home, "Light", LIGHT, BATHROOM);

    // Turn on some devices
    turn_on_device(home, "Lamp");
    turn_on_device(home, "Fan");
    turn_on_device(home, "Refrigerator");

    // Print the status of the smart home
    print_smart_home_status(home);

    return 0;
}