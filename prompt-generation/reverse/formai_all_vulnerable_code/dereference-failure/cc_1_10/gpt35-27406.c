//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void print_board(int** arr, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int can_fit(int** arr,int x,int y,int num,int N){
    for(int i=0;i<N;i++){ 
        if(arr[i][y] == num){
            return 0;
        }
    }
    for(int i=0;i<N;i++){ 
        if(arr[x][i] == num){
            return 0;
        }
    }    
    int sub_grid_x = (x/3)*3;
    int sub_grid_y = (y/3)*3;
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){
            if(arr[i+sub_grid_x][j+sub_grid_y] == num){ 
                return 0;
            }
        }
    }
    return 1;
}

int solve_board(int** arr,int x,int y,int N){
    if(x == N){
        return 1;
    }
    int next_x,next_y;
    if(y == N-1){
        next_x = x+1;
        next_y = 0;
    }
    else{
        next_x = x;
        next_y = y+1;
    }
    if(arr[x][y]!=0){
        return solve_board(arr,next_x,next_y,N);
    }
    for(int num=1;num<=9;num++){
        if(can_fit(arr,x,y,num,N)==1){ 
            arr[x][y] = num;
            if(solve_board(arr,next_x,next_y,N)==1){ 
                return 1;
            }
            arr[x][y] = 0;
        }
    }
    return 0;
}

int main() {
    int N = 9;
    int** arr = (int**)malloc(sizeof(int*)*N);
    for(int i=0;i<N;i++){
        arr[i]= (int*)malloc(sizeof(int)*N);
    }
    //TODO: Replace the board below to input your own if you want
    int board[9][9] = {{5,3,0,0,7,0,0,0,0},
                        {6,0,0,1,9,5,0,0,0},
                        {0,9,8,0,0,0,0,6,0},
                        {8,0,0,0,6,0,0,0,3},
                        {4,0,0,8,0,3,0,0,1},
                        {7,0,0,0,2,0,0,0,6},
                        {0,6,0,0,0,0,2,8,0},
                        {0,0,0,4,1,9,0,0,5},
                        {0,0,0,0,8,0,0,7,9}};
    //Copy board to array
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=board[i][j];
        }
    }
    printf("Given Sudoku board:\n");
    print_board(arr,N);
    if(solve_board(arr,0,0,N)==1){ 
        printf("Solution:\n");
        print_board(arr,N);
    }
    else{
        printf("No solution exists");
    }
    //Free memory
    for(int i=0;i<N;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}