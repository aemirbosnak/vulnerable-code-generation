//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Room* prev;
} Room;

Room* createRoom(char* name) {
    Room* newRoom = malloc(sizeof(Room));
    strcpy(newRoom->name, name);
    newRoom->next = NULL;
    newRoom->prev = NULL;
    return newRoom;
}

void addRoom(Room* currentRoom, char* name) {
    Room* newRoom = createRoom(name);
    if (currentRoom->next) {
        currentRoom->next->prev = newRoom;
    } else {
        currentRoom->next = newRoom;
    }
}

void haunt(Room* currentRoom) {
    srand(time(NULL));
    int randNum = rand() % 3;
    switch (randNum) {
        case 0:
            printf("A disembodied hand reaches out and grabs you.\n");
            break;
        case 1:
            printf("You hear whispers in your ear, 'You're not alone...'\n");
            break;
        case 2:
            printf("The air around you crackles with static, and you feel a cold hand brush against your skin.\n");
            break;
    }
}

int main() {
    Room* startRoom = createRoom("The Foyer");
    addRoom(startRoom, "The Living Room");
    addRoom(startRoom, "The Kitchen");
    addRoom(startRoom, "The Bedroom");

    haunt(startRoom);

    return 0;
}