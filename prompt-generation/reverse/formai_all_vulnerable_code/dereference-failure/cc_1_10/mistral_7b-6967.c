//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MIN_FREQ 5

typedef struct {
    char ch;
    int freq;
} CharFreq;

void compress(char *input, char *output) {
    CharFreq freqTable[256] = {0};
    int tableIndex = 0;
    int outputIndex = 0;
    int windowSize = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (freqTable[input[i]].freq++ < MIN_FREQ) {
            do {
                output[outputIndex++] = '?';
                tableIndex++;
            } while (freqTable[tableIndex % 256].freq > 0);
            freqTable[input[i]].ch = tableIndex % 256;
        }

        output[outputIndex++] = freqTable[input[i]].ch;
        windowSize++;

        if (windowSize >= BUF_SIZE) {
            for (int j = 0; j < 256; j++) {
                if (--freqTable[j].freq == 0) {
                    tableIndex++;
                    freqTable[j].ch = tableIndex % 256;
                }
            }
            windowSize -= BUF_SIZE;
        }
    }

    output[outputIndex] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char *output = argv[2];

    compress(input, output);

    printf("Compression completed.\n");

    return 0;
}