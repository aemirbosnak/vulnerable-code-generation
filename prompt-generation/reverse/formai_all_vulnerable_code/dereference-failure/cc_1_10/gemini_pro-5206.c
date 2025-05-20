//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 256

typedef struct node {
    int frequency;
    char character;
    struct node *left;
    struct node *right;
} node;

typedef struct huffman_tree {
    node *root;
    int size;
} huffman_tree;

huffman_tree *create_huffman_tree(char *message) {
    huffman_tree *tree = malloc(sizeof(huffman_tree));
    tree->size = 0;
    tree->root = NULL;

    int frequency[MAX_TREE_SIZE] = {0};
    for (int i = 0; i < strlen(message); i++) {
        frequency[(int)message[i]]++;
    }

    node *queue[MAX_TREE_SIZE];
    int queue_size = 0;
    for (int i = 0; i < MAX_TREE_SIZE; i++) {
        if (frequency[i] > 0) {
            node *new_node = malloc(sizeof(node));
            new_node->frequency = frequency[i];
            new_node->character = (char)i;
            new_node->left = NULL;
            new_node->right = NULL;
            queue[queue_size++] = new_node;
        }
    }

    while (queue_size > 1) {
        node *node1 = queue[0];
        node *node2 = queue[1];
        for (int i = 2; i < queue_size; i++) {
            if (node1->frequency + node2->frequency > queue[i]->frequency) {
                node1 = queue[i];
            }
        }

        for (int i = 2; i < queue_size; i++) {
            if (node1->frequency + node2->frequency > queue[i]->frequency) {
                node2 = queue[i];
            }
        }

        node *new_node = malloc(sizeof(node));
        new_node->frequency = node1->frequency + node2->frequency;
        new_node->character = '\0';
        new_node->left = node1;
        new_node->right = node2;
        queue[0] = new_node;
        queue[1] = queue[queue_size - 1];
        queue_size--;
    }

    tree->root = queue[0];
    return tree;
}

void print_huffman_tree(huffman_tree *tree) {
    if (tree->root == NULL) {
        return;
    }

    if (tree->root->left == NULL && tree->root->right == NULL) {
        printf("%c: %d\n", tree->root->character, tree->root->frequency);
        return;
    }

    printf("Node: %d\n", tree->root->frequency);
    print_huffman_tree(tree->root->left);
    print_huffman_tree(tree->root->right);
}

void encode_huffman(huffman_tree *tree, char *message, char **encoded_message) {
    int encoded_message_size = 0;
    for (int i = 0; i < strlen(message); i++) {
        node *current_node = tree->root;
        while (current_node->left != NULL && current_node->right != NULL) {
            if (message[i] == current_node->left->character) {
                current_node = current_node->left;
                encoded_message_size++;
            } else {
                current_node = current_node->right;
                encoded_message_size++;
            }
        }
    }

    *encoded_message = malloc(encoded_message_size + 1);
    int index = 0;
    for (int i = 0; i < strlen(message); i++) {
        node *current_node = tree->root;
        while (current_node->left != NULL && current_node->right != NULL) {
            if (message[i] == current_node->left->character) {
                current_node = current_node->left;
                (*encoded_message)[index++] = '0';
            } else {
                current_node = current_node->right;
                (*encoded_message)[index++] = '1';
            }
        }
    }

    (*encoded_message)[index] = '\0';
}

void decode_huffman(huffman_tree *tree, char *encoded_message, char **decoded_message) {
    int decoded_message_size = 0;
    node *current_node = tree->root;
    for (int i = 0; i < strlen(encoded_message); i++) {
        if (encoded_message[i] == '0') {
            current_node = current_node->left;
            if (current_node->left == NULL && current_node->right == NULL) {
                decoded_message_size++;
                current_node = tree->root;
            }
        } else {
            current_node = current_node->right;
            if (current_node->left == NULL && current_node->right == NULL) {
                decoded_message_size++;
                current_node = tree->root;
            }
        }
    }

    *decoded_message = malloc(decoded_message_size + 1);
    int index = 0;
    current_node = tree->root;
    for (int i = 0; i < strlen(encoded_message); i++) {
        if (encoded_message[i] == '0') {
            current_node = current_node->left;
            if (current_node->left == NULL && current_node->right == NULL) {
                (*decoded_message)[index++] = current_node->character;
                current_node = tree->root;
            }
        } else {
            current_node = current_node->right;
            if (current_node->left == NULL && current_node->right == NULL) {
                (*decoded_message)[index++] = current_node->character;
                current_node = tree->root;
            }
        }
    }

    (*decoded_message)[index] = '\0';
}

int main() {
    char *message = "This is a sample message.";
    huffman_tree *tree = create_huffman_tree(message);
    print_huffman_tree(tree);

    char *encoded_message;
    encode_huffman(tree, message, &encoded_message);
    printf("Encoded message: %s\n", encoded_message);

    char *decoded_message;
    decode_huffman(tree, encoded_message, &decoded_message);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}