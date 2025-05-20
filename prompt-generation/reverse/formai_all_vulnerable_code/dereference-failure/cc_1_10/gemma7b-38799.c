//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
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

Node* insertNode(Node* node, char character, int frequency)
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
        node->left = insertNode(node->left, character, frequency);
    }
    else
    {
        node->right = insertNode(node->right, character, frequency);
    }

    return node;
}

void huffmanEncode(Node* node, char* encoded_string)
{
    if (node != NULL)
    {
        encoded_string[0] = '\0';
        huffmanEncode(node->left, encoded_string);
        huffmanEncode(node->right, encoded_string);

        char prefix = '\0';
        if (node->left != NULL)
        {
            prefix = '0';
        }
        else
        {
            prefix = '1';
        }

        strcat(encoded_string, prefix);
        strcat(encoded_string, node->character);
    }
}

int main()
{
    char text[] = "This is a sample text for Huffman coding.";

    Node* root = insertNode(NULL, 'a', 5);
    insertNode(root, 'e', 3);
    insertNode(root, 'h', 2);
    insertNode(root, 'i', 2);
    insertNode(root, 'n', 2);
    insertNode(root, 'o', 2);
    insertNode(root, 'r', 2);
    insertNode(root, 't', 2);
    insertNode(root, 'u', 2);
    insertNode(root, 'y', 2);

    char encoded_string[1024] = "";

    huffmanEncode(root, encoded_string);

    printf("Encoded string: %s\n", encoded_string);

    return 0;
}