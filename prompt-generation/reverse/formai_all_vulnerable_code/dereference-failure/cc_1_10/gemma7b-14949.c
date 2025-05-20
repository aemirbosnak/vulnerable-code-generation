//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node
{
    char character;
    struct Node* left;
    struct Node* right;
} Node;

struct Node* insertNode(struct Node* node, char character)
{
    if (node == NULL)
    {
        node = (struct Node*)malloc(sizeof(struct Node));
        node->character = character;
        node->left = NULL;
        node->right = NULL;
    }
    else if (character < node->character)
    {
        node->left = insertNode(node->left, character);
    }
    else
    {
        node->right = insertNode(node->right, character);
    }

    return node;
}

void traverseTree(struct Node* node)
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
    struct Node* root = NULL;
    insertNode(root, 'a');
    insertNode(root, 'b');
    insertNode(root, 'c');
    insertNode(root, 'd');
    insertNode(root, 'e');

    traverseTree(root);

    return 0;
}