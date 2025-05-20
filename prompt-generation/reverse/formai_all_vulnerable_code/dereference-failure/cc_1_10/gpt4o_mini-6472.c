//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ALIVE 'O'
#define DEAD ' '

typedef struct {
    int width;
    int height;
    char** grid;
} World;

World* create_world(int width, int height);
void destroy_world(World* world);
void print_world(World* world);
void evolve(World* world);
int count_neighbors(World* world, int x, int y);
void randomize_world(World* world);
void delay(int seconds);

int main() {
    int width = 20;
    int height = 10;
    World* world = create_world(width, height);
    
    randomize_world(world);
    
    while (1) {
        print_world(world);
        evolve(world);
        delay(1);  // wait for 1 second before next generation
    }

    destroy_world(world);
    return 0;
}

World* create_world(int width, int height) {
    World* world = malloc(sizeof(World));
    world->width = width;
    world->height = height;
    
    world->grid = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        world->grid[i] = malloc(width * sizeof(char));
    }

    return world;
}

void destroy_world(World* world) {
    for (int i = 0; i < world->height; i++) {
        free(world->grid[i]);
    }
    free(world->grid);
    free(world);
}

void print_world(World* world) {
    system("clear"); // clear the terminal
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            putchar(world->grid[i][j]);
        }
        putchar('\n');
    }
}

void evolve(World* world) {
    char** new_grid = malloc(world->height * sizeof(char*));
    for (int i = 0; i < world->height; i++) {
        new_grid[i] = malloc(world->width * sizeof(char));
    }

    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            int neighbors = count_neighbors(world, i, j);
            if (world->grid[i][j] == ALIVE && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = DEAD;
            } else if (world->grid[i][j] == DEAD && neighbors == 3) {
                new_grid[i][j] = ALIVE;
            } else {
                new_grid[i][j] = world->grid[i][j];
            }
        }
    }

    // Update the old grid
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            world->grid[i][j] = new_grid[i][j];
        }
        free(new_grid[i]);
    }
    free(new_grid);
}

int count_neighbors(World* world, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int ni = x + i;
            int nj = y + j;
            if (ni >= 0 && ni < world->height && nj >= 0 && nj < world->width) {
                count += (world->grid[ni][nj] == ALIVE) ? 1 : 0;
            }
        }
    }
    return count;
}

void randomize_world(World* world) {
    srand(time(0));
    for (int i = 0; i < world->height; i++) {
        for (int j = 0; j < world->width; j++) {
            world->grid[i][j] = (rand() % 2 == 0) ? ALIVE : DEAD;
        }
    }
}

void delay(int seconds) {
    sleep(seconds);
}