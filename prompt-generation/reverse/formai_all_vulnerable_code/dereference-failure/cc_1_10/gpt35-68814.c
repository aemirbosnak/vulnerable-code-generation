//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEARTS "♥"
#define DIAMONDS "♦"
#define CLUBS "♣"
#define SPADES "♠"

#define NUM_SUITS 4
#define NUM_VALUES 13
#define DECK_SIZE 52
#define HAND_SIZE 5

#define MAX_HAND_RANK 7461 // Pre-calculated value for the maximum possible hand rank

// Each card is represented as a struct with a value and a suit
typedef struct {
    int value; // 2-10 = face value, 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    char* suit;
} Card;

// A hand is represented as an array of 5 cards
typedef struct {
    Card* cards[HAND_SIZE];
    int rank;
} Hand;

// Initialize a deck of cards
void initializeDeck(Card** deck) {
    int i, j;
    for (i = 0; i < NUM_SUITS; i++) {
        char* suit;
        switch (i) {
            case 0:
                suit = HEARTS;
                break;
            case 1:
                suit = DIAMONDS;
                break;
            case 2:
                suit = CLUBS;
                break;
            case 3:
                suit = SPADES;
                break;
        }
        for (j = 2; j <= NUM_VALUES + 1; j++) {
            int value = j;
            if (value == 14) {
                value = 1;
            }
            int index = (i * NUM_VALUES) + (j - 2); // Calculate the index of the card in the deck
            deck[index] = malloc(sizeof(Card)); // Allocate memory for the card
            deck[index]->value = value;
            deck[index]->suit = suit;
        }
    }
}

// Shuffle the deck of cards
void shuffleDeck(Card** deck) {
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card* temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal a hand of 5 cards to a player
void dealHand(Hand* hand, Card** deck) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck[i];
    }
}

// Print a card in a human-readable format (e.g. "Ace of Hearts")
void printCard(Card* card) {
    char* value;
    switch (card->value) {
        case 2:
            value = "2";
            break;
        case 3:
            value = "3";
            break;
        case 4:
            value = "4";
            break;
        case 5:
            value = "5";
            break;
        case 6:
            value = "6";
            break;
        case 7:
            value = "7";
            break;
        case 8:
            value = "8";
            break;
        case 9:
            value = "9";
            break;
        case 10:
            value = "10";
            break;
        case 11:
            value = "Jack";
            break;
        case 12:
            value = "Queen";
            break;
        case 13:
            value = "King";
            break;
        case 14:
            value = "Ace";
            break;
    }
    printf("%s of %s", value, card->suit);
}

// Print a hand of 5 cards in a human-readable format
void printHand(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand->cards[i]);
        if (i < HAND_SIZE - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Check if a hand contains a flush
int hasFlush(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand->cards[i]->suit != hand->cards[i+1]->suit) {
            return 0;
        }
    }
    return 1;
}

// Check if a hand contains a straight
int hasStraight(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand->cards[i]->value + 1 != hand->cards[i+1]->value) {
            return 0;
        }
    }
    return 1;
}

// Check if a hand contains a straight flush
int hasStraightFlush(Hand* hand) {
    return hasFlush(hand) && hasStraight(hand);
}

// Check if a hand contains a four of a kind
int hasFourOfAKind(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 3; i++) {
        if (hand->cards[i]->value == hand->cards[i+1]->value &&
            hand->cards[i]->value == hand->cards[i+2]->value &&
            hand->cards[i]->value == hand->cards[i+3]->value) {
            return 1;
        }
    }
    return 0;
}

// Check if a hand contains a full house
int hasFullHouse(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 2; i++) {
        if (hand->cards[i]->value == hand->cards[i+1]->value &&
            hand->cards[i]->value == hand->cards[i+2]->value) {
            int j;
            for (j = i+3; j < HAND_SIZE - 1; j++) {
                if (hand->cards[j]->value == hand->cards[j+1]->value) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Check if a hand contains a three of a kind
int hasThreeOfAKind(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 2; i++) {
        if (hand->cards[i]->value == hand->cards[i+1]->value &&
            hand->cards[i]->value == hand->cards[i+2]->value) {
            return 1;
        }
    }
    return 0;
}

// Check if a hand contains two pairs
int hasTwoPairs(Hand* hand) {
    int i;
    int numPairs = 0;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand->cards[i]->value == hand->cards[i+1]->value) {
            numPairs++;
            i++; // Skip the next card because it's part of the pair
        }
    }
    return numPairs == 2;
}

