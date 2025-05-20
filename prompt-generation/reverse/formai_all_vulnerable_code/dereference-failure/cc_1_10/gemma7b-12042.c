//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store room information
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insert_room(Room** head, int room_number, char status, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
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
Room* search_room(Room* head, int room_number) {
    while (head) {
        if (head->room_number == room_number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Define a function to check if a room is available
int is_room_available(Room* head, int room_number) {
    Room* room = search_room(head, room_number);

    if (room) {
        return room->status == 'A';
    } else {
        return 0;
    }
}

// Define a function to book a room
void book_room(Room** head, int room_number, int occupancy) {
    Room* room = search_room(*head, room_number);

    if (room) {
        if (room->status == 'A') {
            room->occupancy = occupancy;
            room->status = 'B';
            printf("Room booked successfully!\n");
        } else {
            printf("Room is not available.\n");
        }
    } else {
        printf("Room not found.\n");
    }
}

int main() {
    Room* head = NULL;

    // Insert some rooms
    insert_room(&head, 101, 'A', 0);
    insert_room(&head, 102, 'A', 0);
    insert_room(&head, 103, 'A', 0);

    // Book a room
    book_room(&head, 102, 2);

    // Check if the room is available
    if (is_room_available(head, 102)) {
        printf("Room is available.\n");
    } else {
        printf("Room is not available.\n");
    }

    return 0;
}