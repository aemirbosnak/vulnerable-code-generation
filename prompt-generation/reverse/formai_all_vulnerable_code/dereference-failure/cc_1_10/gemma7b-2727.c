//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_ Nodes 256

typedef struct Node
{
    char character;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, char character)
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
        node->left = insert(node->left, character);
    }
    else
    {
        node->right = insert(node->right, character);
    }

    return node;
}

void huffman_encode(Node* node, char* buffer, int index)
{
    if (node != NULL)
    {
        huffman_encode(node->left, buffer, index);
        huffman_encode(node->right, buffer, index);

        if (node->character != '\0')
        {
            buffer[index++] = node->character;
            buffer[index++] = (node->left == NULL) ? '0' : '1';
        }
    }
}

int main()
{
    Node* root = insert(NULL, 'a');
    insert(root, 'b');
    insert(root, 'c');
    insert(root, 'd');
    insert(root, 'e');

    char* buffer = (char*)malloc(1024);
    int index = 0;

    huffman_encode(root, buffer, index);

    printf("%s", buffer);

    return 0;
}