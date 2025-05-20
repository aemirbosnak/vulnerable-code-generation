//FormAI DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define NUM_SUIT 4
#define NUM_RANK 13
#define MAX_HAND_SIZE 5

char* suit_names[NUM_SUIT] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char* rank_names[NUM_RANK] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

typedef struct {
    int suit;
    int rank;
} Card;

typedef struct {
    Card cards[MAX_HAND_SIZE];
    int num_cards;
} Hand;

void print_card(Card card) {
    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

void print_hand(Hand hand) {
    for (int i = 0; i < hand.num_cards; i++) {
        print_card(hand.cards[i]);
    }
}

Card* create_deck() {
    Card* deck = malloc(NUM_CARDS * sizeof(Card));
    int index = 0;
    for (int suit = 0; suit < NUM_SUIT; suit++) {
        for (int rank = 0; rank < NUM_RANK; rank++) {
            deck[index].suit = suit;
            deck[index].rank = rank;
            index++;
        }
    }
    return deck;
}

void shuffle_deck(Card* deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

Hand deal_hand(Card* deck) {
    Hand hand;
    hand.num_cards = MAX_HAND_SIZE;
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        hand.cards[i] = deck[i];
    }
    return hand;
}

void sort_hand(Hand* hand) {
    for (int i = 0; i < hand->num_cards; i++) {
        for (int j = i + 1; j < hand->num_cards; j++) {
            if (hand->cards[j].rank < hand->cards[i].rank) {
                Card temp = hand->cards[i];
                hand->cards[i] = hand->cards[j];
                hand->cards[j] = temp;
            }
        }
    }
}

void play_game() {
    Card* deck = create_deck();
    shuffle_deck(deck);
    Hand hands[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        hands[i] = deal_hand(&deck[i * MAX_HAND_SIZE]);
        sort_hand(&hands[i]);
        printf("Player %d's hand:\n", i + 1);
        print_hand(hands[i]);
        printf("\n");
    }
}

int main() {
    play_game();
    return 0;
}