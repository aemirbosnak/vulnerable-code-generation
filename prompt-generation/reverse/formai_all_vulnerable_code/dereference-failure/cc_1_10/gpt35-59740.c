//FormAI DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// This program is a simple example of a Hotel Management System written in C.

// Define a `room` struct to hold information about each hotel room
struct room {
    int roomNumber;
    char* roomType;
    float rate;
    int occupied;
};

// Define a function to add rooms to the inventory
void addRoom(struct room** rooms, int* numRooms) {
    // Allocate memory for a new room struct
    struct room* newRoom = malloc(sizeof(struct room));

    // Prompt the user for the new room's details
    printf("Enter room number: ");
    scanf("%d", &newRoom->roomNumber);
    printf("Enter room type: ");
    newRoom->roomType = malloc(20 * sizeof(char));
    scanf("%s", newRoom->roomType);
    printf("Enter daily rate: ");
    scanf("%f", &newRoom->rate);
    newRoom->occupied = 0;

    // Increase the size of the `rooms` array and add the new room to it
    (*numRooms)++;
    *rooms = realloc(*rooms, (*numRooms) * sizeof(struct room));
    (*rooms)[*numRooms - 1] = *newRoom;

    // Free memory used by the new room struct
    free(newRoom);

    printf("\nRoom added successfully!\n\n");
}

// Define a function to display the list of available rooms
void displayRooms(struct room* rooms, int numRooms) {
    printf("\n=== AVAILABLE ROOMS ===\n\n");
    for (int i = 0; i < numRooms; i++) {
        if (!rooms[i].occupied) {
            printf("Room %d - Type: %s, Daily Rate: $%.2f\n",
                rooms[i].roomNumber, rooms[i].roomType, rooms[i].rate);
        }
    }
    printf("\n");
}

// Define a function to book a room
void bookRoom(struct room* rooms, int numRooms) {
    int roomNumber;
    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);

    // Find the room with the specified room number
    struct room* room = NULL;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            room = &rooms[i];
        }
    }

    // Book the room if it is available
    if (room && !room->occupied) {
        room->occupied = 1;
        printf("\nRoom %d booked successfully!\n\n", roomNumber);
    }
    else {
        printf("\nRoom %d is not available!\n\n", roomNumber);
    }
}

int main() {
    struct room* rooms = NULL;
    int numRooms = 0;
    char choice;

    do {
        printf("=== HOTEL MANAGEMENT SYSTEM ===\n\n");
        printf("1. Add Room\n");
        printf("2. Display Available Rooms\n");
        printf("3. Book Room\n");
        printf("4. Exit\n\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            addRoom(&rooms, &numRooms);
            break;
        case '2':
            displayRooms(rooms, numRooms);
            break;
        case '3':
            bookRoom(rooms, numRooms);
            break;
        case '4':
            printf("\nExiting...\n\n");
            break;
        default:
            printf("\nInvalid choice!\n\n");
            break;
        }
    } while (choice != '4');

    return 0;
}