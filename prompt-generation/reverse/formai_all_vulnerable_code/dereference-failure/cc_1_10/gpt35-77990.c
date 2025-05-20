//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
/* This program showcases various matrix operations using statistical analysis */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to initialize matrix with random values */
void initializeMatrix(int row, int col, double matrix[row][col]){
    srand(time(NULL)); // Set the seed for random number generator
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = (double)rand() / RAND_MAX; // Assign random value between 0 and 1
        }
    }
}

/* Function to print matrix */
void printMatrix(int row, int col, double matrix[row][col]){
    printf("\n");
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("%.2f ", matrix[i][j]);
        }   
        printf("\n");
    }
    printf("\n");
}

/* Function to find the mean of each column in a matrix */
void findMean(int row, int col, double matrix[row][col]){
    double mean[col];
    for (int j=0; j<col; j++){
        double sum = 0.0;
        for (int i=0; i<row; i++){
            sum += matrix[i][j];
        }
        mean[j] = sum / row;
    }
    printf("The mean of each column is:\n");
    for (int j=0; j<col; j++){
        printf("%.2f ", mean[j]);
    }
    printf("\n");
}

/* Function to find the standard deviation of each column in a matrix */
void findStandardDeviation(int row, int col, double matrix[row][col]){
    double stddev[col];
    for (int j=0; j<col; j++){
        double sum = 0.0;
        double sumOfSquares = 0.0;
        for (int i=0; i<row; i++){
            sum += matrix[i][j];
            sumOfSquares += pow(matrix[i][j], 2);
        }
        double variance = (sumOfSquares / row) - pow((sum / row), 2);
        stddev[j] = sqrt(variance);
    }
    printf("The standard deviation of each column is:\n");
    for (int j=0; j<col; j++){
        printf("%.2f ", stddev[j]);
    }
    printf("\n");
}

int main(){
    int rows = 5;
    int cols = 3;

    double matrix[rows][cols];

    // Initialize matrix with random values
    initializeMatrix(rows, cols, matrix);

    // Print the initialized matrix
    printf("The initialized matrix is:\n");
    printMatrix(rows, cols, matrix);

    // Find the mean of each column in the matrix
    findMean(rows, cols, matrix);

    // Find the standard deviation of each column in the matrix
    findStandardDeviation(rows, cols, matrix);

    return 0;
}