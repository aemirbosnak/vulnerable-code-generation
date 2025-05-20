//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int number;
    char type;
    int available;
    struct Room *next;
} Room;

// Define a function to create a new room
Room *createRoom(int number, char type, int available) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->available = available;
    newRoom->next = NULL;
    return newRoom;
}

// Define a function to insert a new room at the end
void insertRoom(Room *head, int number, char type, int available) {
    Room *newRoom = createRoom(number, type, available);
    if (head == NULL) {
        head = newRoom;
    } else {
        Room *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRoom;
    }
}

// Define a function to check if a room is available
int isRoomAvailable(Room *head, int number) {
    Room *temp = head;
    while (temp) {
        if (temp->number == number && temp->available) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Define a function to book a room
void bookRoom(Room *head, int number, int numDays) {
    Room *temp = head;
    while (temp) {
        if (temp->number == number && temp->available) {
            temp->available = 0;
            printf("Room booked for %d days\n", numDays);
            return;
        }
        temp = temp->next;
    }
    printf("Sorry, room not available\n");
}

int main() {
    Room *head = NULL;
    insertRoom(head, 101, 'A', 1);
    insertRoom(head, 102, 'B', 2);
    insertRoom(head, 103, 'A', 0);
    insertRoom(head, 104, 'B', 1);

    if (isRoomAvailable(head, 102)) {
        bookRoom(head, 102, 3);
    }

    if (isRoomAvailable(head, 101)) {
        bookRoom(head, 101, 2);
    }

    return 0;
}