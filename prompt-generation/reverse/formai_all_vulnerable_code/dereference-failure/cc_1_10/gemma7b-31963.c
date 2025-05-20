//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(Node** board) {
    *board = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        *board = malloc(sizeof(Node));
        (*board)->data = i;
        (*board)->next = NULL;
        board++;
    }
}

void placeMove(Node** board, int move) {
    Node* current = *board;
    while (current->next) {
        if (current->data == move) {
            current->data = 2;
            break;
        }
        current = current->next;
    }
}

int checkWin(Node** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[0]->data == board[1]->data && board[0]->data == board[2]->data) {
            return 1;
        }

        // Check columns
        if (board[0]->data == board[3]->data && board[0]->data == board[6]->data) {
            return 1;
        }

        // Check diagonals
        if (board[0]->data == board[4]->data && board[0]->data == board[8]->data) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Node* board;
    initializeBoard(&board);

    placeMove(&board, 0);
    placeMove(&board, 2);
    placeMove(&board, 4);
    placeMove(&board, 6);
    placeMove(&board, 8);

    if (checkWin(&board)) {
        printf("Player 1 won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}