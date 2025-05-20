//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct room {
    char name[20];
    struct room* next;
    struct monster* monsters;
} room;

typedef struct monster {
    char name[20];
    int health;
    struct monster* next;
} monster;

room* create_room() {
    room* new_room = malloc(sizeof(room));
    new_room->name[0] = '\0';
    new_room->next = NULL;
    new_room->monsters = NULL;
    return new_room;
}

monster* create_monster() {
    monster* new_monster = malloc(sizeof(monster));
    new_monster->name[0] = '\0';
    new_monster->health = 0;
    new_monster->next = NULL;
    return new_monster;
}

void generate_map(room* rooms) {
    int num_rooms = rand() % MAX_ROOMS + 1;
    for (int i = 0; i < num_rooms; i++) {
        rooms = create_room();
        rooms->name[0] = 'A' + i;
        rooms->monsters = create_monster();
        rooms->monsters->name[0] = 'M' + i;
        rooms->monsters->health = rand() % MAX_MONSTERS + 1;
        rooms->next = rooms;
    }
}

int main() {
    srand(time(NULL));
    room* rooms = NULL;
    generate_map(rooms);
    return 0;
}