// Check if a hand contains one pair
int hasOnePair(Hand* hand) {
    int i;
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand->cards[i]->value == hand->cards[i+1]->value) {
            return 1;
        }
    }
    return 0;
}

// Calculate the rank of a hand
int calculateHandRank(Hand* hand) {
    if (hasStraightFlush(hand)) {
        return 800 + hand->cards[4]->value; // Straight flush (e.g. "10, 9, 8, 7, 6 of hearts")
    } else if (hasFourOfAKind(hand)) {
        return 700 + hand->cards[2]->value; // Four of a kind (e.g. "Jack, Jack, Jack, Jack, 7")
    } else if (hasFullHouse(hand)) {
        return 600 + hand->cards[2]->value; // Full house (e.g. "6, 6, 6, 3, 3")
    } else if (hasFlush(hand)) {
        return 500 + hand->cards[4]->value; // Flush (e.g. "Ace, 10, 7, 6, 4 of spades")
    } else if (hasStraight(hand)) {
        return 400 + hand->cards[4]->value; // Straight (e.g. "7, 6, 5, 4, 3")
    } else if (hasThreeOfAKind(hand)) {
        return 300 + hand->cards[2]->value; // Three of a kind (e.g. "Queen, Queen, Queen, 10, 9")
    } else if (hasTwoPairs(hand)) {
        return 200 + hand->cards[3]->value; // Two pairs (e.g. "King, King, 9, 9, 7")
    } else if (hasOnePair(hand)) {
        return 100 + hand->cards[3]->value; // One pair (e.g. "Ace, Ace, 10, 8, 2")
    } else { // High card (e.g. "Queen, 10, 8, 7, 5")
        return hand->cards[4]->value;
    }
}

// Compare two hands and determine which one wins
int compareHands(Hand* hand1, Hand* hand2) {
    int rank1 = hand1->rank;
    int rank2 = hand2->rank;
    if (rank1 > rank2) {
        return 1;
    } else if (rank1 < rank2) {
        return 2;
    } else { // If the hands have the same rank, compare the highest card in each hand
        int i;
        for (i = HAND_SIZE - 1; i >= 0; i--) {
            if (hand1->cards[i]->value > hand2->cards[i]->value) {
                return 1;
            } else if (hand1->cards[i]->value < hand2->cards[i]->value) {
                return 2;
            }
        }
        return 0; // If the hands are completely equal, return a tie
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    Card** deck = malloc(sizeof(Card*) * DECK_SIZE); // Allocate memory for the deck of cards
    initializeDeck(deck); // Initialize the deck of cards
    shuffleDeck(deck); // Shuffle the deck of cards
    Hand* playerHand = malloc(sizeof(Hand)); // Allocate memory for the player's hand
    Hand* opponentHand = malloc(sizeof(Hand)); // Allocate memory for the opponent's hand
    dealHand(playerHand, deck); // Deal a hand of 5 cards to the player
    dealHand(opponentHand, deck + HAND_SIZE); // Deal a hand of 5 cards to the opponent
    playerHand->rank = calculateHandRank(playerHand); // Calculate the rank of the player's hand
    opponentHand->rank = calculateHandRank(opponentHand); // Calculate the rank of the opponent's hand
    printf("Player's hand: ");
    printHand(playerHand); // Print the player's hand
    printf("Opponent's hand: ");
    printHand(opponentHand); // Print the opponent's hand
    int winner = compareHands(playerHand, opponentHand);
    if (winner == 1) {
        printf("Player wins!\n");
    } else if (winner == 2) {
        printf("Opponent wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}