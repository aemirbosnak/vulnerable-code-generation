//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    int frequency;
    char code[50];
} HuffmanNode;

typedef struct {
    char* inputData;
    int inputSize;
    HuffmanNode* nodes;
    int nodeCount;
} HuffmanTree;

typedef struct {
    char* compressedData;
    int compressedSize;
} HuffmanResult;

HuffmanNode* prepareFrequencyTable(char* inputData, int inputSize) {
    int frequencyTable[256] = {0};
    for (int i = 0; i < inputSize; i++) {
        frequencyTable[inputData[i]]++;
    }

    HuffmanNode* nodes = calloc(256, sizeof(HuffmanNode));
    int nodeCount = 0;
    for (int i = 0; i < 256; i++) {
        if (frequencyTable[i] > 0) {
            nodes[nodeCount].symbol = i;
            nodes[nodeCount].frequency = frequencyTable[i];
            nodeCount++;
        }
    }

    return nodes;
}

void sortNodes(HuffmanNode* nodes, int nodeCount) {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = i + 1; j < nodeCount; j++) {
            if (nodes[i].frequency > nodes[j].frequency) {
                HuffmanNode temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

HuffmanNode buildHuffmanTree(HuffmanNode* nodes, int nodeCount) {
    while (nodeCount > 1) {
        HuffmanNode newNode;
        newNode.symbol = '-';
        newNode.frequency = nodes[0].frequency + nodes[1].frequency;
        memcpy(newNode.code, nodes[0].code, 50);
        strcat(newNode.code, "0");
        strcat(nodes[0].code, "1");
        strcat(nodes[1].code, "1");

        if (nodes[0].frequency < nodes[1].frequency) {
            nodes[1] = newNode;
        } else {
            nodes[0] = newNode;
        }

        for (int i = 2; i < nodeCount; i++) {
            nodes[i - 1] = nodes[i];
        }
        nodeCount--;
        sortNodes(nodes, nodeCount);
    }
    return nodes[0];
}

void traverseTreeAndUpdateCodes(HuffmanNode* rootNode, char* code, int level) {
    if (rootNode == NULL) {
        return;
    }

    if (rootNode->symbol != '-') {
        strcpy(rootNode->code, code);
        return;
    }

    traverseTreeAndUpdateCodes(rootNode + 1, strcat(code, "0"), level + 1);
    code[level] = '\0';

    traverseTreeAndUpdateCodes(rootNode + 2, strcat(code, "1"), level + 1);
    code[level] = '\0';
}

HuffmanTree buildHuffmanEncodingTable(char* inputData, int inputSize) {
    HuffmanTree tree;
    tree.inputData = inputData;
    tree.inputSize = inputSize;
    tree.nodes = prepareFrequencyTable(inputData, inputSize);
    tree.nodeCount = 0;

    sortNodes(tree.nodes, 256);
    tree.nodes[0] = buildHuffmanTree(tree.nodes, 256);

    char code[50] = "";
    traverseTreeAndUpdateCodes(tree.nodes, code, 0);

    return tree;
}

HuffmanResult compressDataWithHuffmanEncodingTable(char* inputData, int inputSize, HuffmanTree encodingTable) {
    HuffmanResult result;
    result.compressedData = calloc(inputSize, sizeof(char));
    result.compressedSize = 0;

    for (int i = 0; i < inputSize; i++) {
        for (int j = 0; j < encodingTable.nodeCount; j++) {
            if (encodingTable.nodes[j].symbol == inputData[i]) {
                strcat(result.compressedData, encodingTable.nodes[j].code);
                result.compressedSize += strlen(encodingTable.nodes[j].code);
                break;
            }
        }
    }

    return result;
}

void printEncodingTable(HuffmanTree encodingTable) {
    printf("Symbol - Frequency - Code\n");
    for (int i = 0; i < encodingTable.nodeCount; i++) {
        printf("%c - %d - %s\n", encodingTable.nodes[i].symbol, encodingTable.nodes[i].frequency, encodingTable.nodes[i].code);
    }
}

int main() {
    char inputData[] = "This is a sample sentence that needs to be compressed using the Huffman algorithm.";
    int inputSize = strlen(inputData);
    HuffmanTree encodingTable = buildHuffmanEncodingTable(inputData, inputSize);
    printEncodingTable(encodingTable);
    HuffmanResult compressedData = compressDataWithHuffmanEncodingTable(inputData, inputSize, encodingTable);
    printf("Compressed data: %s\n", compressedData.compressedData);
    printf("Compressed size: %d bits\n", compressedData.compressedSize);
    return 0;
}