//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 64
#define MAX_MOVES 200

typedef struct Node {
    struct Node* next;
    char move;
    int evaluation;
} Node;

Node* createNode() {
    Node* node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->move = '\0';
    node->evaluation = 0;
    return node;
}

void addMove(Node* node, char move) {
    node->move = move;
    node->next = createNode();
}

int evaluateMove(char move) {
    switch (move) {
        case 'e':
            return 10;
        case 'N':
            return 5;
        case 'B':
            return 3;
        case 'R':
            return 2;
        case 'Q':
            return 9;
        case 'K':
            return 8;
        default:
            return 0;
    }
}

int main() {
    Node* root = createNode();
    addMove(root, 'e');
    addMove(root, 'N');
    addMove(root, 'B');
    addMove(root, 'R');
    addMove(root, 'Q');
    addMove(root, 'K');

    int evaluation = evaluateMove(root->move);
    printf("The evaluation of the move %c is %d\n", root->move, evaluation);

    return 0;
}