//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* newNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void playGame() {
    Node* board = newNode(BOARD_SIZE - 1, BOARD_SIZE - 1);
    char currentPlayer = PLAYER_X;

    // Game loop
    while (!board->next) {
        int moveX, moveY;

        // Get move from player
        printf("Enter move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Validate move
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Place move on board
        Node* moveNode = newNode(moveX, moveY);
        moveNode->next = board;
        board = moveNode;

        // Switch player
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Game over
    printf("Game over! %c won!\n", currentPlayer);
}

int main() {
    playGame();
    return 0;
}