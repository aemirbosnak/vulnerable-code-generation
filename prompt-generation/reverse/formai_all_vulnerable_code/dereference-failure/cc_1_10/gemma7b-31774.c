//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: enthusiastic
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

Node* insert(Node* node, char character, int frequency)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
        node->character = character;
        node->frequency = frequency;
        node->left = NULL;
        node->right = NULL;
    }
    else if (character < node->character)
    {
        node->left = insert(node->left, character, frequency);
    }
    else
    {
        node->right = insert(node->right, character, frequency);
    }

    return node;
}

void huffman_encode(Node* node, char* encoded_string)
{
    if (node != NULL)
    {
        encoded_string[0] = '\0';
        huffman_encode(node->left, encoded_string);
        huffman_encode(node->right, encoded_string);

        char left_code = encoded_string[0];
        char right_code = encoded_string[1];

        char prefix_code = left_code ^ right_code;

        sprintf(encoded_string, "%c%s", prefix_code, node->character);
    }
}

int main()
{
    Node* root = insert(NULL, 'a', 5);
    insert(root, 'b', 3);
    insert(root, 'c', 2);
    insert(root, 'd', 4);
    insert(root, 'e', 6);

    char* encoded_string = (char*)malloc(1024);

    huffman_encode(root, encoded_string);

    printf("%s\n", encoded_string);

    return 0;
}