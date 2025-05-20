//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>

/* Recursive implementation of matrix addition */
void recursive_add(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]){
  if(row==0) return; //check if row index is zero, then stop the recursion
  if(col==0){
    recursive_add(row-1,col,matrix1,matrix2,result); //move to next row of the matrix
    return;
  }
  
  result[row-1][col-1] = matrix1[row-1][col-1] + matrix2[row-1][col-1]; //add corresponding elements of both matrices
  recursive_add(row,col-1,matrix1,matrix2,result); //recursive call to next column
}

/* Recursive implementation of matrix multiplication */
void recursive_multiply(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int result[row1][col2]){
  if(row1==0) return; //check if row1 index is zero, then stop the recursion
  if(col2==0){
    recursive_multiply(row1-1,col1,row2,col2,matrix1,matrix2,result); //move to next row of the result matrix
    return;
  }
  
  int sum = 0;
  for(int i=0; i<col1; i++){
    sum += matrix1[row1-1][i] * matrix2[i][col2-1]; //sum of the products of the corresponding elements of the row and column
  }
  result[row1-1][col2-1] = sum; //store the sum in the result matrix
  recursive_multiply(row1,col1,row2,col2-1,matrix1,matrix2,result); //recursive call to next column
}

/* Recursive implementation of matrix traversal */
void recursive_traverse(int row, int col, int matrix[row][col], void (*func)(int)){  
  if(row==0) return; //check if row index is zero, then stop the recursion
  if(col==0){
    recursive_traverse(row-1,col,matrix,func); //move to next row of the matrix
    return;
  }
  
  (*func)(matrix[row-1][col-1]); //apply the function to each element of the matrix
  recursive_traverse(row,col-1,matrix,func); //recursive call to next column
}

/* Function to print an integer */
void print_int(int num){
  printf("%d ",num);
}

int main(){
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int result1[3][3], result2[3][3];
    
    recursive_add(3,3,matrix1,matrix2,result1); //add both matrices
    printf("Sum of matrices:\n");
    recursive_traverse(3,3,result1,&print_int); //traverse and print the result matrix
    
    recursive_multiply(3,3,3,3,matrix1,matrix2,result2); //multiply both matrices
    printf("\nProduct of matrices:\n");
    recursive_traverse(3,3,result2,&print_int); //traverse and print the result matrix

    return 0;
}