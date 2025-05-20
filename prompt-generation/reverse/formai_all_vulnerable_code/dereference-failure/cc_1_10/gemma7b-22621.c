//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node
{
    struct Node* left;
    struct Node* right;
    int symbol;
    int frequency;
} Node;

void insertNode(struct Node* node, int symbol, int frequency)
{
    if (node == NULL)
    {
        node = malloc(sizeof(struct Node));
        node->left = NULL;
        node->right = NULL;
        node->symbol = symbol;
        node->frequency = frequency;
    }
    else if (symbol < node->symbol)
    {
        insertNode(node->left, symbol, frequency);
    }
    else
    {
        insertNode(node->right, symbol, frequency);
    }
}

void traverseTree(struct Node* node)
{
    if (node)
    {
        printf("%c (%d) ", node->symbol, node->frequency);
        traverseTree(node->left);
        traverseTree(node->right);
    }
}

int main()
{
    struct Node* root = NULL;
    insertNode(root, 'a', 5);
    insertNode(root, 'b', 3);
    insertNode(root, 'c', 4);
    insertNode(root, 'd', 2);

    traverseTree(root);

    return 0;
}