//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a new game board
int** create_board(int size) {
    int** board = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        board[i] = malloc(sizeof(int) * size);
    }
    return board;
}

// Function to free the game board
void free_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);
}

// Function to initialize the game board
void initialize_board(int** board, int size) {
    int count = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = count++;
        }
    }
}

// Function to shuffle the game board
void shuffle_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int temp = board[i][j];
            int random_i = rand() % size;
            int random_j = rand() % size;
            board[i][j] = board[random_i][random_j];
            board[random_i][random_j] = temp;
        }
    }
}

// Function to print the game board
void print_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the user's input
int get_input(int size) {
    int input;
    do {
        printf("Enter a number between 1 and %d: ", size * size);
        scanf("%d", &input);
    } while (input < 1 || input > size * size);
    return input;
}

// Function to check if the user's input is a match
int check_match(int** board, int size, int input1, int input2) {
    int row1 = (input1 - 1) / size;
    int col1 = (input1 - 1) % size;
    int row2 = (input2 - 1) / size;
    int col2 = (input2 - 1) % size;
    return board[row1][col1] == board[row2][col2];
}

// Function to play the game
void play_game(int** board, int size) {
    int input1, input2;
    int matches = 0;
    while (matches < size * size / 2) {
        printf("Enter the first number: ");
        input1 = get_input(size);
        printf("Enter the second number: ");
        input2 = get_input(size);
        if (check_match(board, size, input1, input2)) {
            matches++;
            printf("Match!\n");
        } else {
            printf("No match.\n");
        }
    }
    printf("Congratulations! You found all the matches.\n");
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the game board: ");
    scanf("%d", &size);
    int** board = create_board(size);
    initialize_board(board, size);
    shuffle_board(board, size);
    play_game(board, size);
    free_board(board, size);
    return 0;
}