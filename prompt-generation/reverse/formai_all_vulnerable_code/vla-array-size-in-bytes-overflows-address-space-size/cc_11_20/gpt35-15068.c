//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int rows, cols, i, j, k, count = 0;
    printf("Welcome to the C Memory Game!\n");

    printf("Enter number of rows (maximum 10): ");
    scanf("%d", &rows);

    if (rows > 10){
        printf("Invalid input, maximum rows is 10.");
        exit(0);
    }

    printf("Enter number of columns (maximum 10): ");
    scanf("%d", &cols);

    if (cols > 10){
        printf("Invalid input, maximum columns is 10.");
        exit(0);
    }

    int board[rows][cols];

    // initialize board with random integers
    srand(time(0));
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            board[i][j] = rand() % 10;
        }
    }

    // print the board
    printf("\nMemory Game Board\n");
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // play the game
    int flip1_row, flip1_col, flip2_row, flip2_col;
    int num1, num2;

    while (count < (rows * cols)/2){
        printf("\nChoose the first cell to flip (row, column): ");
        scanf("%d %d", &flip1_row, &flip1_col);
        num1 = board[flip1_row][flip1_col];

        if (num1 == -1){
            printf("You already found this matching pair. Please try again.");
            continue;
        }
        if (num1 == -2){
            printf("This cell has already been paired with another cell. Please select another cell.");
            continue;
        }

        printf("\nChoose the second cell to flip (row, column): ");
        scanf("%d %d", &flip2_row, &flip2_col);
        num2 = board[flip2_row][flip2_col];

        if (num2 == -1){
            printf("You already found this matching pair. Please try again.");
            continue;
        }
        if (num2 == -2){
            printf("This cell has already been paired with another cell. Please select another cell.");
            continue;
        }

        // check if matching pair found
        if(num1==num2){
            board[flip1_row][flip1_col] = -1;
            board[flip2_row][flip2_col] = -1;
            printf("\nYou found a matching pair!");
            count++;
        } else {
            board[flip1_row][flip1_col] = -2;
            board[flip2_row][flip2_col] = -2;
            printf("\nSorry, not a matching pair.");
        }

        // print the updated board
        printf("\nUpdated Board\n");
        for (i = 0; i < rows; i++){
            for (j = 0; j < cols; j++){
                if(board[i][j]==-1){
                    printf("X ");
                } else if (board[i][j]==-2){
                    printf("O ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }
    }

    printf("\nCongratulations! You have found all the matching pairs.\n");

    return 0;
}