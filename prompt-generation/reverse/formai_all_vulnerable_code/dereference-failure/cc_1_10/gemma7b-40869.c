//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store room information
typedef struct Room {
    int room_no;
    char status;
    int occupancy;
    struct Room* next;
} Room;

// Function to insert a room into the linked list
void insertRoom(Room* head, int room_no, char status, int occupancy) {
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
}

// Function to search for a room
Room* searchRoom(Room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to update the status of a room
void updateRoomStatus(Room* head, int room_no, char status) {
    Room* room = searchRoom(head, room_no);
    if (room) {
        room->status = status;
    }
}

// Function to check if a room is occupied
int isRoomOccupied(Room* head, int room_no) {
    Room* room = searchRoom(head, room_no);
    if (room) {
        return room->occupancy;
    }
    return 0;
}

// Main function
int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'A', 2);
    insertRoom(head, 102, 'B', 1);
    insertRoom(head, 103, 'C', 0);

    // Update the status of room 102
    updateRoomStatus(head, 102, 'D');

    // Check if room 102 is occupied
    if (isRoomOccupied(head, 102)) {
        printf("Room 102 is occupied.\n");
    }

    return 0;
}