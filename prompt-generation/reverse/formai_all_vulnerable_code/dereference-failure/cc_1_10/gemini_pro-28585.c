//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Entity types
typedef enum {
    PLAYER,
    MONSTER,
    WALL,
    FLOOR
} EntityType;

// Entity structure
typedef struct {
    EntityType type;
    int x, y;
} Entity;

// Map structure
typedef struct {
    Entity **entities;
} Map;

// Function to create a new map
Map *create_map() {
    Map *map = malloc(sizeof(Map));
    map->entities = malloc(sizeof(Entity *) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        map->entities[i] = NULL;
    }
    return map;
}

// Function to generate a random map
void generate_map(Map *map) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (rand() % 100 < 20) {
                map->entities[i + j * WIDTH] = malloc(sizeof(Entity));
                map->entities[i + j * WIDTH]->type = WALL;
                map->entities[i + j * WIDTH]->x = i;
                map->entities[i + j * WIDTH]->y = j;
            }
        }
    }
}

// Function to free a map
void free_map(Map *map) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (map->entities[i] != NULL) {
            free(map->entities[i]);
        }
    }
    free(map->entities);
    free(map);
}

// Function to print a map
void print_map(Map *map) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Entity *entity = map->entities[j + i * WIDTH];
            if (entity != NULL) {
                switch (entity->type) {
                    case PLAYER:
                        printf("@");
                        break;
                    case MONSTER:
                        printf("M");
                        break;
                    case WALL:
                        printf("#");
                        break;
                    case FLOOR:
                        printf(".");
                        break;
                }
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to move the player
void move_player(Map *map, int dx, int dy) {
    Entity *player = NULL;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (map->entities[i] != NULL && map->entities[i]->type == PLAYER) {
            player = map->entities[i];
            break;
        }
    }

    if (player != NULL) {
        if (map->entities[player->x + dx + (player->y + dy) * WIDTH] == NULL ||
            map->entities[player->x + dx + (player->y + dy) * WIDTH]->type == FLOOR) {
            map->entities[player->x + dx + (player->y + dy) * WIDTH] = player;
            map->entities[player->x + (player->y) * WIDTH] = NULL;
            player->x += dx;
            player->y += dy;
        }
    }
}

// Function to main game loop
void game_loop(Map *map) {
    while (1) {
        print_map(map);
        char input = getchar();
        switch (input) {
            case 'w':
                move_player(map, 0, -1);
                break;
            case 'a':
                move_player(map, -1, 0);
                break;
            case 's':
                move_player(map, 0, 1);
                break;
            case 'd':
                move_player(map, 1, 0);
                break;
            case 'q':
                exit(0);
                break;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    Map *map = create_map();
    generate_map(map);
    game_loop(map);
    free_map(map);
    return 0;
}