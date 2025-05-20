//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct Room {
    int x, y;
    struct Room *next;
} Room;

typedef struct Monster {
    int health;
    struct Monster *next;
} Monster;

Room **generateRooms(int numRooms) {
    Room **rooms = malloc(numRooms * sizeof(Room));
    for (int i = 0; i < numRooms; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->x = rand() % 10;
        rooms[i]->y = rand() % 10;
        rooms[i]->next = NULL;
    }
    return rooms;
}

Monster **generateMonsters(int numMonsters) {
    Monster **monsters = malloc(numMonsters * sizeof(Monster));
    for (int i = 0; i < numMonsters; i++) {
        monsters[i] = malloc(sizeof(Monster));
        monsters[i]->health = rand() % 10;
        monsters[i]->next = NULL;
    }
    return monsters;
}

int main() {
    int numRooms = rand() % MAX_ROOMS;
    int numMonsters = rand() % MAX_MONSTERS;

    Room **rooms = generateRooms(numRooms);
    Monster **monsters = generateMonsters(numMonsters);

    // Play the game
    // ...

    // Free memory
    for (Room *room = rooms; room; room = room->next) {
        free(room);
    }
    for (Monster *monster = monsters; monster; monster = monster->next) {
        free(monster);
    }

    return 0;
}