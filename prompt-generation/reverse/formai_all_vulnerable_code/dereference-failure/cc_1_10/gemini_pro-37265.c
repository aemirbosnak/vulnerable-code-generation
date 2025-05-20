//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25

#define PLAYER_SYMBOL '@'
#define WALL_SYMBOL '#'
#define FLOOR_SYMBOL '.'

#define NUM_MONSTERS 10

typedef struct {
    int x, y;
    char symbol;
} Entity;

typedef struct {
    Entity *entities;
    int num_entities;
} World;

World *world;

void init_world() {
    world = malloc(sizeof(World));
    world->entities = malloc(sizeof(Entity) * (NUM_MONSTERS + 1));
    world->num_entities = 0;
}

void free_world() {
    free(world->entities);
    free(world);
}

void generate_dungeon() {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Create a 2D array of characters to represent the dungeon map.
    char map[MAP_HEIGHT][MAP_WIDTH];

    // Fill the map with walls.
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = WALL_SYMBOL;
        }
    }

    // Create a player entity and place it in the center of the map.
    Entity player = {MAP_WIDTH / 2, MAP_HEIGHT / 2, PLAYER_SYMBOL};
    world->entities[world->num_entities++] = player;

    // Create monster entities and place them randomly in the dungeon.
    for (int i = 0; i < NUM_MONSTERS; i++) {
        Entity monster = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT, 'M'};
        world->entities[world->num_entities++] = monster;
    }

    // Dig out a random path from the player to the edge of the map.
    int x = player.x;
    int y = player.y;
    while (x != 0 && y != 0 && x != MAP_WIDTH - 1 && y != MAP_HEIGHT - 1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:  // North
                y--;
                break;
            case 1:  // South
                y++;
                break;
            case 2:  // West
                x--;
                break;
            case 3:  // East
                x++;
                break;
        }
        map[y][x] = FLOOR_SYMBOL;
    }

    // Copy the map to the world's entity list.
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Entity entity = {x, y, map[y][x]};
            world->entities[world->num_entities++] = entity;
        }
    }
}

void draw_world() {
    // Clear the screen.
    system("clear");

    // Draw the map.
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Entity entity = world->entities[y * MAP_WIDTH + x];
            printf("%c", entity.symbol);
        }
        printf("\n");
    }
}

void move_player(int dx, int dy) {
    // Get the player's current position.
    Entity *player = &world->entities[0];

    // Check if the player can move in the given direction.
    if (player->x + dx >= 0 && player->x + dx < MAP_WIDTH &&
        player->y + dy >= 0 && player->y + dy < MAP_HEIGHT &&
        world->entities[(player->y + dy) * MAP_WIDTH + (player->x + dx)].symbol != WALL_SYMBOL) {

        // Move the player.
        player->x += dx;
        player->y += dy;
    }
}

bool check_for_collisions() {
    // Get the player's current position.
    Entity *player = &world->entities[0];

    // Check if the player has collided with any monsters.
    for (int i = 1; i < world->num_entities; i++) {
        Entity *entity = &world->entities[i];
        if (player->x == entity->x && player->y == entity->y) {
            return true;
        }
    }

    // No collisions were found.
    return false;
}

void process_input() {
    // Get the player's input.
    char input = getchar();

    // Handle the player's input.
    switch (input) {
        case 'w':  // North
            move_player(0, -1);
            break;
        case 's':  // South
            move_player(0, 1);
            break;
        case 'a':  // West
            move_player(-1, 0);
            break;
        case 'd':  // East
            move_player(1, 0);
            break;
        case 'q':  // Quit
            exit(0);
            break;
    }
}

int main() {
    // Initialize the world.
    init_world();

    // Generate the dungeon.
    generate_dungeon();

    // Draw the world.
    draw_world();

    // Process the player's input.
    while (true) {
        process_input();

        // Check for collisions.
        if (check_for_collisions()) {
            // The player has collided with a monster.
            printf("You have been eaten by a monster!\n");
            break;
        }

        // Draw the world.
        draw_world();
    }

    // Free the world.
    free_world();

    return 0;
}