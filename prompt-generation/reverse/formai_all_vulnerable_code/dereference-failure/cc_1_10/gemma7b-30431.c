//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    float price;
    struct Room *next;
} Room;

// Define the guest structure
typedef struct Guest {
    char name[20];
    int room_number;
    struct Guest *next;
} Guest;

// Function to insert a room
void insertRoom(Room **head, char *name, int number, float price) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->price = price;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Function to insert a guest
void insertGuest(Guest **head, char *name, int room_number) {
    Guest *newGuest = (Guest *)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_number = room_number;
    newGuest->next = NULL;

    if (*head == NULL) {
        *head = newGuest;
    } else {
        (*head)->next = newGuest;
    }
}

// Function to find a room by name
Room *findRoomByName(Room *head, char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to find a guest by name
Guest *findGuestByName(Guest *head, char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Main function
int main() {
    // Create a linked list of rooms
    Room *headRoom = NULL;
    insertRoom(&headRoom, "Room 1", 1, 100);
    insertRoom(&headRoom, "Room 2", 2, 120);
    insertRoom(&headRoom, "Room 3", 3, 140);

    // Create a linked list of guests
    Guest *headGuest = NULL;
    insertGuest(&headGuest, "Guest 1", 1);
    insertGuest(&headGuest, "Guest 2", 2);
    insertGuest(&headGuest, "Guest 3", 3);

    // Find a room by name
    Room *room = findRoomByName(headRoom, "Room 2");
    if (room) {
        printf("Room name: %s\n", room->name);
        printf("Room number: %d\n", room->number);
        printf("Room price: %.2f\n", room->price);
    }

    // Find a guest by name
    Guest *guest = findGuestByName(headGuest, "Guest 2");
    if (guest) {
        printf("Guest name: %s\n", guest->name);
        printf("Guest room number: %d\n", guest->room_number);
    }

    return 0;
}