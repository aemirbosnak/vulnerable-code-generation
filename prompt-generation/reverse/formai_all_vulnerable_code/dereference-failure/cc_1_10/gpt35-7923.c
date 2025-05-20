//FormAI DATASET v1.0 Category: Sudoku solver ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int isAvailable(int **arr,int r,int c,int num){
    int i,j;

    for(i=0;i<9;i++)    
        if(arr[r][i] == num)
            return 0;
    
    for(i=0;i<9;i++)   
        if(arr[i][c] == num) 
            return 0;
        
    int startRow = r - r%3, startCol = c - c%3;

    for(i=startRow;i<startRow+3;i++)  
        for(j=startCol;j<startCol+3;j++)    
            if(arr[i][j] == num)
                return 0;
            
    return 1;
}

int solveSudoku(int **arr, int r, int c){
    int i,j;
    
    if (r == 9 - 1 && c == 9)
        return 1;
    
    if (c == 9){
        r++;
        c = 0;
    }

    if (arr[r][c] > 0)
        return solveSudoku(arr,r,c+1);

    for (i=1;i<=9;i++){

        if (isAvailable(arr,r,c,i)){
            arr[r][c] = i;

            if (solveSudoku(arr,r,c+1))
                return 1;
        }

        arr[r][c] = 0;
    }
    
    return 0;
}

int main(){
    int i,j;

    int **arr = (int **)malloc(sizeof(int *)*9);

    for(i=0;i<9;i++)
        arr[i] = (int *)malloc(sizeof(int)*9);
    
    printf("Enter the Sudoku Puzzle\n");
    
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            scanf("%d",&arr[i][j]);
        
    if (solveSudoku(arr,0,0)){
        printf("\nThe solution for the Sudoku puzzle you entered is: \n\n");
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
                printf("%d ",arr[i][j]);
            printf("\n");
        }
    }else{
        printf("No Solution exists for the given Sudoku Puzzle\n");
    }

    for(i=0;i<9;i++)
        free(arr[i]);
    free(arr);

    return 0;
}