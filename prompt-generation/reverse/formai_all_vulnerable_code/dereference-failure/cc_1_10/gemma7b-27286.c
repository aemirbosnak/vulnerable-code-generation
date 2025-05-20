//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the structure of a room
typedef struct Room {
    int room_number;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Define the function to create a new room
Room* create_room(int room_number) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    new_room->status = 'O';
    new_room->occupancy = 0;
    new_room->next = NULL;
    return new_room;
}

// Define the function to insert a new room at the end
void insert_room(Room* head, int room_number) {
    Room* new_room = create_room(room_number);
    if (head == NULL) {
        head = new_room;
    } else {
        Room* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_room;
    }
}

// Define the function to check if a room is available
int is_room_available(Room* head, int room_number) {
    Room* temp = head;
    while (temp) {
        if (temp->room_number == room_number && temp->status == 'O') {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Define the function to book a room
void book_room(Room* head, int room_number, int occupancy) {
    Room* temp = head;
    while (temp) {
        if (temp->room_number == room_number && temp->status == 'O') {
            temp->occupancy = occupancy;
            temp->status = 'B';
            return;
        }
        temp = temp->next;
    }
    printf("Error: Room not available.\n");
}

// Define the function to list all rooms
void list_rooms(Room* head) {
    Room* temp = head;
    while (temp) {
        printf("Room number: %d, Status: %c, Occupancy: %d\n", temp->room_number, temp->status, temp->occupancy);
        temp = temp->next;
    }
}

int main() {
    Room* head = NULL;
    insert_room(head, 101);
    insert_room(head, 102);
    insert_room(head, 103);
    insert_room(head, 104);
    insert_room(head, 105);

    book_room(head, 102, 2);
    book_room(head, 104, 3);

    list_rooms(head);

    return 0;
}