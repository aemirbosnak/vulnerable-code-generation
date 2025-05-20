//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct Node {
    int character;
    struct Node* next;
} Node;

void insert(Node* node, int character)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->next = NULL;

    if (node == NULL)
    {
        node = newNode;
    }
    else
    {
        node->next = newNode;
    }

    node = newNode;
}

void huffman(Node* node)
{
    int frequency[MAX] = {0};
    node->next = NULL;

    while (node)
    {
        frequency[node->character]++;
        node = node->next;
    }

    node = NULL;
    for (int i = 0; i < MAX; i++)
    {
        if (frequency[i] > 0)
        {
            insert(node, i);
            node = node->next;
        }
    }

    node = NULL;
    while (node)
    {
        printf("%c: %d ", node->character, frequency[node->character]);
        node = node->next;
    }
}

int main()
{
    Node* node = NULL;
    insert(node, 5);
    insert(node, 3);
    insert(node, 4);
    insert(node, 2);
    insert(node, 7);
    insert(node, 6);

    huffman(node);

    return 0;
}