//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int number;
    char type;
    int capacity;
    struct Room* next;
} Room;

// Define a function to insert a room
void insertRoom(Room** head, int number, char type, int capacity) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->number = number;
    newRoom->type = type;
    newRoom->capacity = capacity;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        (*head)->next = newRoom;
    }
}

// Define a function to find a room
Room* findRoom(Room* head, int number) {
    while (head) {
        if (head->number == number) {
            return head;
        } else {
            head = head->next;
        }
    }

    return NULL;
}

// Define a function to check if a room is available
int isRoomAvailable(Room* head, int number) {
    Room* room = findRoom(head, number);

    if (room) {
        return room->capacity - 1;
    }

    return -1;
}

// Define a function to book a room
void bookRoom(Room* head, int number, int numGuests) {
    Room* room = findRoom(head, number);

    if (room) {
        if (room->capacity - 1 >= numGuests) {
            room->capacity -= numGuests;
            printf("Room booked successfully.\n");
        } else {
            printf("Sorry, the room is not available.\n");
        }
    } else {
        printf("Sorry, the room does not exist.\n");
    }
}

int main() {
    Room* head = NULL;

    insertRoom(&head, 1, 'A', 20);
    insertRoom(&head, 2, 'B', 10);
    insertRoom(&head, 3, 'A', 15);
    insertRoom(&head, 4, 'B', 12);

    bookRoom(head, 1, 5);
    bookRoom(head, 2, 3);
    bookRoom(head, 3, 2);

    bookRoom(head, 5, 4); // This should return an error message

    return 0;
}