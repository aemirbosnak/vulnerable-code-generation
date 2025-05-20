//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

Node* createNode(int r, int c) {
    Node* newNode = malloc(sizeof(Node));
    newNode->row = r;
    newNode->col = c;
    newNode->next = NULL;
    return newNode;
}

void connectNodes(Node* node1, Node* node2) {
    node1->next = node2;
}

int isBoardFull(Node* head) {
    while (head) {
        if (head->row == -1) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}

int main() {
    srand(time(NULL));

    // Create the game board
    Node* head = createNode(-1, -1);
    connectNodes(head, createNode(0, 0));
    connectNodes(head, createNode(0, 1));
    connectNodes(head, createNode(0, 2));
    connectNodes(head, createNode(1, 0));
    connectNodes(head, createNode(1, 1));
    connectNodes(head, createNode(1, 2));
    connectNodes(head, createNode(2, 0));
    connectNodes(head, createNode(2, 1));
    connectNodes(head, createNode(2, 2));

    // Play the game
    int move = rand() % 9;
    head->row = move / BOARD_SIZE;
    head->col = move % BOARD_SIZE;
    head->row = -1;

    // Check if the board is full
    if (isBoardFull(head)) {
        printf("The board is full.\n");
    } else {
        printf("The move was made at (%d, %d).\n", head->row, head->col);
    }

    return 0;
}