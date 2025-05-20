//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 16
#define IMAGE_HEIGHT 16
#define BLOCK_SIZE 8

// Define image data type
typedef struct {
    int width;
    int height;
    float* data;
} Image;

// Allocate memory for image
Image* allocateImage(int width, int height) {
    Image* img = (Image*) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (float*) malloc(width * height * sizeof(float));
    return img;
}

// Deallocate memory for image
void freeImage(Image* img) {
    free(img->data);
    free(img);
}

// Print image
void printImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%0.2f\t", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

// Quantize block using uniform quantization
void quantizeBlock(float* block, int quality) {
    int scale = quality / 10;
    if (scale == 0) scale = 1;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[i * BLOCK_SIZE + j] = round(block[i * BLOCK_SIZE + j] / scale);
        }
    }
}

// Dequantize block using uniform quantization
void dequantizeBlock(float* block, int quality) {
    int scale = quality / 10;
    if (scale == 0) scale = 1;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[i * BLOCK_SIZE + j] *= scale;
        }
    }
}

// Get 8x8 block from image
void getBlock(Image* img, float* block, int row, int col) {
    for (int i = row; i < row + BLOCK_SIZE; i++) {
        for (int j = col; j < col + BLOCK_SIZE; j++) {
            if (i >= img->height || j >= img->width) {
                block[(i - row) * BLOCK_SIZE + (j - col)] = 0;
            } else {
                block[(i - row) * BLOCK_SIZE + (j - col)] = img->data[i * img->width + j];
            }
        }
    }
}

// Put 8x8 block into image
void putBlock(Image* img, float* block, int row, int col) {
    for (int i = row; i < row + BLOCK_SIZE; i++) {
        for (int j = col; j < col + BLOCK_SIZE; j++) {
            if (i < img->height && j < img->width) {
                img->data[i * img->width + j] = block[(i - row) * BLOCK_SIZE + (j - col)];
            }
        }
    }
}

// Perform discrete cosine transform on 8x8 block
void dct(float* block, int size) {
    float temp[size * size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float sum = 0;
            for (int k = 0; k < size; k++) {
                sum += cos(((2 * i + 1) * k * M_PI) / (2 * size)) * cos(((2 * j + 1) * k * M_PI) / (2 * size)) * block[k * size + j];
            }
            temp[i * size + j] = sum;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            block[i * size + j] = temp[i * size + j];
        }
    }
}

// Perform inverse discrete cosine transform on 8x8 block
void idct(float* block, int size) {
    float temp[size * size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float sum = 0;
            for (int k = 0; k < size; k++) {
                sum += cos(((2 * k + 1) * i * M_PI) / (2 * size)) * cos(((2 * j + 1) * k * M_PI) / (2 * size)) * block[i * size + k];
            }
            temp[i * size + j] = sum;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            block[i * size + j] = temp[i * size + j];
        }
    }
}

// Compress image using JPEG-like algorithm
void compressImage(Image* img, int quality) {
    // Check if image size is divisible by 8
    if (img->height % BLOCK_SIZE != 0 || img->width % BLOCK_SIZE != 0) {
        printf("Error: Image size must be divisible by 8.\n");
        return;
    }
    
    // Divide image into 8x8 blocks
    float block[BLOCK_SIZE * BLOCK_SIZE];
    for (int i = 0; i < img->height; i += BLOCK_SIZE) {
        for (int j = 0; j < img->width; j += BLOCK_SIZE) {
            getBlock(img, block, i, j);
            
            // Perform DCT on block
            dct(block, BLOCK_SIZE);
            
            // Quantize block
            quantizeBlock(block, quality);
            
            // Store quantized block in image data
            putBlock(img, block, i, j);
        }
    }
}

// Decompress image using JPEG-like algorithm
void decompressImage(Image* img, int quality) {
    // Check if image size is divisible by 8
    if (img->height % BLOCK_SIZE != 0 || img->width % BLOCK_SIZE != 0) {
        printf("Error: Image size must be divisible by 8.\n");
        return;
    }
    
    // Divide image into 8x8 blocks
    float block[BLOCK_SIZE * BLOCK_SIZE];
    for (int i = 0; i < img->height; i += BLOCK_SIZE) {
        for (int j = 0; j < img->width; j += BLOCK_SIZE) {
            getBlock(img, block, i, j);
            
            // Dequantize block
            dequantizeBlock(block, quality);
            
            // Perform IDCT on block
            idct(block, BLOCK_SIZE);
            
            // Store dequantized block in image data
            putBlock(img, block, i, j);
        }
    }
}

int main() {
    // Create example image
    Image* img = allocateImage(IMAGE_WIDTH, IMAGE_HEIGHT);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            img->data[i * IMAGE_WIDTH + j] = sin(i * M_PI / 8) * sin(j * M_PI / 8);
        }
    }
    
    // Print original image
    printf("Original image:\n");
    printImage(img);
    
    // Compress and decompress image with quality 30
    compressImage(img, 30);
    decompressImage(img, 30);
    
    // Print decompressed image
    printf("Decompressed image (quality 30):\n");
    printImage(img);
    
    // Compress and decompress image with quality 70
    compressImage(img, 70);
    decompressImage(img, 70);
    
    // Print decompressed image
    printf("Decompressed image (quality 70):\n");
    printImage(img);
    
    // Free memory
    freeImage(img);
    
    return 0;
}