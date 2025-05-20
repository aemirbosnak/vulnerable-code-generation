//FormAI DATASET v1.0 Category: Computer Biology ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable declarations 
int row;
int col;
int arr[100][100];
int rotate = 0;

// Function to print the matrix 
void printMatrix() 
{ 
   for (int i = 0; i < row; i++) 
   { 
       for (int j = 0; j < col; j++) 
       {
           printf("%d ", arr[i][j]); 
       } 
       printf("\n"); 
   } 
} 

// Function to rotate the matrix 
void rotateMatrix() 
{ 
   int temp[row][col];
   for(int i = 0; i < row; i++) 
   {
       for(int j = 0; j < col; j++) 
       {
           temp[i][j] = arr[i][j];
       }
   }
   for(int i = 0; i < row; i++) 
   {
       for(int j = 0; j < col; j++) 
       {
           arr[i][j] = temp[row - j - 1][i];
       }
   }   
}

int main() 
{ 
    // Instructions to the user on how to use the program
    printf("Welcome to the Matrix Rotation Program!\n\n");
    printf("Please enter the dimensions of the matrix:\n");
    scanf("%d %d", &row, &col);
    printf("Now please enter the elements of the matrix:\n");
    
    // Store user's matrix elements in the 2D array
    for (int i = 0; i < row; i++) 
    { 
        for (int j = 0; j < col; j++) 
        {
            scanf("%d", &arr[i][j]);
        } 
    } 

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix();

    // Prompt the user to rotate the matrix
    printf("\nWould you like to rotate the matrix? Enter 1 for yes and 0 for no:\n");
    scanf("%d", &rotate);

    // Rotate the matrix if desired by user
    if (rotate == 1) 
    {
        rotateMatrix();
        printf("\nRotated Matrix:\n");
        printMatrix();
    }
    else 
    {
        printf("\nThank you for using the Matrix Rotation Program. Goodbye!\n");
    }
    return 0; 
}