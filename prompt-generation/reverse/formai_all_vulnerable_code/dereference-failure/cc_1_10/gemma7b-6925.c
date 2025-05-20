//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct room {
    int x, y;
    struct room* next;
    char name[20];
    struct monster* monsters;
} room_t;

typedef struct monster {
    char name[20];
    int health;
    int attack;
    struct monster* next;
} monster_t;

room_t* generate_rooms() {
    room_t* rooms = NULL;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms = malloc(sizeof(room_t));
        rooms->x = rand() % 10;
        rooms->y = rand() % 10;
        rooms->next = NULL;
        rooms->name[0] = 'A' + i;
        rooms->monsters = NULL;
    }
    return rooms;
}

monster_t* generate_monsters() {
    monster_t* monsters = NULL;
    for (int i = 0; i < MAX_MONSTERS; i++) {
        monsters = malloc(sizeof(monster_t));
        monsters->name[0] = 'M' + i;
        monsters->health = rand() % 10 + 1;
        monsters->attack = rand() % 5 + 1;
        monsters->next = NULL;
    }
    return monsters;
}

int main() {
    room_t* rooms = generate_rooms();
    monster_t* monsters = generate_monsters();

    // Play the game
    // ...

    return 0;
}