//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5

typedef struct Room {
    int x, y;
    char name[20];
    struct Room* next;
} Room;

typedef struct Monster {
    int health, attack, defense;
    char name[20];
} Monster;

Room* generate_map() {
    Room* head = malloc(sizeof(Room));
    head->x = 0;
    head->y = 0;
    head->name[0] = 'A';
    head->next = NULL;

    for (int i = 1; i < MAX_ROOMS; i++) {
        Room* new_room = malloc(sizeof(Room));
        new_room->x = rand() % 10;
        new_room->y = rand() % 10;
        new_room->name[0] = 'A' + i;
        new_room->next = head;
        head = new_room;
    }

    return head;
}

Monster* generate_monster() {
    Monster* monster = malloc(sizeof(Monster));
    monster->health = rand() % 10 + 1;
    monster->attack = rand() % 5 + 1;
    monster->defense = rand() % 3 + 1;
    monster->name[0] = 'M' + rand() % MAX_MONSTERS;
    return monster;
}

int main() {
    srand(time(NULL));

    Room* map = generate_map();
    Monster* monster = generate_monster();

    printf("Welcome to the dungeon, brave traveler!\n");
    printf("You are in the %s.\n", map->name);

    printf("Suddenly, a %s appears!\n", monster->name);
    printf("Prepare for battle!\n");

    // Battle code goes here

    free(map);
    free(monster);

    return 0;
}