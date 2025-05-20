//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Hotel Management System structure
typedef struct HotelManagementSystem {
    char name[50];
    int rooms_available;
    int rooms_occupied;
    struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to insert a room into the hotel management system
void insert_room(HotelManagementSystem* head, char* name, int rooms_available, int rooms_occupied) {
    HotelManagementSystem* new_room = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
    strcpy(new_room->name, name);
    new_room->rooms_available = rooms_available;
    new_room->rooms_occupied = rooms_occupied;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        HotelManagementSystem* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_room;
    }
}

// Function to search for a room in the hotel management system
HotelManagementSystem* search_room(HotelManagementSystem* head, char* name) {
    HotelManagementSystem* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to update the number of available rooms in a room
void update_available_rooms(HotelManagementSystem* head, char* name, int rooms_available) {
    HotelManagementSystem* room = search_room(head, name);
    if (room) {
        room->rooms_available = rooms_available;
    }
}

// Function to check if a room is available
int is_room_available(HotelManagementSystem* head, char* name) {
    HotelManagementSystem* room = search_room(head, name);
    if (room) {
        return room->rooms_available > 0;
    }
    return 0;
}

int main() {
    HotelManagementSystem* head = NULL;

    // Insert some rooms
    insert_room(head, "Room 1", 10, 2);
    insert_room(head, "Room 2", 12, 4);
    insert_room(head, "Room 3", 8, 3);

    // Search for a room
    HotelManagementSystem* room = search_room(head, "Room 2");
    if (room) {
        printf("Room name: %s\n", room->name);
        printf("Number of available rooms: %d\n", room->rooms_available);
    }

    // Update the number of available rooms
    update_available_rooms(head, "Room 1", 15);

    // Check if a room is available
    if (is_room_available(head, "Room 1")) {
        printf("Room 1 is available.\n");
    }

    return 0;
}