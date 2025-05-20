//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_NUMBER 8

void play_game(int board[][BOARD_SIZE], int size);
void initialize_board(int board[][BOARD_SIZE], int size);
void shuffle(int *arr, int size);
void print_board(int board[][BOARD_SIZE], int size);
void swap(int *a, int *b);
int get_random_num(int max);
int get_input();
int check_match(int board[][BOARD_SIZE], int size, int row1, int col1, int row2, int col2);
int count_pairs_found(int board[][BOARD_SIZE], int size);

int main()
{
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    initialize_board(board, BOARD_SIZE);
    play_game(board, BOARD_SIZE);

    return 0;
}

void play_game(int board[][BOARD_SIZE], int size)
{
    int row1, col1, row2, col2;
    int pairs_found = 0;
    int moves = 0;

    while (pairs_found < MAX_NUMBER) {
        printf("\nMoves: %d\n", moves);
        print_board(board, size);

        printf("Enter first card (row, col): ");
        row1 = get_input();
        col1 = get_input();

        printf("Enter second card (row, col): ");
        row2 = get_input();
        col2 = get_input();

        if (check_match(board, size, row1, col1, row2, col2)) {
            printf("Match found!\n");
            board[row1][col1] = board[row2][col2] = 0;
            pairs_found++;
        } else {
            printf("No match.\n");
        }

        moves++;
    }

    printf("\nCongratulations! You won in %d moves\n", moves);
}

void initialize_board(int board[][BOARD_SIZE], int size)
{
    int num_arr[MAX_NUMBER * 2];
    int index = 0;

    // fill num_arr with pairs of numbers
    for (int i = 1; i <= MAX_NUMBER; i++) {
        num_arr[index++] = i;
        num_arr[index++] = i;
    }

    shuffle(num_arr, MAX_NUMBER * 2);

    index = 0;

    // fill board with shuffled numbers
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = num_arr[index++];
        }
    }
}

void shuffle(int *arr, int size)
{
    for (int i = size - 1; i > 0; i--) {
        int j = get_random_num(i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void print_board(int board[][BOARD_SIZE], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                printf("\t*");
            } else {
                printf("\t%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_random_num(int max)
{
    return rand() % max;
}

int get_input()
{
    int input;
    scanf("%d", &input);
    return input - 1;
}

int check_match(int board[][BOARD_SIZE], int size, int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2]) {
        return 1;
    } else {
        return 0;
    }
}

int count_pairs_found(int board[][BOARD_SIZE], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }
    return count / 2;
}