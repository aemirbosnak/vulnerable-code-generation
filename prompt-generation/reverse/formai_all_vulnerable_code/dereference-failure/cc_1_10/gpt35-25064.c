//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void convert(int num);
void multiplayer(int num);

int main(void) {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    convert(num);
    multiplayer(num);

    return 0;
}

// Converts the decimal number to hexadecimal using sprintf()
void convert(int num) {
    char hex[20];
    sprintf(hex, "%X", num);
    printf("\nIn hexadecimal: %s\n", hex);
}

// Multiplayer game where players guess the hexadecimal representation of the number
void multiplayer(int num) {
    int player1_score = 0;
    int player2_score = 0;
    int player_turn = 1;
    char hex_guess[20];

    printf("\nLet's play a multiplayer game!\n");
    printf("Player 1 goes first.\n");

    while (player1_score < 3 && player2_score < 3) {
        if (player_turn == 1) {
            printf("\nPlayer 1's turn. Guess the hexadecimal representation of the number: ");
            scanf("%s", hex_guess);
            if (strcmp(hex_guess, "exit") == 0) {
                printf("Game over!\n");
                exit(0);
            }
            if (strcmp(hex_guess, sprintf("%X", num)) == 0) {
                printf("Correct!\n");
                player1_score++;
            } else {
                printf("Incorrect.\n");
            }
            printf("Player 1's score: %d\n", player1_score);
            player_turn = 2;
        } else {
            printf("\nPlayer 2's turn. Guess the hexadecimal representation of the number: ");
            scanf("%s", hex_guess);
            if (strcmp(hex_guess, "exit") == 0) {
                printf("Game over!\n");
                exit(0);
            }
            if (strcmp(hex_guess, sprintf("%X", num)) == 0) {
                printf("Correct!\n");
                player2_score++;
            } else {
                printf("Incorrect.\n");
            }
            printf("Player 2's score: %d\n", player2_score);
            player_turn = 1;
        }
    }

    printf("\nGame over!\n");
    if (player1_score == 3) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}