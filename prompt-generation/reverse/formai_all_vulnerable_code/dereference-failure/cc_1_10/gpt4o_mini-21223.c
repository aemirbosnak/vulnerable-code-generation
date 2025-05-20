//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 4
#define TOTAL_CARDS (BOARD_SIZE * BOARD_SIZE)
#define CARD_PAIRS (TOTAL_CARDS / 2)

typedef struct {
    char symbol;
    int revealed;
} Card;

void initialize_board(Card board[BOARD_SIZE][BOARD_SIZE]);
void shuffle_cards(Card board[BOARD_SIZE][BOARD_SIZE]);
void display_board(Card board[BOARD_SIZE][BOARD_SIZE]);
int check_pair(Card board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
int all_pairs_found(Card board[BOARD_SIZE][BOARD_SIZE]);
void play_game(Card board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    Card board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    shuffle_cards(board);
    play_game(board);
    return 0;
}

void initialize_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    char symbols[CARD_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = symbols[index / 2];
            board[i][j].revealed = 0; 
            if (index % 2 == 1) {
                index++;
            }
        }
    }
}

void shuffle_cards(Card board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < TOTAL_CARDS; i++) {
        int random_index = rand() % TOTAL_CARDS;
        Card temp = board[i / BOARD_SIZE][i % BOARD_SIZE];
        board[i / BOARD_SIZE][i % BOARD_SIZE] = board[random_index / BOARD_SIZE][random_index % BOARD_SIZE];
        board[random_index / BOARD_SIZE][random_index % BOARD_SIZE] = temp;
    }
}

void display_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nGame Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("[%c] ", board[i][j].symbol);
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int check_pair(Card board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    if (board[row1][col1].symbol == board[row2][col2].symbol) {
        board[row1][col1].revealed = 1;
        board[row2][col2].revealed = 1;
        return 1;
    } else {
        return 0;
    }
}

int all_pairs_found(Card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

void play_game(Card board[BOARD_SIZE][BOARD_SIZE]) {
    int row1, col1, row2, col2;
    while (!all_pairs_found(board)) {
        display_board(board);
        printf("Enter coordinates of first card (row col): ");
        scanf("%d %d", &row1, &col1);
        printf("Enter coordinates of second card (row col): ");
        scanf("%d %d", &row2, &col2);

        if (check_pair(board, row1, col1, row2, col2)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match, try again.\n");
        }
    }
    printf("Congratulations, you've found all pairs!\n");
}