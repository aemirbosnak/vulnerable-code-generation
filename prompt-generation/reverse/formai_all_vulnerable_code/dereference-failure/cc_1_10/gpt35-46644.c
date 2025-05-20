//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print the Tic Tac Toe board
void print_board(char board[][3]){
    printf("\n\n\tTic Tac Toe\n\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t     |     |     \n");
}

// Function to check if someone has won or not
int check_win(char board[][3], char symbol){
    int i, j;

    // Checking the rows
    for(i=0; i<3; i++){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol){
            return 1;
        }
    }

    // Checking the columns
    for(j=0; j<3; j++){
        if(board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol){
            return 1;
        }
    }

    // Checking the diagonals
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol){
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol){
        return 1;
    }

    return 0;
}

// Function to make the computer move
void computer_move(char board[][3]){
    int i, j;

    // Randomly choose a position on the board
    do{
        i = rand() % 3;
        j = rand() % 3;
    }while(board[i][j] == 'X' || board[i][j] == 'O'); // Check if the position is empty or not
    
    // Place the computer's symbol on the board
    board[i][j] = 'O';
}

// Function to make the user move
void user_move(char board[][3]){
    int i, j;

    // Ask the user for the row and column numbers
    printf("\nEnter the row and column numbers: ");
    scanf("%d %d", &i, &j);

    // Check if the position is empty or not
    while(board[i-1][j-1] == 'X' || board[i-1][j-1] == 'O'){
        printf("\nInvalid move. Try again.\n");
        printf("\nEnter the row and column numbers: ");
        scanf("%d %d", &i, &j);
    }

    // Place the user's symbol on the board
    board[i-1][j-1] = 'X';
}

// Main function
int main(){
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int turn = 1, win = 0;

    // Set the seed for the random number generator
    srand(time(NULL));

    // Loop until someone wins or the board is full
    while(!win && turn <= 9){
        print_board(board);

        if(turn % 2 == 0){ // Computer's turn
            printf("\nComputer's turn\n");
            computer_move(board);
        }
        else{ // User's turn
            printf("\nYour turn\n");
            user_move(board);
        }

        // Check if someone has won
        if(turn >= 5){ // Need at least 5 moves for someone to win
            if(check_win(board, 'X')){
                printf("\nCongratulations! You have won!\n");
                win = 1;
            }
            else if(check_win(board, 'O')){
                printf("\nSorry, you have lost.\n");
                win = 1;
            }
        }

        turn++;
    }

    // If the game ended in a tie
    if(!win){
        print_board(board);
        printf("\nIt's a tie.\n");
    }

    return 0;
}