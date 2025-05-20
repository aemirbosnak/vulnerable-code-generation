//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct Node {
    char data;
    unsigned freq;
    struct Node* left;
    struct Node* right;
};

// A Min Heap Node
struct MinHeapNode {
    struct Node* data;
    unsigned freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

// The Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Create a new Huffman tree node
struct Node* newNode(char data, unsigned freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new Min Heap node
struct MinHeapNode* newMinHeapNode(struct Node* node, unsigned freq) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->left = NULL;
    minHeapNode->right = NULL;
    minHeapNode->data = node;
    minHeapNode->freq = freq;
    return minHeapNode;
}

// Create a new Min Heap
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two Min Heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify the Min Heap
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

// Check if Min Heap has only one node
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract minimum value node from Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        struct Node* node = newNode(data[i], freq[i]);
        struct MinHeapNode* minHeapNode = newMinHeapNode(node, freq[i]);
        insertMinHeap(minHeap, minHeapNode);
    }
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap)->data;
        right = extractMin(minHeap)->data;
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        struct MinHeapNode* minHeapNode = newMinHeapNode(top, top->freq);
        insertMinHeap(minHeap, minHeapNode);
    }
    return extractMin(minHeap)->data;
}

// Print Huffman codes from the root of Huffman Tree.
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Encode the input string using the given Huffman Tree.
void encode(struct Node* root, char* str) {
    int n = strlen(str);
    int arr[MAX_TREE_HT], top = 0;
    for (int i = 0; i < n; ++i) {
        struct Node* temp = root;
        while (temp->data != str[i]) {
            if (temp->left && strchr(temp->left->data, str[i])) {
                temp = temp->left;
                arr[top++] = 0;
            }
            else {
                temp = temp->right;
                arr[top++] = 1;
            }
        }
    }
    arr[top] = '\0';
    printf("Encoded string is: %s\n", arr);
}

// Decode the encoded string using the given Huffman Tree.
void decode(struct Node* root, char* str) {
    int n = strlen(str);
    struct Node* temp = root;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        if (!temp->left && !temp->right) {
            printf("%c", temp->data);
            temp = root;
        }
    }
}

/************************ Multi-threaded implementation **************************/

// A Huffman tree node, with additional fields for multithreading
struct Node_Thread {
    char data;
    unsigned freq;
    struct Node_Thread *left;
    struct Node_Thread *right;
    pthread_t threadID;
    pthread_mutex_t lock;
};

// Create a new Huffman tree node with the additional fields for multithreading
struct Node_Thread *newNode_Thread(char data, unsigned freq) {
    struct Node_Thread *node = (struct Node_Thread *)malloc(sizeof(struct Node_Thread));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    pthread_mutex_init(&node->lock, NULL);
    return node;
}

// Update the freq value of a Node_Thread struct using a lock to avoid race condition
void updateNodeFreq(struct Node_Thread *node, int freq) {
    pthread_mutex_lock(&node->lock);
    node->freq = freq;
    pthread_mutex_unlock(&node->lock);
}

// A Min Heap Node, with additional fields for multithreading
struct MinHeapNode_Thread {
    struct Node_Thread *data;
    unsigned freq;
    struct MinHeapNode_Thread *left;
    struct MinHeapNode_Thread *right;
    pthread_t threadID;
    pthread_mutex_t lock;
};

// Create a new Min Heap node with the additional fields for multithreading
struct MinHeapNode_Thread *newMinHeapNode_Thread(struct Node_Thread *node, unsigned freq) {
    struct MinHeapNode_Thread *minHeapNode = (struct MinHeapNode_Thread *)malloc(sizeof(struct MinHeapNode_Thread));
    minHeapNode->data = node;
    minHeapNode->freq = freq;
    minHeapNode->left = NULL;
    minHeapNode->right = NULL;
    pthread_mutex_init(&minHeapNode->lock, NULL);
    return minHeapNode;
}

// The Min Heap with the additional fields for multithreading
struct MinHeap_Thread {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode_Thread **array;
    pthread_t threadID;
    pthread_mutex_t lock;
};

// Create a new Min Heap with the additional fields for multithreading
struct MinHeap_Thread *createMinHeap_Thread(unsigned capacity) {
    struct MinHeap_Thread *minHeap = (struct MinHeap_Thread *)malloc(sizeof(struct MinHeap_Thread));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode_Thread **)malloc(minHeap->capacity * sizeof(struct MinHeapNode_Thread *));
    pthread_mutex_init(&minHeap->lock, NULL);
    return minHeap;
}

// Swap two Min Heap nodes with a lock to avoid race condition
void swapMinHeapNode_Thread(struct MinHeapNode_Thread **a, struct MinHeapNode_Thread **b) {
    pthread_mutex_lock(&(*a)->lock);
    pthread_mutex_lock(&(*b)->lock);
    struct MinHeapNode_Thread *t = *a;
    *a = *b;
    *b = t;
    pthread_mutex_unlock(&(*b)->lock);
    pthread_mutex_unlock(&(*a)->lock);
}

