//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 75

int main() {
    int bingo_cards[MAX_ROWS][MAX_COLS];
    int num_cards;
    int i, j, k, l, m, n, o;
    int card_num;
    int num_drawn;
    int player_num;
    int valid_input;
    int bingo;

    srand(time(NULL));

    // Initialize bingo cards
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            bingo_cards[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }

    // Get number of cards to play
    printf("How many bingo cards do you want to play? ");
    scanf("%d", &num_cards);

    // Print bingo cards
    printf("\n");
    for (i = 0; i < num_cards; i++) {
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                printf("%d ", bingo_cards[i][j * MAX_COLS + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Draw numbers
    num_drawn = 0;
    while (num_drawn < MAX_NUMBERS) {
        card_num = rand() % num_cards;
        player_num = rand() % MAX_NUMBERS;
        valid_input = 0;
        while (!valid_input) {
            printf("Card %d, number %d: ", card_num + 1, player_num);
            scanf("%d", &bingo_cards[card_num][player_num - 1]);
            if (bingo_cards[card_num][player_num - 1] < 1 || bingo_cards[card_num][player_num - 1] > MAX_NUMBERS) {
                printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
            } else {
                valid_input = 1;
            }
        }
        num_drawn++;
    }

    // Check for bingo
    for (i = 0; i < num_cards; i++) {
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                if (bingo_cards[i][j * MAX_COLS + k] == MAX_NUMBERS) {
                    printf("Bingo on card %d!\n", i + 1);
                    return 0;
                }
            }
        }
    }

    return 0;
}