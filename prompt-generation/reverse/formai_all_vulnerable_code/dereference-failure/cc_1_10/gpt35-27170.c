//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

// tree node
typedef struct TreeNode {
    char data;
    unsigned freq;
    struct TreeNode *left, *right;
} TreeNode;

// min heap node
typedef struct MinHeapNode {
    TreeNode *treeNode;
    struct MinHeapNode *next;
} MinHeapNode;

// the root node of Huffman Tree
TreeNode *root;

// function to create a new node with given character and frequency
TreeNode *newTreeNode(char data, unsigned freq)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// function that creates a new min heap node with given tree node
MinHeapNode *newMinHeapNode(TreeNode *treeNode)
{
    MinHeapNode *node = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    node->next = NULL;
    node->treeNode = treeNode;
    return node;
}

// function to check if given node is leaf node
int isLeaf(TreeNode *node) { return !(node->left) && !(node->right); }

// function to compare two heap nodes based on their frequency
int minHeapNodeCompare(MinHeapNode *a, MinHeapNode *b)
{
    return (a->treeNode->freq < b->treeNode->freq);
}

// function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// function to sort and insert a new min heap node into the heap
void insertNodeToMinHeap(MinHeapNode **headNode, MinHeapNode *newNode)
{
    if (*headNode == NULL) {
        *headNode = newNode;
        return;
    }
    if (minHeapNodeCompare(newNode, *headNode)) {
        newNode->next = *headNode;
        *headNode = newNode;
    }
    else {
        MinHeapNode *currentNode = *headNode;
        while (currentNode->next != NULL
               && !minHeapNodeCompare(newNode, currentNode->next)) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

// function to remove a node from min heap array
MinHeapNode *removeNodeFromMinHeap(MinHeapNode **headNode)
{
    MinHeapNode *temp = *headNode;
    *headNode = (*headNode)->next;
    return temp;
}

// function to build Huffman Tree
TreeNode *buildHuffmanTree(char data[], unsigned freq[], int size)
{
    MinHeapNode *left, *right, *top;
    MinHeapNode *minHeapHead = NULL;

    for (int i = 0; i < size; ++i) {
        insertNodeToMinHeap(&minHeapHead, newMinHeapNode(newTreeNode(data[i], freq[i])));
    }

    while (minHeapHead->next != NULL) {
        left = removeNodeFromMinHeap(&minHeapHead);
        right = removeNodeFromMinHeap(&minHeapHead);

        top = newMinHeapNode(newTreeNode('$', left->treeNode->freq + right->treeNode->freq));
        top->treeNode->left = left->treeNode;
        top->treeNode->right = right->treeNode;

        insertNodeToMinHeap(&minHeapHead, top);
    }

    return (removeNodeFromMinHeap(&minHeapHead))->treeNode;
}

// function to encode a character using the Huffman Tree
void encodeCharacter(TreeNode *root, char code[], int index)
{
    if (root->left) {
        code[index] = '0';
        encodeCharacter(root->left, code, index + 1);
    }

    if (root->right) {
        code[index] = '1';
        encodeCharacter(root->right, code, index + 1);
    }

    if (isLeaf(root)) {
        code[index] = '\0';
        printf("%c: %s\n", root->data, code);
    }
}

// function to encode the given string using the Huffman Tree
void encodeString(TreeNode *root, char *string)
{
    char code[MAX_TREE_HT], character;
    int i, length = 0;

    for (i = 0; string[i] != '\0'; ++i) {
        if (string[i] != ' ') {
            length++;
        }
    }

    for (i = 0; string[i] != '\0'; ++i) {
        character = string[i];
        if (character != ' ') {
            encodeCharacter(root, code, 0);
        }
    }
}

// main function
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    unsigned freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    root = buildHuffmanTree(data, freq, size);

    char string[] = "this is a test string";
    printf("Huffman Codes for the characters:\n");
    encodeString(root, string);

    return 0;
}