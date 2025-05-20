//Falcon-180B DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void print_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void generate_table(int table[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = rand() % 100;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int table[MAX_ROWS][MAX_COLS];
    generate_table(table, rows, cols);
    printf("Generated table:\n");
    print_table(table, rows, cols);

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += table[i][j];
        }
    }
    printf("The sum of all elements in the table is: %d\n", sum);

    int avg = (int) (sum / (rows * cols));
    printf("The average of all elements in the table is: %d\n", avg);

    return 0;
}