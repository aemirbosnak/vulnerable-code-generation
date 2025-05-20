//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void playTicTacToe() {
    Node* head = createNode(0);
    head->next = createNode(1);
    head->next->next = createNode(2);

    int player = 1;
    int gameWon = 0;
    int moveMade = 0;

    // Loop until someone wins or it's a draw
    while (!gameWon && moveMade < BOARD_SIZE * BOARD_SIZE) {
        // Get the player's move
        int move = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (head->next->value == move) {
            // Make the move
            head->next->value = player;

            // Check if the player has won
            gameWon = checkWin(player, head);

            // Increment the number of moves made
            moveMade++;
        }
    }

    // Print the winner or draw
    if (gameWon) {
        printf("Winner: Player %d\n", player);
    } else {
        printf("Draw\n");
    }
}

int checkWin(int player, Node* head) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (head->next->value == player && head->next->next->value == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (head->next->value == player && head->next->next->next->value == player) {
            return 1;
        }
    }

    // Check diagonals
    if (head->next->value == player && head->next->next->next->value == player) {
        return 1;
    }

    // No win, so return 0
    return 0;
}

int main() {
    playTicTacToe();
    return 0;
}