//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define DUNGEON_WIDTH 80
#define DUNGEON_HEIGHT 21

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int hp;
    int atk;
    int def;
} Entity;

typedef struct {
    Entity *entities;
    int num_entities;
} Level;

typedef struct {
    Level *levels;
    int num_levels;
    int current_level;
} Dungeon;

Dungeon *generate_dungeon(int num_levels) {
    Dungeon *dungeon = malloc(sizeof(Dungeon));
    dungeon->num_levels = num_levels;
    dungeon->levels = malloc(sizeof(Level) * num_levels);

    for (int i = 0; i < num_levels; i++) {
        Level *level = &dungeon->levels[i];
        level->num_entities = 10 + rand() % 20;
        level->entities = malloc(sizeof(Entity) * level->num_entities);

        for (int j = 0; j < level->num_entities; j++) {
            Entity *entity = &level->entities[j];
            entity->pos.x = rand() % DUNGEON_WIDTH;
            entity->pos.y = rand() % DUNGEON_HEIGHT;
            entity->hp = 10 + rand() % 20;
            entity->atk = 5 + rand() % 10;
            entity->def = 5 + rand() % 10;
        }
    }

    return dungeon;
}

void print_dungeon(Dungeon *dungeon) {
    for (int i = 0; i < DUNGEON_HEIGHT; i++) {
        for (int j = 0; j < DUNGEON_WIDTH; j++) {
            int entity_index = -1;
            for (int k = 0; k < dungeon->levels[dungeon->current_level].num_entities; k++) {
                Entity *entity = &dungeon->levels[dungeon->current_level].entities[k];
                if (entity->pos.x == j && entity->pos.y == i) {
                    entity_index = k;
                    break;
                }
            }
            if (entity_index != -1) {
                printf("%c", 'A' + entity_index);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void move_player(Dungeon *dungeon, int dx, int dy) {
    Level *level = &dungeon->levels[dungeon->current_level];
    Entity *player = &level->entities[0];

    player->pos.x = fmod(player->pos.x + dx, DUNGEON_WIDTH);
    player->pos.y = fmod(player->pos.y + dy, DUNGEON_HEIGHT);
}

int main() {
    srand(time(NULL));

    Dungeon *dungeon = generate_dungeon(5);

    while (1) {
        print_dungeon(dungeon);

        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move_player(dungeon, 0, -1);
                break;
            case 's':
                move_player(dungeon, 0, 1);
                break;
            case 'a':
                move_player(dungeon, -1, 0);
                break;
            case 'd':
                move_player(dungeon, 1, 0);
                break;
            case 'q':
                return 0;
        }
    }

    return 0;
}