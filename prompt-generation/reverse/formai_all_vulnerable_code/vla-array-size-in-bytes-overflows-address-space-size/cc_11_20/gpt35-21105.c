//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int row, col;
    printf("Enter the number of rows in the table: ");
    scanf("%d", &row);
    printf("Enter the number of columns in the table: ");
    scanf("%d", &col);

    // Create the Table
    int table[row][col];
    srand(time(NULL)); // Initialize the Seed for Random Number Generator

    // Fill the Table with Random Numbers
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            table[i][j] = (rand() % 100) + 1; // Random Numbers between 1 to 100
        }
    }

    // Print the Table
    printf("\n\nTable:\n\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%5d", table[i][j]);
        }
        printf("\n");
    }

    // Find the Maximum Element in Each Row
    int maxElement[row];
    for(int i=0; i<row; i++){
        maxElement[i] = table[i][0];
        for(int j=1; j<col; j++){
            if(table[i][j] > maxElement[i]){
                maxElement[i] = table[i][j];
            }
        }
    }

    // Print the Maximum Element in Each Row
    printf("\n\nMaximum Element in Each Row:\n\n");
    for(int i=0; i<row; i++){
        printf("Row %d: %d\n", i+1, maxElement[i]);
    }

    // Find the Minimum Element in Each Column
    int minElement[col];
    for(int i=0; i<col; i++){
        minElement[i] = table[0][i];
        for(int j=1; j<row; j++){
            if(table[j][i] < minElement[i]){
                minElement[i] = table[j][i];
            }
        }
    }

    // Print the Minimum Element in Each Column
    printf("\n\nMinimum Element in Each Column:\n\n");
    for(int i=0; i<col; i++){
        printf("Column %d: %d\n", i+1, minElement[i]);
    }

    return 0;
}