// Heapify the Min Heap with a lock to avoid race condition
void minHeapify_Thread(struct MinHeap_Thread *minHeap, int idx) {
    pthread_mutex_lock(&minHeap->array[idx]->lock);
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
        swapMinHeapNode_Thread(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify_Thread(minHeap, smallest);
    }
    pthread_mutex_unlock(&minHeap->array[idx]->lock);
}

// Check if Min Heap has only one node with a lock to avoid race condition
int isSizeOne_Thread(struct MinHeap_Thread *minHeap) {
    int size;
    pthread_mutex_lock(&minHeap->lock);
    size = minHeap->size;
    pthread_mutex_unlock(&minHeap->lock);
    return (size == 1);
}

// Extract minimum value node from Min Heap with a lock to avoid race condition
struct MinHeapNode_Thread *extractMin_Thread(struct MinHeap_Thread *minHeap) {
    pthread_mutex_lock(&minHeap->lock);
    struct MinHeapNode_Thread *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    pthread_mutex_unlock(&minHeap->lock);
    minHeapify_Thread(minHeap, 0);
    return temp;
}

// Insert a new node to Min Heap with a lock to avoid race condition
void insertMinHeap_Thread(struct MinHeap_Thread *minHeap, struct MinHeapNode_Thread *minHeapNode) {
    pthread_mutex_lock(&minHeap->lock);
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
    pthread_mutex_unlock(&minHeap->lock);
}

// Build Huffman tree with multithreading
void *buildHuffmanTree_Thread(void* arg) {
    struct MinHeap_Thread *minHeap = (struct MinHeap_Thread *)arg;
    while (!isSizeOne_Thread(minHeap)) {
        pthread_mutex_lock(&minHeap->lock);
        struct Node_Thread *left = extractMin_Thread(minHeap)->data;
        struct Node_Thread *right = extractMin_Thread(minHeap)->data;
        struct Node_Thread *top = newNode_Thread('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        updateNodeFreq(left, left->freq + right->freq);
        updateNodeFreq(right, left->freq + right->freq);
        struct MinHeapNode_Thread *minHeapNode = newMinHeapNode_Thread(top, top->freq);
        insertMinHeap_Thread(minHeap, minHeapNode);
        pthread_mutex_unlock(&minHeap->lock);
    }
    return NULL;
}

// Print Huffman codes from the root of Huffman Tree with a lock to avoid race condition
void printCodes_Thread(struct Node_Thread *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes_Thread(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes_Thread(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Encode the input string using the given Huffman Tree with multithreading
void encode_Thread(struct Node_Thread *root, char *str) {
    int n = strlen(str);
    int arr[MAX_TREE_HT], top = 0;
    for (int i = 0; i < n; ++i) {
        struct Node_Thread *temp = root;
        while (temp->data != str[i]) {
            if (temp->left && strchr(temp->left->data, str[i])) {
                temp = temp->left;
                arr[top++] = 0;
            }
            else {
                temp = temp->right;
                arr[top++] = 1;
            }
        }
    }
    arr[top] = '\0';
    printf("Encoded string is: %s\n", arr);
}

// Decode the encoded string using the given Huffman Tree with multithreading
void decode_Thread(struct Node_Thread *root, char *str) {
    int n = strlen(str);
    struct Node_Thread *temp = root;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '0') {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
        if (!temp->left && !temp->right) {
            printf("%c", temp->data);
            temp = root;
        }
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Single-threaded implementation
    struct Node* root = buildHuffmanTree(arr, freq, size);
    int arr_single[MAX_TREE_HT], top = 0;
    printCodes(root, arr_single, top);
    encode(root, "abacdef");
    decode(root, "10101111000");

    // Multi-threaded implementation
    struct Node_Thread *root_thread = newNode_Thread('$', 0);
    struct MinHeap_Thread *minHeap_thread = createMinHeap_Thread(size);
    for (int i = 0; i < size; ++i) {
        struct Node_Thread *node = newNode_Thread(arr[i], freq[i]);
        struct MinHeapNode_Thread *minHeapNode = newMinHeapNode_Thread(node, freq[i]);
        insertMinHeap_Thread(minHeap_thread, minHeapNode);
    }
    pthread_create(&minHeap_thread->threadID, NULL, buildHuffmanTree_Thread, minHeap_thread);
    pthread_join(minHeap_thread->threadID, NULL);
    memcpy(root_thread, minHeap_thread->array[0]->data, sizeof(struct Node_Thread));
    int arr_thread[MAX_TREE_HT];
    top = 0;
    printCodes_Thread(root_thread, arr_thread, top);
    encode_Thread(root_thread, "abacdef");
    decode_Thread(root_thread, "10101111000");

    return 0;
}