//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void display_game(char game_board[ROWS][COLS], int rows, int cols) {
    printf("  ");
    for (int i=0; i<cols; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i=0; i<rows; i++) {
        printf("%d ", i);
        for (int j=0; j<cols; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }
}

void initialize_game_board(char game_board[ROWS][COLS], int rows, int cols) {
    char cards[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // place cards randomly on board
    srand(time(NULL));
    int card_count = 0;
    while (card_count < 8) {
        int row = rand() % rows;
        int col = rand() % cols;
        if (game_board[row][col] == ' ') {
            game_board[row][col] = cards[card_count];
            card_count++;
        }
    }
}

void check_selection(char game_board[ROWS][COLS], int rows, int cols, int first_row, int first_col, int second_row, int second_col) {
    if (game_board[first_row][first_col] == game_board[second_row][second_col]) {
        printf("\nMatch found!\n");
        game_board[first_row][first_col] = ' ';
        game_board[second_row][second_col] = ' ';
    }
    else {
        printf("\nNo match found, try again!\n");
    }
}

int main() {
    char game_board[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            game_board[i][j] = ' ';
        }
    }

    printf("Welcome to the Memory Game!\n");
    printf("Match all pairs of cards to win.\n");

    initialize_game_board(game_board, ROWS, COLS);

    int first_row, first_col, second_row, second_col;
    while (1) {
        display_game(game_board, ROWS, COLS);

        printf("\nEnter coordinates of first card: ");
        scanf("%d %d", &first_row, &first_col);

        printf("Enter coordinates of second card: ");
        scanf("%d %d", &second_row, &second_col);

        check_selection(game_board, ROWS, COLS, first_row, first_col, second_row, second_col);

        // check if all cards have been matched
        int cards_remaining = 0;
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (game_board[i][j] != ' ') {
                    cards_remaining++;
                }
            }
        }
        if (cards_remaining == 0) {
            printf("Congratulations, you have won the game!\n");
            break;
        }
    }

    return 0;
}