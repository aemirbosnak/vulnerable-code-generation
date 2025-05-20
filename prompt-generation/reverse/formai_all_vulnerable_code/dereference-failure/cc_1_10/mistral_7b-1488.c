//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>

#define HEIGHT 22
#define WIDTH 50
#define MIN_CH 48
#define MAX_CH 57
#define SPACE ' '
#define LEFT '<'
#define RIGHT '>'
#define BOLDB 'B'
#define BOLD_OFF ' '

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void print_tree(Node *node, int level);
void print_space(int count);
Node* new_node(int data);
Node* insert(Node *node, int data);

int main() {
    Node *root = NULL;

    int arr[] = {37, 26, 65, 12, 34, 88, 93, 74, 2, 44, 55, 79, 66, 20};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        root = insert(root, arr[i]);
    }

    print_tree(root, 0);

    return 0;
}

Node* new_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node *node, int data) {
    if (node == NULL) {
        return new_node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }

    return node;
}

void print_tree(Node *node, int level) {
    if (node == NULL) {
        return;
    }

    print_space(level);

    if (level == 0) {
        printf("%c%c", BOLDB, (node->data + MIN_CH - 23) % (INT_MAX - (MIN_CH - 23)) + MIN_CH);
    } else {
        printf("%c%c", (node->data + MIN_CH - 23) % (INT_MAX - (MIN_CH - 23)) + MIN_CH, BOLD_OFF);
    }

    printf("%s%c", (node->data > INT_MAX / 2 ? "   " : ""), node->data > INT_MAX / 2 ? '\n' : ' ');

    print_tree(node->left, level + 1);
    print_tree(node->right, level + 1);
}

void print_space(int count) {
    for (int i = 0; i < count; i++) {
        printf(SPACE);
    }
}