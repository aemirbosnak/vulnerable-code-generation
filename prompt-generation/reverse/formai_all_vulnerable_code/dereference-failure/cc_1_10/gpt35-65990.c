//FormAI DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void init_board(int board[][BOARD_SIZE]);
void print_board(int board[][BOARD_SIZE]);
void shuffle(int arr[], int n);
void play_game(int board[][BOARD_SIZE]);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    print_board(board);
    play_game(board);
    return 0;
}

void init_board(int board[][BOARD_SIZE])
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
    shuffle(nums, BOARD_SIZE * BOARD_SIZE);
    int k = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = nums[k];
            k++;
        }
    }
}

void shuffle(int arr[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_board(int board[][BOARD_SIZE])
{
    printf("  1 2 3 4\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void play_game(int board[][BOARD_SIZE])
{
    int num_turns = 0;
    int num_matches = 0;
    int first_row, first_col, second_row, second_col;
    while (num_matches < BOARD_SIZE * BOARD_SIZE / 2) {
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &first_row, &first_col);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &second_row, &second_col);
        if (board[first_row - 1][first_col - 1] == board[second_row - 1][second_col - 1]) {
            printf("You found a match!\n");
            board[first_row - 1][first_col - 1] = -1;
            board[second_row - 1][second_col - 1] = -1;
            num_matches++;
        } else {
            printf("Sorry, those cards do not match.\n");
        }
        num_turns++;
        print_board(board);
    }
    printf("Congratulations! You won in %d turns.\n", num_turns);
}