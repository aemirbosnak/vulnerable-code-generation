//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS
} Suit;

typedef struct {
    Suit suit;
    int value; // 1=Ace, 2-10, 11=Jack, 12=Queen, 13=King
    char* name; // e.g. "Ace of Spades", "Jack of Diamonds"
} Card;

void initializeDeck(Card deck[]) {
    int i, j, value;
    char* name;
    for (i = 0; i < DECK_SIZE; i++) {
        switch (i / 13) {
            case 0:
                name = "Ace"; value = 1; break;
            case 1:
                name = "2"; value = 2; break;
            case 2:
                name = "3"; value = 3; break;
            case 3:
                name = "4"; value = 4; break;
            case 4:
                name = "5"; value = 5; break;
            case 5:
                name = "6"; value = 6; break;
            case 6:
                name = "7"; value = 7; break;
            case 7:
                name = "8"; value = 8; break;
            case 8:
                name = "9"; value = 9; break;
            case 9:
                name = "10"; value = 10; break;
            case 10:
                name = "Jack"; value = 11; break;
            case 11:
                name = "Queen"; value = 12; break;
            case 12:
                name = "King"; value = 13; break;
        }
        deck[i].value = value;
        deck[i].name = (char*)malloc((strlen(name) + 10) * sizeof(char));
        sprintf(deck[i].name, "%s of ", name);
        switch (i % 4) {
            case 0: deck[i].suit = SPADES; strcat(deck[i].name, "Spades"); break;
            case 1: deck[i].suit = HEARTS; strcat(deck[i].name, "Hearts"); break;
            case 2: deck[i].suit = DIAMONDS; strcat(deck[i].name, "Diamonds"); break;
            case 3: deck[i].suit = CLUBS; strcat(deck[i].name, "Clubs"); break;
        }
    }
}

void shuffleDeck(Card deck[]) {
    int i, j;
    Card temp;
    for (i = 0; i < DECK_SIZE; i++) {
        j = i + (rand() % (DECK_SIZE - i));
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printHand(Card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%s\n", hand[i].name);
    }
}

int main() {
    srand(time(NULL));
    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];
    initializeDeck(deck);
    shuffleDeck(deck);
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    printHand(hand);
    return 0;
}