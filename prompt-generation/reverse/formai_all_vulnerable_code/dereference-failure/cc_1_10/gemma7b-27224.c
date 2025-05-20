//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room
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
int isRoomTypeAvailable(Room* head, char type) {
    while (head) {
        if (head->type == type && head->occupancy == 0) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

// Define a function to book a room
void bookRoom(Room** head, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    insertRoom(head, number, type, occupancy);
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'A', 2);
    insertRoom(&head, 102, 'B', 1);
    insertRoom(&head, 103, 'A', 3);

    // Check if room 102 is available
    if (isRoomAvailable(head, 102)) {
        printf("Room 102 is available.\n");
    }

    // Check if room type 'A' is available
    if (isRoomTypeAvailable(head, 'A')) {
        printf("Room type 'A' is available.\n");
    }

    // Book a room
    bookRoom(&head, 104, 'B', 2);

    // Check if room 104 is booked
    if (isRoomAvailable(head, 104)) {
        printf("Room 104 is not available.\n");
    }

    return 0;
}