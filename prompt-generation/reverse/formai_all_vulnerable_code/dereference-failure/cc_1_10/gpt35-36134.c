//FormAI DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_CARDS 10
#define CARD_MIN_VALUE 1
#define CARD_MAX_VALUE 5

void shuffle(int *array, size_t n);
void swap(int *a, int *b);
int *create_cards(int number_of_cards);
void print_cards(int *cards, int number_of_cards);
int *make_guesses(int number_of_cards);
int get_score(int *cards, int *guesses, int number_of_cards);

int main()
{
    srand(time(NULL));
    int *cards = create_cards(NUMBER_OF_CARDS);
    printf("Welcome to the memory game! You will see a set of cards with numbers on them that are face down. Each card has a value between %d and %d.\n", CARD_MIN_VALUE, CARD_MAX_VALUE);
    printf("You will have to guess what each card's value is by selecting two cards at a time. If the values match, you will score a point and the cards will stay face up. If the values do not match, the cards will be flipped back over.\n");
    printf("Let's begin!\n\n");
    print_cards(cards, NUMBER_OF_CARDS);
    int *guesses = make_guesses(NUMBER_OF_CARDS);
    int score = get_score(cards, guesses, NUMBER_OF_CARDS);
    printf("Game over! Your score is %d/%d.\n", score, NUMBER_OF_CARDS/2);
    free(cards);
    free(guesses);
    return 0;
}

/*
 * Shuffles an array of integers using the Fisher-Yates shuffle algorithm.
 */
void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            swap(&array[j], &array[i]);
        }
    }
}

/*
 * Swaps two integers.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Creates an array of cards with random values between CARD_MIN_VALUE and CARD_MAX_VALUE.
 * Duplicate values are guaranteed to appear exactly twice.
 */
int *create_cards(int number_of_cards) {
    if (number_of_cards % 2 == 1) {
        number_of_cards++;
    }
    int *cards = malloc(sizeof(int)*number_of_cards);
    for (int i=0; i<number_of_cards/2; i++) {
        cards[i] = i + CARD_MIN_VALUE;
        cards[i + number_of_cards/2] = i + CARD_MIN_VALUE;
    }
    shuffle(cards, number_of_cards);
    return cards;
}

/*
 * Prints an array of cards with their values hidden.
 */
void print_cards(int *cards, int number_of_cards) {
    printf("Cards:");
    for (int i=0; i<number_of_cards; i++) {
        printf(" ");
        if (i%2 == 0) {
            printf("[");
        }
        if (cards[i] > CARD_MIN_VALUE) {
            printf("?");
        } else {
            printf("%d", cards[i]);
        }
        if (i%2 == 1) {
            printf("]");
        }
    }
    printf("\n\n");
}

/*
 * Prompts the user to make guesses and returns an array of the guesses.
 */
int *make_guesses(int number_of_cards) {
    int *guesses = calloc(number_of_cards, sizeof(int));
    int guess1, guess2;
    for (int i=0; i<number_of_cards/2; i++) {
        do {
            printf("Enter the index of the first card you want to flip (0-%d): ", number_of_cards-1);
            scanf("%d", &guess1);
        } while (guess1<0 || guess1>=number_of_cards || guesses[guess1] != 0);
        guesses[guess1] = 1;
        do {
            printf("Enter the index of the second card you want to flip (0-%d): ", number_of_cards-1);
            scanf("%d", &guess2);
        } while (guess2<0 || guess2>=number_of_cards || guesses[guess2] != 0);
        guesses[guess2] = 1;
        printf("You guessed %d and %d.\n", guess1, guess2);
    }
    return guesses;
}

/*
 * Calculates the user's score based on their guesses and the actual card values.
 * Returns the score.
 */
int get_score(int *cards, int *guesses, int number_of_cards) {
    int score = 0;
    for (int i=0; i<number_of_cards; i++) {
        if (guesses[i] == 1) {
            for (int j=0; j<number_of_cards; j++) {
                if (i != j && guesses[j] == 1 && cards[i] == cards[j]) {
                    score++;
                }
            }
        }
    }
    return score;
}