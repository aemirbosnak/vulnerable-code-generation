//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define the card suit and rank as strings
const char *suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"}; 
const char *ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// define a struct for each card, with suit, rank, and value
typedef struct {
    int rank;
    int suit;
    int value;
} card;

// define a hand struct to hold the player's cards
typedef struct {
    card *cards[5];
    int num_cards;
    int total_value;
} hand;

// print a string with a newline
void print_message(char *message) {
    printf("%s\n", message);
}

// generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// create a new card with suit, rank, and value
card *new_card(int suit, int rank, int value) {
    card *c = (card *)malloc(sizeof(card));
    c->suit = suit;
    c->rank = rank;
    c->value = value;
    return c;
}

// create a new deck of 52 cards, in order
card **new_deck() {
    card **deck = (card **)malloc(sizeof(card *) * 52);
    int i, j, count = 0;
    for(i=0;i<4;i++) {
        for(j=0;j<13;j++) {
            deck[count++] = new_card(i, j, (j + 1));
        }
    }
    return deck;
}

// shuffle a deck of cards
void shuffle_deck(card **deck) {
    int i, j;
    for(i=0;i<52;i++) {
        j = random_number(0, 51);
        card *temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// deal one card to a hand
void deal_card(hand *h, card *c) {
    h->cards[h->num_cards++] = c;
    h->total_value += c->value;
}

// deal a hand of cards
void deal_hand(hand *h, card **deck, int num_cards) {
    int i;
    for(i=0;i<num_cards;i++) {
        deal_card(h, deck[i]);
    }
}

// print a card's suit and rank
void print_card(card *c) {
    printf("%s of %s\n", ranks[c->rank], suits[c->suit]);
}

// print a hand's cards
void print_hand(hand *h) {
    int i;
    for(i=0;i<h->num_cards;i++) {
        print_card(h->cards[i]);
    }
    printf("Total value: %d\n", h->total_value);
}

// check if a hand is a flush
int is_flush(hand *h) {
    int i, suit = h->cards[0]->suit;
    for(i=1;i<h->num_cards;i++) {
        if(h->cards[i]->suit != suit) {
            return 0;
        }
    }
    return 1;
}

// check if a hand is a straight
int is_straight(hand *h) {
    int i, rank = h->cards[0]->rank;
    for(i=1;i<h->num_cards;i++) {
        if(h->cards[i]->rank != rank + 1) {
            return 0;
        }
        rank = h->cards[i]->rank;
    }
    return 1;
}

// evaluate a hand and return its rank
// 1 = Flush
// 2 = Straight
// 3 = Three of a Kind
// 4 = Two Pair
// 5 = Pair
// 6 = High Card
int evaluate_hand(hand *h) {
    if(is_flush(h)) {
        return 1;
    }
    if(is_straight(h)) {
        return 2;
    }
    int i, j, num_pairs = 0, num_of_a_kind = 0;
    for(i=0;i<h->num_cards;i++) {
        for(j=i+1;j<h->num_cards;j++) {
            if(h->cards[i]->rank == h->cards[j]->rank) {
                num_pairs++;
                num_of_a_kind++;
            }
        }
    }
    if(num_of_a_kind == 3) {
        return 3;
    } else if(num_pairs == 2) {
        return 4;
    } else if(num_of_a_kind == 2) {
        return 5;
    } else {
        return 6;
    }
}

int main() {
    srand(time(NULL));
    card **deck = new_deck();
    shuffle_deck(deck);
    hand *player_hand = malloc(sizeof(hand));
    player_hand->num_cards = 0;
    player_hand->total_value = 0;
    deal_hand(player_hand, deck, 5);
    print_message("Your hand:");
    print_hand(player_hand);
    int rank = evaluate_hand(player_hand);
    switch(rank) {
        case 1:
            print_message("You have a flush!");
            break;
        case 2:
            print_message("You have a straight!");
            break;
        case 3:
            print_message("You have three of a kind!");
            break;
        case 4:
            print_message("You have two pair!");
            break;
        case 5:
            print_message("You have a pair!");
            break;
        case 6:
            print_message("You only have a high card.");
            break;
    }
    return 0;
}