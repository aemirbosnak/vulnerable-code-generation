//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
/*********************************************
 * DNA Sequence Alignment Program           //
 * Written by AI Chatbot                     //
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define global variable and constants
const float Match = 1;
const float Mismatch = 0; 
const float Gap = -1;

// Function prototypes
float max(float a, float b, float c);
void calcAlignment(char* sequence1, char* sequence2, float** matrix, int rows, int cols);
void printMatrix(float** matrix, int rows, int cols);
void printAlignment(char* sequence1, char* sequence2, float** matrix, int rows, int cols);

// Main program
int main(int argc, char** argv) {
    // Initialize sequences
    char* sequence1 = "AGTGCCAGACGCCGCGACT";
    char* sequence2 = "AGTGACGCGGCCGCCACT";
    
    // Calculate lengths of sequences
    int len1 = strlen(sequence1);
    int len2 = strlen(sequence2);
    
    // Allocate memory for matrix
    float** matrix = (float**) malloc ((len1+1) * sizeof(float*));
    for (int i=0; i<=len1; i++) {
        matrix[i] = (float*) malloc ((len2+1) * sizeof(float));
        memset(matrix[i], 0, (len2+1) * sizeof(float));
    }
    
    // Call function to calculate alignment
    calcAlignment(sequence1, sequence2, matrix, len1, len2);
    
    // Print the alignment matrix
    printf("Alignment Matrix:\n");
    printMatrix(matrix, len1+1, len2+1);
    
    // Print the aligned sequences
    printf("\nAligned Sequences:\n");
    printAlignment(sequence1, sequence2, matrix, len1+1, len2+1);
    
    // Free memory
    for (int i=0; i<=len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}

// Calculate maximum value among three floats
float max(float a, float b, float c) {
    float max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

// Calculate alignment matrix
void calcAlignment(char* sequence1, char* sequence2, float** matrix, int rows, int cols) {
    // Calculate matrix values using dynamic programming
    for (int i=1; i<rows; i++) {
        for (int j=1; j<cols; j++) {
            float a = matrix[i-1][j-1] + (sequence1[i-1] == sequence2[j-1] ? Match : Mismatch);
            float b = matrix[i-1][j] + Gap;
            float c = matrix[i][j-1] + Gap;
            matrix[i][j] = max(a, b, c);
        }
    }
}

// Print the alignment matrix
void printMatrix(float** matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Print the aligned sequences
void printAlignment(char* sequence1, char* sequence2, float** matrix, int rows, int cols) {
    int i = rows-1;
    int j = cols-1;
    char align1[rows+cols-2];
    char align2[rows+cols-2];
    int index = 0;
    while (i>0 || j>0) {
        if (i>0 && j>0 && matrix[i][j] == matrix[i-1][j-1] + (sequence1[i-1] == sequence2[j-1] ? Match : Mismatch)) {
            align1[index] = sequence1[i-1];
            align2[index] = sequence2[j-1];
            i--;
            j--;
        } else if (i>0 && matrix[i][j] == matrix[i-1][j] + Gap) {
            align1[index] = sequence1[i-1];
            align2[index] = '-';
            i--;
        } else {
            align1[index] = '-';
            align2[index] = sequence2[j-1];
            j--;
        }
        index++;
    }
    for (int k=index-1; k>=0; k--) {
        printf("%c", align1[k]);
    }
    printf("\n");
    for (int k=index-1; k>=0; k--) {
        printf("%c", align2[k]);
    }
    printf("\n");
}