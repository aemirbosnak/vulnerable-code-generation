//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct node {
    char data;
    int frequency;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(char data, int frequency) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void free_node(Node* node) {
    if (node!= NULL) {
        free_node(node->left);
        free_node(node->right);
        free(node);
    }
}

void print_tree(Node* root) {
    if (root!= NULL) {
        print_tree(root->left);
        printf("%c: %d\n", root->data, root->frequency);
        print_tree(root->right);
    }
}

void build_tree(Node** root, Node** min_node, Node** max_node) {
    if (*min_node == NULL || (*min_node)->frequency > (*max_node)->frequency) {
        *min_node = *max_node;
        *max_node = *min_node;
    }
    if (*min_node!= NULL) {
        (*min_node)->left = create_node('\0', 0);
        (*min_node)->right = create_node('\0', 0);
        build_tree(&((*min_node)->left), min_node, max_node);
        build_tree(&((*min_node)->right), min_node, max_node);
    }
}

void inorder_traversal(Node* root) {
    if (root!= NULL) {
        inorder_traversal(root->left);
        printf("%c: %d\n", root->data, root->frequency);
        inorder_traversal(root->right);
    }
}

void compress(char* data, Node* root, char* compressed) {
    if (root == NULL) {
        return;
    }
    if (data[0] == root->data) {
        compressed[0] = root->data;
        compressed[1] = '\0';
        return;
    }
    compress(data + 1, root->left, compressed);
    compress(data + 1, root->right, compressed);
}

void decompress(char* compressed, Node* root, char* data) {
    if (root == NULL) {
        return;
    }
    if (compressed[0] == root->data) {
        data[0] = root->data;
        data[1] = '\0';
        return;
    }
    decompress(compressed + 1, root->left, data);
    decompress(compressed + 1, root->right, data);
}

int main() {
    char data[] = "This is a test string for Huffman compression";
    char compressed[MAX_LEN + 1];
    Node* root;
    Node* min_node;
    Node* max_node;
    Node* node;

    build_tree(&root, &min_node, &max_node);
    print_tree(root);
    printf("\nInorder traversal of the tree:\n");
    inorder_traversal(root);
    printf("\nCompressing the string:\n");
    compress(data, root, compressed);
    printf("Compressed string: %s\n", compressed);
    printf("\nDecompressing the string:\n");
    decompress(compressed, root, data);
    printf("Decompressed string: %s\n", data);

    free_node(root);
    free_node(min_node);
    free_node(max_node);

    return 0;
}