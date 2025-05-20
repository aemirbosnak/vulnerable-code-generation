//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_number;
    char room_type;
    int occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insert_room(Room* head, int room_number, char room_type, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
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

// Define a function to print the list of rooms
void print_rooms(Room* head) {
    while (head) {
        printf("Room number: %d, Room type: %c, Occupancy: %d\n", head->room_number, head->room_type, head->occupancy);
        head = head->next;
    }
}

int main() {
    Room* head = NULL;

    // Insert some rooms into the linked list
    insert_room(head, 101, 'A', 2);
    insert_room(head, 102, 'B', 1);
    insert_room(head, 103, 'A', 3);
    insert_room(head, 104, 'B', 0);

    // Print the list of rooms
    print_rooms(head);

    // Update the occupancy of room number 102
    update_occupancy(head, 102, 2);

    // Print the updated list of rooms
    print_rooms(head);

    return 0;
}