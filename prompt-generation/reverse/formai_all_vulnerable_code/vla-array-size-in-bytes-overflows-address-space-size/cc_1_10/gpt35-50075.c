//FormAI DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player {
    char name[50];
    int score;
};

int main() {
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    struct player players[num_players];

    for (int i = 0; i < num_players; i++) {
        printf("\nEnter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int round = 1;
    while (round <= 3) {
        printf("\nRound %d\n", round);

        for (int i = 0; i < num_players; i++) {
            int guess;
            printf("%s, enter your guess: ", players[i].name);
            scanf("%d", &guess);

            if (guess == round) {
                players[i].score += 3;
            } else if (abs(guess - round) == 1) {
                players[i].score += 1;
            }
        }

        printf("\nCurrent Scores:\n");
        for (int i = 0; i < num_players; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        round++;
    }

    printf("\nFinal Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}