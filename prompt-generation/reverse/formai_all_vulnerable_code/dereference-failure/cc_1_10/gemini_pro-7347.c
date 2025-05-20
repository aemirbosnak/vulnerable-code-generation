//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    int x, y;
    char glyph;
} Entity;

typedef struct {
    char *name;
    int hp, atk, def;
} Stats;

typedef struct {
    Entity entity;
    Stats stats;
} Mob;

typedef struct {
    int level;
    Mob *mobs;
    int num_mobs;
} DungeonLevel;

typedef struct {
    DungeonLevel *levels;
    int num_levels;
} Dungeon;

Dungeon *dungeon;

void generate_dungeon() {
    dungeon = malloc(sizeof(Dungeon));
    dungeon->num_levels = 10;
    dungeon->levels = malloc(dungeon->num_levels * sizeof(DungeonLevel));

    for (int i = 0; i < dungeon->num_levels; i++) {
        dungeon->levels[i].level = i + 1;
        dungeon->levels[i].num_mobs = 10;
        dungeon->levels[i].mobs = malloc(dungeon->levels[i].num_mobs * sizeof(Mob));

        for (int j = 0; j < dungeon->levels[i].num_mobs; j++) {
            dungeon->levels[i].mobs[j].entity.x = rand() % WIDTH;
            dungeon->levels[i].mobs[j].entity.y = rand() % HEIGHT;
            dungeon->levels[i].mobs[j].entity.glyph = 'M';

            dungeon->levels[i].mobs[j].stats.name = malloc(10 * sizeof(char));
            strcpy(dungeon->levels[i].mobs[j].stats.name, "Mob");
            dungeon->levels[i].mobs[j].stats.hp = 10;
            dungeon->levels[i].mobs[j].stats.atk = 2;
            dungeon->levels[i].mobs[j].stats.def = 1;
        }
    }
}

void print_dungeon() {
    for (int i = 0; i < dungeon->num_levels; i++) {
        printf("Level %d:\n", dungeon->levels[i].level);
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < WIDTH; k++) {
                int found = 0;
                for (int l = 0; l < dungeon->levels[i].num_mobs; l++) {
                    if (dungeon->levels[i].mobs[l].entity.x == k && dungeon->levels[i].mobs[l].entity.y == j) {
                        printf("%c", dungeon->levels[i].mobs[l].entity.glyph);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_dungeon();
    print_dungeon();
    return 0;
}