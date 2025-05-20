//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW_LENGTH 5
#define COL_LENGTH 5

struct player {
    char name[50];
    int bingo_board[ROW_LENGTH][COL_LENGTH];
};

typedef struct player Player;

void create_bingo_board(int bingo_board[ROW_LENGTH][COL_LENGTH]);
void print_bingo_board(int bingo_board[ROW_LENGTH][COL_LENGTH]);
int generate_random_number(int already_called_numbers[], int num_of_called_numbers);
int check_bingo_win(int bingo_board[ROW_LENGTH][COL_LENGTH]);
void play_bingo(Player players[], int num_of_players);

int main() {
    printf("Welcome to the Post-Apocalyptic Bingo Simulator!\n");
    printf("The world may have ended, but the game must go on.\n");

    // Get the number of players
    int num_of_players;
    printf("How many players? ");
    scanf("%d", &num_of_players);

    // Initialize the players
    Player players[num_of_players];
    for (int i = 0; i < num_of_players; i++) {
        printf("\nPLAYER %d:\n", i+1);
        printf("What's your name? ");
        scanf("%s", players[i].name);
        printf("\n%s, here's your bingo board:\n", players[i].name);
        create_bingo_board(players[i].bingo_board);
        print_bingo_board(players[i].bingo_board);
    }

    // Start the game
    play_bingo(players, num_of_players);

    printf("\nThank you for playing Post-Apocalyptic Bingo.\n");

    return 0;
}

// Creates a random bingo board
void create_bingo_board(int bingo_board[ROW_LENGTH][COL_LENGTH]) {
    int num_of_called_numbers = 0;
    int already_called_numbers[75];
    memset(already_called_numbers, 0, sizeof(already_called_numbers));

    for (int i = 0; i < ROW_LENGTH; i++) {
        for (int j = 0; j < COL_LENGTH; j++) {
            int num = generate_random_number(already_called_numbers, num_of_called_numbers);
            bingo_board[i][j] = num;
            num_of_called_numbers++;
        }
    }

    bingo_board[2][2] = 0; // Center cell is free
}

// Prints the bingo board to the console
void print_bingo_board(int bingo_board[ROW_LENGTH][COL_LENGTH]) {
    printf("\tB\tI\tN\tG\tO\n");

    for (int i = 0; i < ROW_LENGTH; i++) {
        for (int j = 0; j < COL_LENGTH; j++) {
            printf("\t%d", bingo_board[i][j]);
        }
        printf("\n");
    }
}

// Generates a random number that hasn't already been called
int generate_random_number(int already_called_numbers[], int num_of_called_numbers) {
    srand(time(NULL));
    int num = (rand() % 75) + 1;

    while (1) {
        int found = 0;
        for (int i = 0; i < num_of_called_numbers; i++) {
            if (already_called_numbers[i] == num) {
                found = 1;
                break;
            }
        }
        if (found) {
            num = (rand() % 75) + 1;
        } else {
            already_called_numbers[num_of_called_numbers] = num;
            break;
        }
    }

    return num;
}

// Checks if there's a bingo win on the board
int check_bingo_win(int bingo_board[ROW_LENGTH][COL_LENGTH]) {
    int num_of_bingo_rows = 0;
    int num_of_bingo_cols = 0;

    // Check rows
    for (int i = 0; i < ROW_LENGTH; i++) {
        int num_of_checked_numbers = 0;
        for (int j = 0; j < COL_LENGTH; j++) {
            if (bingo_board[i][j] == 0) {
                num_of_checked_numbers++;
            }
        }
        if (num_of_checked_numbers == ROW_LENGTH) {
            num_of_bingo_rows++;
        }
    }

    // Check columns
    for (int i = 0; i < ROW_LENGTH; i++) {
        int num_of_checked_numbers = 0;
        for (int j = 0; j < COL_LENGTH; j++) {
            if (bingo_board[j][i] == 0) {
                num_of_checked_numbers++;
            }
        }
        if (num_of_checked_numbers == COL_LENGTH) {
            num_of_bingo_cols++;
        }
    }

    // Check diagonals
    int num_of_bingo_diag = 0;
    if (bingo_board[0][0] == 0 && bingo_board[1][1] == 0 && bingo_board[2][2] == 0 && bingo_board[3][3] == 0 && bingo_board[4][4] == 0) {
        num_of_bingo_diag++;
    }
    if (bingo_board[0][4] == 0 && bingo_board[1][3] == 0 && bingo_board[2][2] == 0 && bingo_board[3][1] == 0 && bingo_board[4][0] == 0) {
        num_of_bingo_diag++;
    }

    // Return the number of bingos
    return num_of_bingo_rows + num_of_bingo_cols + num_of_bingo_diag;
}

// Runs the game of bingo
void play_bingo(Player players[], int num_of_players) {
    int num_of_called_numbers = 0;
    int already_called_numbers[75];
    int winner_found = 0;

    while (!winner_found) {
        int num = generate_random_number(already_called_numbers, num_of_called_numbers);
        num_of_called_numbers++;
        printf("\n\nThe next number is: %d\n", num);

        // Loop through the players
        for (int i = 0; i < num_of_players; i++) {
            int bingo = check_bingo_win(players[i].bingo_board);
            if (bingo > 0) {
                printf("\nBINGO! %s has won!\n", players[i].name);
                winner_found = 1;
                break;
            }
        }

        // Check if all 75 numbers have been called
        if (num_of_called_numbers == 75) {
            printf("\n\nAll 75 numbers have been called. No one has won!\n");
            break;
        }
    }
}