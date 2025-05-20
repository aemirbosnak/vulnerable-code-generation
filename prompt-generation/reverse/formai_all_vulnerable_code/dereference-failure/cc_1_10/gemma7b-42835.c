//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
    char name[20];
    int room_number;
    float rate;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Create a linked list of hotel management system structures
HotelManagementSystem* head = NULL;

// Function to add a new room to the hotel management system
void addRoom(char* name, int room_number, float rate) {
    HotelManagementSystem* newRoom = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(newRoom->name, name);
    newRoom->room_number = room_number;
    newRoom->rate = rate;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
        head = newRoom;
    }
}

// Function to search for a room in the hotel management system
HotelManagementSystem* searchRoom(int room_number) {
    HotelManagementSystem* currentRoom = head;

    while (currentRoom) {
        if (currentRoom->room_number == room_number) {
            return currentRoom;
        }
        currentRoom = currentRoom->next;
    }

    return NULL;
}

// Function to update the rate of a room in the hotel management system
void updateRate(int room_number, float new_rate) {
    HotelManagementSystem* currentRoom = searchRoom(room_number);

    if (currentRoom) {
        currentRoom->rate = new_rate;
    }
}

// Function to list all rooms in the hotel management system
void listRooms() {
    HotelManagementSystem* currentRoom = head;

    while (currentRoom) {
        printf("Name: %s, Room Number: %d, Rate: %.2f\n", currentRoom->name, currentRoom->room_number, currentRoom->rate);
        currentRoom = currentRoom->next;
    }
}

int main() {
    // Add some rooms to the hotel management system
    addRoom("John Doe", 101, 50.0);
    addRoom("Jane Doe", 102, 60.0);
    addRoom("Peter Pan", 103, 70.0);

    // List all rooms in the hotel management system
    listRooms();

    // Update the rate of room 102
    updateRate(102, 80.0);

    // List all rooms in the hotel management system again
    listRooms();

    return 0;
}