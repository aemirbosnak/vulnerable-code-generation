//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

#define WALL '#'
#define PLAYER '@'
#define GOAL '$'
#define EMPTY ' '

typedef struct {
    int x, y;
} Vector;

typedef struct {
    char **grid;
    Vector player;
    Vector goal;
} World;

void init_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            world->grid[i][j] = EMPTY;
        }
    }

    world->player.x = 1;
    world->player.y = 1;

    world->goal.x = WIDTH - 2;
    world->goal.y = HEIGHT - 2;

    // Generate a random maze
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) {
                world->grid[i][j] = WALL;
            }
        }
    }

    // Create a path from the player to the goal
    Vector current = world->player;
    while (current.x != world->goal.x || current.y != world->goal.y) {
        Vector next;
        do {
            next.x = current.x + rand() % 3 - 1;
            next.y = current.y + rand() % 3 - 1;
        } while (next.x < 0 || next.x >= WIDTH || next.y < 0 || next.y >= HEIGHT || world->grid[next.y][next.x] == WALL);

        world->grid[current.y][current.x] = EMPTY;
        current = next;
        world->grid[current.y][current.x] = PLAYER;
    }
}

void draw_world(World *world) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", world->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    World world;
    world.grid = malloc(HEIGHT * sizeof(char *));
    for (int i = 0; i < HEIGHT; i++) {
        world.grid[i] = malloc(WIDTH);
    }

    init_world(&world);

    while (1) {
        draw_world(&world);

        // Get input from the user
        char input = getchar();

        // Move the player
        switch (input) {
            case 'w':
                if (world.grid[world.player.y - 1][world.player.x] != WALL) {
                    world.grid[world.player.y][world.player.x] = EMPTY;
                    world.player.y--;
                    world.grid[world.player.y][world.player.x] = PLAYER;
                }
                break;
            case 'a':
                if (world.grid[world.player.y][world.player.x - 1] != WALL) {
                    world.grid[world.player.y][world.player.x] = EMPTY;
                    world.player.x--;
                    world.grid[world.player.y][world.player.x] = PLAYER;
                }
                break;
            case 's':
                if (world.grid[world.player.y + 1][world.player.x] != WALL) {
                    world.grid[world.player.y][world.player.x] = EMPTY;
                    world.player.y++;
                    world.grid[world.player.y][world.player.x] = PLAYER;
                }
                break;
            case 'd':
                if (world.grid[world.player.y][world.player.x + 1] != WALL) {
                    world.grid[world.player.y][world.player.x] = EMPTY;
                    world.player.x++;
                    world.grid[world.player.y][world.player.x] = PLAYER;
                }
                break;
        }

        // Check if the player has reached the goal
        if (world.player.x == world.goal.x && world.player.y == world.goal.y) {
            printf("You win!\n");
            break;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(world.grid[i]);
    }
    free(world.grid);

    return 0;
}