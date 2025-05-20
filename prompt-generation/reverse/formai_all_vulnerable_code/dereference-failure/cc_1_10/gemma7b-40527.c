//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#define PACMAN_SIZE 5
#define PACMAN_SPEED 2

#define FOOD_SIZE 2
#define FOOD_AMOUNT 20

typedef struct Food {
    int x;
    int y;
} Food;

typedef struct Pacman {
    int x;
    int y;
    int direction;
} Pacman;

void initializeBoard(int **board) {
    for (int r = 0; r < BOARD_HEIGHT; r++) {
        for (int c = 0; c < BOARD_WIDTH; c++) {
            board[r][c] = 0;
        }
    }
}

void placeFood(Food *food, int amount) {
    for (int i = 0; i < amount; i++) {
        food[i].x = rand() % BOARD_WIDTH;
        food[i].y = rand() % BOARD_HEIGHT;
    }
}

void movePacman(Pacman *pacman) {
    switch (pacman->direction) {
        case 0:
            pacman->x++;
            break;
        case 1:
            pacman->y++;
            break;
        case 2:
            pacman->x--;
            break;
        case 3:
            pacman->y--;
            break;
    }
}

void drawBoard(int **board, Pacman *pacman, Food *food) {
    for (int r = 0; r < BOARD_HEIGHT; r++) {
        for (int c = 0; c < BOARD_WIDTH; c++) {
            if (board[r][c] == 1) {
                printf("#");
            } else if (board[r][c] == 2) {
                printf("$");
            } else if (board[r][c] == 3) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int **board = malloc(BOARD_HEIGHT * sizeof(int *));
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        board[i] = malloc(BOARD_WIDTH * sizeof(int));
    }

    initializeBoard(board);
    Food food[FOOD_AMOUNT];
    placeFood(food, FOOD_AMOUNT);
    Pacman pacman;
    pacman.x = 0;
    pacman.y = 0;
    pacman.direction = 0;

    drawBoard(board, &pacman, food);

    int game_over = 0;
    while (!game_over) {
        movePacman(&pacman);
        drawBoard(board, &pacman, food);

        for (int i = 0; i < FOOD_AMOUNT; i++) {
            if (pacman.x == food[i].x && pacman.y == food[i].y) {
                board[food[i].x][food[i].y] = 0;
                food[i].x = -1;
                food[i].y = -1;
            }
        }

        if (pacman.x == BOARD_WIDTH - 1 || pacman.x == 0) {
            pacman.direction = (pacman.direction + 1) % 4;
        }

        if (pacman.y == BOARD_HEIGHT - 1 || pacman.y == 0) {
            pacman.direction = (pacman.direction + 1) % 4;
        }

        if (food[0].x == -1 && food[0].y == -1) {
            game_over = 1;
        }
    }

    free(board);
    return 0;
}