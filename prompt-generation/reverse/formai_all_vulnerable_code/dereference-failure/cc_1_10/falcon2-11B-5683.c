//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 100
#define MAX_OBJECTS 20

typedef struct {
    char name[20];
    int x;
    int y;
} Room;

typedef struct {
    char name[20];
    int x;
    int y;
} Object;

Room rooms[MAX_ROOMS];
Object objects[MAX_OBJECTS];

void generateRooms() {
    int numRooms = 0;
    while (numRooms < MAX_ROOMS) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        char roomName[20];
        sprintf(roomName, "Room %d", numRooms);

        Room newRoom;
        newRoom.x = x;
        newRoom.y = y;
        strcpy(newRoom.name, roomName);

        rooms[numRooms++] = newRoom;
    }
}

void generateObjects() {
    int numObjects = 0;
    while (numObjects < MAX_OBJECTS) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        char objectName[20];
        sprintf(objectName, "Object %d", numObjects);

        Object newObject;
        newObject.x = x;
        newObject.y = y;
        strcpy(newObject.name, objectName);

        objects[numObjects++] = newObject;
    }
}

void displayRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i].name);
    }
}

void displayObjects() {
    for (int i = 0; i < MAX_OBJECTS; i++) {
        printf("Object %d: %s\n", i + 1, objects[i].name);
    }
}

int main() {
    generateRooms();
    generateObjects();

    displayRooms();
    displayObjects();

    return 0;
}