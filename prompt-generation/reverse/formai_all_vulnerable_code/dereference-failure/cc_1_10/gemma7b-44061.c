//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    double price;
    struct Room* next;
} Room;

// Define the hotel management structure
typedef struct HotelManagement {
    Room* head;
    int numRooms;
    double totalRevenue;
} HotelManagement;

// Create a new room
Room* createRoom(char* name, int number, double price) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->price = price;
    newRoom->next = NULL;
    return newRoom;
}

// Insert a new room at the end
void insertRoom(HotelManagement* hotel, Room* newRoom) {
    if (hotel->head == NULL) {
        hotel->head = newRoom;
    } else {
        hotel->head->next = newRoom;
        hotel->head = newRoom;
    }
    hotel->numRooms++;
}

// Calculate the total revenue
double calculateTotalRevenue(HotelManagement* hotel) {
    double totalRevenue = 0;
    Room* currentRoom = hotel->head;
    while (currentRoom) {
        totalRevenue += currentRoom->price;
        currentRoom = currentRoom->next;
    }
    return totalRevenue;
}

int main() {
    // Create a new hotel management system
    HotelManagement* hotel = (HotelManagement*)malloc(sizeof(HotelManagement));
    hotel->head = NULL;
    hotel->numRooms = 0;
    hotel->totalRevenue = 0;

    // Insert some rooms
    insertRoom(hotel, createRoom("Room 1", 1, 100));
    insertRoom(hotel, createRoom("Room 2", 2, 120));
    insertRoom(hotel, createRoom("Room 3", 3, 140));

    // Calculate the total revenue
    double totalRevenue = calculateTotalRevenue(hotel);

    // Print the total revenue
    printf("Total revenue: %.2lf", totalRevenue);

    return 0;
}