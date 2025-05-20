//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell Cell;
typedef struct Game Game;

struct Cell {
    int x;
    int y;
    char status;
};

struct Game {
    Cell board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int winner;
    int gameStatus;
};

void initializeGame(Game* game)
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            game->board[i][j].x = i;
            game->board[i][j].y = j;
            game->board[i][j].status = ' ';
        }
    }

    game->currentPlayer = 'X';
    game->winner = -1;
    game->gameStatus = 0;
}

void makeMove(Game* game, int x, int y)
{
    if(game->board[x][y].status == ' ')
    {
        game->board[x][y].status = game->currentPlayer;
    }
}

void checkWinner(Game* game)
{
    // Check rows
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        if(game->board[0][i].status == game->board[1][i].status && game->board[0][i].status == game->board[2][i].status && game->board[0][i].status != ' ')
        {
            game->winner = game->board[0][i].status;
            game->gameStatus = 1;
            return;
        }
    }

    // Check columns
    for(int j = 0; j < BOARD_SIZE; j++)
    {
        if(game->board[j][0].status == game->board[j][1].status && game->board[j][0].status == game->board[j][2].status && game->board[j][0].status != ' ')
        {
            game->winner = game->board[j][0].status;
            game->gameStatus = 1;
            return;
        }
    }

    // Check diagonals
    if(game->board[0][0].status == game->board[1][1].status && game->board[0][0].status == game->board[2][2].status && game->board[0][0].status != ' ')
    {
        game->winner = game->board[0][0].status;
        game->gameStatus = 1;
        return;
    }

    // If all cells are occupied and no winner, it's a draw
    if(game->gameStatus == 0)
    {
        game->winner = 'D';
        game->gameStatus = 1;
    }
}

int main()
{
    Game game;
    initializeGame(&game);

    // Game loop
    while(!game.gameStatus)
    {
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        makeMove(&game, x, y);
        checkWinner(&game);
    }

    // Game over
    printf("Game over! The winner is: %c\n", game.winner);

    return 0;
}