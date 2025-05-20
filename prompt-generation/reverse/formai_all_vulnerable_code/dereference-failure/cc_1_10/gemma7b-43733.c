//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room structure
typedef struct Room {
    int room_number;
    char status;
    char guest_name[20];
    int num_of_guests;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* head = NULL;

// Function to insert a room into the linked list
void insert_room(int room_number, char status, char guest_name[], int num_of_guests) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = status;
    strcpy(new_room->guest_name, guest_name);
    new_room->num_of_guests = num_of_guests;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }
}

// Function to find a room by room number
Room* find_room(int room_number) {
    Room* current_room = head;

    while (current_room) {
        if (current_room->room_number == room_number) {
            return current_room;
        }
        current_room = current_room->next;
    }

    return NULL;
}

// Function to check if a room is available
int is_room_available(int room_number) {
    Room* current_room = find_room(room_number);

    if (current_room) {
        return current_room->status == 'A';
    }

    return 0;
}

// Function to book a room
void book_room(int room_number, char guest_name[], int num_of_guests) {
    Room* current_room = find_room(room_number);

    if (current_room) {
        current_room->status = 'B';
        strcpy(current_room->guest_name, guest_name);
        current_room->num_of_guests = num_of_guests;
    }
}

int main() {
    // Insert some rooms into the linked list
    insert_room(101, 'A', "John Doe", 2);
    insert_room(102, 'A', "Jane Doe", 1);
    insert_room(103, 'B', "Peter Pan", 3);

    // Check if room 101 is available
    if (is_room_available(101)) {
        printf("Room 101 is available.\n");
    }

    // Book room 101
    book_room(101, "Mary Smith", 2);

    // Check if room 101 is booked
    if (is_room_available(101)) {
        printf("Room 101 is not available.\n");
    }

    return 0;
}