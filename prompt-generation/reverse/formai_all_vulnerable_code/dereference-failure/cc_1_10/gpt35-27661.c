//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256

typedef struct Node {
    char character;
    int frequency;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(char character, int frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct PriorityQueue {
    int size;
    int capacity;
    Node** array;
} PriorityQueue;

PriorityQueue* newPriorityQueue(int capacity) {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (Node**) malloc(capacity * sizeof(Node*));
    return queue;
}

void swap(Node** x, Node** y) {
    Node* temp = *x;
    *x = *y;
    *y = temp;
}

void push(PriorityQueue* queue, Node* node) {
    int i = (queue->size)++;
    while (i > 0 && queue->array[(i - 1) / 2]->frequency > node->frequency) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

Node* pop(PriorityQueue* queue) {
    Node* min = queue->array[0];
    queue->array[0] = queue->array[--(queue->size)];
    int i = 0, j = 1;
    while (j < queue->size) {
        if (j + 1 < queue->size && queue->array[j + 1]->frequency < queue->array[j]->frequency) {
            ++j;
        }
        if (queue->array[i]->frequency <= queue->array[j]->frequency) {
            break;
        }
        swap(&queue->array[i], &queue->array[j]);
        i = j;
        j = i * 2 + 1;
    }
    return min;
}

Node* buildHuffmanTree(int* frequencies) {
    PriorityQueue* queue = newPriorityQueue(ALPHABET_SIZE);
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (frequencies[i] > 0) {
            push(queue, newNode((char) i, frequencies[i]));
        }
    }
    while (queue->size > 1) {
        Node* left = pop(queue);
        Node* right = pop(queue);
        push(queue, newNode('\0', left->frequency + right->frequency));
        queue->array[queue->size - 1]->left = left;
        queue->array[queue->size - 1]->right = right;
    }
    Node* root = pop(queue);
    free(queue->array);
    free(queue);
    return root;
}

void writeBits(FILE* file, unsigned char* buffer, int bufferBits, int* outBits) {
    while (bufferBits >= 8) {
        fputc(*buffer, file);
        (*outBits) += 8;
        bufferBits -= 8;
        ++buffer;
    }
    if (bufferBits > 0) {
        fputc(*buffer, file);
        (*outBits) += bufferBits;
    }
}

void writeCode(FILE* file, Node* root, char* code, int* bufferBits, unsigned char* buffer, int* outBits) {
    if (root->left == NULL && root->right == NULL) {
        code[strlen(code) - 1] = '\0';
        int bitLength = strlen(code);
        int bytes = bitLength / 8;
        int leftBits = bitLength % 8;
        for (int i = 0; i < bytes; ++i) {
            *buffer <<= 1;
            *buffer |= code[i] - '0';
            ++(*bufferBits);
            if (*bufferBits == 8) {
                writeBits(file, buffer, 8, outBits);
                *bufferBits = 0;
                *buffer = 0;
            }
        }
        if (leftBits > 0) {
            for (int i = bitLength - leftBits; i < bitLength; ++i) {
                *buffer <<= 1;
                *buffer |= code[i] - '0';
                ++(*bufferBits);
            }
        }
        if (*bufferBits == 8) {
            writeBits(file, buffer, 8, outBits);
            *bufferBits = 0;
            *buffer = 0;
        }
    } else {
        code[strlen(code)] = '0';
        writeCode(file, root->left, code, bufferBits, buffer, outBits);
        code[strlen(code) - 1] = '1';
        writeCode(file, root->right, code, bufferBits, buffer, outBits);
        code[strlen(code) - 1] = '\0';
    }
}

int compress(char* inputFilename, char* outputFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open %s\n", inputFilename);
        return 1;
    }
    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        printf("Error: could not create %s\n", outputFilename);
        fclose(inputFile);
        return 1;
    }
    int frequencies[ALPHABET_SIZE] = {0};
    char character;
    while ((character = fgetc(inputFile)) != EOF) {
        ++frequencies[(unsigned char) character];
    }
    Node* root = buildHuffmanTree(frequencies);
    char code[ALPHABET_SIZE] = "";
    int bufferBits = 0, outBits = 0;
    unsigned char buffer = 0;
    writeCode(outputFile, root, code, &bufferBits, &buffer, &outBits);
    fwrite(&buffer, 1, 1, outputFile);
    fputc(bufferBits, outputFile);
    fseek(inputFile, 0, SEEK_SET);
    int bytesRead = 0;
    while ((bytesRead = fread(&buffer, 1, 1, inputFile)) > 0) {
        code[0] = '\0';
        Node* node = root;
        int bitLength = 0;
        while (node->left != NULL || node->right != NULL) {
            if (buffer & (1 << (7 - bitLength))) {
                node = node->right;
                code[bitLength++] = '1';
            } else {
                node = node->left;
                code[bitLength++] = '0';
            }
        }
        writeCode(outputFile, root, code, &bufferBits, &buffer, &outBits);
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("Compression complete. Output file: %s\n", outputFilename);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    compress(argv[1], argv[2]);
    return 0;
}