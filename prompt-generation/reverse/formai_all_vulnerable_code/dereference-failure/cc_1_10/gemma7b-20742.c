//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_ITERATIONS 1000

typedef struct Node {
    struct Node* up;
    struct Node* left;
    struct Node* right;
    struct Node* down;
    int state;
} Node;

void percolate(Node* node) {
    if (node->state == 1) {
        node->up->state = 1;
        node->left->state = 1;
        node->right->state = 1;
        node->down->state = 1;
    }
}

int main() {
    srand(time(NULL));

    Node* head = malloc(sizeof(Node));
    head->up = NULL;
    head->left = NULL;
    head->right = NULL;
    head->down = NULL;
    head->state = 0;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Node* node = malloc(sizeof(Node));
            node->up = head;
            node->left = NULL;
            node->right = NULL;
            node->down = NULL;
            node->state = rand() % 2;
            head->left = node;
            head = node;
        }
    }

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        percolate(head);
    }

    return 0;
}