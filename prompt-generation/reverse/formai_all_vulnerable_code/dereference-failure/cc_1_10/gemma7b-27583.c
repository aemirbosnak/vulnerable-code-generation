//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[50];
    int room_number;
    double price;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a new room into the hotel management system
void insertRoom(HotelManagementSystem* head, char* name, int room_number, double price) {
    HotelManagementSystem* newRoom = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(newRoom->name, name);
    newRoom->room_number = room_number;
    newRoom->price = price;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }
}

// Function to search for a room in the hotel management system
HotelManagementSystem* searchRoom(HotelManagementSystem* head, int room_number) {
    HotelManagementSystem* currentRoom = head;

    while (currentRoom) {
        if (currentRoom->room_number == room_number) {
            return currentRoom;
        }
        currentRoom = currentRoom->next;
    }

    return NULL;
}

// Function to update the price of a room in the hotel management system
void updatePrice(HotelManagementSystem* head, int room_number, double new_price) {
    HotelManagementSystem* currentRoom = searchRoom(head, room_number);

    if (currentRoom) {
        currentRoom->price = new_price;
    }
}

// Main function
int main() {
    HotelManagementSystem* head = NULL;

    // Insert some rooms
    insertRoom(head, "John Doe", 101, 50.0);
    insertRoom(head, "Jane Doe", 102, 60.0);
    insertRoom(head, "Peter Pan", 103, 70.0);

    // Search for a room
    HotelManagementSystem* foundRoom = searchRoom(head, 102);

    // If the room is found, update its price
    if (foundRoom) {
        updatePrice(head, 102, 80.0);
    }

    // Print the updated room price
    foundRoom = searchRoom(head, 102);
    printf("The price of room %d is $%.2f", foundRoom->room_number, foundRoom->price);

    return 0;
}