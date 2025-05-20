//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    char symbol;
    int hp;
    int atk;
    Point pos;
} Entity;

typedef struct {
    char symbol;
    int hp;
    int atk;
    Point pos;
} Wall;

typedef struct {
    Entity *entities;
    Wall *walls;
    int num_entities;
    int num_walls;
} Level;

Level *generate_level(int width, int height) {
    Level *level = malloc(sizeof(Level));
    level->entities = malloc(sizeof(Entity) * 100);
    level->walls = malloc(sizeof(Wall) * 100);
    level->num_entities = 0;
    level->num_walls = 0;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (rand() % 100 < 20) {
                Entity entity;
                entity.symbol = '@';
                entity.hp = 10;
                entity.atk = 2;
                entity.pos.x = i;
                entity.pos.y = j;
                level->entities[level->num_entities++] = entity;
            } else if (rand() % 100 < 50) {
                Wall wall;
                wall.symbol = '#';
                wall.hp = 10;
                wall.atk = 0;
                wall.pos.x = i;
                wall.pos.y = j;
                level->walls[level->num_walls++] = wall;
            }
        }
    }

    return level;
}

void free_level(Level *level) {
    free(level->entities);
    free(level->walls);
    free(level);
}

void print_level(Level *level) {
    for (int i = 0; i < level->num_entities; i++) {
        Entity entity = level->entities[i];
        printf("%c", entity.symbol);
    }

    for (int i = 0; i < level->num_walls; i++) {
        Wall wall = level->walls[i];
        printf("%c", wall.symbol);
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    Level *level = generate_level(80, 24);
    print_level(level);

    free_level(level);

    return 0;
}