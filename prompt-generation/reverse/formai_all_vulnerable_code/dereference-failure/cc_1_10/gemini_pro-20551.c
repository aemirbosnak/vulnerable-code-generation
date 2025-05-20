//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    char symbol;
} Entity;

Entity player;
Entity* enemies;
int num_enemies;

void init_game() {
    srand(time(NULL));

    // Initialize the player
    player.pos.x = WIDTH / 2;
    player.pos.y = HEIGHT / 2;
    player.symbol = '@';

    // Initialize the enemies
    num_enemies = 5;
    enemies = malloc(sizeof(Entity) * num_enemies);
    for (int i = 0; i < num_enemies; i++) {
        enemies[i].pos.x = rand() % WIDTH;
        enemies[i].pos.y = rand() % HEIGHT;
        enemies[i].symbol = 'E';
    }
}

void draw_game() {
    // Clear the screen
    system("clear");

    // Draw the player
    printf("\033[%d;%dH%c", player.pos.y + 1, player.pos.x + 1, player.symbol);

    // Draw the enemies
    for (int i = 0; i < num_enemies; i++) {
        printf("\033[%d;%dH%c", enemies[i].pos.y + 1, enemies[i].pos.x + 1, enemies[i].symbol);
    }
}

void update_game() {
    // Get the player's input
    char input = getchar();

    // Move the player
    switch (input) {
        case 'w':
            player.pos.y--;
            break;
        case 's':
            player.pos.y++;
            break;
        case 'a':
            player.pos.x--;
            break;
        case 'd':
            player.pos.x++;
            break;
    }

    // Handle collisions
    for (int i = 0; i < num_enemies; i++) {
        if (player.pos.x == enemies[i].pos.x && player.pos.y == enemies[i].pos.y) {
            printf("Game over!\n");
            exit(0);
        }
    }

    // Move the enemies
    for (int i = 0; i < num_enemies; i++) {
        // Choose a random direction for the enemy to move in
        int direction = rand() % 4;
        switch (direction) {
            case 0:
                enemies[i].pos.y--;
                break;
            case 1:
                enemies[i].pos.y++;
                break;
            case 2:
                enemies[i].pos.x--;
                break;
            case 3:
                enemies[i].pos.x++;
                break;
        }
    }
}

int main() {
    init_game();

    while (1) {
        draw_game();
        update_game();
    }

    return 0;
}