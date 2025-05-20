//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    int player1 = 1, player2 = 2, currentPlayer = 1, board[BOARD_SIZE][BOARD_SIZE] = {0};

    // Game loop
    while (!board[2][2] && currentPlayer == player1) {
        printf("Enter move (row, column): ");
        int moveRow, moveColumn;
        scanf("%d %d", &moveRow, &moveColumn);

        // Validate move
        if (moveRow < 0 || moveRow >= BOARD_SIZE || moveColumn < 0 || moveColumn >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Place mark
        board[moveRow][moveColumn] = currentPlayer;

        // Check if player won
        if (checkWin(board, currentPlayer) || board[2][2] == currentPlayer) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }

    // Game over
    printf("Game over!\n");

    return 0;
}

int checkWin(int** board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // No win
    return 0;
}