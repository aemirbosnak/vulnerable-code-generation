//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void initBoard(Node** board) {
    *board = NULL;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = *board;
            *board = newNode;
        }
    }
}

int isMoveValid(Node* board, int x, int y) {
    if (board == NULL) {
        return 0;
    }

    for (Node* node = board; node; node = node->next) {
        if (node->x == x && node->y == y) {
            return 0;
        }
    }

    return 1;
}

void makeMove(Node** board, int x, int y) {
    if (!isMoveValid(*board, x, y)) {
        return;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = *board;
    *board = newNode;
}

int main() {
    Node* board;
    initBoard(&board);

    makeMove(&board, 0, 0);
    makeMove(&board, 1, 0);
    makeMove(&board, 2, 0);
    makeMove(&board, 0, 1);
    makeMove(&board, 1, 1);

    for (Node* node = board; node; node = node->next) {
        printf("(%d, %d) ", node->x, node->y);
    }

    return 0;
}