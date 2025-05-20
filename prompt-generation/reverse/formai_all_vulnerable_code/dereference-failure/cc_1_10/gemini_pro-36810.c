//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int frequency;
    char character;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int frequency, char character) {
    Node *node = malloc(sizeof(Node));
    node->frequency = frequency;
    node->character = character;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compare_nodes(const void *a, const void *b) {
    Node *node_a = (Node *)a;
    Node *node_b = (Node *)b;
    return node_a->frequency - node_b->frequency;
}

Node *build_huffman_tree(Node **nodes, int size) {
    if (size == 1) {
        return nodes[0];
    }

    qsort(nodes, size, sizeof(Node), compare_nodes);

    Node *left = nodes[0];
    Node *right = nodes[1];

    Node *parent = create_node(left->frequency + right->frequency, '\0');
    parent->left = left;
    parent->right = right;

    nodes[0] = parent;
    nodes[1] = nodes[size - 1];
    size--;

    return build_huffman_tree(nodes, size);
}

void print_huffman_code(Node *root, char *code, int size) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->character, code);
        return;
    }

    char left_code[size + 1];
    strcpy(left_code, code);
    strcat(left_code, "0");
    print_huffman_code(root->left, left_code, size + 1);

    char right_code[size + 1];
    strcpy(right_code, code);
    strcat(right_code, "1");
    print_huffman_code(root->right, right_code, size + 1);
}

int main() {
    char input[] = "This is an example of a Huffman coding implementation";

    int frequencies[256] = {0};
    for (int i = 0; input[i] != '\0'; i++) {
        frequencies[input[i]]++;
    }

    int size = 0;
    Node **nodes = malloc(sizeof(Node *) * 256);
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[size++] = create_node(frequencies[i], i);
        }
    }

    Node *root = build_huffman_tree(nodes, size);
    char code[1024];
    print_huffman_code(root, code, 0);

    return 0;
}