//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Room {
    char name[50];
    int x;
    int y;
    int width;
    int height;
    int numGhosts;
    int ghostIndex;
};

struct Room rooms[10];
int numRooms = 10;

void addRoom(char *name, int x, int y, int width, int height, int numGhosts, int ghostIndex) {
    struct Room *room = malloc(sizeof(struct Room));
    strcpy(room->name, name);
    room->x = x;
    room->y = y;
    room->width = width;
    room->height = height;
    room->numGhosts = numGhosts;
    room->ghostIndex = ghostIndex;
    rooms[numRooms] = *room;
    numRooms++;
}

void printRooms() {
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s, x=%d, y=%d, width=%d, height=%d, numGhosts=%d, ghostIndex=%d\n", i + 1, rooms[i].name, rooms[i].x, rooms[i].y, rooms[i].width, rooms[i].height, rooms[i].numGhosts, rooms[i].ghostIndex);
    }
}

void moveTo(int ghostIndex) {
    for (int i = 0; i < numRooms; i++) {
        if (ghostIndex == rooms[i].ghostIndex) {
            printf("Ghost %d moved to room %s at (%d, %d)\n", ghostIndex, rooms[i].name, rooms[i].x, rooms[i].y);
            break;
        }
    }
}

int main() {
    addRoom("Living Room", 0, 0, 10, 10, 1, 0);
    addRoom("Kitchen", 5, 0, 10, 10, 2, 1);
    addRoom("Bathroom", 0, 10, 10, 10, 3, 2);
    addRoom("Bedroom", 5, 10, 10, 10, 4, 3);
    printRooms();

    moveTo(0);
    moveTo(1);
    moveTo(2);
    moveTo(3);
    moveTo(4);
    moveTo(5);

    return 0;
}