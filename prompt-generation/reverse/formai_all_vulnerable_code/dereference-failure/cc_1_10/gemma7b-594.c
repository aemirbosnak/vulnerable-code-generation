//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
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
            board++;
        }
    }
}

int findEmptySlot(Node* board) {
    for (Node* current = board; current; current = current->next) {
        if (current->x == -1 && current->y == -1) {
            return 1;
        }
    }
    return 0;
}

void makeMove(Node** board, int player) {
    int move = findEmptySlot(*board);
    if (move) {
        Node* newNode = malloc(sizeof(Node));
        newNode->x = move % BOARD_SIZE;
        newNode->y = move / BOARD_SIZE;
        newNode->next = NULL;
        *board = newNode;
    }
}

int checkWin(Node* board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->x == board->next->x && board->x == board->next->next->x && board->x == player) {
            return 1;
        }
        board++;
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->y == board->next->y && board->y == board->next->next->y && board->y == player) {
            return 1;
        }
        board++;
    }

    // Check diagonals
    if (board->x == board->next->y && board->x == board->next->next->x && board->x == player) {
        return 1;
    }
    return 0;
}

int main() {
    Node* board;
    initializeBoard(&board);

    // Game loop
    while (1) {
        makeMove(&board, 1);
        if (checkWin(board, 1)) {
            printf("Player 1 won!\n");
            break;
        }

        makeMove(&board, 2);
        if (checkWin(board, 2)) {
            printf("Player 2 won!\n");
            break;
        }

        if (findEmptySlot(board) == 0) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}