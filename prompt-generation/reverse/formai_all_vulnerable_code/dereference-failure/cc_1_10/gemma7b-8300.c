//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

#define MAX_BOARD_SIZE 3

typedef enum Direction { UP, DOWN, RIGHT, LEFT } Direction;

typedef struct Node {
    int x, y;
    Direction direction;
    struct Node* next;
} Node;

void placeMove(int x, int y, Node** board) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->direction = UP;
    newNode->next = NULL;

    if (*board == NULL) {
        *board = newNode;
    } else {
        (*board)->next = newNode;
    }
}

int checkWin(Node* board) {
    int win = 0;
    Direction currentDirection = UP;

    for (Node* node = board; node; node = node->next) {
        switch (currentDirection) {
            case UP:
                if (node->y == 0 && node->next && node->next->y == 0 && node->next->next && node->next->next->y == 0) {
                    win = 1;
                }
                break;
            case DOWN:
                if (node->y == MAX_BOARD_SIZE - 1 && node->next && node->next->y == MAX_BOARD_SIZE - 1 && node->next->next && node->next->next->y == MAX_BOARD_SIZE - 1) {
                    win = 1;
                }
                break;
            case RIGHT:
                if (node->x == MAX_BOARD_SIZE - 1 && node->next && node->next->x == MAX_BOARD_SIZE - 1 && node->next->next && node->next->next->x == MAX_BOARD_SIZE - 1) {
                    win = 1;
                }
                break;
            case LEFT:
                if (node->x == 0 && node->next && node->next->x == 0 && node->next->next && node->next->next->x == 0) {
                    win = 1;
                }
                break;
        }

        currentDirection = node->direction;
    }

    return win;
}

int main() {
    Node* board = NULL;
    placeMove(0, 0, &board);
    placeMove(1, 0, &board);
    placeMove(2, 0, &board);
    placeMove(0, 1, &board);
    placeMove(1, 1, &board);

    if (checkWin(board)) {
        printf("Win!");
    } else {
        printf("No win.");
    }

    return 0;
}