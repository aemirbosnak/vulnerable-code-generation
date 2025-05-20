//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct {
    int x;
    int y;
    int fuel;
    int health;
} Ship;

// Define the game board
typedef struct {
    int width;
    int height;
    char **grid;
} Board;

// Create a new ship
Ship *create_ship() {
    Ship *ship = malloc(sizeof(Ship));
    ship->x = 0;
    ship->y = 0;
    ship->fuel = 100;
    ship->health = 100;
    return ship;
}

// Create a new game board
Board *create_board(int width, int height) {
    Board *board = malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->grid = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        board->grid[i] = malloc(sizeof(char) * width);
    }
    return board;
}

// Initialize the game board
void initialize_board(Board *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            board->grid[i][j] = '.';
        }
    }
}

// Place the ship on the game board
void place_ship(Board *board, Ship *ship) {
    board->grid[ship->y][ship->x] = 'S';
}

// Move the ship
void move_ship(Board *board, Ship *ship, int dx, int dy) {
    if (ship->x + dx >= 0 && ship->x + dx < board->width && ship->y + dy >= 0 && ship->y + dy < board->height) {
        board->grid[ship->y][ship->x] = '.';
        ship->x += dx;
        ship->y += dy;
        board->grid[ship->y][ship->x] = 'S';
    }
}

// Print the game board
void print_board(Board *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%c", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new game board
    Board *board = create_board(80, 25);

    // Initialize the game board
    initialize_board(board);

    // Create a new ship
    Ship *ship = create_ship();

    // Place the ship on the game board
    place_ship(board, ship);

    // Main game loop
    while (1) {
        // Get the player's input
        int dx = 0;
        int dy = 0;
        char input = getchar();
        switch (input) {
            case 'w':
                dy = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'a':
                dx = -1;
                break;
            case 'd':
                dx = 1;
                break;
            case 'q':
                return 0;
        }
        //Move the ship
        move_ship(board, ship, dx, dy);

        //Print the game board
        print_board(board);
    }
    
    return 0;
}