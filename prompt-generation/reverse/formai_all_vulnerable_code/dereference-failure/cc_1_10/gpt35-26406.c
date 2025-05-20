//FormAI DATASET v1.0 Category: Smart home light control ; Style: Romeo and Juliet
// Romeo and Juliet: A Smart Home Light Control Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants
#define MAX_ROOMS 5
#define MAX_BULBS 10

// Define our room and bulb structures
typedef struct {
    char name[20];
    int num_bulbs;
    int bulbs[MAX_BULBS];
} Room;

typedef struct {
    int brightness;
    int color;
} Bulb;

// Define our global variables
Room rooms[MAX_ROOMS];
int num_rooms = 0;

// Define our functions
void add_room(char name[]);
void add_bulb(int room_index, int brightness, int color);
void print_state();
void set_brightness(int room_index, int bulb_index, int brightness);
void set_color(int room_index, int bulb_index, int color);

// The main function
int main() {

    // Welcome messages
    printf("Welcome to Smart Home Light Control - Romeo and Juliet style!\n");
    printf("Let us create some rooms first.\n\n");

    // Add some rooms
    add_room("Balcony");
    add_room("Garden");
    add_room("Bedroom");
    add_room("Bathroom");

    // Add some bulbs
    add_bulb(0, 100, 1);
    add_bulb(0, 75, 2);
    add_bulb(1, 50, 3);
    add_bulb(2, 100, 1);
    add_bulb(2, 75, 2);
    add_bulb(2, 50, 3);
    add_bulb(3, 100, 1);
    add_bulb(3, 75, 2);

    // Print the initial state
    print_state();

    // Make some changes
    set_brightness(1, 0, 100);
    set_brightness(2, 2, 100);
    set_color(3, 1, 2);

    // Print the final state
    print_state();

    return 0;

}

// Add a room
void add_room(char name[]) {

    // Create the room
    Room room;
    strcpy(room.name, name);
    room.num_bulbs = 0;

    // Add the room to the list of rooms
    rooms[num_rooms] = room;
    num_rooms++;

    // Print a message
    printf("Added room '%s'\n\n", name);

}

// Add a bulb to a room
void add_bulb(int room_index, int brightness, int color) {

    // Check if the room exists
    if (room_index >= num_rooms) {
        printf("Error: Room index %d out of range (0-%d)\n\n", room_index, num_rooms-1);
        return;
    }

    // Create the bulb
    Bulb bulb;
    bulb.brightness = brightness;
    bulb.color = color;

    // Add the bulb to the room
    Room *room = &rooms[room_index];
    int bulb_index = room->num_bulbs;
    room->bulbs[bulb_index] = bulb_index;
    room->num_bulbs++;

    // Print a message
    printf("Added bulb in room '%s' with brightness %d and color %d\n\n", room->name, brightness, color);

}

// Print the current state
void print_state() {

    // Print a header
    printf("Current State:\n\n");

    // Loop through the rooms
    for (int i = 0; i < num_rooms; i++) {

        // Print the room name
        printf("%s:\n", rooms[i].name);

        // Loop through the bulbs in the room
        Room *room = &rooms[i];
        for (int j = 0; j < room->num_bulbs; j++) {

            // Get the bulb index
            int bulb_index = room->bulbs[j];

            // Get the bulb properties
            Bulb *bulb = &room->bulbs[bulb_index];

            // Print the bulb properties
            printf("  Bulb %d: brightness=%d, color=%d\n", j+1, bulb->brightness, bulb->color);

        }

        // Print a blank line
        printf("\n");

    }

    // Print a footer
    printf("End State.\n\n");

}

// Set the brightness of a bulb in a room
void set_brightness(int room_index, int bulb_index, int brightness) {

    // Check if the room exists
    if (room_index >= num_rooms) {
        printf("Error: Room index %d out of range (0-%d)\n\n", room_index, num_rooms-1);
        return;
    }

    // Get the room
    Room *room = &rooms[room_index];

    // Check if the bulb exists
    if (bulb_index >= room->num_bulbs) {
        printf("Error: Bulb index %d out of range (0-%d) for room '%s'\n\n", bulb_index, room->num_bulbs-1, room->name);
        return;
    }

    // Get the bulb
    Bulb *bulb = &room->bulbs[bulb_index];

    // Set the brightness
    bulb->brightness = brightness;

    // Print a message
    printf("Set brightness of bulb %d in room '%s' to %d.\n\n", bulb_index+1, room->name, brightness);

}

// Set the color of a bulb in a room
void set_color(int room_index, int bulb_index, int color) {

    // Check if the room exists
    if (room_index >= num_rooms) {
        printf("Error: Room index %d out of range (0-%d)\n\n", room_index, num_rooms-1);
        return;
    }

    // Get the room
    Room *room = &rooms[room_index];

    // Check if the bulb exists
    if (bulb_index >= room->num_bulbs) {
        printf("Error: Bulb index %d out of range (0-%d) for room '%s'\n\n", bulb_index, room->num_bulbs-1, room->name);
        return;
    }

    // Get the bulb
    Bulb *bulb = &room->bulbs[bulb_index];

    // Set the color
    bulb->color = color;

    // Print a message
    printf("Set color of bulb %d in room '%s' to %d.\n\n", bulb_index+1, room->name, color);

}