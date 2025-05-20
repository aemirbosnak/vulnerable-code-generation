//FormAI DATASET v1.0 Category: Image compression ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// This is a cheerful program that demonstrates image compression using Huffman Coding.

// Huffman Tree Node structure
struct HuffmanNode {
    int frequency;
    unsigned char data;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Priority Queue Node structure
struct PriorityQueueNode {
    struct HuffmanNode* data;
    struct PriorityQueueNode* next;
};

// Priority Queue structure
struct PriorityQueue {
    struct PriorityQueueNode* head;
};

// This function creates a new Huffman Tree node
struct HuffmanNode* newHuffmanNode(unsigned char data, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This function creates a new Priority Queue Node
struct PriorityQueueNode* newPriorityQueueNode(struct HuffmanNode* data) {
    struct PriorityQueueNode* node = (struct PriorityQueueNode*) malloc(sizeof(struct PriorityQueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// This function creates a new priority queue
struct PriorityQueue* newPriorityQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    queue->head = NULL;
    return queue;
}

// This function inserts a Huffman Node into the Priority Queue based on frequency
void insertIntoPriorityQueue(struct PriorityQueue* queue, struct HuffmanNode* data) {
    struct PriorityQueueNode* node = newPriorityQueueNode(data);
    if (queue->head == NULL || queue->head->data->frequency >= data->frequency) {
        node->next = queue->head;
        queue->head = node;
    } else {
        struct PriorityQueueNode* current = queue->head;
        while (current->next != NULL && current->next->data->frequency < data->frequency) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// This function extracts the minimum node from the priority queue
struct HuffmanNode* extractMinimumFromPriorityQueue(struct PriorityQueue* queue) {
    struct PriorityQueueNode* node = queue->head;
    queue->head = node->next;
    struct HuffmanNode* data = node->data;
    free(node);
    return data;
}

// This function builds the Huffman Tree
struct HuffmanNode* buildHuffmanTree(int frequencyTable[]) {
    struct PriorityQueue* queue = newPriorityQueue();
    int i;
    for (i = 0; i < 256; i++) {
        if (frequencyTable[i] > 0) {
            insertIntoPriorityQueue(queue, newHuffmanNode(i, frequencyTable[i]));
        }
    }
    while (queue->head->next != NULL) {
        struct HuffmanNode* left = extractMinimumFromPriorityQueue(queue);
        struct HuffmanNode* right = extractMinimumFromPriorityQueue(queue);
        insertIntoPriorityQueue(queue, newHuffmanNode(0, left->frequency + right->frequency));
        queue->head->data->left = left;
        queue->head->data->right = right;
    }
    return extractMinimumFromPriorityQueue(queue);
}

// This function recursively traverses the Huffman tree and generates the binary codes for each character
void generateBinaryCodes(struct HuffmanNode* node, char* codeTable[], char* code, int depth) {
    if (node == NULL) {
        return;
    }
    if (node->data != 0) {
        code[depth] = '\0';
        codeTable[node->data] = (char*) malloc((depth + 1) * sizeof(char));
        strcpy(codeTable[node->data], code);
    } else {
        code[depth] = '0';
        generateBinaryCodes(node->left, codeTable, code, depth + 1);
        code[depth] = '1';
        generateBinaryCodes(node->right, codeTable, code, depth + 1);
    }
}

// This function compresses the input image file using Huffman coding and generates an output file
void compressImage(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    int frequencyTable[256] = {0};
    unsigned char buffer;
    while (fread(&buffer, sizeof(char), 1, input)) {
        frequencyTable[buffer]++;
    }
    fclose(input);
    struct HuffmanNode* root = buildHuffmanTree(frequencyTable);
    char* codeTable[256];
    char code[256];
    generateBinaryCodes(root, codeTable, code, 0);
    input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    int bitIndex = 0;
    char outputBuffer = '\0';
    while (fread(&buffer, sizeof(char), 1, input)) {
        char* code = codeTable[buffer];
        int codeLength = strlen(code);
        int i;
        for (i = 0; i < codeLength; i++) {
            if (code[i] == '1') {
                outputBuffer |= 1 << (7 - bitIndex);
            }
            bitIndex++;
            if (bitIndex == 8) {
                fwrite(&outputBuffer, sizeof(char), 1, output);
                bitIndex = 0;
                outputBuffer = '\0';
            }
        }
    }
    if (bitIndex > 0) {
        fwrite(&outputBuffer, sizeof(char), 1, output);
    }
    fclose(input);
    fclose(output);
}

// This function decompresses the input compressed image file and generates an output file
void decompressImage(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    struct HuffmanNode* root = newHuffmanNode(0, 0);
    struct HuffmanNode* current = root;
    unsigned char buffer;
    fread(&buffer, sizeof(char), 1, input);
    while (!feof(input)) {
        int bitIndex;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if ((buffer & (1 << (7 - bitIndex))) == 0) {
                current = current->left;
            } else {
                current = current->right;
            }
            if (current->data != 0) {
                fwrite(&(current->data), sizeof(char), 1, output);
                current = root;
            }
        }
        fread(&buffer, sizeof(char), 1, input);
    }
    fclose(input);
    fclose(output);
}

int main() {
    printf("Welcome to Huffman Image Compression Program!\n");
    printf("Please enter 1 to compress an image file or 2 to decompress a compressed image file: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Please enter the name of the input image file: ");
        char inputFile[256];
        scanf("%s", inputFile);
        printf("Please enter the name of the output compressed file: ");
        char compressedFile[256];
        scanf("%s", compressedFile);
        compressImage(inputFile, compressedFile);
        printf("Image compression complete!\n");
    } else if (choice == 2) {
        printf("Please enter the name of the compressed input file: ");
        char compressedFile[256];
        scanf("%s", compressedFile);
        printf("Please enter the name of the output decompressed image file: ");
        char outputFile[256];
        scanf("%s", outputFile);
        decompressImage(compressedFile, outputFile);
        printf("Image decompression complete!\n");
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}