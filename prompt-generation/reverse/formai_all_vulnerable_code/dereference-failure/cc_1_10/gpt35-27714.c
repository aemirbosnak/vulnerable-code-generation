//FormAI DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

typedef struct block {
    unsigned char data[BLOCK_SIZE];
    int length;
    struct block *next;
} Block;

void compress(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (in == NULL) {
        printf("Error opening input file %s\n", inputFile);
        return;
    }

    FILE *out = fopen(outputFile, "wb");
    if (out == NULL) {
        printf("Error opening output file %s\n", outputFile);
        return;
    }

    Block *currentBlock = NULL;
    int totalLength = 0, blockLength = 0;
    unsigned char currentByte = fgetc(in);

    while (currentByte != EOF) {
        if (currentBlock == NULL || blockLength >= BLOCK_SIZE) {
            if (currentBlock != NULL) {
                currentBlock->length = blockLength;
                totalLength += blockLength;
            }

            currentBlock = (Block *) malloc(sizeof(Block));
            currentBlock->next = NULL;
            blockLength = 0;

            if (totalLength == 0) {
                fwrite(&(currentBlock->length), sizeof(int), 1, out);
            } else {
                fwrite(&(currentBlock->length), sizeof(int), 1, out);
                fwrite(currentBlock->data, sizeof(char), BLOCK_SIZE, out);
            }
        }

        currentBlock->data[blockLength++] = currentByte;
        currentByte = fgetc(in);
    }

    if (currentBlock != NULL) {
        currentBlock->length = blockLength;
        totalLength += blockLength;
        fwrite(&(currentBlock->length), sizeof(int), 1, out);
        fwrite(currentBlock->data, sizeof(char), BLOCK_SIZE, out);
    }

    fclose(in);
    fclose(out);
}

void decompress(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (in == NULL) {
        printf("Error opening input file %s\n", inputFile);
        return;
    }

    FILE *out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Error opening output file %s\n", outputFile);
        return;
    }

    Block *currentBlock = NULL;
    int totalLength = 0, blockLength = 0;
    unsigned char currentByte;

    while (1) {
        if (currentBlock == NULL || blockLength >= currentBlock->length) {
            if (!fread(&blockLength, sizeof(int), 1, in)) {
                break;
            }

            currentBlock = (Block *) malloc(sizeof(Block));
            currentBlock->length = blockLength;
            totalLength += blockLength;

            if (totalLength >= BLOCK_SIZE) {
                fwrite(currentBlock->data, sizeof(char), blockLength, out);
            } else {
                fread(currentBlock->data, sizeof(char), blockLength, in);
            }

            currentBlock->next = NULL;

            if (totalLength == blockLength) {
                fwrite(currentBlock->data, sizeof(char), blockLength, out);
            }
        }

        currentByte = currentBlock->data[blockLength++];
        fputc(currentByte, out);

        if (blockLength == currentBlock->length) {
            Block *temp = currentBlock;
            currentBlock = currentBlock->next;
            free(temp);
            blockLength = 0;
        }
    }

    fclose(in);
    fclose(out);
}

int main(void) {
    char inputFile[] = "input.txt";
    char compressedFile[] = "compressed.dat";
    char outputFile[] = "output.txt";

    compress(inputFile, compressedFile);
    decompress(compressedFile, outputFile);

    return 0;
}