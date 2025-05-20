//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_COUNT 10
#define MAX_MONSTER_COUNT 5

typedef struct Room {
    char name[20];
    int monsters;
    struct Room* next;
} Room;

typedef struct Monster {
    char name[20];
    int health;
    struct Monster* next;
} Monster;

Room* generateRooms() {
    srand(time(NULL));
    int numRooms = rand() % MAX_ROOM_COUNT + 1;
    Room* rooms = NULL;
    for (int i = 0; i < numRooms; i++) {
        rooms = malloc(sizeof(Room));
        rooms->name[0] = 'A' + i;
        rooms->monsters = rand() % MAX_MONSTER_COUNT + 1;
        rooms->next = rooms;
    }
    return rooms;
}

Monster* generateMonsters(Room* room) {
    srand(time(NULL));
    int numMonsters = room->monsters;
    Monster* monsters = NULL;
    for (int i = 0; i < numMonsters; i++) {
        monsters = malloc(sizeof(Monster));
        monsters->name[0] = 'M' + i;
        monsters->health = rand() % 100 + 1;
        monsters->next = monsters;
    }
    return monsters;
}

int main() {
    Room* rooms = generateRooms();
    Monster* monsters = generateMonsters(rooms);

    // Play the game
    // ...

    return 0;
}