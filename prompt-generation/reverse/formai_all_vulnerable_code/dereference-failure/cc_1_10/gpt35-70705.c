//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

//create a new Min Heap Node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

//swap the nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

//heapify
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

//create min heap
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return minHeap;
}

//check if the size is 1
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

//get minimum frequency node
struct MinHeapNode* getMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

//insertion (min heap)
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

//build min heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

//check if the node is leaf
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

//create min heap
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

//build huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = getMin(minHeap);
        right = getMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return getMin(minHeap);
}

//print the array
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

//check if the element is present in the array
int isPresent(char arr[], int n, char key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

//huffman coding
void huffmanCodes(struct MinHeapNode* root, int arr[], int top, char* mapping[], int n) {
    if (root->left) {
        arr[top] = 0;
        huffmanCodes(root->left, arr, top + 1, mapping, n);
    }

    if (root->right) {
        arr[top] = 1;
        huffmanCodes(root->right, arr, top + 1, mapping, n);
    }

    if (isLeaf(root)) {
        //assign the code to the element in the mapping array
        int index = isPresent(mapping, n, root->data);
        for (int i = 0; i < top; ++i) {
            mapping[index][i] = arr[i] + '0';
        }
        mapping[index][top] = '\0';
    }
}

//encode the message
void encodeMessage(char message[], char* mapping[], int n) {
    int len = strlen(message);
    printf("Encoded message: ");

    for (int i = 0; i < len; ++i) {
        int index = isPresent(mapping, n, message[i]);
        printf("%s", mapping[index]);
    }
}

//driver program
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data)/sizeof(data[0]);
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT];
    char* mapping[size];

    for(int i = 0; i < size; i++) {
        mapping[i] = (char*) malloc(MAX_TREE_HT * sizeof(char));
    }

    int top = 0;

    huffmanCodes(root, arr, top, mapping, size);
    printf("Huffman codes: \n");
    for (int i = 0; i < size; ++i) {
        printf("%c: %s\n", data[i], mapping[i]);
    }

    char message[] = "badbed";
    encodeMessage(message, mapping, size);
    printf("\n");

    return 0;
}