//GEMINI-pro DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_SHIPS 5
#define MAX_SHIP_SIZE 5

typedef struct ship {
    int size;
    int orientation; // 0 for horizontal, 1 for vertical
    int x, y; // coordinates of the first cell of the ship
} ship;

// create a new ship with the given parameters
ship *create_ship(int size, int orientation, int x, int y) {
    ship *new_ship = (ship *)malloc(sizeof(ship));
    if (new_ship == NULL) {
        perror("malloc");
        exit(1);
    }
    new_ship->size = size;
    new_ship->orientation = orientation;
    new_ship->x = x;
    new_ship->y = y;
    return new_ship;
}

// free the memory allocated to a ship
void free_ship(ship *ship) {
    free(ship);
}

// create a new game board
int **create_board() {
    int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    if (board == NULL) {
        perror("malloc");
        exit(1);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        if (board[i] == NULL) {
            perror("malloc");
            exit(1);
        }
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

// free the memory allocated to a game board
void free_board(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// place a ship on the game board
int place_ship(ship *ship, int **board) {
    // check if the ship is within the bounds of the board
    if (ship->x < 0 || ship->x >= BOARD_SIZE || ship->y < 0 || ship->y >= BOARD_SIZE) {
        return -1;
    }
    // check if there is enough space for the ship
    if (ship->orientation == 0) {
        if (ship->x + ship->size > BOARD_SIZE) {
            return -1;
        }
    } else {
        if (ship->y + ship->size > BOARD_SIZE) {
            return -1;
        }
    }
    // check if the space is occupied
    for (int i = 0; i < ship->size; i++) {
        if (ship->orientation == 0) {
            if (board[ship->x + i][ship->y] != 0) {
                return -1;
            }
        } else {
            if (board[ship->x][ship->y + i] != 0) {
                return -1;
            }
        }
    }
    // place the ship on the board
    for (int i = 0; i < ship->size; i++) {
        if (ship->orientation == 0) {
            board[ship->x + i][ship->y] = 1;
        } else {
            board[ship->x][ship->y + i] = 1;
        }
    }
    return 0;
}

// generate a random ship
ship *generate_random_ship() {
    int size = rand() % MAX_SHIP_SIZE + 1;
    int orientation = rand() % 2;
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    return create_ship(size, orientation, x, y);
}

// generate a random game board
int **generate_random_board() {
    int **board = create_board();
    for (int i = 0; i < NUM_SHIPS; i++) {
        ship *ship = generate_random_ship();
        while (place_ship(ship, board) != 0) {
            free_ship(ship);
            ship = generate_random_ship();
        }
    }
    return board;
}

// print the game board
void print_board(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    srand(time(NULL));
    int **board = generate_random_board();
    print_board(board);
    free_board(board);
    return 0;
}