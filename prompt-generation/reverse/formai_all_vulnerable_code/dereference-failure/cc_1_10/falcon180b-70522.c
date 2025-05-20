//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_ROUNDS 5

// Function prototypes
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void generate_mines(char board[BOARD_SIZE][BOARD_SIZE]);
void game_loop(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    srand(time(0));
    char board[BOARD_SIZE][BOARD_SIZE];
    generate_mines(board);
    game_loop(board);
    return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '*') {
                printf("*");
            } else if(board[i][j] == '-') {
                printf("-");
            } else {
                printf("%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

void generate_mines(char board[BOARD_SIZE][BOARD_SIZE]) {
    int mines = rand() % (BOARD_SIZE * BOARD_SIZE) + 1;
    int count = 0;
    while(count < mines) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if(board[x][y]!= '*') {
            board[x][y] = '*';
            count++;
        }
    }
}

void game_loop(char board[BOARD_SIZE][BOARD_SIZE]) {
    int x, y, round = 0;
    while(round < MAX_ROUNDS) {
        printf("Round %d:\n", round + 1);
        print_board(board);
        printf("Enter your move (x, y): ");
        scanf("%d%d", &x, &y);
        if(board[x][y] == '*') {
            printf("You hit a mine! Game over.\n");
            break;
        } else if(board[x][y] == '-') {
            printf("You uncovered a blank tile.\n");
        } else {
            printf("You uncovered a tile with %d mines nearby.\n", board[x][y]);
        }
        round++;
    }
    printf("Thanks for playing!\n");
}