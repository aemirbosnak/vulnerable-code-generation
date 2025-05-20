//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int num_cards = 16;
    int *cards = (int*)malloc(num_cards * sizeof(int));
    int num_matches = 4;
    int *matches = (int*)malloc(num_matches * sizeof(int));

    for (int i = 0; i < num_cards; i++) {
        cards[i] = rand() % 16 + 1;
    }

    printf("Here are your %d cards:\n", num_cards);
    for (int i = 0; i < num_cards; i++) {
        printf("%d. %d\n", i+1, cards[i]);
    }

    printf("\nFlip over the cards and try to find the matches!\n");

    for (int i = 0; i < num_matches; i++) {
        int match_card = rand() % num_cards + 1;
        matches[i] = cards[match_card - 1];
    }

    for (int i = 0; i < num_matches; i++) {
        printf("%d. %d\n", i+1, matches[i]);
    }

    int correct_matches = 0;
    int tries = 0;

    while (correct_matches < num_matches) {
        int guess;
        printf("Enter your guess (1-%d): ", num_cards);
        scanf("%d", &guess);

        if (guess > 0 && guess <= num_cards) {
            if (guess == cards[guess - 1]) {
                correct_matches++;
                printf("Correct!\n");
            } else if (guess == matches[tries - 1]) {
                correct_matches++;
                printf("Correct!\n");
                tries++;
            } else {
                printf("Wrong!\n");
            }
        } else {
            printf("Invalid guess. Try again.\n");
        }
    }

    printf("\nCongratulations! You found all the matches in %d tries.\n", tries);

    free(cards);
    free(matches);

    return 0;
}