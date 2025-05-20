//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_Nodes 256

typedef struct Node
{
    char character;
    struct Node* left;
    struct Node* right;
} Node;

void insertNode(Node* node, char character)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
        node->character = character;
        node->left = NULL;
        node->right = NULL;
    }
    else if (character < node->character)
    {
        insertNode(node->left, character);
    }
    else
    {
        insertNode(node->right, character);
    }
}

void traverseTree(Node* node)
{
    if (node)
    {
        printf("%c ", node->character);
        traverseTree(node->left);
        traverseTree(node->right);
    }
}

int main()
{
    Node* root = NULL;
    insertNode(root, 'a');
    insertNode(root, 'b');
    insertNode(root, 'c');
    insertNode(root, 'd');
    insertNode(root, 'e');

    traverseTree(root);

    return 0;
}