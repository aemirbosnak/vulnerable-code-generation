//Gemma-7B DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFERSIZE 1024

typedef struct DSPNode {
    struct DSPNode* next;
    double* data;
    int size;
} DSPNode;

void DSPNode_create(DSPNode** node, int size) {
    *node = (DSPNode*)malloc(sizeof(DSPNode));
    (*node)->next = NULL;
    (*node)->data = (double*)malloc(size * sizeof(double));
    (*node)->size = size;
}

void DSPNode_append(DSPNode* node, double* data, int size) {
    DSPNode* newNode = (DSPNode*)malloc(sizeof(DSPNode));
    newNode->next = NULL;
    newNode->data = (double*)malloc(size * sizeof(double));
    newNode->size = size;

    memcpy(newNode->data, data, size * sizeof(double));

    if (node) {
        node->next = newNode;
    }
}

int main() {
    DSPNode* head = NULL;

    // Generate a 1 kHz sine wave
    double* sineData = (double*)malloc(BUFFERSIZE * sizeof(double));
    for (int i = 0; i < BUFFERSIZE; i++) {
        sineData[i] = sin(2 * M_PI * 1000 * i / SAMPLE_RATE) * 2;
    }

    // Append the sine wave to the DSP node
    DSPNode_append(head, sineData, BUFFERSIZE);

    // Play the sine wave
    for (DSPNode* node = head; node; node = node->next) {
        for (int i = 0; i < node->size; i++) {
            printf("%f ", node->data[i]);
        }
        printf("\n");
    }

    return 0;
}