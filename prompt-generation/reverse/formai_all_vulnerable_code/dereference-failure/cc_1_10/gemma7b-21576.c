//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    return newNode;
}

int checkWin(Node* head) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        Node* current = head;
        while (current) {
            if (current->x == i && current->y == 0) {
                return 1;
            }
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        Node* current = head;
        while (current) {
            if (current->x == 0 && current->y == j) {
                return 1;
            }
        }
    }

    // Check diagonals
    Node* current = head;
    while (current) {
        if (current->x == current->y) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Create the game board
    Node* head = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            insertNode(head, i, j);
        }
    }

    // Play the game
    int playerTurn = 0;
    while (!checkWin(head) && head) {
        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Place the move
        insertNode(head, x, y);

        // Switch turns
        playerTurn = (playerTurn == 0) ? 1 : 0;
    }

    // Check if the game has ended
    if (checkWin(head)) {
        printf("You win!");
    } else {
        printf("Draw!");
    }

    return 0;
}