//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum CellState { EMPTY, PLAYER_ONE, PLAYER_TWO } CellState;

typedef struct Node {
    CellState state;
    struct Node* next;
} Node;

Node* createNode(CellState state) {
    Node* node = malloc(sizeof(Node));
    node->state = state;
    node->next = NULL;
    return node;
}

void printBoard(Node* head) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (head->state) {
                case EMPTY:
                    printf(" ");
                    break;
                case PLAYER_ONE:
                    printf("X");
                    break;
                case PLAYER_TWO:
                    printf("O");
                    break;
            }
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = createNode(EMPTY);
    head->next = createNode(EMPTY);
    head->next->next = createNode(EMPTY);

    head->next->next->next = createNode(PLAYER_ONE);
    head->next->next->next->next = createNode(EMPTY);
    head->next->next->next->next->next = createNode(EMPTY);

    printBoard(head);

    return 0;
}