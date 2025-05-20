//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define the function to insert a room into the linked list
void insertRoom(Room* head, int number, char type, int occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }
}

// Define the function to find a room by number
Room* findRoom(Room* head, int number) {
    Room* currentRoom = head;

    while (currentRoom) {
        if (currentRoom->number == number) {
            return currentRoom;
        } else {
            currentRoom = currentRoom->next;
        }
    }

    return NULL;
}

// Define the function to check if a room is occupied
int isRoomOccupied(Room* head, int number) {
    Room* currentRoom = findRoom(head, number);

    if (currentRoom) {
        return currentRoom->occupancy;
    } else {
        return -1;
    }
}

int main() {
    // Create a linked list of rooms
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'A', 2);
    insertRoom(head, 102, 'B', 1);
    insertRoom(head, 103, 'A', 0);
    insertRoom(head, 104, 'B', 3);

    // Check if a room is occupied
    if (isRoomOccupied(head, 102) == 1) {
        printf("Room 102 is occupied.\n");
    } else {
        printf("Room 102 is not occupied.\n");
    }

    return 0;
}