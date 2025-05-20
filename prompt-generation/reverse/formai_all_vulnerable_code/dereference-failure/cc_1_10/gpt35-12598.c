//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct TreeNode TreeNode;
typedef struct PriorityQueue PriorityQueue;

/* Structure to hold the Huffman code */
typedef struct {
    unsigned int code; /* Huffman code */
    unsigned char length; /* Code length */
} HuffCode;

/* Node of the Huffman tree */
struct TreeNode {
    unsigned int freq; /* Frequency of character */
    unsigned char ch; /* Character */
    TreeNode *left; /* Pointer to left child node */
    TreeNode *right; /* Pointer to right child node */
};

/* Priority queue to hold the nodes of the Huffman tree */
struct PriorityQueue {
    int size; /* Current number of elements in queue */
    int capacity; /* Maximum number of elements */
    TreeNode **data; /* Array to hold queue elements */
};

/* Create a PriorityQueue with the given maximum size */
PriorityQueue *createPriorityQueue(int capacity) {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->data = (TreeNode **)malloc(capacity * sizeof(TreeNode *));
    return queue;
}

/* Compare two TreeNodes by frequency */
int compareByFreq(const void *a, const void *b) {
    TreeNode *aNode = *(TreeNode **)a;
    TreeNode *bNode = *(TreeNode **)b;
    return (aNode->freq - bNode->freq);
}

/* Add a TreeNode to the PriorityQueue */
void addToPriorityQueue(PriorityQueue *queue, TreeNode *node) {
    int i = queue->size;
    queue->size++;
    while (i > 0 && (node->freq < queue->data[(i - 1) / 2]->freq)) {
        queue->data[i] = queue->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->data[i] = node;
}

/* Remove and return the minimum element from the PriorityQueue */
TreeNode *removeMinFromPriorityQueue(PriorityQueue *queue) {
    if (queue->size <= 0) {
        return NULL;
    } else {
        TreeNode *minNode = queue->data[0];
        queue->size--;
        if (queue->size > 0) {
            queue->data[0] = queue->data[queue->size];
            int i = 0;
            while ((2 * i + 1) < queue->size) {
                int child = 2 * i + 1;
                if (((child + 1) < queue->size) && (queue->data[child + 1]->freq < queue->data[child]->freq)) {
                    child++;
                }
                if (queue->data[i]->freq > queue->data[child]->freq) {
                    TreeNode *tmp = queue->data[i];
                    queue->data[i] = queue->data[child];
                    queue->data[child] = tmp;
                    i = child;
                } else {
                    break;
                }
            }
        }
        return minNode;
    }
}

/* Create a binary Huffman tree from the input frequency array */
TreeNode *createHuffmanTree(unsigned int *freqArr) {
    PriorityQueue *queue = createPriorityQueue(MAX_CHARS);
    TreeNode *node;

    /* Create a priority queue with tree nodes */
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freqArr[i] > 0) {
            node = (TreeNode *)malloc(sizeof(TreeNode));
            node->ch = (unsigned char)i;
            node->freq = freqArr[i];
            node->left = NULL;
            node->right = NULL;
            addToPriorityQueue(queue, node);
        }
    }

    while (queue->size > 1) {
        TreeNode *left = removeMinFromPriorityQueue(queue);
        TreeNode *right = removeMinFromPriorityQueue(queue);
        node = (TreeNode *)malloc(sizeof(TreeNode));
        node->ch = 0;
        node->freq = left->freq + right->freq;
        node->left = left;
        node->right = right;
        addToPriorityQueue(queue, node);
    }
    node = removeMinFromPriorityQueue(queue);
    free(queue->data);
    free(queue);
    return node;
}

/* Generate Huffman codes recursively */
void generateHuffCodes(TreeNode *node, unsigned int code, unsigned int length, HuffCode *huffCodes) {
    if (node == NULL) {
        return;
    } else {
        if ((node->left == NULL) && (node->right == NULL)) {
            huffCodes[node->ch].code = code;
            huffCodes[node->ch].length = length;
        } else {
            generateHuffCodes(node->left, code << 1, length + 1, huffCodes);
            generateHuffCodes(node->right, (code << 1) | 1, length + 1, huffCodes);
        }
    }
}

/* Print the Huffman code table */
void printHuffCodes(HuffCode *huffCodes) {
    printf("Huffman Code Table:\n");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (huffCodes[i].length > 0) {
            printf("%c: %u (%d bits)\n", i, huffCodes[i].code, huffCodes[i].length);
        }
    }
}

/* Encode the input string using the Huffman code table */
unsigned char *encodeString(const char *str, HuffCode *huffCodes, size_t *len) {
    size_t strLen = strlen(str);
    unsigned char *encodedData = (unsigned char *)malloc(strLen * sizeof(unsigned char));
    unsigned int bitsWritten = 0;
    unsigned char byte = 0;
    for (int i = 0; i < strLen; i++) {
        HuffCode code = huffCodes[str[i]];
        for (int j = 0; j < code.length; j++) {
            byte |= ((code.code >> (code.length - 1 - j)) & 1) << (7 - bitsWritten);
            bitsWritten++;
            if (bitsWritten == 8) {
                encodedData[*len] = byte;
                (*len)++;
                byte = 0;
                bitsWritten = 0;
            }
        }
    }
    if (bitsWritten > 0) {
        encodedData[*len] = byte;
        (*len)++;
    }
    return encodedData;
}

/* Decode the input string using the Huffman code table */
char *decodeString(unsigned char *data, size_t len, TreeNode *tree) {
    char *decodedStr = (char *)malloc((len + 1) * sizeof(char));
    TreeNode *node = tree;
    int index = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 7; j >= 0; j--) {
            int bit = ((data[i] >> j) & 1);
            if (bit == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            if ((node->left == NULL) && (node->right == NULL)) {
                decodedStr[index] = node->ch;
                index++;
                node = tree;
            }
        }
    }
    decodedStr[index] = '\0';
    return decodedStr;
}

int main() {
    const char *str = "abacabadabacaba";
    unsigned int freqArr[MAX_CHARS] = {0};
    for (int i = 0; i < strlen(str); i++) {
        freqArr[(int)str[i]]++;
    }

    TreeNode *tree = createHuffmanTree(freqArr);
    HuffCode huffCodes[MAX_CHARS] = {0};
    generateHuffCodes(tree, 0, 0, huffCodes);

    printHuffCodes(huffCodes);

    size_t len = 0;
    unsigned char *encodedData = encodeString(str, huffCodes, &len);

    printf("Encoded Data (len=%lu):\n", len);
    for (int i = 0; i < len; i++) {
        printf("%02x ", encodedData[i]);
    }
    printf("\n");

    char *decodedData = decodeString(encodedData, len, tree);
    printf("Decoded Data: %s\n", decodedData);

    free(encodedData);
    free(decodedData);
    free(tree);

    return 0;
}