//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct room {
    int room_no;
    char status;
    int occupancy;
    struct room* next;
} room;

// Function to insert a room into the linked list
void insert_room(room** head, int room_no, char status, int occupancy) {
    room* new_room = (room*)malloc(sizeof(room));
    new_room->room_no = room_no;
    new_room->status = status;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Function to search for a room in the linked list
room* search_room(room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Function to update the status of a room
void update_room_status(room* head, int room_no, char status) {
    room* room = search_room(head, room_no);
    if (room) {
        room->status = status;
    }
}

// Function to update the occupancy of a room
void update_room_occupancy(room* head, int room_no, int occupancy) {
    room* room = search_room(head, room_no);
    if (room) {
        room->occupancy = occupancy;
    }
}

// Main function
int main() {
    room* head = NULL;

    // Insert some rooms
    insert_room(&head, 101, 'O', 2);
    insert_room(&head, 102, 'A', 0);
    insert_room(&head, 103, 'O', 1);

    // Update the status of room 102
    update_room_status(head, 102, 'C');

    // Update the occupancy of room 101
    update_room_occupancy(head, 101, 3);

    // Search for room 103
    room* room = search_room(head, 103);
    if (room) {
        printf("Room number: %d\n", room->room_no);
        printf("Status: %c\n", room->status);
        printf("Occupancy: %d\n", room->occupancy);
    }

    return 0;
}