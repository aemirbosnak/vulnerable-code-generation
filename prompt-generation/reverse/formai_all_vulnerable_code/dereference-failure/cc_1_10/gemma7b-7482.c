//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initializeBoard(Node** board) {
    *board = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        *board = malloc(sizeof(Node));
        ((*board)->data = 0);
        ((*board)->next = NULL);
        board++;
    }
}

void placeMove(Node** board, int move) {
    Node* current = *board;
    while (current->next) {
        current = current->next;
    }
    current->data = move;
    current->next = malloc(sizeof(Node));
    (*board) = current->next;
}

int checkWin(Node** board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0]->data == board[i]->data && board[0]->data != 0) {
            return board[0]->data;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j]->data == board[j + 1]->data && board[j]->data != 0) {
            return board[j]->data;
        }
    }

    // Check diagonals
    if (board[0]->data == board[4]->data && board[0]->data != 0) {
        return board[0]->data;
    }

    // If all moves have been made and there is no winner, it's a draw
    return 0;
}

int main() {
    Node** board = NULL;
    initializeBoard(&board);

    // Play the game
    int move = 0;
    int winner = 0;

    // Loop until there is a winner or a draw
    while (!winner) {
        // Get the player's move
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Place the move
        placeMove(&board, move);

        // Check if there is a winner
        winner = checkWin(&board);
    }

    // Print the winner
    if (winner) {
        printf("Congratulations! You won!");
    } else {
        printf("It's a draw.");
    }

    return 0;
}