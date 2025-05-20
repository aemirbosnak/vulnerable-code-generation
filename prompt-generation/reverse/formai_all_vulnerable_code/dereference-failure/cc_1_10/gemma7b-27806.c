//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct Room {
    char name[20];
    int number;
    float rate;
    struct Room* next;
} Room;

typedef struct Hotel {
    Room* head;
    int numRooms;
} Hotel;

void createRoom(Hotel* hotel, char* name, int number, float rate) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->rate = rate;
    newRoom->next = NULL;

    if (hotel->head == NULL) {
        hotel->head = newRoom;
    } else {
        hotel->head->next = newRoom;
    }

    hotel->numRooms++;
}

void displayRooms(Hotel* hotel) {
    Room* currentRoom = hotel->head;
    while (currentRoom) {
        printf("%s (%d) - $%.2f\n", currentRoom->name, currentRoom->number, currentRoom->rate);
        currentRoom = currentRoom->next;
    }
}

int main() {
    Hotel* hotel = malloc(sizeof(Hotel));
    hotel->head = NULL;
    hotel->numRooms = 0;

    createRoom(hotel, "Standard", 101, 50.0);
    createRoom(hotel, "Suite", 102, 70.0);
    createRoom(hotel, "Luxury", 103, 90.0);

    displayRooms(hotel);

    return 0;
}