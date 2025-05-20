//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define MAP_WIDTH 80
#define MAP_HEIGHT 21

// Types
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char symbol;
    int health;
} Entity;

// Global variables
Position playerPos;
Entity *map[MAP_WIDTH][MAP_HEIGHT];

// Function prototypes
void generateMap();
void movePlayer(char direction);
void drawMap();
int main();

// Generate a new map
void generateMap() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the map
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (rand() % 100 < 20) {
                map[i][j] = malloc(sizeof(Entity));
                map[i][j]->symbol = 'G';
                map[i][j]->health = 10;
            } else {
                map[i][j] = NULL;
            }
        }
    }

    // Place the player in the center of the map
    playerPos.x = MAP_WIDTH / 2;
    playerPos.y = MAP_HEIGHT / 2;
}

// Move the player in the specified direction
void movePlayer(char direction) {
    switch (direction) {
        case 'w':
            if (playerPos.y > 0 && map[playerPos.x][playerPos.y - 1] == NULL) {
                playerPos.y--;
            }
            break;
        case 's':
            if (playerPos.y < MAP_HEIGHT - 1 && map[playerPos.x][playerPos.y + 1] == NULL) {
                playerPos.y++;
            }
            break;
        case 'a':
            if (playerPos.x > 0 && map[playerPos.x - 1][playerPos.y] == NULL) {
                playerPos.x--;
            }
            break;
        case 'd':
            if (playerPos.x < MAP_WIDTH - 1 && map[playerPos.x + 1][playerPos.y] == NULL) {
                playerPos.x++;
            }
            break;
    }
}

// Draw the map
void drawMap() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (playerPos.x == i && playerPos.y == j) {
                printf("@");
            } else if (map[i][j] != NULL) {
                printf("%c", map[i][j]->symbol);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Generate the map
    generateMap();

    // Draw the map
    drawMap();

    // Get the player's input
    while (1) {
        char direction = getchar();

        // Move the player
        movePlayer(direction);

        // Draw the map
        drawMap();
    }

    return 0;
}