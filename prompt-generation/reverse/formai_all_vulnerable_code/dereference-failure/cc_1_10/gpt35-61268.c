//FormAI DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game board
void display_board(char board[]) {
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

// Function to randomly select the player
int select_player() {
    int player;
    srand(time(NULL));
    player = rand() % 2 + 1;
    return player;
}

// Function to input the player's move
int player_move(char player_char, int player_number, char board[]) {
    int position, invalid_move = 0;
    printf("Player %d (%c) move: ", player_number, player_char);
    scanf("%d", &position);
    if (board[position - 1] == ' ') {
        board[position - 1] = player_char;
    }
    else {
        printf("Invalid move! Try again.\n");
        invalid_move = 1;
    }
    return invalid_move;
}

// Function to check if the game is over
int game_over(char board[]) {
    int i, winner = 0;
    for (i = 0; i < 9; i += 3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ') {
            winner = 1;
            break;
        }
    }
    for (i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
            winner = 1;
            break;
        }
    }
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        winner = 1;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        winner = 1;
    }
    if (winner) {
        return winner;
    }
    for (i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 2;
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int player, invalid_move, game_result;
    player = select_player();
    do {
        display_board(board);
        invalid_move = player_move((player == 1) ? 'X' : 'O', player, board);
        if (!invalid_move) {
            player = (player == 1) ? 2 : 1;
        }
        game_result = game_over(board);
    } while (!game_result);

    display_board(board);
    if (game_result == 1) {
        printf("Player %d wins!\n", (player == 1) ? 2 : 1);
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}