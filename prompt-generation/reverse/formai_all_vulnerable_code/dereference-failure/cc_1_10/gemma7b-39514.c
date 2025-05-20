//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_COUNT 10
#define MAX_MONSTER_COUNT 5

typedef struct Room {
    char name[20];
    struct Room* next;
    struct Monster* monsters;
} Room;

typedef struct Monster {
    char name[20];
    int health;
    struct Monster* next;
} Monster;

Room* generateRooms() {
    int numRooms = rand() % MAX_ROOM_COUNT + 1;
    Room* rooms = NULL;
    for (int i = 0; i < numRooms; i++) {
        rooms = malloc(sizeof(Room));
        rooms->name[0] = 'A' + i;
        rooms->next = rooms;
        rooms->monsters = NULL;
    }
    return rooms;
}

Monster* generateMonsters() {
    int numMonsters = rand() % MAX_MONSTER_COUNT + 1;
    Monster* monsters = NULL;
    for (int i = 0; i < numMonsters; i++) {
        monsters = malloc(sizeof(Monster));
        monsters->name[0] = 'M' + i;
        monsters->health = rand() % 10 + 1;
        monsters->next = monsters;
    }
    return monsters;
}

int main() {
    Room* rooms = generateRooms();
    Monster* monsters = generateMonsters();

    // Traverse the rooms and monsters
    for (Room* room = rooms; room; room = room->next) {
        printf("Room: %s\n", room->name);
        for (Monster* monster = room->monsters; monster; monster = monster->next) {
            printf("Monster: %s, Health: %d\n", monster->name, monster->health);
        }
    }

    return 0;
}