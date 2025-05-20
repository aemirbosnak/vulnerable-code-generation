//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_number;
    char room_type;
    int occupancy;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* create_room_list() {
    Room* head = NULL;
    return head;
}

// Insert a room into the linked list
void insert_room(Room* head, int room_number, char room_type, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->room_type = room_type;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        Room* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_room;
    }
}

// Search for a room in the linked list
Room* search_room(Room* head, int room_number) {
    Room* current = head;
    while (current) {
        if (current->room_number == room_number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Update the occupancy of a room
void update_occupancy(Room* head, int room_number, int new_occupancy) {
    Room* room = search_room(head, room_number);
    if (room) {
        room->occupancy = new_occupancy;
    }
}

// Print the rooms in the linked list
void print_rooms(Room* head) {
    Room* current = head;
    while (current) {
        printf("Room number: %d, Room type: %c, Occupancy: %d\n", current->room_number, current->room_type, current->occupancy);
        current = current->next;
    }
}

int main() {
    // Create a linked list of rooms
    Room* head = create_room_list();

    // Insert rooms into the linked list
    insert_room(head, 101, 'A', 2);
    insert_room(head, 102, 'B', 1);
    insert_room(head, 103, 'A', 3);

    // Print the rooms in the linked list
    print_rooms(head);

    // Update the occupancy of a room
    update_occupancy(head, 102, 2);

    // Print the rooms in the linked list after updating occupancy
    print_rooms(head);

    return 0;
}