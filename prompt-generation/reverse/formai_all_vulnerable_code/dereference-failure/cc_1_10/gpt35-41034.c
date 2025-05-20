//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[][3]);
void player_move(int board[][3]);
void computer_move(int board[][3]);

int main()
{
    int board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    srand(time(NULL)); // seed random number generator

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as X against the computer.\n\n");
    print_board(board);

    int turn_count = 0; // keep track of turns taken
    while(turn_count < 9)
    {
        player_move(board);
        if(turn_count == 8) // check for tie game
        {
            printf("It's a tie game!\n");
            break;
        }
        computer_move(board);
        if(turn_count == 7) // check for tie game
        {
            printf("It's a tie game!\n");
            break;
        }
        turn_count += 2; // increment turn count
    }

    return 0;
}

void print_board(int board[][3])
{
    printf(" %c | %c | %c \n",
        (board[0][0] == 1) ? 'X' : ((board[0][0] == 2) ? 'O' : ' '),
        (board[0][1] == 1) ? 'X' : ((board[0][1] == 2) ? 'O' : ' '),
        (board[0][2] == 1) ? 'X' : ((board[0][2] == 2) ? 'O' : ' ')
        );
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",
        (board[1][0] == 1) ? 'X' : ((board[1][0] == 2) ? 'O' : ' '),
        (board[1][1] == 1) ? 'X' : ((board[1][1] == 2) ? 'O' : ' '),
        (board[1][2] == 1) ? 'X' : ((board[1][2] == 2) ? 'O' : ' ')
        );
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",
        (board[2][0] == 1) ? 'X' : ((board[2][0] == 2) ? 'O' : ' '),
        (board[2][1] == 1) ? 'X' : ((board[2][1] == 2) ? 'O' : ' '),
        (board[2][2] == 1) ? 'X' : ((board[2][2] == 2) ? 'O' : ' ')
        );
}

void player_move(int board[][3])
{
    int row, col;
    printf("Enter the row and column of your move (separated by a space): ");
    scanf("%d %d", &row, &col);

    if(board[row][col] != 0) // check for valid move
    {
        printf("Invalid move!\n");
        player_move(board); // try again
    }
    else
    {
        board[row][col] = 1; // mark the board
        printf("Player move:\n");
        print_board(board);
    }
}

void computer_move(int board[][3])
{
    int row, col;
    printf("Computer move:\n");
    do{ // generate random move until valid one found
        row = rand() % 3;
        col = rand() % 3;
    }while(board[row][col] != 0);
    board[row][col] = 2; // mark the board
    print_board(board);
}