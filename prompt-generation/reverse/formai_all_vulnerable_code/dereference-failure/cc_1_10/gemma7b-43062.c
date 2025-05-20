//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Function to insert a room into the linked list
void insertRoom(Room** head, int number, char status, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Function to search for a room by number
Room* searchRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to check if a room is available
int isRoomAvailable(Room* head, int number) {
    Room* room = searchRoom(head, number);

    if (room) {
        return room->status == 'A';
    } else {
        return 0;
    }
}

// Function to book a room
void bookRoom(Room** head, int number, char name) {
    Room* room = searchRoom(*head, number);

    if (room) {
        room->status = 'B';
        room->occupancy = 1;
        printf("Room booked successfully!\n");
    } else {
        printf("Error booking room.\n");
    }
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(&head, 101, 'A', 0);
    insertRoom(&head, 102, 'A', 0);
    insertRoom(&head, 103, 'A', 0);

    // Book a room
    bookRoom(&head, 102, "John Doe");

    // Check if the room is available
    if (isRoomAvailable(head, 102)) {
        printf("Room 102 is available.\n");
    } else {
        printf("Room 102 is not available.\n");
    }

    return 0;
}