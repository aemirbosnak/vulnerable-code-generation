//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct Room {
    int x, y;
    char description[256];
    struct Room* north, *south, *east, *west;
} Room;

typedef struct Monster {
    int type;
    int health;
    struct Monster* next;
} Monster;

Room* generate_room(int x, int y) {
    Room* room = malloc(sizeof(Room));
    room->x = x;
    room->y = y;
    room->description[0] = '\0';
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;
    return room;
}

Monster* generate_monster(int type, int health) {
    Monster* monster = malloc(sizeof(Monster));
    monster->type = type;
    monster->health = health;
    monster->next = NULL;
    return monster;
}

int main() {
    srand(time(NULL));

    // Create a list of rooms
    Room* rooms = generate_room(0, 0);
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms = rooms->north = generate_room(rooms->x + rand() % 5, rooms->y);
    }

    // Create a list of monsters
    Monster* monsters = generate_monster(0, 10);
    for (int i = 0; i < MAX_MONSTERS; i++) {
        monsters = monsters->next = generate_monster(rand() % 3, rand() % 10);
    }

    // Play the game
    // ...
}