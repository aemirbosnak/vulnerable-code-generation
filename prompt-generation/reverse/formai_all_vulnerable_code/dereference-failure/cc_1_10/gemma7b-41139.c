//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Rooms 10
#define MAX_Monsters 5

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

Room* generate_room(int level) {
    Room* room = malloc(sizeof(Room));
    room->name[0] = 'A' + level;
    room->monsters = rand() % MAX_Monsters;
    room->next = NULL;

    return room;
}

Monster* generate_monster(int level) {
    Monster* monster = malloc(sizeof(Monster));
    monster->name[0] = 'M' + level;
    monster->health = rand() % MAX_Rooms + 1;
    monster->next = NULL;

    return monster;
}

int main() {
    srand(time(NULL));

    // Generate the dungeon
    Room* dungeon = generate_room(1);
    for (int i = 0; i < MAX_Rooms - 1; i++) {
        dungeon->next = generate_room(i + 1);
        dungeon = dungeon->next;
    }

    // Print the dungeon
    for (Room* room = dungeon; room; room = room->next) {
        printf("Room: %s\n", room->name);
        printf("Monsters: %d\n", room->monsters);
    }

    return 0;
}