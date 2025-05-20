//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void initializeBoard(Node** board) {
    *board = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            *board = newNode;
            board = &((*board)->next);
        }
    }
}

void placeMove(Node** board, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    *board = newNode;
    board = &((*board)->next);
}

int checkWin(Node* board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->x == board->next->x && board->x == board->next->next->x) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->y == board->next->y && board->y == board->next->next->y) {
            return 1;
        }
    }

    // Check diagonals
    if (board->x == board->next->y && board->x == board->next->next->x) {
        return 1;
    }

    // No winner
    return 0;
}

int main() {
    Node** board = NULL;
    initializeBoard(&board);

    // Play the game
    placeMove(board, 0, 0);
    placeMove(board, 1, 1);
    placeMove(board, 0, 2);

    if (checkWin(board) == 1) {
        printf("Player 1 won!");
    } else {
        printf("No winner");
    }

    return 0;
}