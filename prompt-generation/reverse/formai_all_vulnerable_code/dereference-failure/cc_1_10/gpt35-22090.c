//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define PIXELS 64
#define BLOCK_SIZE 8

typedef struct {
    int values[PIXELS][PIXELS];
} Image;

typedef struct {
    int block[BLOCK_SIZE][BLOCK_SIZE];
} Block;

typedef struct {
    int x, y;
    Block data;
} CompressedBlock;

CompressedBlock compressBlock(int startX, int startY, Image* image) 
{
    CompressedBlock result;
    result.x = startX;
    result.y = startY;

    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            result.data.block[i][j] = image->values[startX + i][startY + j];
        }
    }

    return result;
}

Block decompressBlock(CompressedBlock* compressed) 
{
    Block result;

    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            result.block[i][j] = compressed->data.block[i][j];
        }
    }

    return result;
}

CompressedBlock* compressImage(Image* image) 
{
    CompressedBlock* compressedImage = malloc(sizeof(CompressedBlock) * (PIXELS/BLOCK_SIZE) * (PIXELS/BLOCK_SIZE));

    int count = 0;

    for (int i = 0; i < PIXELS; i += BLOCK_SIZE) {
        for (int j = 0; j < PIXELS; j += BLOCK_SIZE) {
            compressedImage[count] = compressBlock(i, j, image);
            count++;
        }
    }

    return compressedImage;
}

Image* decompressImage(CompressedBlock* compressedImage) 
{
    Image* image = malloc(sizeof(Image));

    int count = 0;

    for (int i = 0; i < PIXELS; i += BLOCK_SIZE) {
        for (int j = 0; j < PIXELS; j += BLOCK_SIZE) {
            Block block = decompressBlock(&compressedImage[count]);
            for (int k = 0; k < BLOCK_SIZE; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    image->values[i+k][j+l] = block.block[k][l];
                }
            }
            count++;
        }
    }

    return image;
}

int main() 
{
    Image* original = malloc(sizeof(Image));
    CompressedBlock* compressed;
    Image* decompressed;

    // initialize image with example pixel values
    for (int i = 0; i < PIXELS; i++) {
        for (int j = 0; j < PIXELS; j++) {
            original->values[i][j] = i + j;
        }
    }

    compressed = compressImage(original);
    decompressed = decompressImage(compressed);

    // check if the decompressed image matches the original
    for (int i = 0; i < PIXELS; i++) {
        for (int j = 0; j < PIXELS; j++) {
            if (original->values[i][j] != decompressed->values[i][j]) {
                printf("Error: decompressed image does not match original image.\n");
                return 1;
            }
        }
    }

    printf("Compression and decompression successful.\n");

    free(original);
    free(compressed);
    free(decompressed);

    return 0;
}