//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define MAX_NUM_CARDS 20

typedef struct Card {
    int number;
    struct Card* next;
} Card;

void initialize_cards(Card** head) {
    *head = NULL;
    for (int i = 0; i < MAX_NUM_CARDS; i++) {
        Card* new_card = malloc(sizeof(Card));
        new_card->number = i + 1;
        new_card->next = *head;
        *head = new_card;
    }
}

void shuffle_cards(Card* head) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM_CARDS; i++) {
        int r = rand() % MAX_NUM_CARDS;
        Card* tmp = head;
        for (int j = 0; j < r; j++) {
            tmp = tmp->next;
        }
        Card* swap = tmp->next;
        tmp->next = swap->next;
        swap->next = tmp;
    }
}

void play_game(Card* head) {
    int guess_num = 0;
    int score = 0;
    char guess_again = 'y';

    printf("Welcome to the Memory Game!\n");

    while (guess_again == 'y') {
        printf("Guess a number between 1 and %d: ", MAX_NUM_CARDS);
        scanf("%d", &guess_num);

        if (head->number == guess_num) {
            score++;
            printf("Congratulations! You guessed the number!\n");
        } else {
            printf("Sorry, the number was not found.\n");
        }

        printf("Do you want to guess again? (y/n): ");
        scanf(" %c", &guess_again);
    }

    printf("Your final score is: %d\n", score);
}

int main() {
    Card* head = NULL;
    initialize_cards(&head);
    shuffle_cards(head);
    play_game(head);

    return 0;
}