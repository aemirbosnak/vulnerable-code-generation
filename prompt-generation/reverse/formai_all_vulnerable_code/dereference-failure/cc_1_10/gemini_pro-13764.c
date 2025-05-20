//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int room_number;
    char *room_type;
    double price;
    int availability;
} room;

typedef struct {
    char *name;
    char *address;
    char *phone_number;
    room *rooms;
    int num_rooms;
} hotel;

int main() {
    // Create a hotel
    hotel h1;
    h1.name = "The Grand Hotel";
    h1.address = "123 Main Street";
    h1.phone_number = "555-1212";
    h1.num_rooms = 100;

    // Create some rooms
    h1.rooms = malloc(h1.num_rooms * sizeof(room));
    for (int i = 0; i < h1.num_rooms; i++) {
        h1.rooms[i].room_number = i + 1;
        h1.rooms[i].room_type = "Standard";
        h1.rooms[i].price = 100.0;
        h1.rooms[i].availability = 1;
    }

    // Print the hotel information
    printf("Hotel: %s\n", h1.name);
    printf("Address: %s\n", h1.address);
    printf("Phone Number: %s\n", h1.phone_number);
    printf("Number of Rooms: %d\n", h1.num_rooms);

    // Print the room information
    for (int i = 0; i < h1.num_rooms; i++) {
        printf("Room %d:\n", h1.rooms[i].room_number);
        printf("Type: %s\n", h1.rooms[i].room_type);
        printf("Price: $%.2f\n", h1.rooms[i].price);
        printf("Availability: %d\n", h1.rooms[i].availability);
        printf("\n");
    }

    return 0;
}