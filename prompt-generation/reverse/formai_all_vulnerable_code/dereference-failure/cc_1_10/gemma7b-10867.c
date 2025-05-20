//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the hotel
void insertRoom(Room** head, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define a function to check if a room is available
int isRoomAvailable(Room* head, int number) {
    while (head) {
        if (head->number == number && head->occupancy == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

// Define a function to check if a room type is available
int isTypeAvailable(Room* head, char type) {
    while (head) {
        if (head->type == type && head->occupancy == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

// Main function
int main() {
    // Create a head of the hotel room list
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'A', 0);
    insertRoom(&head, 102, 'B', 2);
    insertRoom(&head, 103, 'A', 1);

    // Check if room 101 is available
    if (isRoomAvailable(head, 101)) {
        printf("Room 101 is available.\n");
    } else {
        printf("Room 101 is not available.\n");
    }

    // Check if room type A is available
    if (isTypeAvailable(head, 'A')) {
        printf("Room type A is available.\n");
    } else {
        printf("Room type A is not available.\n");
    }

    return 0;
}