//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node structure
struct HuffmanNode
{
    char element;
    unsigned frequency;
    struct HuffmanNode *left, *right;
};

// Huffman tree structure
struct HuffmanTree
{
    int size;
    struct HuffmanNode** array;
};

// Utility function to create a new Huffman tree node
struct HuffmanNode* newNode(char element, unsigned frequency)
{
    struct HuffmanNode* node =
        (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->element = element;
    node->frequency = frequency;
    return node;
}

// Utility function to create a new Huffman tree
struct HuffmanTree* createHuffmanTree(int size)
{
    struct HuffmanTree* tree =
        (struct HuffmanTree*) malloc(sizeof(struct HuffmanTree));
    tree->size = 0;
    tree->array = (struct HuffmanNode**) malloc(size * sizeof(struct HuffmanNode*));
    return tree;
}

// Utility function to swap two nodes in the Huffman tree
void swapNodes(struct HuffmanNode** node1, struct HuffmanNode** node2)
{
    struct HuffmanNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Heapify function for min-heap
void minHeapify(struct HuffmanTree* tree, int index)
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if (left < tree->size && tree->array[left]->frequency < tree->array[smallest]->frequency)
        smallest = left;
    if (right < tree->size && tree->array[right]->frequency < tree->array[smallest]->frequency)
        smallest = right;
    if (smallest != index)
    {
        swapNodes(&tree->array[smallest], &tree->array[index]);
        minHeapify(tree, smallest);
    }
}

// Utility function to check if the node is a leaf node
int isLeaf(struct HuffmanNode* node)
{
    return !(node->left) && !(node->right);
}

// Function to build Huffman tree
struct HuffmanNode* buildHuffmanTree(char element[], int frequency[], int size)
{
    struct HuffmanNode *left, *right, *top;
    struct HuffmanTree* tree = createHuffmanTree(size);
    for (int i = 0; i < size; ++i)
        tree->array[i] = newNode(element[i], frequency[i]);
    tree->size = size;

    // Building min-heap for the Huffman tree
    for (int i = (size - 1) / 2; i >= 0; --i)
        minHeapify(tree, i);

    // Extracting the two minimum frequency nodes from the min-heap
    while (tree->size != 1)
    {
        left = tree->array[0];
        swapNodes(&tree->array[0], &tree->array[tree->size-1]);
        --tree->size;
        minHeapify(tree, 0);

        right = tree->array[0];
        swapNodes(&tree->array[0], &tree->array[tree->size-1]);
        --tree->size;
        minHeapify(tree, 0);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        tree->array[tree->size] = top;
        ++tree->size;
        minHeapify(tree, tree->size-1);
    }

    return tree->array[0];
}

// Utility function to print Huffman codes for all characters in the Huffman tree
void printCodes(struct HuffmanNode* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("%c: ", root->element);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    char element[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(element)/sizeof(element[0]);
    struct HuffmanNode* root = buildHuffmanTree(element, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman codes for the characters: \n");
    printCodes(root, arr, top);
    return 0;
}