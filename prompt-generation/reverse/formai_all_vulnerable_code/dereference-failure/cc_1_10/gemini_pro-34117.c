//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Structures for Hotel and Room
typedef struct Hotel {
    char name[50];
    int num_rooms;
    struct Room *rooms;
} Hotel;

typedef struct Room {
    int room_number;
    char type[20]; // e.g. "Standard", "Deluxe", "Suite"
    int capacity; // number of occupants allowed
    float price;
} Room;

// Function to create a new hotel
Hotel *create_hotel(char *name, int num_rooms) {
    Hotel *hotel = (Hotel *)malloc(sizeof(Hotel));
    strcpy(hotel->name, name);
    hotel->num_rooms = num_rooms;
    hotel->rooms = (Room *)malloc(num_rooms * sizeof(Room));
    return hotel;
}

// Function to add a room to a hotel
void add_room(Hotel *hotel, Room room) {
    hotel->rooms[hotel->num_rooms++] = room;
}

// Function to find a room by room number
Room *find_room_by_number(Hotel *hotel, int room_number) {
    for (int i = 0; i < hotel->num_rooms; i++) {
        if (hotel->rooms[i].room_number == room_number) {
            return &hotel->rooms[i];
        }
    }
    return NULL;
}

// Function to print the details of a hotel
void print_hotel(Hotel *hotel) {
    printf("Hotel Name: %s\n", hotel->name);
    printf("Number of Rooms: %d\n", hotel->num_rooms);
    for (int i = 0; i < hotel->num_rooms; i++) {
        printf("Room %d:\n", hotel->rooms[i].room_number);
        printf("Type: %s\n", hotel->rooms[i].type);
        printf("Capacity: %d\n", hotel->rooms[i].capacity);
        printf("Price: %.2f\n", hotel->rooms[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new hotel
    Hotel *hotel = create_hotel("Grand Hyatt", 10);

    // Add some rooms to the hotel
    Room room1 = {101, "Standard", 2, 100.0};
    add_room(hotel, room1);
    Room room2 = {102, "Deluxe", 4, 150.0};
    add_room(hotel, room2);
    Room room3 = {103, "Suite", 6, 200.0};
    add_room(hotel, room3);

    // Find a room by room number
    Room *room = find_room_by_number(hotel, 102);
    if (room != NULL) {
        printf("Room details:\n");
        printf("Room Number: %d\n", room->room_number);
        printf("Type: %s\n", room->type);
        printf("Capacity: %d\n", room->capacity);
        printf("Price: %.2f\n", room->price);
        printf("\n");
    } else {
        printf("Room not found.\n");
    }

    // Print the details of the hotel
    print_hotel(hotel);

    return 0;
}