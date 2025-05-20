//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 32

const char *romance_cards[NUM_CARDS] = {
    "The Lovers",
    "The Empress",
    "The Chariot",
    "The Star",
    "The Moon",
    "The Sun",
    "The Fool",
    "The Magician",
    "The High Priestess",
    "The Empress",
    "The Emperor",
    "The Hierophant",
    "The Lovers",
    "The Chariot",
    "Strength",
    "The Hermit",
    "The Wheel of Fortune",
    "Justice",
    "The Hanged Man",
    "Death",
    "Temperance",
    "The Devil",
    "The Tower",
    "The Judgement",
    "The World"
};

void shuffleDeck(int *cards) {
    int i, j, temp;
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void dealCards(int *cards, int numCards) {
    int i;
    for (i = 0; i < numCards; i++)
        printf("Card %d: %s\n", i + 1, romance_cards[cards[i]]);
}

int main() {
    int i, cards[3];
    srand(time(NULL));
    shuffleDeck(cards);
    dealCards(cards, 3);
    printf("\nYour romantic future is unveiled:\n");
    for (i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                printf("The first card represents your present love situation.\n");
                break;
            case 1:
                printf("The second card symbolizes your past loves and experiences.\n");
                break;
            case 2:
                printf("The third card reveals your future love potential.\n");
                break;
        }
    }
    return 0;
}