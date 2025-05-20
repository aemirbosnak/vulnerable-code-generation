//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE 'X'
#define UNUSED_SPACE ' '

void print_bingo_board(char bingo_board[ROWS][COLS])
{
    printf("\n\tB   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\n\t");
        for (int j = 0; j < COLS; j++) {
            printf("%2c  ", bingo_board[i][j]);
        }
        printf("\n");
    }
}

char** generate_bingo_board_numbers()
{
    char** bingo_numbers;
    bingo_numbers = (char**) calloc(75, sizeof(char*));
    
    for (int i = 0; i < 75; i++) {
        bingo_numbers[i] = (char*) calloc(3, sizeof(char));
    }
    
    int index = 0;
    for (char letter = 'B'; letter <= 'O'; letter++) {
        for (int i = 1; i <= 15; i++) {
            sprintf(bingo_numbers[index++], "%c%d", letter, i);
        }
    }

    return bingo_numbers;
}

int is_win(char bingo_board[ROWS][COLS])
{
    // Check horizontal lines
    for (int i = 0; i < ROWS; i++) {
        if (bingo_board[i][0] != FREE_SPACE && bingo_board[i][0] == bingo_board[i][1] && bingo_board[i][1] == bingo_board[i][2] 
            && bingo_board[i][2] == bingo_board[i][3] && bingo_board[i][3] == bingo_board[i][4]) {
            return 1;
        }
    }

    // Check vertical lines
    for (int i = 0; i < COLS; i++) {
        if (bingo_board[0][i] != FREE_SPACE && bingo_board[0][i] == bingo_board[1][i] && bingo_board[1][i] == bingo_board[2][i] 
            && bingo_board[2][i] == bingo_board[3][i] && bingo_board[3][i] == bingo_board[4][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (bingo_board[0][0] != FREE_SPACE && bingo_board[0][0] == bingo_board[1][1] && bingo_board[1][1] == bingo_board[2][2] 
        && bingo_board[2][2] == bingo_board[3][3] && bingo_board[3][3] == bingo_board[4][4]) {
        return 1;
    }

    if (bingo_board[0][4] != FREE_SPACE && bingo_board[0][4] == bingo_board[1][3] && bingo_board[1][3] == bingo_board[2][2] 
        && bingo_board[2][2] == bingo_board[3][1] && bingo_board[3][1] == bingo_board[4][0]) {
        return 1;
    }

    return 0;
}

int main()
{
    char bingo_board[ROWS][COLS] = {
        {UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE},
        {UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE},
        {UNUSED_SPACE, UNUSED_SPACE, FREE_SPACE, UNUSED_SPACE, UNUSED_SPACE},
        {UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE},
        {UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE, UNUSED_SPACE}
    };

    char** bingo_numbers = generate_bingo_board_numbers();

    int num_called_numbers = 0;
    int max_called_numbers = 75;
    char called_numbers[max_called_numbers][3];

    while (num_called_numbers < max_called_numbers) {
        int random_index = rand() % 75;
        char* random_bingo_number = bingo_numbers[random_index];

        int already_called = 0;
        for (int i = 0; i < num_called_numbers; i++) {
            if (strcmp(random_bingo_number, called_numbers[i]) == 0) {
                already_called = 1;
                break;
            }
        }

        if (!already_called) {
            called_numbers[num_called_numbers][0] = random_bingo_number[0];
            called_numbers[num_called_numbers][1] = random_bingo_number[1];
            called_numbers[num_called_numbers][2] = '\0';

            int row_index = -1;
            int col_index = -1;

            // Mark the number on the bingo board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (bingo_board[i][j] == called_numbers[num_called_numbers][1]) {
                        bingo_board[i][j] = FREE_SPACE;
                        row_index = i;
                        col_index = j;
                        break;
                    }
                }
                if (row_index != -1) {
                    break;
                }
            }

            printf("\nCalled number: %c%s", called_numbers[num_called_numbers][0], called_numbers[num_called_numbers] + 1);
            print_bingo_board(bingo_board);

            int win = is_win(bingo_board);
            if (win) {
                printf("\nBingo! You won in %d called numbers!\n", num_called_numbers + 1);
                break;
            }

            num_called_numbers++;
        }
    }

    return 0;
}