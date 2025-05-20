//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the room structure
typedef struct Room {
    char name[20];
    int number;
    float rate;
    struct Room *next;
} Room;

// Define the hotel structure
typedef struct Hotel {
    Room *head;
    int numRooms;
    float totalRevenue;
} Hotel;

// Function to insert a room into the hotel
void insertRoom(Hotel *h, Room *r) {
    if (h->head == NULL) {
        h->head = r;
    } else {
        r->next = h->head;
        h->head = r;
    }
    h->numRooms++;
}

// Function to calculate the total revenue of the hotel
void calculateTotalRevenue(Hotel *h) {
    Room *r = h->head;
    while (r) {
        h->totalRevenue += r->rate * r->number;
        r = r->next;
    }
}

// Function to check if a room is available
int isRoomAvailable(Hotel *h, char *name) {
    Room *r = h->head;
    while (r) {
        if (strcmp(r->name, name) == 0) {
            return 0;
        }
        r = r->next;
    }
    return 1;
}

// Function to book a room
void bookRoom(Hotel *h, char *name, int number, float rate) {
    Room *r = malloc(sizeof(Room));
    strcpy(r->name, name);
    r->number = number;
    r->rate = rate;
    insertRoom(h, r);
}

int main() {
    Hotel *h = malloc(sizeof(Hotel));
    h->head = NULL;
    h->numRooms = 0;
    h->totalRevenue = 0;

    bookRoom(h, "John Doe", 101, 50);
    bookRoom(h, "Jane Doe", 102, 60);
    bookRoom(h, "Peter Pan", 103, 70);

    calculateTotalRevenue(h);

    if (isRoomAvailable(h, "John Doe")) {
        printf("Room available for John Doe\n");
    } else {
        printf("Room not available for John Doe\n");
    }

    free(h);

    return 0;
}