//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k, l;
    char ch, ch1;
    srand(time(NULL));

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize the array with random characters
    char arr[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            ch = rand() % 26 + 65; // Generates a random uppercase letter
            arr[i][j] = ch;
        }
    }

    // Print the array in a scientific style
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    // Print the array in a pattern
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                ch1 = arr[i][j] + 32; // Converts uppercase letter to lowercase
                printf("%c", ch1);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Print the array in reverse order
    printf("\n");
    for (i = rows - 1; i >= 0; i--) {
        for (j = cols - 1; j >= 0; j--) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}