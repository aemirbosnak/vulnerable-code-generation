//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 50

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Stats;

typedef struct {
    Entity entity;
    Stats stats;
} Character;

typedef struct {
    char *name;
    int level;
    int monsters;
    int items;
} Room;

typedef struct {
    Room *rooms;
    int num_rooms;
} Dungeon;

Dungeon *generate_dungeon(int num_rooms) {
    Dungeon *dungeon = malloc(sizeof(Dungeon));
    dungeon->num_rooms = num_rooms;
    dungeon->rooms = malloc(sizeof(Room) * num_rooms);
    for (int i = 0; i < num_rooms; i++) {
        dungeon->rooms[i].name = malloc(sizeof(char) * 16);
        sprintf(dungeon->rooms[i].name, "Room %d", i);
        dungeon->rooms[i].level = 1 + rand() % 10;
        dungeon->rooms[i].monsters = 1 + rand() % 5;
        dungeon->rooms[i].items = 1 + rand() % 5;
    }
    return dungeon;
}

Character *generate_character() {
    Character *character = malloc(sizeof(Character));
    character->entity.x = 0;
    character->entity.y = 0;
    character->entity.symbol = '@';
    character->stats.name = malloc(sizeof(char) * 16);
    strcpy(character->stats.name, "Player");
    character->stats.health = 10;
    character->stats.attack = 1;
    character->stats.defense = 1;
    return character;
}

void print_dungeon(Dungeon *dungeon) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(".");
        }
        printf("\n");
    }
    for (int i = 0; i < dungeon->num_rooms; i++) {
        Room *room = &dungeon->rooms[i];
        for (int y = 0; y < room->level; y++) {
            for (int x = 0; x < room->level; x++) {
                printf("#");
            }
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Dungeon *dungeon = generate_dungeon(10);
    Character *character = generate_character();
    print_dungeon(dungeon);
    return 0;
}