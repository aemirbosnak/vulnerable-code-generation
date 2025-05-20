//FormAI DATASET v1.0 Category: Image compression ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define constants for compression
#define BLOCK_SIZE 4
#define COMPRESS_RATIO 0.5

// Define function prototypes
bool compress_image(int **image, int rows, int cols);
bool decompress_image(int **compressed_image, int rows, int cols);

int main() {
    printf("Welcome to our amazing image compression program!\n");

    // Prompt user for image dimensions
    int rows, cols;
    printf("\nPlease enter the number of rows in the image: ");
    scanf("%d", &rows);
    printf("\nPlease enter the number of columns in the image: ");
    scanf("%d", &cols);

    // Allocate memory for the original image
    int **image = (int**) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
        image[i] = (int*) malloc(cols * sizeof(int));
    }

    // Prompt user for image pixel values
    printf("\nPlease enter the pixel values of the image:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("Pixel(%d,%d): ", i, j);
            scanf("%d", &image[i][j]);
        }
    }

    // Compress the image
    bool is_compressed = compress_image(image, rows, cols);
    if(is_compressed) {
        printf("\nImage compression has been successful!\n");
    } else {
        printf("\nFailed to compress the image!\n");
    }

    // Deallocate memory for the original image
    for(int i=0; i<rows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}

// Define the compression function
bool compress_image(int **image, int rows, int cols) {
    printf("\nCompressing the image...\n");

    // Allocate memory for the compressed array
    int **compressed_image = (int**) malloc(rows/BLOCK_SIZE * sizeof(int*));
    for(int i=0; i<rows/BLOCK_SIZE; i++) {
        compressed_image[i] = (int*) malloc(cols/BLOCK_SIZE * sizeof(int));
    }

    // Iterate through the image pixels and calculate the average block value
    for(int i=0; i<rows; i+=BLOCK_SIZE) {
        for(int j=0; j<cols; j+=BLOCK_SIZE) {
            int sum = 0;
            for(int k=i; k<i+BLOCK_SIZE; k++) {
                for(int l=j; l<j+BLOCK_SIZE; l++) {
                    sum += image[k][l];
                }
            }
            int average = sum / (BLOCK_SIZE*BLOCK_SIZE);
            compressed_image[i/BLOCK_SIZE][j/BLOCK_SIZE] = average * COMPRESS_RATIO;
        }
    }

    // Deallocate memory for the original image
    for(int i=0; i<rows; i++) {
        free(image[i]);
    }
    free(image);

    // Call the decompression function to show the compressed image
    bool is_decompressed = decompress_image(compressed_image, rows/BLOCK_SIZE, cols/BLOCK_SIZE);
    if(!is_decompressed) {
        printf("\nFailed to decompress the image!\n");
        return false;
    }

    // Deallocate memory for the compressed image
    for(int i=0; i<rows/BLOCK_SIZE; i++) {
        free(compressed_image[i]);
    }
    free(compressed_image);

    return true;
}

// Define the decompression function
bool decompress_image(int **compressed_image, int rows, int cols) {
    printf("\nDecompressing the image...\n");

    // Allocate memory for the decompressed array
    int **decompressed_image = (int**) malloc(rows * BLOCK_SIZE * sizeof(int*));
    for(int i=0; i<rows*BLOCK_SIZE; i++) {
        decompressed_image[i] = (int*) malloc(cols * BLOCK_SIZE * sizeof(int));
    }

    // Iterate through the compressed image blocks and repeat the values
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int value = compressed_image[i][j];
            for(int k=i*BLOCK_SIZE; k<i*BLOCK_SIZE+BLOCK_SIZE; k++) {
                for(int l=j*BLOCK_SIZE; l<j*BLOCK_SIZE+BLOCK_SIZE; l++) {
                    decompressed_image[k][l] = value;
                }
            }
        }
    }

    // Print the decompressed image for display
    printf("\nThe decompressed image is:\n");
    for(int i=0; i<rows*BLOCK_SIZE; i++) {
        for(int j=0; j<cols*BLOCK_SIZE; j++) {
            printf("%d ", decompressed_image[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for the decompressed image
    for(int i=0; i<rows*BLOCK_SIZE; i++) {
        free(decompressed_image[i]);
    }
    free(decompressed_image);

    return true;
}