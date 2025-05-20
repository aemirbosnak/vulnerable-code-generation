//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void drawBoard(char board[]);
void playerMove(char board[], char playerMarker);
void computerMove(char board[], char computerMarker);
int checkWin(char board[]);
int checkTie(char board[]);
int getComputerMove(char board[]);

int main() {
    char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char playerMarker, computerMarker;
    int turn, winner;

    // seed random generator
    srand(time(NULL));

    // get player marker
    printf("Choose your marker (X/O): ");
    scanf("%c", &playerMarker);
    getchar();

    // set computer marker
    if (playerMarker == 'X')
        computerMarker = 'O';
    else
        computerMarker = 'X';

    // pick random turn
    turn = rand() % 2;

    // game loop
    while (1) {
        // player turn
        if (turn == 0) {
            drawBoard(board);
            printf("Your turn (%c): ", playerMarker);
            playerMove(board, playerMarker);
            winner = checkWin(board);
            if (winner != 0)
                break;
            turn = 1;
        }
        // computer turn
        else {
            printf("Computer turn (%c):\n", computerMarker);
            computerMove(board, computerMarker);
            winner = checkWin(board);
            if (winner != 0)
                break;
            turn = 0;
        }
        // check for tie
        if (checkTie(board)) {
            drawBoard(board);
            printf("It's a tie!\n");
            break;
        }
    }

    // print winner
    drawBoard(board);
    if (winner == 1)
        printf("Congratulations, you won!\n");
    else
        printf("Sorry, you lost. Better luck next time!\n");

    return 0;
}

/**
 * Draws the tic-tac-toe board.
 */
void drawBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("\n");
}

/**
 * Allows the player to make a move on the board.
 */
void playerMove(char board[], char playerMarker) {
    int move;
    do {
        scanf("%d", &move);
        getchar();
    } while (board[move] == 'X' || board[move] == 'O' || move < 1 || move > 9);
    board[move] = playerMarker;
}

/**
 * Makes a move for the computer.
 */
void computerMove(char board[], char computerMarker) {
    int move = getComputerMove(board);
    board[move] = computerMarker;
    printf("Computer placed %c in position %d\n", computerMarker, move);
}

/**
 * Checks if there is a win on the board.
 * Returns 0 if there is no winner,
 * 1 if player wins and 2 if computer wins.
 */
int checkWin(char board[]) {
    if (board[1] == board[2] && board[2] == board[3])
        return board[1] == 'X' ? 1 : 2;
    if (board[4] == board[5] && board[5] == board[6])
        return board[4] == 'X' ? 1 : 2;
    if (board[7] == board[8] && board[8] == board[9])
        return board[7] == 'X' ? 1 : 2;
    if (board[1] == board[4] && board[4] == board[7])
        return board[1] == 'X' ? 1 : 2;
    if (board[2] == board[5] && board[5] == board[8])
        return board[2] == 'X' ? 1 : 2;
    if (board[3] == board[6] && board[6] == board[9])
        return board[3] == 'X' ? 1 : 2;
    if (board[1] == board[5] && board[5] == board[9])
        return board[1] == 'X' ? 1 : 2;
    if (board[3] == board[5] && board[5] == board[7])
        return board[3] == 'X' ? 1 : 2;
    return 0;
}

/**
 * Checks if there is a tie on the board.
 * Returns 1 if there is a tie, 0 otherwise.
 */
int checkTie(char board[]) {
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O')
            return 0;
    }
    return 1;
}

/**
 * Gets the computer's next move.
 */
int getComputerMove(char board[]) {
    // check for winning moves
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            if (checkWin(board) == 2) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }

    // check for blocking moves
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ') {
            board[i] = 'X';
            if (checkWin(board) == 1) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }

    // pick random spot
    int move;
    do {
        move = rand() % 9 + 1;
    } while (board[move] != ' ');
    return move;
}