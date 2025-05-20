//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print the board
void printBoard(char board[][3]){
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

//Function to check if the game has ended
int gameOver(char board[][3], char symbol){
    int i, j;
  
    //Check for rows
    for(i=0; i<3; i++){
        if((board[i][0] == symbol) && (board[i][1] == symbol) && (board[i][2] == symbol)){
            return 1;
        }
    }
    
    //Check for columns
    for(i=0; i<3; i++){
        if((board[0][i] == symbol) && (board[1][i] == symbol) && (board[2][i] == symbol)){
            return 1;
        }
    }
    
    //Check for diagonals
    if((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol)){
        return 1;
    }
    
    if((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol)){
        return 1;
    }
    
    //Check if board is full
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    
    return 2;
}

//Function for computer move
void computerMove(char board[][3], char computerSymbol){
    int i, j, flag;
    srand(time(NULL));
    
    do{
        flag = 0;
        i = rand() % 3;
        j = rand() % 3;
        if(board[i][j] == ' '){
            board[i][j] = computerSymbol;
            flag = 1;
        }
    }while(flag != 1);
}

//Function for user move
void userMove(char board[][3], char userSymbol){
    int i, j, flag;
    do{
        printf("\nPlease enter row number (1, 2, or 3) and column number (1, 2, or 3) of your move: ");
        scanf("%d%d", &i, &j);
        i--;
        j--;
        if(board[i][j] == ' '){
            board[i][j] = userSymbol;
            flag = 1;
        }
        else{
            printf("\nThe cell is already occupied. Please select another cell.\n");
            flag = 0;
        }
    }while(flag != 1);
}

//Main function to play the game
int main(){
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char userSymbol, computerSymbol, playAgain;
    int result, flag;
    printf("Welcome to Tic Tac Toe game!\n");
    printf("\nPlease select your symbol (X or O): ");
    scanf("%c", &userSymbol);
    
    //Assign opposite symbol to computer
    if(userSymbol == 'X'){
        computerSymbol = 'O';
    }
    else{
        computerSymbol = 'X';
    }
    
    do{
        flag = 1;
        while(flag == 1){
            printf("\nYour turn:\n");
            printBoard(board);
            userMove(board, userSymbol);
            result = gameOver(board, userSymbol);
            if(result == 1){
                printBoard(board);
                printf("\nCongratulations! You win!\n");
                flag = 0;
            }
            else if(result == 2){
                printBoard(board);
                printf("\nIt's a tie!\n");
                flag = 0;
            }
            else{
                printf("\nComputer's turn:\n");
                computerMove(board, computerSymbol);
                result = gameOver(board, computerSymbol);
                if(result == 1){
                    printBoard(board);
                    printf("\nSorry, you lost.\n");
                    flag = 0;
                }
                else if(result == 2){
                    printBoard(board);
                    printf("\nIt's a tie!\n");
                    flag = 0;
                }
            }
        }
        
        //Ask user to Play again
        printf("\nDo you want to play again? (Y/N): ");
        fflush(stdin);
        scanf("%c", &playAgain);
        if(playAgain == 'Y' || playAgain == 'y'){
            board[0][0] = ' ';
            board[0][1] = ' ';
            board[0][2] = ' ';
            board[1][0] = ' ';
            board[1][1] = ' ';
            board[1][2] = ' ';
            board[2][0] = ' ';
            board[2][1] = ' ';
            board[2][2] = ' ';
            flag = 1;
        }
    }while(playAgain == 'Y' || playAgain == 'y');
    
    printf("\nThanks for playing! Bye.\n");
    return 0;
}