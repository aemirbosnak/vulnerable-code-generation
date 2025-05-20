//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int isMoveValid(Node* head, int x, int y) {
    for (Node* node = head; node; node = node->next) {
        if (node->x == x && node->y == y) {
            return 0;
        }
    }
    return 1;
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Node* head = NULL;

    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}};

    int player = 1;
    int moveMade = 0;

    // Game loop
    while (!moveMade) {
        // Get the player's move
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (isMoveValid(head, x, y)) {
            // Insert the move into the board
            board[x][y] = player;

            // Insert the move into the linked list
            insertNode(head, x, y);

            // Mark the move as made
            moveMade = 1;
        }
    }

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}