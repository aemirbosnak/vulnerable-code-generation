//FormAI DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the player's name
char* getPlayerName() {
    char* name = malloc(sizeof(char) * 50);
    printf("What is your name?: ");
    fgets(name, 50, stdin);
    strtok(name, "\n");
    return name;
}

int main() {
    printf("Welcome to the Love Table Game!\n");
    char* player1 = getPlayerName();
    char* player2 = getPlayerName();
    printf("\n%s and %s, let's begin!\n\n", player1, player2);

    int score1 = 0;
    int score2 = 0;
    int round = 1;

    while (round <= 5) {
        printf("Round %d:\n", round);
        printf("%s, please choose a number between 1 and 10: ", player1);
        int choice1;
        scanf("%d", &choice1);

        printf("%s, please choose a number between 1 and 10: ", player2);
        int choice2;
        scanf("%d", &choice2);

        if (choice1 == choice2) {
            printf("You both chose %d - it's a tie!\n\n", choice1);
        } else if (choice1 > choice2) {
            printf("%s wins this round!\n\n", player1);
            score1++;
        } else {
            printf("%s wins this round!\n\n", player2);
            score2++;
        }

        round++;
    }

    printf("GAME OVER!\n");
    if (score1 == score2) {
        printf("You both got %d points - it's a tie!\n", score1);
    } else if (score1 > score2) {
        printf("%s wins with %d points!\n", player1, score1);
    } else {
        printf("%s wins with %d points!\n", player2, score2);
    }

    free(player1);
    free(player2);
    return 0;
}