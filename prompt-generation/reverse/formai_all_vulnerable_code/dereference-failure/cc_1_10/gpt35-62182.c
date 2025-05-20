//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct MinHeapNode {
    char data;              // input character
    unsigned freq;          // frequency of the character
    struct MinHeapNode *left, *right;   // left and right child nodes
};

// Min heap node
struct MinHeap {
    unsigned size;              // current size of the heap
    unsigned capacity;          // maximum capacity of the heap
    struct MinHeapNode **array;  // array of pointers to heap nodes
};

// create a new Huffman tree node
struct MinHeapNode *newNode(char data, unsigned freq) {
    struct MinHeapNode *node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// create a priority queue with given capacity
struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// swap two nodes of the min heap
void swapNodes(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

// min heapify function
void minHeapify(struct MinHeap *minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

// check if the min heap contains only one node
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// extract the minimum node from the min heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// insert a new node into the min heap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// build the Huffman tree
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// assign codes to characters in the Huffman tree
void assignHuffmanCodes(struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        assignHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        assignHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman encoding function
void encodeHuffmanText(struct MinHeapNode *root, char* text) {
    int len = strlen(text);
    int arr[MAX_TREE_HT], top = 0;
    for (int i = 0; i < len; ++i) {
        struct MinHeapNode *temp = root;
        while (temp->left && temp->right) {
            if (text[i] == '0')
                temp = temp->left;
            else
                temp = temp->right;
            if (!temp->left && !temp->right) {
                printf("%c", temp->data);
                break;
            }
        }
    }
}

// main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    assignHuffmanCodes(root, arr, top);
    char text[] = "aabccdeeeeffffff";
    printf("Encoded text: ");
    encodeHuffmanText(root, text);
    return 0;
}