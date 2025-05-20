//FormAI DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold the compressed data */
typedef struct {
    unsigned char value;
    int count;
} CompressedData;

/* Function to compress the given data and return the compressed data */
CompressedData* compressData(unsigned char* data, int size, int* compressedSize) {
    
    /* Allocate memory for compressed data */
    CompressedData* compressedData = (CompressedData*) malloc(size * sizeof(CompressedData));
    
    /* Compress the data */
    int i,j,k;
    for(i=0, j=0; i<size; j++) {
        compressedData[j].value = data[i];
        compressedData[j].count = 1;
        k=i+1;
        while(data[k] == data[i]) {
            compressedData[j].count++;
            k++;
        }
        i=k;
    }
    
    /* Set the compressed size */
    *compressedSize = j;
    
    /* Return the compressed data */
    return compressedData;
}

/* Function to decompress the given data and return the original data */
unsigned char* decompressData(CompressedData* compressedData, int compressedSize, int* size) {
    
    /* Allocate memory for decompressed data */
    unsigned char* data = (unsigned char*) malloc(compressedSize * sizeof(unsigned char));
    
    /* Decompress the data */
    int i,j,k;
    for(i=0, j=0; i<compressedSize; j++) {
        for(k=0; k<compressedData[i].count; k++) {
            data[j] = compressedData[i].value;
            j++;
        }
        i++;
    }
    
    /* Set the size */
    *size = j;
    
    /* Return the original data */
    return data;
}

/* Demo function to test the compression/decompression */
void demo() {
    
    /* Sample input data */
    unsigned char data[] = {1,1,1,2,2,3,4,4,4,4,5,5};
    int size = sizeof(data) / sizeof(data[0]);
    
    /* Compress the data */
    int compressedSize = 0;
    CompressedData* compressedData = compressData(data, size, &compressedSize);
    
    /* Print the compressed data */
    printf("Compressed Data:\n");
    int i;
    for(i=0; i<compressedSize; i++) {
        printf("(%d, %d) ", compressedData[i].value, compressedData[i].count);
    }
    printf("\n");
    
    /* Decompress the data */
    int originalSize = 0;
    unsigned char* originalData = decompressData(compressedData, compressedSize, &originalSize);
    
    /* Print the original data */
    printf("Original Data:\n");
    for(i=0; i<originalSize; i++) {
        printf("%d ", originalData[i]);
    }
    printf("\n");
    
    /* Free the memory */
    free(compressedData);
    free(originalData);
}

int main() {
    
    /* Demo the compression */
    demo();
    
    /* Exit successfully */
    return 0;
}