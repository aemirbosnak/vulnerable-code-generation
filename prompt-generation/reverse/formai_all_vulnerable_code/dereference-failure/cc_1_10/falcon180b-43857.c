//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void shuffle_cards(char cards[NUM_CARDS][3]) {
    srand(time(NULL));
    int i, j, temp;
    for (i = 0; i < NUM_CARDS; i++) {
        for (j = 0; j < 2; j++) {
            temp = rand() % NUM_CARDS;
            char temp_card[3];
            strcpy(temp_card, cards[i]);
            strcpy(cards[i], cards[temp]);
            strcpy(cards[temp], temp_card);
        }
    }
}

int main() {
    char board[ROWS][COLS];
    char cards[NUM_CARDS][3];
    int i;

    // Initialize the board
    initialize_board(board);

    // Shuffle the cards
    shuffle_cards(cards);

    // Print the initial board
    printf("Initial board:\n");
    print_board(board);

    // Main game loop
    int num_matches = 0;
    while (num_matches < NUM_CARDS) {
        int choice;
        printf("\nChoose a card: ");
        for (i = 0; i < NUM_CARDS; i++) {
            printf("%d. %s\n", i + 1, cards[i]);
        }
        scanf("%d", &choice);
        choice--;

        // Check if the card is already flipped
        if (cards[choice][2] == 'F') {
            printf("Card %s is already flipped.\n", cards[choice]);
        } else {
            // Flip the card
            cards[choice][2] = 'F';

            // Check for a match
            int row = (choice % ROWS) / 2;
            int col = (choice % 2) * 2;
            if (board[row][col] == cards[choice][0]) {
                board[row][col] = cards[choice][0];
                board[row][col + 1] = cards[choice][1];
                num_matches++;
            } else {
                // Flip the card back
                cards[choice][2] = 'B';
            }
        }

        // Print the current board
        printf("\nCurrent board:\n");
        print_board(board);
    }

    // Print the final score
    printf("\nYou found %d matches in %d turns.\n", num_matches, NUM_CARDS);

    return 0;
}