//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
struct room {
    int number;
    char status;
    int guests;
    struct room* next;
};

// Create a linked list of rooms
struct room* head = NULL;

// Function to insert a room into the linked list
void insertRoom(int number, char status, int guests) {
    struct room* newRoom = (struct room*)malloc(sizeof(struct room));
    newRoom->number = number;
    newRoom->status = status;
    newRoom->guests = guests;
    newRoom->next = NULL;

    if (head == NULL) {
        head = newRoom;
    } else {
        struct room* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

// Function to check if a room is available
int isRoomAvailable(int number) {
    struct room* temp = head;
    while (temp) {
        if (temp->number == number && temp->status == 'A') {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to book a room
void bookRoom(int number, int guests) {
    struct room* temp = head;
    while (temp) {
        if (temp->number == number && temp->status == 'A') {
            temp->guests = guests;
            temp->status = 'B';
            printf("Room booked successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Room not available.\n");
}

int main() {
    insertRoom(1, 'A', 0);
    insertRoom(2, 'A', 0);
    insertRoom(3, 'A', 0);
    insertRoom(4, 'A', 0);
    insertRoom(5, 'A', 0);

    bookRoom(2, 2);
    bookRoom(4, 3);

    if (isRoomAvailable(1)) {
        printf("Room 1 is available.\n");
    }

    return 0;
}