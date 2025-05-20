//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_no;
    char status;
    char occupancy;
    struct Room* next;
} Room;

// Define a function to insert a room into the hotel
void insertRoom(Room* head, int room_no, char status, char occupancy) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_no = room_no;
    newRoom->status = status;
    newRoom->occupancy = occupancy;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        head->next = newRoom;
    }
}

// Define a function to search for a room
Room* searchRoom(Room* head, int room_no) {
    while (head) {
        if (head->room_no == room_no) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Define a function to update the status of a room
void updateRoomStatus(Room* head, int room_no, char new_status) {
    Room* room = searchRoom(head, room_no);

    if (room) {
        room->status = new_status;
    }
}

// Define a function to update the occupancy of a room
void updateRoomOccupancy(Room* head, int room_no, char new_occupancy) {
    Room* room = searchRoom(head, room_no);

    if (room) {
        room->occupancy = new_occupancy;
    }
}

// Main function
int main() {
    Room* head = NULL;

    // Insert some rooms
    insertRoom(head, 101, 'O', 'A');
    insertRoom(head, 102, 'A', 'B');
    insertRoom(head, 103, 'O', 'C');

    // Search for a room
    Room* room = searchRoom(head, 102);

    // Update the status of a room
    updateRoomStatus(head, 101, 'A');

    // Update the occupancy of a room
    updateRoomOccupancy(head, 102, 'C');

    // Print the updated rooms
    for (room = head; room; room = room->next) {
        printf("Room No: %d, Status: %c, Occupancy: %c\n", room->room_no, room->status, room->occupancy);
    }

    return 0;
}