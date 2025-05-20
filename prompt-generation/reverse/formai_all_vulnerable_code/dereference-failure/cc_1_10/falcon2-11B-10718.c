//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_numbers(int *numbers, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 75 + 1; // Random number between 1 and 75
    }
}

void print_numbers(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void play_bingo(int *numbers, int size) {
    int *board = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        board[i] = 0;
    }
    int current_number = 0;
    int bingo = 0;

    while (bingo!= 1) {
        print_numbers(numbers, size);
        printf("Current number: %d\n", current_number);
        int player_guess = 0;
        printf("Enter your guess: ");
        scanf("%d", &player_guess);
        if (player_guess == current_number) {
            printf("BINGO!\n");
            bingo = 1;
            for (int i = 0; i < size; i++) {
                if (board[i] == current_number) {
                    board[i] = 0;
                    printf("Number %d is marked as BINGO.\n", current_number);
                }
            }
        } else {
            printf("Sorry, wrong guess. Try again.\n");
            current_number = numbers[current_number];
        }
    }

    printf("Game over.\n");
    free(board);
}

int main() {
    int size = 5;
    int *numbers = (int *)malloc(size * sizeof(int));
    generate_numbers(numbers, size);
    play_bingo(numbers, size);
    free(numbers);
    return 0;
}