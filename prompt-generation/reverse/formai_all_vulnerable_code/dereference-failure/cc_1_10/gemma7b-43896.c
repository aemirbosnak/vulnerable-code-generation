//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct Room {
    char name[20];
    int number;
    struct Room* next;
} Room;

typedef struct Hotel {
    Room* head;
    int numRooms;
} Hotel;

void createRoom(Hotel* h, char* name, int number) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->number = number;
    newRoom->next = NULL;

    if (h->head == NULL) {
        h->head = newRoom;
    } else {
        h->head->next = newRoom;
    }

    h->numRooms++;
}

void checkIn(Hotel* h, char* name) {
    Room* currentRoom = h->head;
    while (currentRoom) {
        if (strcmp(currentRoom->name, name) == 0) {
            printf("Room number: %d\n", currentRoom->number);
            return;
        }
        currentRoom = currentRoom->next;
    }

    printf("No room found for %s\n", name);
}

int main() {
    Hotel* h = malloc(sizeof(Hotel));
    h->head = NULL;
    h->numRooms = 0;

    createRoom(h, "John Doe", 1);
    createRoom(h, "Jane Doe", 2);
    createRoom(h, "Bill Smith", 3);

    checkIn(h, "John Doe");
    checkIn(h, "Jane Doe");
    checkIn(h, "Bob Green");

    return 0;
}