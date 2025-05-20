//FormAI DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 1000

void recoverFile(char *diskImage, char *filename);

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <disk image> <file to recover>\n", argv[0]);
        return 1;
    }

    recoverFile(argv[1], argv[2]);

    return 0;
}

void recoverFile(char *diskImage, char *filename) {
    FILE *image = fopen(diskImage, "rb");

    if(image == NULL) {
        printf("Error opening disk image\n");
        return;
    }

    int blocksUsed[MAX_BLOCKS] = {0};
    char block[BLOCK_SIZE];
    int blockIndex = 0;
    int fileFound = 0;

    while(fread(block, sizeof(char), BLOCK_SIZE, image) > 0) {
        if(strstr(block, filename) != NULL) {
            fileFound = 1;
            break;
        }

        if(blockIndex >= MAX_BLOCKS) {
            printf("Too many blocks read, giving up\n");
            return;
        }

        blocksUsed[blockIndex] = 1;
        blockIndex++;
    }

    if(!fileFound) {
        printf("File not found\n");
        return;
    }

    printf("File found!\n");

    FILE *recoveredFile = fopen(filename, "wb");

    if(recoveredFile == NULL) {
        printf("Error creating recovered file\n");
        return;
    }

    fwrite(block, sizeof(char), BLOCK_SIZE, recoveredFile);

    int nextBlock;

    memcpy(&nextBlock, block + 6, sizeof(int));

    while(nextBlock != -1) {
        if(blocksUsed[nextBlock]) {
            printf("Circular file reference detected\n");
            fclose(recoveredFile);
            remove(filename);
            return;
        }

        fseek(image, nextBlock * BLOCK_SIZE, SEEK_SET);
        fread(block, sizeof(char), BLOCK_SIZE, image);

        fwrite(block, sizeof(char), BLOCK_SIZE, recoveredFile);

        blocksUsed[nextBlock] = 1;

        memcpy(&nextBlock, block + 6, sizeof(int));
    }

    fclose(image);
    fclose(recoveredFile);

    printf("File recovered successfully!\n");
}