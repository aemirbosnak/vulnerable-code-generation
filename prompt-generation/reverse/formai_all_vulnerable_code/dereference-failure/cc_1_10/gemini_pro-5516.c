//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
    int hp, atk, def;
    char *name;
} Entity;

typedef struct {
    char *name;
    char symbol;
    int hardness, durability;
} Tile;

typedef struct {
    Tile **tiles;
    Entity *entities;
    int num_entities;
} World;

void init_world(World *world) {
    world->tiles = malloc(sizeof(Tile *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        world->tiles[i] = malloc(sizeof(Tile) * WIDTH);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                world->tiles[i][j].name = "Wall";
                world->tiles[i][j].symbol = '#';
                world->tiles[i][j].hardness = 100;
                world->tiles[i][j].durability = 100;
            } else {
                world->tiles[i][j].name = "Floor";
                world->tiles[i][j].symbol = '.';
                world->tiles[i][j].hardness = 0;
                world->tiles[i][j].durability = 0;
            }
        }
    }

    world->entities = malloc(sizeof(Entity) * 100);
    world->num_entities = 0;
}

void free_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        free(world->tiles[i]);
    }
    free(world->tiles);
    free(world->entities);
}

void print_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", world->tiles[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    World world;
    init_world(&world);

    Entity player;
    player.x = 1;
    player.y = 1;
    player.hp = 100;
    player.atk = 10;
    player.def = 5;
    player.name = "Player";

    world.entities[world.num_entities++] = player;

    print_world(&world);

    while (1) {
        char input;
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                if (world.tiles[player.y - 1][player.x].hardness <= player.atk) {
                    player.y--;
                }
                break;
            case 's':
                if (world.tiles[player.y + 1][player.x].hardness <= player.atk) {
                    player.y++;
                }
                break;
            case 'a':
                if (world.tiles[player.y][player.x - 1].hardness <= player.atk) {
                    player.x--;
                }
                break;
            case 'd':
                if (world.tiles[player.y][player.x + 1].hardness <= player.atk) {
                    player.x++;
                }
                break;
        }

        print_world(&world);
    }

    free_world(&world);

    return 0;
}