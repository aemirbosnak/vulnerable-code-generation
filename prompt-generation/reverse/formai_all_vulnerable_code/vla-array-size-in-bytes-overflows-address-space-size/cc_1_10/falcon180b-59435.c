//Falcon-180B DATASET v1.0 Category: Educational ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a 2D array
void print_array(int arr[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a 2D array
void transpose_array(int arr[][10], int rows, int cols) {
    int new_arr[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_arr[j][i] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = new_arr[j][i];
        }
    }
}

int main() {
    srand(time(0));

    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int arr[rows][cols];

    // Fill the array with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand_num(1, 100);
        }
    }

    // Print the original array
    printf("Original array:\n");
    print_array(arr, rows, cols);

    // Transpose the array
    transpose_array(arr, rows, cols);

    // Print the transposed array
    printf("Transposed array:\n");
    print_array(arr, cols, rows);

    return 0;
}