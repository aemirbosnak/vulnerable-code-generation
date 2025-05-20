//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct Room {
    int number;
    int status;
};

struct Hotel {
    char name[100];
    int capacity;
    struct Room* rooms;
};

struct Hotel* create_hotel(char* name, int capacity) {
    struct Hotel* hotel = (struct Hotel*) malloc(sizeof(struct Hotel));
    strcpy(hotel->name, name);
    hotel->capacity = capacity;
    hotel->rooms = (struct Room*) malloc(capacity * sizeof(struct Room));
    return hotel;
}

void print_rooms(struct Hotel* hotel) {
    int i;
    for (i = 0; i < hotel->capacity; i++) {
        printf("Room %d: %d\n", i + 1, hotel->rooms[i].status);
    }
}

int main() {
    struct Hotel* hotel = create_hotel("ABC Hotel", 10);
    struct Room rooms[10] = {
        {1, 1},
        {2, 0},
        {3, 1},
        {4, 0},
        {5, 1},
        {6, 0},
        {7, 1},
        {8, 0},
        {9, 1},
        {10, 0}
    };
    int i;
    for (i = 0; i < 10; i++) {
        hotel->rooms[i] = rooms[i];
    }
    print_rooms(hotel);
    return 0;
}