//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int room_number;
    char *room_type;
    int price;
    int availability;
} Room;

typedef struct {
    char *name;
    char *address;
    char *phone_number;
    Room *rooms;
    int num_rooms;
} Hotel;

void print_hotel(Hotel *hotel) {
    printf("Hotel: %s\n", hotel->name);
    printf("Address: %s\n", hotel->address);
    printf("Phone Number: %s\n", hotel->phone_number);
    printf("Rooms:\n");
    for (int i = 0; i < hotel->num_rooms; i++) {
        Room *room = &hotel->rooms[i];
        printf("Room Number: %d\n", room->room_number);
        printf("Room Type: %s\n", room->room_type);
        printf("Price: %d\n", room->price);
        printf("Availability: %d\n", room->availability);
        printf("\n");
    }
}

int main() {
    // Initialize the hotel
    Hotel hotel;
    hotel.name = "The Grand Hotel";
    hotel.address = "123 Main Street";
    hotel.phone_number = "555-1212";
    hotel.num_rooms = 10;
    hotel.rooms = malloc(sizeof(Room) * hotel.num_rooms);

    // Initialize the rooms
    for (int i = 0; i < hotel.num_rooms; i++) {
        Room *room = &hotel.rooms[i];
        room->room_number = i + 1;
        room->room_type = "Standard";
        room->price = 100;
        room->availability = 1;
    }

    // Print the hotel
    print_hotel(&hotel);

    return 0;
}