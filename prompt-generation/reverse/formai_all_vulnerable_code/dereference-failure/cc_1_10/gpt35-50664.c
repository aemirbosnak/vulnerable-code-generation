//FormAI DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board(int **board, int rows, int cols)
{
    srand(time(NULL));
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            board[i][j] = (rand() % 2 == 0) ? 0 : 1;
        }
    }
}

void print_board(int **board, int rows, int cols)
{
    printf("\n");
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%c ", board[i][j] == 1 ? '*' : '.');
        }
        printf("\n");
    }
}

void calculate_next_board(int **board, int **next_board, int rows, int cols)
{
    int i, j, k, l, count;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            count = 0;
            for(k=-1; k<=1; k++){
                for(l=-1; l<=1; l++){
                    if((i+k >=0 && i+k <rows) && (j+l >=0 && j+l <cols) && !(k == 0 && l == 0)){
                        count += board[i+k][j+l];
                    }
                }
            }
            if(board[i][j] == 0){
                if(count == 3){
                    next_board[i][j] = 1;
                }else{
                    next_board[i][j] = 0;
                }
            }else{
                if(count == 2 || count == 3){
                    next_board[i][j] = 1;
                }else{
                    next_board[i][j] = 0;
                }
            }
        }
    }

}

int main()
{
    int rows = 20;
    int cols = 20;
    int i;

    int **board = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++){
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    int **next_board = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++){
        next_board[i] = (int *)malloc(cols * sizeof(int));
    }

    init_board(board, rows, cols);

    for(i=0; i<100; i++){
        print_board(board, rows, cols);
        calculate_next_board(board, next_board, rows, cols);
        int **temp = board;
        board = next_board;
        next_board = temp;
    }

    free(board);
    free(next_board);

    return 0;
}