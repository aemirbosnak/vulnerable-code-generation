//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
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

void printBoard(Node* head) {
    for (Node* node = head; node; node = node->next) {
        printf("%d ", node->x);
    }
    printf("\n");
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
    srand(time(NULL));

    Node* head = newNode(0, 0);
    head->next = newNode(1, 0);
    head->next->next = newNode(2, 0);
    head->next->next->next = newNode(0, 1);
    head->next->next->next->next = newNode(1, 1);
    head->next->next->next->next->next = newNode(2, 1);
    head->next->next->next->next->next->next = newNode(0, 2);
    head->next->next->next->next->next->next->next = newNode(1, 2);
    head->next->next->next->next->next->next->next->next = newNode(2, 2);

    int move = rand() % 9;
    int x = move / BOARD_SIZE;
    int y = move % BOARD_SIZE;

    if (isMoveValid(head, x, y)) {
        printf("Move valid\n");
    } else {
        printf("Move invalid\n");
    }

    return 0;
}