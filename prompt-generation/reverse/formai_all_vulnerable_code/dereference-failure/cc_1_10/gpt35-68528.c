//FormAI DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef unsigned char byte;

typedef struct CompressionResult {
    byte* data;
    uint32_t size;
} CompressionResult;

typedef struct HuffmanNode {
    byte byteData;
    uint32_t frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

typedef struct HuffmanQueue {
    uint32_t size;
    uint32_t capacity;
    HuffmanNode **data;
} HuffmanQueue;

static HuffmanNode *NewHuffmanNode(byte byteData){
    HuffmanNode *node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->byteData = byteData;
    node->frequency = 0;
    node->left = node->right = NULL;
    return node;
}

static HuffmanQueue *NewHuffmanQueue(uint32_t capacity){
    HuffmanQueue *queue = (HuffmanQueue*)malloc(sizeof(HuffmanQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->data = (HuffmanNode**)malloc(queue->capacity * sizeof(HuffmanNode*));
    return queue;
}

static void Enqueue(HuffmanQueue *queue, HuffmanNode* node){
    // insert in a sorted fashion
    int i = queue->size - 1;
    while (i >= 0 && node->frequency < queue->data[i]->frequency){
        queue->data[i + 1] = queue->data[i];
        --i;
    }
    queue->data[i + 1] = node;
    ++queue->size;
}

static HuffmanNode *Dequeue(HuffmanQueue *queue){
    HuffmanNode *node = queue->data[--queue->size];
    queue->data[queue->size] = NULL;
    return node;
}

static bool IsLeaf(HuffmanNode *node){
    return node->left == NULL && node->right == NULL;
}

static HuffmanNode *BuildHuffmanTree(byte *data, uint32_t size) {
    if(size == 0){
        return NULL;
    }
    // We create a huffman queue.
    HuffmanQueue* q = NewHuffmanQueue(size);
  
    uint32_t freqCount[256] = {0};
    for(uint32_t i = 0; i < size; ++i){
        ++freqCount[data[i]];
    }
    // Next, we insert the nodes with non-zero frequencies into the queue.
    for(uint32_t i = 0; i < 256; ++i){
        if(freqCount[i] > 0){
            HuffmanNode *node = NewHuffmanNode((byte)i);
            node->frequency = freqCount[i];
            Enqueue(q, node);
        }
    }
    while(q->size > 1){
        HuffmanNode *left = Dequeue(q);
        HuffmanNode *right = Dequeue(q);
        
        HuffmanNode *newNode = NewHuffmanNode(0);
        newNode->frequency = left->frequency + right->frequency;
        newNode->left = left;
        newNode->right = right;
        
        Enqueue(q, newNode);
    }
    return Dequeue(q);
}

static void BuildCodewordsTable(HuffmanNode *node, int32_t code, 
                      uint16_t bitCount, uint16_t *codewords, 
                      uint16_t *codewordLengths){
    if(node == NULL)
        return;
    if(IsLeaf(node)){
        codewords[node->byteData] = (uint16_t)code;
        codewordLengths[node->byteData] = bitCount;
        return;
    }
    BuildCodewordsTable(node->left, (code << 1) | 0, bitCount + 1, 
                codewords, codewordLengths);
    BuildCodewordsTable(node->right, (code << 1) | 1, bitCount + 1, 
                codewords, codewordLengths);
}

static CompressionResult CompressData(byte *data, uint32_t size){
    // we will use a buffer of size 1024 which we will fill in with the compressed data
    byte* buffer = (byte*)malloc(BUFFER_SIZE);
    uint32_t bufferPosition = 0;
    uint32_t bitPosition = 0;
    
    HuffmanNode *root = BuildHuffmanTree(data, size);
    uint16_t codewords[256] = {0};
    uint16_t codewordLengths[256] = {0};
    BuildCodewordsTable(root, 0, 0, codewords, codewordLengths);
    
    // write the codeword lengths into the compressed data
    for(uint32_t i = 0; i < 256; ++i){
        buffer[bufferPosition++] = codewordLengths[i] >> 8;
        buffer[bufferPosition++] = codewordLengths[i] & 0xFF;
    }
    // Write the size of the uncompressed data
    buffer[bufferPosition++] = size >> 24;
    buffer[bufferPosition++] = size >> 16;
    buffer[bufferPosition++] = size >> 8;
    buffer[bufferPosition++] = size & 0xFF;
    for(uint32_t i = 0; i < size; ++i){
        uint16_t code = codewords[data[i]];
        uint16_t codeLength = codewordLengths[data[i]];
        for(uint32_t j = 0; j < codeLength; ++j){
            if((code & (1 << j)) > 0){
                buffer[bufferPosition] |= (1 << bitPosition);
            }
            if(++bitPosition == 8){
                bitPosition = 0;
                ++bufferPosition;
            }
            if(bufferPosition == BUFFER_SIZE - 1){
                // flush the buffer
                fwrite(buffer, sizeof(byte), BUFFER_SIZE, stdout);
                bufferPosition = 0;
            }
        }
    }
    if(bufferPosition > 0){
        // flush the last bytes left in the buffer
        fwrite(buffer, sizeof(byte), bufferPosition, stdout);
    }

    CompressionResult result = {NULL, 0};
    result.size = ftell(stdout);
    result.data = malloc(result.size);
    fseek(stdout, 0, SEEK_SET);
    fread(result.data, sizeof(byte), result.size, stdout);
    fclose(stdout);
    return result;
}

int main(){
    byte testString[] = "ABRACADABRA";
    CompressionResult result = CompressData(testString, sizeof(testString));
    // output the compressed data to the console
    for(uint32_t i = 0; i < result.size; ++i){
        printf("%02X ", result.data[i]);
    }
    // free the memory used to store the compressed data
    free(result.data);
    return 0;
}