//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a room
typedef struct Room {
    int number;
    char type;
    int occupancy;
    struct Room* next;
} Room;

// Define the structure of a guest
typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest* next;
} Guest;

// Create a linked list of rooms
Room* createRoomList() {
    Room* head = NULL;
    Room* newNode = malloc(sizeof(Room));
    newNode->number = 1;
    newNode->type = 'A';
    newNode->occupancy = 0;
    newNode->next = NULL;
    head = newNode;

    newNode = malloc(sizeof(Room));
    newNode->number = 2;
    newNode->type = 'B';
    newNode->occupancy = 1;
    newNode->next = NULL;
    head->next = newNode;

    return head;
}

// Create a linked list of guests
Guest* createGuestList() {
    Guest* head = NULL;
    Guest* newNode = malloc(sizeof(Guest));
    newNode->name[0] = 'A';
    newNode->room_number = 1;
    newNode->next = NULL;
    head = newNode;

    newNode = malloc(sizeof(Guest));
    newNode->name[0] = 'B';
    newNode->room_number = 2;
    newNode->next = NULL;
    head->next = newNode;

    return head;
}

// Check if a room is available
int isRoomAvailable(int room_number) {
    Room* head = createRoomList();
    Room* current = head;

    while (current) {
        if (current->number == room_number && current->occupancy == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Book a room
void bookRoom(char* name, int room_number) {
    Room* head = createRoomList();
    Room* current = head;

    while (current) {
        if (current->number == room_number && current->occupancy == 0) {
            current->occupancy = 1;
            Guest* newNode = malloc(sizeof(Guest));
            newNode->name[0] = name[0];
            newNode->room_number = room_number;
            newNode->next = NULL;
            current->next = newNode;
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Sorry, the room is not available.\n");
    }
}

int main() {
    bookRoom("John Doe", 1);
    bookRoom("Jane Doe", 2);

    if (isRoomAvailable(1)) {
        printf("Room 1 is available.\n");
    } else {
        printf("Room 1 is not available.\n");
    }

    return 0;
}