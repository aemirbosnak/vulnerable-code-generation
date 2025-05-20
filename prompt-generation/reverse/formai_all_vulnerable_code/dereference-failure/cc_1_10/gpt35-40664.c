//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defines the suits of the cards
enum Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

// defines the ranks of the cards
enum Rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

// defines a card
typedef struct {
    enum Suit suit;
    enum Rank rank;
} Card;

// prints a card to the console
void printCard(Card card) {
    switch (card.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("10");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
    }

    switch (card.suit) {
        case HEARTS:
            printf(" of Hearts");
            break;
        case DIAMONDS:
            printf(" of Diamonds");
            break;
        case CLUBS:
            printf(" of Clubs");
            break;
        case SPADES:
            printf(" of Spades");
            break;
    }

    printf("\n");
}

// creates a deck of cards
Card* createDeck() {
    Card* deck = malloc(52 * sizeof(Card));
    int index = 0;

    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[index].suit = suit;
            deck[index].rank = rank;
            index++;
        }
    }

    return deck;
}

// shuffles a deck of cards using Fisher-Yates algorithm
void shuffleDeck(Card* deck) {
    srand(time(NULL));

    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// deals cards to players
void dealCards(Card* deck, int numPlayers, int numCards, Card** hands) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numCards; j++) {
            hands[i][j] = deck[(i * numCards) + j];
        }
    }
}

int main() {
    Card* deck = createDeck();
    shuffleDeck(deck);

    int numPlayers, numCards;
    printf("Enter the number of players and number of cards per player:\n");
    scanf("%d %d", &numPlayers, &numCards);

    Card** hands = malloc(numPlayers * sizeof(Card*));
    for (int i = 0; i < numPlayers; i++) {
        hands[i] = malloc(numCards * sizeof(Card));
    }

    dealCards(deck, numPlayers, numCards, hands);

    printf("Hands:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i+1);
        for (int j = 0; j < numCards; j++) {
            printCard(hands[i][j]);
        }
        printf("\n");
    }

    free(deck);
    for (int i = 0; i < numPlayers; i++) {
        free(hands[i]);
    }
    free(hands);

    return 0;
}