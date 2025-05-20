//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node {
    int freq;
    char ch;
    struct _node *left;
    struct _node *right;
} node;

node *create_node(char ch, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->freq = freq;
    new_node->ch = ch;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *find_min(node *root) {
    node *current = root;
    while (current->left!= NULL) {
        current = current->left;
    }
    return current;
}

void inorder_traversal(node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%c ", root->ch);
    inorder_traversal(root->right);
}

void build_huffman_tree(node **root, node *nodes[], int num_nodes) {
    if (num_nodes == 1) {
        (*root) = nodes[0];
        return;
    }
    node *node1 = nodes[0];
    node *node2 = nodes[1];
    int freq1 = node1->freq;
    int freq2 = node2->freq;
    node *new_node = create_node('?', freq1 + freq2);
    new_node->left = node1;
    new_node->right = node2;
    nodes[0] = node1;
    nodes[1] = node2;
    nodes[2] = new_node;
    build_huffman_tree(&(new_node->left), nodes, 3);
    build_huffman_tree(&(new_node->right), nodes, 3);
}

int main() {
    char input[] = "THIS IS A TEST";
    node *nodes[10];
    int num_nodes = 0;
    int i = 0;
    for (i = 0; i < sizeof(input); i++) {
        node *new_node = create_node(input[i], 1);
        nodes[num_nodes] = new_node;
        num_nodes++;
    }
    node **root = &nodes[0];
    build_huffman_tree(root, nodes, num_nodes);
    node *current = find_min(root);
    while (current!= NULL) {
        printf("%c", current->ch);
        current = current->left;
    }
    printf("\n");
    return 0;
}