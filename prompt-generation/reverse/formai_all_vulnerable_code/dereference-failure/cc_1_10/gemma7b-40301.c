//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Create a linked list of rooms
Room* insert_room(Room* head, int room_no, char status, int occupancy) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = room_no;
    new_room->status = status;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (head == NULL) {
        head = new_room;
    } else {
        head->next = new_room;
    }

    return head;
}

// Print the list of rooms
void print_rooms(Room* head) {
    while (head) {
        printf("Room No: %d, Status: %c, Occupancy: %d\n", head->room_no, head->status, head->occupancy);
        head = head->next;
    }
}

// Main function
int main() {
    // Create a linked list of rooms
    Room* head = NULL;

    // Insert some rooms
    insert_room(head, 101, 'O', 2);
    insert_room(head, 102, 'A', 1);
    insert_room(head, 103, 'F', 0);

    // Print the list of rooms
    print_rooms(head);

    return 0;
}