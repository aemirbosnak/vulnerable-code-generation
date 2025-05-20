//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    double price;
    struct Room* next;
} Room;

// Define the hotel structure
typedef struct Hotel {
    Room* head;
    int numRooms;
    double totalRevenue;
} Hotel;

// Function to insert a room into the hotel
void insertRoom(Hotel* hotel, Room* room) {
    if (hotel->head == NULL) {
        hotel->head = room;
    } else {
        hotel->head->next = room;
        hotel->head = room;
    }
    hotel->numRooms++;
}

// Function to find a room in the hotel
Room* findRoom(Hotel* hotel, char* name) {
    Room* currentRoom = hotel->head;
    while (currentRoom) {
        if (strcmp(currentRoom->name, name) == 0) {
            return currentRoom;
        }
        currentRoom = currentRoom->next;
    }
    return NULL;
}

// Function to calculate the total revenue of the hotel
double calculateTotalRevenue(Hotel* hotel) {
    double totalRevenue = 0;
    Room* currentRoom = hotel->head;
    while (currentRoom) {
        totalRevenue += currentRoom->price;
        currentRoom = currentRoom->next;
    }
    return totalRevenue;
}

// Main function
int main() {
    // Create a hotel
    Hotel* hotel = malloc(sizeof(Hotel));
    hotel->head = NULL;
    hotel->numRooms = 0;
    hotel->totalRevenue = 0;

    // Insert some rooms into the hotel
    Room* room1 = malloc(sizeof(Room));
    strcpy(room1->name, "Room 1");
    room1->number = 1;
    room1->price = 100;
    insertRoom(hotel, room1);

    Room* room2 = malloc(sizeof(Room));
    strcpy(room2->name, "Room 2");
    room2->number = 2;
    room2->price = 120;
    insertRoom(hotel, room2);

    // Find a room in the hotel
    Room* foundRoom = findRoom(hotel, "Room 1");
    if (foundRoom) {
        printf("Found room: %s\n", foundRoom->name);
    } else {
        printf("Room not found.\n");
    }

    // Calculate the total revenue of the hotel
    double totalRevenue = calculateTotalRevenue(hotel);
    printf("Total revenue: %f\n", totalRevenue);

    // Free the memory allocated for the rooms and the hotel
    free(room1);
    free(room2);
    free(hotel);

    return 0;
}