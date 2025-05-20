//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int** board, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == -1) {
                printf("*** ");
            } else {
                printf("%2d  ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int has_won(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != i * size + j) {
                return 0;
            }
        }
    }
    return 1;
}

int** create_board(int size) {
    int** board = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            board[i][j] = -1;
        }
    }
    return board;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int* array, int size) {
    // seed the random number generator
    srand(time(NULL));
    
    // shuffle the array
    for (int i = size - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        swap(&array[i], &array[j]);
    }
}

int* create_random_array(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    shuffle(array, size);
    return array;
}

void free_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    int** board = create_board(BOARD_SIZE);
    int* random_array = create_random_array(BOARD_SIZE * BOARD_SIZE);
    
    // populate the board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = random_array[index++];
        }
    }
    
    free(random_array);
    
    // play the game
    printf("Welcome to the Memory Game!\n");
    printf("Try to match all the pairs by entering their coordinates.\n");
    
    int moves = 0;
    while (1) {
        print_board(board, BOARD_SIZE);
        printf("Enter the coordinates of the first card: ");
        int row1, col1;
        scanf("%d %d", &row1, &col1);
        if (row1 < 0 || row1 >= BOARD_SIZE || col1 < 0 || col1 >= BOARD_SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        if (board[row1][col1] == -1) {
            board[row1][col1] = board[row1][col1] = -2;
        } else {
            printf("Card already revealed. Try again.\n");
            continue;
        }
        print_board(board, BOARD_SIZE);
        printf("Enter the coordinates of the second card: ");
        int row2, col2;
        scanf("%d %d", &row2, &col2);
        if (row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
            printf("Invalid coordinates. Try again.\n");
            board[row1][col1] = board[row1][col1] = -1;
            continue;
        }
        if (board[row2][col2] == -1) {
            board[row2][col2] = board[row1][col1];
        } else {
            printf("Card already revealed. Try again.\n");
            board[row1][col1] = board[row1][col1] = -1;
            continue;
        }
        moves++;
        if (has_won(board, BOARD_SIZE)) {
            printf("Congratulations! You won with %d moves!\n", moves);
            break;
        }
    }
    
    free_board(board, BOARD_SIZE);
    
    return 0;
}