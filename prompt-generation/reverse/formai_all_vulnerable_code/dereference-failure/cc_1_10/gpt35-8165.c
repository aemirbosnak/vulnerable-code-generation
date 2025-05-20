//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode_t;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
} MinHeap_t;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *next;
} HuffmanNode_t;

typedef struct HuffmanList {
    struct HuffmanNode *head;
    struct HuffmanNode *tail;
} HuffmanList_t;

MinHeapNode_t *newMinHeapNode(char data, unsigned freq) {
    MinHeapNode_t *node = (MinHeapNode_t *)malloc(sizeof(MinHeapNode_t));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap_t *newMinHeap(unsigned capacity) {
    MinHeap_t *minHeap = (MinHeap_t *)malloc(sizeof(MinHeap_t));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode_t **)malloc(minHeap->capacity * sizeof(MinHeapNode_t *));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode_t **a, MinHeapNode_t **b) {
    MinHeapNode_t *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap_t *minHeap, int idx) {
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

int isSizeOne(MinHeap_t *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode_t *extractMin(MinHeap_t *minHeap) {
    MinHeapNode_t *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(MinHeap_t *minHeap, MinHeapNode_t *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap_t *minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(MinHeapNode_t *root) {
    return !(root->left) && !(root->right);
}

MinHeap_t *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap_t *minHeap = newMinHeap(size);

    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

MinHeapNode_t *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode_t *left, *right, *top;
    MinHeap_t *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newMinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(MinHeapNode_t *root, int arr[], int top, HuffmanList_t *list) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, list);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, list);
    }

    if (isLeaf(root)) {
        HuffmanNode_t *node = (HuffmanNode_t *)malloc(sizeof(HuffmanNode_t));
        node->data = root->data;
        node->code = (char *)malloc((top + 1) * sizeof(char));
        for (int i = 0; i <= top; ++i) {
            node->code[i] = arr[i] + '0';
        }
        node->next = NULL;

        if (list->head == NULL) {
            list->head = list->tail = node;
        } else {
            list->tail->next = node;
            list->tail = node;
        }
    }
}

void printList(HuffmanList_t *list) {
    HuffmanNode_t *node = list->head;

    while (node != NULL) {
        printf("%c: %s\n", node->data, node->code);
        node = node->next;
    }
}

void encodeHuffman(char data[], char encoded[], HuffmanList_t *list) {
    int n = strlen(data);
    char *code;

    for (int i = 0; i < n; ++i) {
        HuffmanNode_t *node = list->head;

        while (node && node->data != data[i]) {
            node = node->next;
        }

        if (node == NULL) {
            printf("Error encoding: character '%c' missing from Huffman list\n", data[i]);
            return;
        }

        code = node->code;
        strcat(encoded, code);
    }
}

void decodeHuffman(MinHeapNode_t *root, char encoded[], int len) {
    MinHeapNode_t *current = root;

    for (int i = 0; i < len; ++i) {
        if (encoded[i] == '0') {
            current = current->left;
        } else if (encoded[i] == '1') {
            current = current->right;
        }

        if (isLeaf(current)) {
            printf("%c", current->data);
            current = root;
        }
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    MinHeapNode_t *root = buildHuffmanTree(data, freq, size);
    HuffmanList_t *list = (HuffmanList_t *)malloc(sizeof(HuffmanList_t));
    list->head = list->tail = NULL;
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top, list);
    printf("Huffman list:\n");
    printList(list);
    char encoded[100] = "";
    char input[] = "edcba";
    encodeHuffman(input, encoded, list);
    printf("\nEncoded string: %s\n", encoded);
    printf("Decoded string: ");
    decodeHuffman(root, encoded, strlen(encoded));

    return 0;
}