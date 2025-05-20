//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rows, columns;
   printf("Enter number of rows: ");
   scanf("%d", &rows);
   printf("Enter number of columns: ");
   scanf("%d", &columns);
   
   int matrix[rows][columns];
   
   printf("Enter elements of matrix:\n");
   
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
   
   printf("Matrix before addition:\n");
   
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   
   int matrix2[rows][columns];
   
   printf("Enter elements of second matrix:\n");
   
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }
   
   printf("Matrix after addition:\n");
   
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         matrix[i][j] += matrix2[i][j];
      }
   }
   
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}