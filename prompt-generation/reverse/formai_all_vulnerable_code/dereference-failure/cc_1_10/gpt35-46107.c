//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DECK_SIZE 52
#define CARD_FACES 13

//For storing Card's attributes like face and color
struct card {
    char* face;
    char* color;
};

//Fills a deck of cards with all possible faces and colors
void fillDeck(struct card* deck) {
    char* faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six",
                    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    char* colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    for (int i = 0; i < DECK_SIZE; ++i) {
        deck[i].face = faces[i % CARD_FACES];
        deck[i].color = colors[i / CARD_FACES];
    }
}

//Prints the all the cards in deck
void printDeck(struct card* deck) {
    for (int i = 0; i < DECK_SIZE; ++i) {
        printf("%s of %s\n", deck[i].face, deck[i].color);
    }
    printf("\n");
}

//Shuffles a deck of cards using the Fisher-Yates algorithm
void shuffleDeck(struct card* deck) {
    srand(time(NULL));

    for (int i = (DECK_SIZE - 1); i > 0; --i) {
        int j = rand() % (i + 1);
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//Draws a card from the deck and places it face up on the table
void drawCard(struct card* deck, int* topCard, struct card* table, int* tableCards) {
    table[*tableCards] = deck[*topCard];
    (*tableCards)++;
    (*topCard)++;
}

//Deals cards to the players and adds them to their hand
void dealCards(struct card* deck, int* topCard, struct card** hands, int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        for (int j = 0; j < 2; ++j) {
            hands[i][j] = deck[*topCard];
            (*topCard)++;
        }
    }
}

//Prints the specified player's hand
void printHand(struct card* hand, int handSize) {
    for (int i = 0; i < handSize; ++i) {
        printf("%s of %s\n", hand[i].face, hand[i].color);
    }
    printf("\n");
}

//Calculates the total point value of a hand of cards
int getHandValue(struct card* hand, int handSize) {
    int value = 0;
    int aces = 0;

    for (int i = 0; i < handSize; ++i) {
        if (hand[i].face == "Jack" || hand[i].face == "Queen" || hand[i].face == "King") {
            value += 10;
        }
        else if (hand[i].face == "Ace") {
            aces++;
        }
        else {
            value += atoi(hand[i].face);
        }
    }

    for (int i = 0; i < aces; ++i) {
        if (value + 11 <= 21) {
            value += 11;
        }
        else {
            value += 1;
        }
    }

    return value;
}

//Prints the current state of the game
void printGameState(struct card** hands, int* handSizes, int numPlayers, struct card* table, int tableCards, int topCard) {
    for (int i = 0; i < numPlayers; ++i) {
        printf("Player %d: ", i + 1);
        printHand(hands[i], handSizes[i]);
        printf("Total Value: %d\n\n", getHandValue(hands[i], handSizes[i]));
    }

    printf("Table Cards: ");
    printHand(table, tableCards);
    printf("Top Card: %s of %s\n\n", table[tableCards - 1].face, table[tableCards - 1].color);
}

int main() {
    int numPlayers;
    printf("Enter the number of players (1-8): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > 8) {
        printf("Invalid number of players. Exiting...\n\n");
        return 0;
    }

    struct card* deck = (struct card*)malloc(DECK_SIZE * sizeof(struct card));
    struct card** hands = (struct card**)malloc(numPlayers * sizeof(struct card*));
    for (int i = 0; i < numPlayers; ++i) {
        hands[i] = (struct card*)malloc(10 * sizeof(struct card));
    }
    struct card* table = (struct card*)malloc(10 * sizeof(struct card));

    fillDeck(deck);
    shuffleDeck(deck);

    int topCard = 0;
    int* handSizes = (int*)malloc(numPlayers * sizeof(int));
    for (int i = 0; i < numPlayers; ++i) {
        handSizes[i] = 2;
    }

    dealCards(deck, &topCard, hands, numPlayers);

    int tableCards = 0;
    drawCard(deck, &topCard, table, &tableCards);

    printf("Welcome to the Poker game!\n\n");
    printGameState(hands, handSizes, numPlayers, table, tableCards, topCard);

    for (int i = 0; i < numPlayers; ++i) {
        printf("Player %d's turn...\n\n", i + 1);
        char choice;
        do {
            printf("Do you want to hit or stay? (h/s): ");
            scanf(" %c", &choice);
            if (choice == 'h') {
                drawCard(deck, &topCard, hands[i], &handSizes[i]);
                printGameState(hands, handSizes, numPlayers, table, tableCards, topCard);
            }
        } while (choice == 'h');

        printf("Player %d's turn over.\n\n", i + 1);
    }

    printf("Dealer's turn...\n\n");
    while (getHandValue(table, tableCards) < 17) {
        drawCard(deck, &topCard, table, &tableCards);
        printGameState(hands, handSizes, numPlayers, table, tableCards, topCard);
    }
    printf("Dealer's turn over.\n\n");

    int dealerValue = getHandValue(table, tableCards);
    for (int i = 0; i < numPlayers; ++i) {
        int playerValue = getHandValue(hands[i], handSizes[i]);
        if (playerValue > 21) {
            printf("Player %d busts!\n\n", i + 1);
        }
        else if (playerValue > dealerValue || dealerValue > 21) {
            printf("Player %d wins!\n\n", i + 1);
        }
        else if (playerValue < dealerValue) {
            printf("Player %d loses!\n\n", i + 1);
        }
        else {
            printf("Player %d ties with the dealer!\n\n", i + 1);
        }
    }

    free(deck);
    free(table);
    free(handSizes);
    for (int i = 0; i < numPlayers; ++i) {
        free(hands[i]);
    }
    free(hands);

    return 0;
}