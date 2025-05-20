//FormAI DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int num_list[ROWS * COLS / 2];

void generate_numbers()
{
    srand(time(NULL));   // Initialize random seed
    int count = 0;
    while (count < ROWS * COLS / 2) {
        int num = rand() % 10 + 1;
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (num_list[i] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            num_list[count] = num;
            count++;
        }
    }
}

void shuffle_numbers(int** board)
{
    int count = 0;
    while (count < ROWS * COLS) {
        int i1 = rand() % ROWS;
        int j1 = rand() % COLS;
        int i2 = rand() % ROWS;
        int j2 = rand() % COLS;
        if (board[i1][j1] == 0 && board[i2][j2] == 0 && (i1 != i2 || j1 != j2)) {
            board[i1][j1] = num_list[count / 2];
            board[i2][j2] = num_list[count / 2];
            count += 2;
        }
    }
}

void initialize_board(int** board)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int** board)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(" * ");
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int check_win(int** board)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int** board = (int**)malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        board[i] = (int*)malloc(sizeof(int) * COLS);
    }

    int done = 0;
    generate_numbers();

    while (!done) {
        initialize_board(board);
        shuffle_numbers(board);
        int turns = 0;
        while (1) {
            printf("Turns Left: %d\n", ROWS * COLS / 2 - turns);
            print_board(board);
            int i1, j1, i2, j2;
            printf("Enter 1st card coordinates: ");
            scanf("%d%d", &i1, &j1);
            printf("Enter 2nd card coordinates: ");
            scanf("%d%d", &i2, &j2);
            if (i1 < 0 || i1 >= ROWS || j1 < 0 || j1 >= COLS || i2 < 0 || i2 >= ROWS || j2 < 0 || j2 >= COLS) {
                printf("Invalid coordinates. Try again.\n");
            } else if (board[i1][j1] == 0 || board[i2][j2] == 0 || (i1 == i2 && j1 == j2)) {
                printf("Invalid cards. Try again.\n");
            } else if (board[i1][j1] != board[i2][j2]) {
                printf("Cards do not match. Try again.\n");
                turns++;
                if (turns >= ROWS * COLS / 2) {
                    printf("You lose!\n");
                    done = 1;
                    break;
                }
            } else {
                board[i1][j1] = 0;
                board[i2][j2] = 0;
                if (check_win(board)) {
                    printf("You win!\n");
                    done = 1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}