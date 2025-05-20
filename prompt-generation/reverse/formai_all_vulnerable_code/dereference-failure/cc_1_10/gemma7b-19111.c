//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct room {
    int number;
    char type;
    int occupancy;
    struct room *next;
} room;

// Define a function to insert a room into the linked list
void insert_room(room **head, int number, char type, int occupancy) {
    room *new_room = (room *)malloc(sizeof(room));
    new_room->number = number;
    new_room->type = type;
    new_room->occupancy = occupancy;
    new_room->next = NULL;

    if (*head == NULL) {
        *head = new_room;
    } else {
        (*head)->next = new_room;
    }
}

// Define a function to check if a room is available
int is_room_available(room *head, int number) {
    while (head) {
        if (head->number == number && head->occupancy == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// Define a function to check if a room type is available
int is_room_type_available(room *head, char type) {
    while (head) {
        if (head->type == type && head->occupancy == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

// Define a function to check if a room number is valid
int is_room_number_valid(int number) {
    return number > 0 && number <= 100;
}

// Main function
int main() {
    room *head = NULL;

    // Insert some rooms
    insert_room(&head, 101, 'A', 2);
    insert_room(&head, 102, 'B', 1);
    insert_room(&head, 103, 'A', 0);
    insert_room(&head, 104, 'B', 0);

    // Check if room 103 is available
    if (is_room_available(head, 103)) {
        printf("Room 103 is available.\n");
    } else {
        printf("Room 103 is not available.\n");
    }

    // Check if room type A is available
    if (is_room_type_available(head, 'A')) {
        printf("Room type A is available.\n");
    } else {
        printf("Room type A is not available.\n");
    }

    // Check if room number 101 is valid
    if (is_room_number_valid(101)) {
        printf("Room number 101 is valid.\n");
    } else {
        printf("Room number 101 is not valid.\n");
    }

    return 0;
}