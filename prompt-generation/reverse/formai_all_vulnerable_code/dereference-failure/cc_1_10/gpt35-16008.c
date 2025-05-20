//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 8

void print_board(int board[ROWS][COLS], int rows, int cols);
void shuffle(int *arr, int n);
int check_match(int board[ROWS][COLS], int x1, int y1, int x2, int y2);
void initialize_game(int board[ROWS][COLS], int rows, int cols);
int gameplay(int board[ROWS][COLS], int rows, int cols);

int main(){
    int board[ROWS][COLS];
    initialize_game(board, ROWS, COLS);
    int result = gameplay(board, ROWS, COLS);
    if(result == 1)
        printf("Congratulations, you beat the game!");
    return 0;
}

//Prints the current state of the board
void print_board(int board[ROWS][COLS], int rows, int cols){
    printf("\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(board[i][j] < 0)
                printf("  -  ");
            else
                printf("  %d  ", board[i][j]);
        }
        printf("\n");
    }
}

//Simple Fisher-Yates shuffle algorithm implementation
void shuffle(int *arr, int n){
    srand(time(NULL));
    for(int i=n-1;i>0;i--){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//Checks if two given cards match each other. Returns 1 if they match, 0 if they don't.
int check_match(int board[ROWS][COLS], int x1, int y1, int x2, int y2){
    if(board[x1][y1] == board[x2][y2])
        return 1;
    return 0;
}

//Initializes the game board with random values
void initialize_game(int board[ROWS][COLS], int rows, int cols){
    int values[MAX_VALUE] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7};
    shuffle(values, MAX_VALUE);
    int index = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board[i][j] = values[index++];
            printf(" [%d][%d] = %d \n ",i,j,board[i][j]);
        }
    }
}

//Main gameplay function
int gameplay(int board[ROWS][COLS], int rows, int cols){
    int x1,y1,x2,y2;
    int moves = 0;
    int matched_count = 0;
    while(matched_count < (MAX_VALUE * 2)){
        print_board(board, rows, cols);
        printf("Enter card position (e.g. 1 2): ");
        scanf("%d %d", &x1, &y1);
        if(board[x1][y1] < 0){
            printf("This spot has been matched already. Please choose another card.\n");
            continue;
        }
        printf("Enter another card position (e.g. 3 4): ");
        scanf("%d %d", &x2, &y2);
        if(board[x2][y2] < 0){
            printf("This spot has been matched already. Please choose another card.\n");
            continue;
        }
        if(check_match(board, x1, y1, x2, y2) == 1){
            printf("Yes, they match! You got a pair!\n");
            board[x1][y1] = -1;
            board[x2][y2] = -1;
            matched_count += 2;
        }
        else{
            printf("Nope, sorry, not a match. Try again!\n");
            board[x1][y1] = -1;
            board[x2][y2] = -1;
        }
        moves++;
    }
    return 1;
}