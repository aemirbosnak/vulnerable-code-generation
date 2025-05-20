//FormAI DATASET v1.0 Category: QR code generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(int height, int width, int **matrix){
    srand(time(NULL)); // Set the seed for random number generator
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            matrix[i][j] = rand() % 2; // Randomly assign 1 or 0 to each cell
        }
    }
}

void printMatrix(int height, int width, int **matrix){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            printf("%d ", matrix[i][j]); // Print the cell value
        }
        printf("\n"); // Move to next row
    }
}

char *generateQRCode(int height, int width, int **matrix){
    char *code = (char*)malloc((height*width)+1); // Allocate memory for QR code
    int count=0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            code[count] = matrix[i][j] + '0'; // Convert integer value to character and add to code
            count++;
        }
    }
    code[count] = '\0'; // Add null terminator at the end
    return code;
}

int main(){
    int height = 10; // Set the dimensions of matrix
    int width = 10;
    int **matrix = (int**)malloc(sizeof(int*)*height); // Allocate memory for matrix
    for(int i=0;i<height;i++){
        matrix[i] = (int*)malloc(sizeof(int)*width);
    }

    generateMatrix(height, width, matrix); // Generate matrix
    printMatrix(height, width, matrix); // Print matrix for reference

    char *qrCode = generateQRCode(height, width, matrix); // Generate QR code
    printf("\nQR Code: %s\n", qrCode); // Print QR code
    free(qrCode); // Free allocated memory for QR code

    for(int i=0;i<height;i++){
        free(matrix[i]); // Free allocated memory for matrix
    }
    free(matrix);

    return 0;
}