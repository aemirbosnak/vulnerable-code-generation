//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

typedef struct {
    char *name;
    Rectangle bounds;
} Room;

typedef struct {
    Room **rooms;
    int numRooms;
} House;

void generateHouse(House *house) {
    house->numRooms = rand() % 10 + 5;
    house->rooms = malloc(house->numRooms * sizeof(Room *));
    for (int i = 0; i < house->numRooms; i++) {
        house->rooms[i] = malloc(sizeof(Room));
        house->rooms[i]->name = malloc(10 * sizeof(char));
        sprintf(house->rooms[i]->name, "Room %d", i + 1);
        house->rooms[i]->bounds.topLeft.x = rand() % 100;
        house->rooms[i]->bounds.topLeft.y = rand() % 100;
        house->rooms[i]->bounds.bottomRight.x = rand() % 100 + 50;
        house->rooms[i]->bounds.bottomRight.y = rand() % 100 + 50;
    }
}

void printHouse(House *house) {
    for (int i = 0; i < house->numRooms; i++) {
        printf("Room %d: %s\n", i + 1, house->rooms[i]->name);
        printf("  Bounds: (%d,%d) - (%d,%d)\n", house->rooms[i]->bounds.topLeft.x, house->rooms[i]->bounds.topLeft.y, house->rooms[i]->bounds.bottomRight.x, house->rooms[i]->bounds.bottomRight.y);
    }
}

void freeHouse(House *house) {
    for (int i = 0; i < house->numRooms; i++) {
        free(house->rooms[i]->name);
        free(house->rooms[i]);
    }
    free(house->rooms);
}

int main() {
    srand(time(NULL));
    House house;
    generateHouse(&house);
    printHouse(&house);
    freeHouse(&house);
    return 0;
}