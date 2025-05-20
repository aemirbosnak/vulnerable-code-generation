//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room *next;
} Room;

// Define a function to insert a room into the linked list
void insert_room(Room **head, int room_number, char status, int occupancy) {
    Room *new_room = (Room *)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = status;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Define a function to search for a room
Room *search_room(Room *head, int room_number) {
    while (head) {
        if (head->room_number == room_number) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define a function to update the status of a room
void update_room_status(Room *head, int room_number, char new_status) {
    Room *room = search_room(head, room_number);

    if (room) {
        room->status = new_status;
    }
}

// Define a function to update the occupancy of a room
void update_room_occupancy(Room *head, int room_number, int new_occupancy) {
    Room *room = search_room(head, room_number);

    if (room) {
        room->occupancy = new_occupancy;
    }
}

int main() {
    // Create a linked list of rooms
    Room *head = NULL;

    // Insert some rooms
    insert_room(&head, 101, 'O', 2);
    insert_room(&head, 102, 'A', 1);
    insert_room(&head, 103, 'O', 3);

    // Search for a room
    Room *room = search_room(head, 102);

    // Update the status of a room
    update_room_status(head, 101, 'A');

    // Update the occupancy of a room
    update_room_occupancy(head, 103, 4);

    // Print the updated list of rooms
    for (room = head; room; room = room->next) {
        printf("Room number: %d, Status: %c, Occupancy: %d\n", room->room_number, room->status, room->occupancy);
    }

    return 0;
}