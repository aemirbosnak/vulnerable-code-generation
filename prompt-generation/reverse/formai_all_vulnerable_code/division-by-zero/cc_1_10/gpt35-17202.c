//FormAI DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("  ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {{-1,-1,-2,-2},{-3,-3,-4,-4},{-5,-5,-6,-6},{-7,-7,-8,-8}};
    int temp[ROWS*COLS];
    int i, j, k, num_unique_pairs, num_pairs_remaining, rand_index, temp_value, temp_index;
    srand(time(NULL));
    num_unique_pairs = ROWS * COLS / 2;
    num_pairs_remaining = num_unique_pairs;
    for (k = 0; k < num_unique_pairs; k++) {
        temp[k] = k;
        temp[k+num_unique_pairs] = k;
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            rand_index = rand() % num_pairs_remaining;
            board[i][j] = temp[rand_index];
            temp_value = temp[rand_index];
            temp[rand_index] = temp[num_pairs_remaining-1];
            num_pairs_remaining--;
            for (temp_index = rand_index+1; temp_index < num_pairs_remaining; temp_index++) {
                temp[temp_index-1] = temp[temp_index];
            }
            temp[temp_index-1] = temp_value;
        }
    }
    print_board(board);
    return 0;
}