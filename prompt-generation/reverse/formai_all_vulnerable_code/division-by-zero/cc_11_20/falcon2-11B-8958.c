//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 16

typedef struct node {
    int value;
    struct node* next;
} node;

int main() {
    int num_cards;
    printf("Enter the number of cards: ");
    scanf("%d", &num_cards);

    node* cards[num_cards];
    for (int i = 0; i < num_cards; i++) {
        cards[i] = NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < num_cards; i++) {
        int card_value = rand() % 16 + 1;
        cards[i] = malloc(sizeof(node));
        cards[i]->value = card_value;
        cards[i]->next = NULL;
    }

    for (int i = 0; i < num_cards; i++) {
        printf("%d ", cards[i]->value);
    }
    printf("\n");

    int turn = 1;
    while (true) {
        int player_guess = turn % num_cards;
        printf("Player %d, guess a card: ", turn);
        int guess;
        scanf("%d", &guess);

        for (int i = 0; i < num_cards; i++) {
            if (guess == cards[i]->value) {
                printf("Correct!\n");
                free(cards[i]);
                cards[i] = NULL;
            } else if (guess == cards[i]->next->value) {
                printf("Correct!\n");
                free(cards[i]);
                cards[i] = NULL;
                free(cards[i]->next);
                cards[i]->next = NULL;
            } else {
                printf("Incorrect. Try again.\n");
            }
        }

        turn++;

        if (turn % 2 == 0) {
            int computer_guess = rand() % num_cards;
            printf("Computer %d, guess a card: ", turn);
            int comp_guess;
            scanf("%d", &comp_guess);

            for (int i = 0; i < num_cards; i++) {
                if (comp_guess == cards[i]->value) {
                    printf("Correct!\n");
                    free(cards[i]);
                    cards[i] = NULL;
                } else if (comp_guess == cards[i]->next->value) {
                    printf("Correct!\n");
                    free(cards[i]);
                    cards[i] = NULL;
                    free(cards[i]->next);
                    cards[i]->next = NULL;
                } else {
                    printf("Incorrect. Try again.\n");
                }
            }
        }

        if (turn % num_cards == 0) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}