//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Brave warrior struct to represent cells
struct Warrior {
    int alive; // True if alive, false if dead
    int strength; // Current strength of the warrior
};

// Function to create a brave new world
void create_world(struct Warrior **world, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Initialize warriors with random strength
            struct Warrior *warrior = malloc(sizeof(struct Warrior));
            warrior->alive = rand() % 2;
            warrior->strength = rand() % 10 + 1;
            world[i * height + j] = warrior;
        }
    }
}

// Function to update brave warriors
void update_world(struct Warrior **world, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check if warrior is alive and has a neighbor alive
            if (world[i * height + j]->alive &&
                    world[i * height + j - 1]->alive &&
                    world[i * height + j + 1]->alive &&
                    world[i * height + j - width]->alive) {
                // Increase strength if all neighbors are alive
                world[i * height + j]->strength += 2;
            } else {
                // Decrease strength if no alive neighbors
                world[i * height + j]->strength -= 2;
            }
            // Check if warrior is too weak or too strong
            if (world[i * height + j]->strength < 1 ||
                    world[i * height + j]->strength > 10) {
                // Kill warrior if too weak or too strong
                free(world[i * height + j]);
                world[i * height + j] = NULL;
            }
        }
    }
}

// Function to draw brave warriors
void draw_world(struct Warrior **world, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (world[i * height + j] != NULL) {
                printf(" %d ", world[i * height + j]->strength);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a brave new world
    struct Warrior **world = malloc(sizeof(struct Warrior *) * WIDTH * HEIGHT);
    create_world(world, WIDTH, HEIGHT);

    // Update brave warriors
    update_world(world, WIDTH, HEIGHT);

    // Draw brave warriors
    draw_world(world, WIDTH, HEIGHT);

    return 0;
}