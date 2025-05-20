//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* InsertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintBoard(int** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int CheckWin(int** board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
            return board[j][0];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }

    // If all cells are filled and there is no winner, it's a draw
    return 0;
}

int main() {
    int** board = (int**)malloc(sizeof(int*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int*)malloc(sizeof(int) * BOARD_SIZE);
    }

    int player = 1;
    int gameWon = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Play the game until someone wins or it's a draw
    while (!gameWon) {
        // Get the player's move
        int moveX = 0;
        int moveY = 0;

        // Validate the move
        while (board[moveX][moveY] != 0) {
            printf("Invalid move. Please try again:");
            scanf("%d %d", &moveX, &moveY);
        }

        // Place the player's mark on the board
        board[moveX][moveY] = player;

        // Check if the player has won
        gameWon = CheckWin(board);

        // If the player has not won, switch to the next player
        if (!gameWon) {
            player = (player == 1) ? 2 : 1;
        }
    }

    // Print the winning board
    PrintBoard(board);

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}