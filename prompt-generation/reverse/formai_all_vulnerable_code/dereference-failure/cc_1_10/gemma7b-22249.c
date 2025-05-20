//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_number;
    char room_type;
    int available_beds;
    int occupied_beds;
    struct Room* next;
} Room;

// Define a function to insert a room into the linked list
void insertRoom(Room** head, int room_number, char room_type, int available_beds, int occupied_beds) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->room_number = room_number;
    newRoom->room_type = room_type;
    newRoom->available_beds = available_beds;
    newRoom->occupied_beds = occupied_beds;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define a function to check if a room is available
int isRoomAvailable(Room* head, int room_number) {
    while (head) {
        if (head->room_number == room_number && head->available_beds > 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// Define a function to check if a room is occupied
int isRoomOccupied(Room* head, int room_number) {
    while (head) {
        if (head->room_number == room_number) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Room* head = NULL;
    insertRoom(&head, 101, 'A', 2, 0);
    insertRoom(&head, 102, 'B', 4, 1);
    insertRoom(&head, 103, 'A', 2, 1);

    if (isRoomAvailable(head, 101)) {
        printf("Room 101 is available.\n");
    }

    if (isRoomOccupied(head, 102)) {
        printf("Room 102 is occupied.\n");
    }

    return 0;
}