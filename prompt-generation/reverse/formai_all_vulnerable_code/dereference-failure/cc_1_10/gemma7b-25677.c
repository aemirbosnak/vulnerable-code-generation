//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 1024

typedef struct Node
{
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char character, int frequency)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node* node, char character, int frequency)
{
    if (node == NULL)
    {
        node = newNode(character, frequency);
        return;
    }

    if (character < node->character)
    {
        insert(node->left, character, frequency);
    }
    else
    {
        insert(node->right, character, frequency);
    }
}

void traverse(Node* node)
{
    if (node)
    {
        printf("%c (%d) ", node->character, node->frequency);
        traverse(node->left);
        traverse(node->right);
    }
}

int main()
{
    Node* root = NULL;

    insert(root, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    traverse(root);

    return 0;
}