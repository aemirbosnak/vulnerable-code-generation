//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for game board and game character
#define ROWS 20
#define COLS 30
#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define EMPTY ' '

// Struct to hold game board
typedef struct board {
    int rows;
    int cols;
    char **grid;
} Board;

// Struct to hold game character
typedef struct character {
    int x;
    int y;
} Character;

// Function to create game board
Board *create_board() {
    Board *new_board = malloc(sizeof(Board));
    new_board->rows = ROWS;
    new_board->cols = COLS;
    new_board->grid = malloc(ROWS * sizeof(char *));
    for (int i = 0; i < ROWS; i++) {
        new_board->grid[i] = malloc(COLS * sizeof(char));
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                new_board->grid[i][j] = WALL;
            } else {
                new_board->grid[i][j] = FOOD;
            }
        }
    }
    return new_board;
}

// Function to print game board
void print_board(Board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%c", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to create game character
Character *create_character() {
    Character *new_character = malloc(sizeof(Character));
    new_character->x = ROWS / 2;
    new_character->y = COLS / 2;
    return new_character;
}

// Function to move game character
void move_character(Board *board, Character *character, char direction) {
    int new_x = character->x;
    int new_y = character->y;
    switch(direction) {
        case 'U':
            new_x--;
            break;
        case 'D':
            new_x++;
            break;
        case 'L':
            new_y--;
            break;
        case 'R':
            new_y++;
            break;
    }
    if (board->grid[new_x][new_y] != WALL) {
        character->x = new_x;
        character->y = new_y;
        if (board->grid[new_x][new_y] == FOOD) {
            board->grid[new_x][new_y] = EMPTY;
        }
    }
}

int main() {
    srand(time(NULL));
    Board *board = create_board();
    Character *character = create_character();
    char direction;
    while (1) {
        system("clear");
        print_board(board);
        printf("Enter direction (U/D/L/R): ");
        scanf("%c", &direction);
        move_character(board, character, direction);
        if (board->grid[character->x][character->y] == EMPTY) {
            printf("You win!\n");
            break;
        }
    }
    return 0;
}