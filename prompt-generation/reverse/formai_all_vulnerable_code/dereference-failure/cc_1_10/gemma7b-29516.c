//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Node {
    char symbol;
    struct Node* next[BOARD_SIZE];
} Node;

void initializeBoard(Node** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = NULL;
    }
}

void placeSymbol(Node** board, char symbol, int position) {
    board[position]->symbol = symbol;
}

char checkWin(Node** board, char symbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i]->symbol == symbol && board[i]->next[0] == NULL) {
            return symbol;
        }
    }

    return '\0';
}

int main() {
    Node** board = (Node**)malloc(sizeof(Node*) * BOARD_SIZE);
    initializeBoard(board);

    // Game logic
    char currentSymbol = 'X';
    int movePosition;

    // Loop until someone wins or it's a draw
    while (!checkWin(board, currentSymbol) && !checkWin(board, 'O')) {
        printf("Enter move position: ");
        scanf("%d", &movePosition);

        placeSymbol(board, currentSymbol, movePosition);

        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
    }

    // Print the winner or draw
    if (checkWin(board, currentSymbol) == currentSymbol) {
        printf("Winner: %c!\n", currentSymbol);
    } else if (checkWin(board, currentSymbol) == '\0') {
        printf("Draw!\n");
    }

    return 0;
}