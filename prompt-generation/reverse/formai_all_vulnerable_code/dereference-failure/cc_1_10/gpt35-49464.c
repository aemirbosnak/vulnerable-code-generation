//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Huffman tree node
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

// Structure for a priority queue node
struct PQNode
{
    struct Node* data;
    struct PQNode* next;
};

// Create a new node
struct Node* newNode(char ch, int freq)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Create a new priority queue node
struct PQNode* newPQNode(struct Node* data)
{
    struct PQNode* node = (struct PQNode*)malloc(sizeof(struct PQNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node into priority queue
void insertPQNode(struct PQNode** headRef, struct Node* data)
{
    struct PQNode* node = newPQNode(data);
    if (*headRef == NULL || (*headRef)->data->freq > data->freq)
    {
        node->next = *headRef;
        *headRef = node;
    }
    else
    {
        struct PQNode* current = *headRef;
        while (current->next != NULL && current->next->data->freq < data->freq)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// Function to remove the minimum element from priority queue
struct Node* removeMinPQNode(struct PQNode** headRef)
{
    struct PQNode* minNode = *headRef;
    *headRef = (*headRef)->next;
    struct Node* minData = minNode->data;
    free(minNode);
    return minData;
}

// Function to build a Huffman tree
struct Node* buildHuffmanTree(char* data, int* freq, int size)
{
    struct PQNode *first, *second = NULL;
    struct Node *left, *right, *top = NULL;
    first = second = NULL;
    // Create a priority queue and insert all leaf nodes
    for (int i = 0; i < size; i++)
    {
        insertPQNode(&first, newNode(data[i], freq[i]));
    }
    while (first->next != NULL)
    {
        // Remove two minimum frequency nodes from priority queue
        left = removeMinPQNode(&first);
        right = removeMinPQNode(&first);

        // Create a new internal node with frequency equal to sum of two nodes
        // Assign left and right nodes as children of this node
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Add this node to the priority queue
        insertPQNode(&second, top);
    }
    return top;
}

// Function to print Huffman Codes of individual characters
void printHuffmanCodes(struct Node* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    struct Node* root = buildHuffmanTree(data, freq, size);

    int arr[100], top = 0;
    printHuffmanCodes(root, arr, top);

    return 0;
}