//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Node {
    struct Node* up;
    struct Node* right;
    struct Node* down;
    struct Node* left;
    int value;
} Node;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(struct Node));
    newNode->up = NULL;
    newNode->right = NULL;
    newNode->down = NULL;
    newNode->left = NULL;
    newNode->value = value;
    return newNode;
}

void percolate(Node* node) {
    if (node->value == 0) {
        return;
    }
    if (node->up && node->up->value > node->value) {
        node->value = node->up->value;
    }
    if (node->right && node->right->value > node->value) {
        node->value = node->right->value;
    }
    if (node->down && node->down->value > node->value) {
        node->value = node->down->value;
    }
    if (node->left && node->left->value > node->value) {
        node->value = node->left->value;
    }
}

int main() {
    srand(time(NULL));

    Node* root = createNode(rand() % 20);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            createNode(rand() % 20);
        }
    }

    percolate(root);

    return 0;
}