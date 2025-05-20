//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
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

void printBoard(Node* head) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Node* current = head;
            while (current) {
                if (current->x == x && current->y == y) {
                    printf("X ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Node* board = newNode(0, 0);
    board = newNode(1, 0);
    board = newNode(2, 0);
    board = newNode(0, 1);
    board = newNode(1, 1);
    board = newNode(2, 1);
    board = newNode(0, 2);
    board = newNode(1, 2);
    board = newNode(2, 2);

    printBoard(board);

    return 0;
}