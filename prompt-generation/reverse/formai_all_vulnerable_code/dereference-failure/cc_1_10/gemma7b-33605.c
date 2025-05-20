//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(struct Node));
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

int getRandomMove(Node* head) {
    srand(time(NULL));
    int randMove = rand() % 9;
    while (head && head->x == randMove / BOARD_SIZE && head->y == (randMove % BOARD_SIZE) * BOARD_SIZE) {
        randMove = rand() % 9;
    }
    return randMove;
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 0, 2);
    insertNode(head, 1, 2);
    insertNode(head, 2, 2);

    int move = getRandomMove(head);

    printf("The AI's move is: (%d, %d)\n", move / BOARD_SIZE, move % BOARD_SIZE);

    return 0;
}