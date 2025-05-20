//FormAI DATASET v1.0 Category: Image compression ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to compress the image
void compressImage(int **image, int rows, int cols, float compressionRatio) {
    
    // Calculating the number of pixels to be compressed
    int numPixelsToCompress = (int)(compressionRatio * rows * cols);
    
    // Creating an array to store pixel values
    int pixelValues[rows * cols];
    int index = 0;
    
    // Storing pixel values in pixelValues array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            pixelValues[index] = image[i][j];
            index++;
        }
    }
    
    // Sorting the pixelValues array in non-increasing order
    for(int i = 0; i < rows * cols - 1; i++) {
        for(int j = 0; j < rows * cols - i - 1; j++) {
            if(pixelValues[j] < pixelValues[j+1]) {
                int temp = pixelValues[j];
                pixelValues[j] = pixelValues[j+1];
                pixelValues[j+1] = temp;
            }
        }
    }
    
    // Replacing pixels with compressed values
    int numCompressedPixels = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(numCompressedPixels < numPixelsToCompress) {
                image[i][j] = (int)round(pixelValues[numPixelsToCompress]);
                numCompressedPixels++;
            }
        }
    }
}

int main() {
    
    // Initializing image dimensions and compression ratio
    int rows = 10;
    int cols = 10;
    float compressionRatio = 0.5;
    
    // Creating the image
    int **image = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        image[i] = (int *)malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            image[i][j] = i + j;
        }
    }
    
    // Compressing the image
    compressImage(image, rows, cols, compressionRatio);
    
    // Printing the compressed image
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}