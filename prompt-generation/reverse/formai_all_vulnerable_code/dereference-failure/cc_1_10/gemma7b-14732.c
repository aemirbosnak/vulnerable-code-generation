//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the tic tac toe board
#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the tic tac toe board
    Node* board = createNode(0);
    board->next = createNode(1);
    board->next->next = createNode(2);

    // Play the game
    int player = 1;
    int move = 0;

    // Loop until one of the players wins or there is a draw
    while (!board->next->next->next->data) {
        // Get the player's move
        move = rand() % BOARD_SIZE;

        // Place the player's mark on the board
        board->next->next->data = player;

        // Check if the player has won
        if (checkWin(board, player)) {
            printf("Player %d has won!\n", player);
            break;
        }

        // If there has not been a win, switch to the next player
        player = (player == 1) ? 2 : 1;
    }

    // If there has been a draw, print a draw message
    if (!board->next->next->next->data) {
        printf("It's a draw!\n");
    }

    return 0;
}

int checkWin(Node* board, int player) {
    // Check if the player has won in a row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->next->data == player && board->next->next->data == player && board->next->next->next->data == player) {
            return 1;
        }
    }

    // Check if the player has won in a column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->data == player && board->next->data == player && board->next->next->data == player) {
            return 1;
        }
    }

    // Check if the player has won in a diagonal
    if (board->data == player && board->next->next->data == player && board->next->next->next->data == player) {
        return 1;
    }

    // If the player has not won, return 0
    return 0;
}