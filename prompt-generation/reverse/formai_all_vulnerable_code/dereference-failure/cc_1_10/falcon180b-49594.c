//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CARDS 75

void create_card(int *card) {
    int i;
    for (i = 0; i < COLS; i++) {
        if (i == COLS - 1) {
            card[i] = rand() % 15 + 1;
        } else {
            card[i] = rand() % 15 + 1;
        }
    }
}

void print_card(int *card) {
    int i;
    for (i = 0; i < COLS; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int cards[MAX_CARDS];
    int i, j, k, num_cards = 0;
    int player_cards[ROWS][COLS];
    char play_again;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            create_card(player_cards[i][j]);
        }
    }

    while (1) {
        system("clear");
        printf("Welcome to Bingo!\n\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                print_card(player_cards[i][j]);
            }
        }

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (player_cards[i][j] == 0) {
                    create_card(player_cards[i][j]);
                }
            }
        }

        num_cards = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (player_cards[i][j]!= 0) {
                    num_cards++;
                }
            }
        }

        if (num_cards == MAX_CARDS) {
            printf("Bingo! You win!\n");
            break;
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again == 'n') {
            break;
        }
    }

    return 0;
}