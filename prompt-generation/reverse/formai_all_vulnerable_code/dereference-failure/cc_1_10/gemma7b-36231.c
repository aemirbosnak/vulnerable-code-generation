//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of rooms
#define NUM_ROOMS 10

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    int available;
    struct Room* next;
} Room;

// Define the hotel structure
typedef struct Hotel {
    Room* head;
    int num_rooms;
    int num_available_rooms;
} Hotel;

// Function to insert a room into the hotel
void insert_room(Hotel* hotel, char* name, int number, int available) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->number = number;
    new_room->available = available;
    new_room->next = NULL;

    if (hotel->head == NULL) {
        hotel->head = new_room;
    } else {
        hotel->head->next = new_room;
    }

    hotel->num_rooms++;
    hotel->num_available_rooms++;
}

// Function to check if a room is available
int is_room_available(Hotel* hotel, int number) {
    Room* current_room = hotel->head;

    while (current_room) {
        if (current_room->number == number && current_room->available) {
            return 1;
        }
        current_room = current_room->next;
    }

    return 0;
}

// Function to book a room
void book_room(Hotel* hotel, char* name, int number) {
    Room* current_room = hotel->head;

    while (current_room) {
        if (current_room->number == number && current_room->available) {
            current_room->available = 0;
            printf("Room booked successfully!\n");
            return;
        }
        current_room = current_room->next;
    }

    printf("Room not available.\n");
}

int main() {
    Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
    hotel->head = NULL;
    hotel->num_rooms = 0;
    hotel->num_available_rooms = 0;

    insert_room(hotel, "John Doe", 101, 1);
    insert_room(hotel, "Jane Doe", 102, 1);
    insert_room(hotel, "Peter Pan", 103, 1);

    if (is_room_available(hotel, 102)) {
        book_room(hotel, "Mary Smith", 102);
    }

    return 0;
}