//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the number of rooms in the hotel
#define NUM_ROOMS 100

// Define the room status (available, occupied, etc.)
#define AVAILABLE 0
#define OCCUPIED 1
#define DIRTY 2

// Define the room type (single, double, etc.)
#define SINGLE 0
#define DOUBLE 1

// Define the guest information structure
typedef struct Guest {
    char name[50];
    int room_num;
    int num_nights;
    struct Guest* next;
} Guest;

// Function to insert a guest into the linked list
void insertGuest(Guest** head, char* name, int room_num, int num_nights) {
    Guest* newGuest = (Guest*)malloc(sizeof(Guest));
    strcpy(newGuest->name, name);
    newGuest->room_num = room_num;
    newGuest->num_nights = num_nights;
    newGuest->next = NULL;

    if (*head == NULL) {
        *head = newGuest;
    } else {
        (*head)->next = newGuest;
    }
}

// Function to check if a room is available
int isRoomAvailable(int room_num) {
    Guest* head = NULL;
    insertGuest(&head, "John Doe", room_num, 3);
    insertGuest(&head, "Jane Doe", room_num, 2);

    for (Guest* guest = head; guest; guest = guest->next) {
        if (guest->room_num == room_num) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Check if room 10 is available
    if (isRoomAvailable(10)) {
        printf("Room 10 is available.\n");
    } else {
        printf("Room 10 is occupied.\n");
    }

    return 0;
}