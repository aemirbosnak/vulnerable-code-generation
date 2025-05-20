//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node
struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

// Min heap node
struct minHeapNode {
    struct node *data;
    unsigned freq;
    struct minHeapNode *left, *right;
};

// Min heap structure
struct minHeap {
    unsigned size;
    unsigned capacity;
    struct minHeapNode **array;
};

// Create a new node
struct node* newNode(char data, unsigned freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a min heap node
struct minHeapNode* newMinHeapNode(struct node* node, unsigned freq) {
    struct minHeapNode* temp = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    temp->left = temp->right = NULL;
    temp->data = node;
    temp->freq = freq;
    return temp;
}

// Swap two min heap nodes
void swapMinHeapNode(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify for min heap
void minHeapify(struct minHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check size of heap
int isSizeOne(struct minHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the minimum value from min heap
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a node into the min heap
void insertMinHeap(struct minHeap* minHeap, struct minHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Build min heap using an array of nodes
void buildMinHeap(struct minHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2;i >= 0;--i)
        minHeapify(minHeap, i);
}

// Check if a node is a leaf node
int isLeaf(struct node* root) {
    return !(root->left) && !(root->right);
}

// Create and build a min heap from node array
struct minHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (struct minHeapNode**)malloc(minHeap->capacity * sizeof(struct minHeapNode*));

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newMinHeapNode(newNode(data[i], freq[i]), freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman tree
struct node* buildHuffmanTree(char data[], int freq[], int size) {
    struct node* left, * right, * top;
    struct minHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left->data;
        top->right = right->data;
        insertMinHeap(minHeap, newMinHeapNode(top, top->freq));
    }

    return extractMin(minHeap)->data;
}

// Hash table for storing codes
void saveCodes(struct node* root, int arr[], int top, int codeTable[][50]) {
    if (root->left) {
        arr[top] = 0;
        saveCodes(root->left, arr, top + 1, codeTable);
    }

    if (root->right) {
        arr[top] = 1;
        saveCodes(root->right, arr, top + 1, codeTable);
    }

    if (isLeaf(root)) {
        for (int i = 0; i < top; ++i) {
            codeTable[root->data][i] = arr[i];
        }
    }
}

// Encode a string using a Huffman tree
void encodeString(char str[], int codeTable[][50], int size) {
    int i, j;
    for (i = 0; str[i]; ++i) {
        for (j = 0; j < size; ++j) {
            if (str[i] == j) {
                for (int k = 0;k < 50;++k) {
                    if (codeTable[j][k] != -1) {
                        printf("%d", codeTable[j][k]);
                    } else {
                        break;
                    }
                }
                printf(" ");
            }
        }
    }
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    struct node* root = buildHuffmanTree(data, freq, size);
    int arr[50], codeTable[256][50];

    for (int i = 0;i < 256;++i) {
        for (int j = 0;j < 50;++j) {
            codeTable[i][j] = -1;
        }
    }

    int top = 0;

    saveCodes(root, arr, top, codeTable);

    printf("Huffman Codes:\n");
    for (int i = 0; i < 256; ++i) {
        if (codeTable[i][0] != -1) {
            printf("%c: ", i);
            for (int j = 0; j < 50; ++j) {
                if (codeTable[i][j] != -1) {
                    printf("%d", codeTable[i][j]);
                } else {
                    break;
                }
            }
            printf("\n");
        }
    }

    printf("\nEncoded string is: ");
    char str[] = "deadbeef";
    encodeString(str, codeTable, size);

    return 0;
}