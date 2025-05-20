//Gemma-7B DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void play_c_table_game()
{
    // Declare variables
    int player_1_score = 0;
    int player_2_score = 0;
    int current_player = 1;

    // Initialize the game board
    int game_board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Play until one player reaches a score of 5
    while (player_1_score < 5 && player_2_score < 5)
    {
        // Get the player's move
        int move = get_player_move();

        // Validate the move
        if (move < 0 || move > 8)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the marker on the game board
        game_board[move / 3][move % 3] = current_player;

        // Check if the player has won
        if (check_win(game_board, current_player) == 1)
        {
            // The player has won, so increment their score
            player_1_score++;
            if (current_player == 1)
            {
                printf("Player 1 has won!\n");
            }
            else
            {
                printf("Player 2 has won!\n");
            }
        }

        // Switch to the next player
        current_player = (current_player == 1) ? 2 : 1;
    }

    // Print the final score
    printf("Final score:\n");
    printf("Player 1: %d\n", player_1_score);
    printf("Player 2: %d\n", player_2_score);
}

int get_player_move()
{
    int move;

    printf("Enter your move (0-8): ");
    scanf("%d", &move);

    return move;
}

int check_win(int **board, int player)
{
    // Check for a win in the rows
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return 1;
        }
    }

    // Check for a win in the columns
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
        {
            return 1;
        }
    }

    // Check for a win in the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // If there has not been a win, return 0
    return 0;
}

int main()
{
    play_c_table_game();

    return 0;
}