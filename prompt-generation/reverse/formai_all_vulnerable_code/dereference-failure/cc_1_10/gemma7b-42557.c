//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

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

void placeMove(Node* board, int x, int y) {
    board = newNode(x, y);
    board->next = board;
}

int isBoardFull(Node* board) {
    for (Node* node = board; node; node = node->next) {
        if (node->x == -1) {
            return 0;
        }
    }
    return 1;
}

int checkWin(Node* board) {
    // Horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->x == i && board->next->x == i && board->next->next->x == i) {
            return 1;
        }
    }

    // Vertical win
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->y == j && board->next->y == j && board->next->next->y == j) {
            return 1;
        }
    }

    // Diagonal win
    if (board->x == board->next->y && board->next->next->x == board->y) {
        return 1;
    }

    return 0;
}

int main() {
    Node* board = newNode(-1, -1);
    placeMove(board, 0, 0);
    placeMove(board, 1, 1);
    placeMove(board, 2, 2);

    if (checkWin(board)) {
        printf("Player won!");
    } else if (isBoardFull(board)) {
        printf("Draw!");
    } else {
        printf("Next move...");
    }

    return 0;
}