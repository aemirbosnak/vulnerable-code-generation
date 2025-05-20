//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_number;
    char room_type;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insert_room(Room** head, int room_number, char room_type, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Define a function to search for a room in the linked list
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

// Define a function to update the occupancy of a room
void update_occupancy(Room* head, int room_number, int new_occupancy) {
    Room* room = search_room(head, room_number);

    if (room) {
        room->occupancy = new_occupancy;
    }
}

// Main function
int main() {
    Room* head = NULL;

    // Insert some rooms into the linked list
    insert_room(&head, 101, 'A', 2);
    insert_room(&head, 102, 'B', 1);
    insert_room(&head, 103, 'A', 3);
    insert_room(&head, 104, 'B', 2);

    // Search for a room and update its occupancy
    update_occupancy(head, 102, 3);

    // Print the updated room occupancy
    Room* room = search_room(head, 102);
    if (room) {
        printf("Room number: %d, Occupancy: %d\n", room->room_number, room->occupancy);
    }

    return 0;
}