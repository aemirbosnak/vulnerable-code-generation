//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to create a random table
int** createTable(int rows, int cols) {
    int** table = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        table[i] = (int*)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            table[i][j] = rand() % 10;
        }
    }
    return table;
}

// Function to print a table
void printTable(int** table, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

// Function to find the sum of all elements in a table
int sumTable(int** table, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += table[i][j];
        }
    }
    return sum;
}

// Function to find the average of all elements in a table
double avgTable(int** table, int rows, int cols) {
    int sum = sumTable(table, rows, cols);
    double avg = (double)sum / (rows * cols);
    return avg;
}

// Function to find the maximum element in a table
int maxTable(int** table, int rows, int cols) {
    int max = table[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (table[i][j] > max) {
                max = table[i][j];
            }
        }
    }
    return max;
}

// Function to find the minimum element in a table
int minTable(int** table, int rows, int cols) {
    int min = table[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (table[i][j] < min) {
                min = table[i][j];
            }
        }
    }
    return min;
}

// Function to find the saddle point of a table
int saddlePoint(int** table, int rows, int cols) {
    int saddle = -1;
    for (int i = 0; i < rows; i++) {
        int minRow = table[i][0];
        int minRowIdx = 0;
        for (int j = 1; j < cols; j++) {
            if (table[i][j] < minRow) {
                minRow = table[i][j];
                minRowIdx = j;
            }
        }
        int maxCol = table[0][minRowIdx];
        for (int k = 1; k < rows; k++) {
            if (table[k][minRowIdx] > maxCol) {
                maxCol = table[k][minRowIdx];
            }
        }
        if (minRow == maxCol) {
            saddle = minRow;
            break;
        }
    }
    return saddle;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a random table
    int** table = createTable(MAX_ROWS, MAX_COLS);

    // Print the table
    printf("Original table:\n");
    printTable(table, MAX_ROWS, MAX_COLS);

    // Find the sum of all elements in the table
    int sum = sumTable(table, MAX_ROWS, MAX_COLS);

    // Find the average of all elements in the table
    double avg = avgTable(table, MAX_ROWS, MAX_COLS);

    // Find the maximum element in the table
    int max = maxTable(table, MAX_ROWS, MAX_COLS);

    // Find the minimum element in the table
    int min = minTable(table, MAX_ROWS, MAX_COLS);

    // Find the saddle point of the table
    int saddle = saddlePoint(table, MAX_ROWS, MAX_COLS);

    // Print the results
    printf("Sum of all elements: %d\n", sum);
    printf("Average of all elements: %.2f\n", avg);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    if (saddle != -1) {
        printf("Saddle point: %d\n", saddle);
    } else {
        printf("No saddle point found.\n");
    }

    // Free the table
    for (int i = 0; i < MAX_ROWS; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}