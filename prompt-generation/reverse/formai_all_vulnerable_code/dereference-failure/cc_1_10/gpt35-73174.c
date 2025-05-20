//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure which stores character and their frequency
struct character
{
    int frequency;
    char c;
    
    struct character *left, *right;
};
typedef struct character Character;

//Structure to store a node in the Huffman tree
struct node
{
    int frequency;
    Character *character;
    
    struct node *left, *right;
};
typedef struct node Node;

//Function to create a node in the Huffman tree
Node* newNode(Character *data)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->frequency = data->frequency;
    node->character = data;
    node->left = node->right = NULL;
    return node;
}

//Function to create a Huffman tree
Node* createHuffmanTree(Character *chars[], int n)
{
    //Create a heap of all the character frequencies
    Node *heap[n];
    for(int i = 0; i < n; i++)
        heap[i] = newNode(chars[i]);

    int count = n;
    
    //Build the Huffman tree by merging the 2 minimum character frequencies
    while(count != 1)
    {
        Node *left = heap[--count];
        Node *right = heap[--count];
        Node *node = (Node*) malloc(sizeof(Node));
        node->frequency = left->frequency + right->frequency;
        node->left = left;
        node->right = right;
        heap[count++] = node;
    }

    return heap[0];
}

//Function to print the Huffman codes for each character
void printCodes(Node *node, char *code)
{
    if(node->character)
    {
        printf("Character: %c, Frequency: %d, Code: %s\n", node->character->c, node->character->frequency, code);
        return;
    }

    char leftCode[strlen(code) + 2];
    sprintf(leftCode, "%s0", code);
    printCodes(node->left, leftCode);
    
    char rightCode[strlen(code) + 2];
    sprintf(rightCode, "%s1", code);
    printCodes(node->right, rightCode);
}

//Huffman Coding Driver program
int main()
{
    //Input string
    char inputStr[] = "HuffmanCoding";

    int n = strlen(inputStr);

    //Count each character's frequency in the input string
    int counts[256] = {0};
    for(int i = 0; i < n; i++)
        counts[inputStr[i]]++;

    //Create a character for each non-zero element in the frequency array
    Character *chars[n];
    int j = 0;
    for(int i = 0; i < 256; i++)
    {
        if(counts[i])
        {
            chars[j] = (Character*) malloc(sizeof(Character));
            chars[j]->c = (char) i;
            chars[j]->frequency = counts[i];
            chars[j]->left = chars[j]->right = NULL;
            j++;
        }
    }

    //Build the Huffman tree
    Node *root = createHuffmanTree(chars, j);

    //Print the Huffman codes for each character
    char code[256];
    code[0] = '\0';
    printCodes(root, code);

    return 0;
}