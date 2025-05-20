//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct room {
    char name[20];
    int number;
    double price;
    struct room* next;
} room;

// Define a function to insert a room into the linked list
void insertRoom(room** head, char* name, int number, double price) {
    room* newRoom = (room*)malloc(sizeof(room));
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

// Define a function to search for a room by name
room* searchRoomByName(room* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Define a function to list all rooms
void listRooms(room* head) {
    while (head) {
        printf("Room name: %s, number: %d, price: %.2lf\n", head->name, head->number, head->price);
        head = head->next;
    }
}

// Main function
int main() {
    // Create a linked list of rooms
    room* head = NULL;

    // Insert some rooms
    insertRoom(&head, "Baker Street", 101, 100.0);
    insertRoom(&head, "221B Baker Street", 221, 200.0);
    insertRoom(&head, "The Pink House", 321, 300.0);

    // Search for a room by name
    room* room = searchRoomByName(head, "221B Baker Street");
    if (room) {
        printf("Room name: %s, number: %d, price: %.2lf\n", room->name, room->number, room->price);
    } else {
        printf("Room not found.\n");
    }

    // List all rooms
    listRooms(head);

    return 0;
}