//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_MOVES 10

typedef struct {
    int x;
    int y;
} Position;

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE], Position *treasure, Position *obstacles, int num_obstacles);
void display_grid(char grid[GRID_SIZE][GRID_SIZE], Position player);
int move_player(Position *player, char direction, char grid[GRID_SIZE][GRID_SIZE]);
int check_position(Position player, Position treasure, int moves_remaining);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position player = {0, 0}; // Starting position
    Position treasure;
    Position obstacles[3]; // Number of obstacles
    int moves_remaining = MAX_MOVES;
    char move;
    int won = 0;

    srand(time(NULL));
    initialize_grid(grid, &treasure, obstacles, 3);

    while (moves_remaining > 0 && !won) {
        display_grid(grid, player);
        printf("Moves remaining: %d\n", moves_remaining);
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        if (move_player(&player, move, grid)) {
            moves_remaining--;
            won = check_position(player, treasure, moves_remaining);
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    if (won) {
        printf("Congratulations! You've found the treasure at (%d, %d)!\n", treasure.x, treasure.y);
    } else {
        printf("You've run out of moves! The treasure was at (%d, %d).\n", treasure.x, treasure.y);
    }

    return 0;
}

void initialize_grid(char grid[GRID_SIZE][GRID_SIZE], Position *treasure, Position *obstacles, int num_obstacles) {
    // Fill grid with spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }

    // Place treasure randomly
    treasure->x = rand() % GRID_SIZE;
    treasure->y = rand() % GRID_SIZE;
    grid[treasure->x][treasure->y] = 'T'; // T for treasure

    // Place obstacles randomly
    for (int i = 0; i < num_obstacles; i++) {
        do {
            obstacles[i].x = rand() % GRID_SIZE;
            obstacles[i].y = rand() % GRID_SIZE;
        } while ((obstacles[i].x == treasure->x && obstacles[i].y == treasure->y) || (obstacles[i].x == 0 && obstacles[i].y == 0));
        grid[obstacles[i].x][obstacles[i].y] = 'O'; // O for obstacle
    }
}

void display_grid(char grid[GRID_SIZE][GRID_SIZE], Position player) {
    system("clear"); // Clear the terminal for better display
    grid[player.x][player.y] = 'P'; // P for player

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("[%c]", grid[i][j]);
        }
        printf("\n");
    }

    grid[player.x][player.y] = ' '; // Reset player position for next display
}

int move_player(Position *player, char direction, char grid[GRID_SIZE][GRID_SIZE]) {
    Position new_position = *player;

    switch (direction) {
        case 'w': new_position.x--; break; // Move up
        case 's': new_position.x++; break; // Move down
        case 'a': new_position.y--; break; // Move left
        case 'd': new_position.y++; break; // Move right
        default: return 0; // Invalid direction
    }

    // Check if the move is valid
    if (new_position.x < 0 || new_position.x >= GRID_SIZE || new_position.y < 0 || new_position.y >= GRID_SIZE) {
        return 0; // Out of bounds
    }
    if (grid[new_position.x][new_position.y] == 'O') {
        return 0; // Hit an obstacle
    }

    *player = new_position; // Update the player's position
    return 1;
}

int check_position(Position player, Position treasure, int moves_remaining) {
    return player.x == treasure.x && player.y == treasure.y;
}