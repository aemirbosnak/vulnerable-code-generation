//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, num_players;

    // get input from user for number of rows, columns, and players
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    // create 2D array for the game board
    int board[rows][cols];

    // initialize all elements to zero
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 0;
        }
    }

    // print initial game board
    printf("Initial game board:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // randomly assign starting position for each player
    srand(time(NULL));
    for (int i = 1; i <= num_players; i++) {
        int start_row = rand() % rows;
        int start_col = rand() % cols;
        board[start_row][start_col] = i;
    }

    // play the game
    int current_player = 1;
    while (1) {
        // print current game board
        printf("Current game board:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // get input from current player for move
        int current_row, current_col, new_row, new_col;
        printf("Player %d, enter current row and column: ", current_player);
        scanf("%d %d", &current_row, &current_col);

        printf("Player %d, enter new row and column: ", current_player);
        scanf("%d %d", &new_row, &new_col);

        // check if move is valid
        if (current_row < 0 || current_row >= rows || current_col < 0 || current_col >= cols ||
            new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols ||
            board[current_row][current_col] != current_player ||
            board[new_row][new_col] != 0) {
            printf("Invalid move, try again.\n");
            continue;
        }

        // make the move and switch to next player
        board[current_row][current_col] = 0;
        board[new_row][new_col] = current_player;
        current_player = current_player % num_players + 1;

        // check if game is over
        int winner = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != 0) {
                    if (winner == 0) {
                        winner = board[i][j];
                    } else if (board[i][j] != winner) {
                        winner = -1;
                        break;
                    }
                }
            }
            if (winner == -1) {
                break;
            }
        }
        if (winner != 0) {
            printf("Player %d wins!\n", winner);
            break;
        }
    }

    return 0;
}