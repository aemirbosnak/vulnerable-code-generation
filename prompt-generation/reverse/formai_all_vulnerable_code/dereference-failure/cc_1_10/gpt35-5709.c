//FormAI DATASET v1.0 Category: Poker Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of cards in a deck
#define DECK_SIZE 52

// Face values of the cards
const char *faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Suits of the cards
const char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

// Value of each card
const int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// struct to represent a card
typedef struct {
    const char *face;
    const char *suit;
    int value;
} Card;

// struct to represent a player's hand
typedef struct {
    Card *cards[5];
    int num_cards;
} Hand;

// struct to represent the deck of cards
typedef struct {
    Card *cards[DECK_SIZE];
    int num_cards;
} Deck;

// function to initialize a new deck of cards
void initialize_deck(Deck* deck) {
    deck->num_cards = DECK_SIZE;
    int i, j, k = 0;
    for (i = 0; i < 13; i++) {
        for (j = 0; j < 4; j++) {
            Card *card = malloc(sizeof(Card));
            card->face = faces[i];
            card->suit = suits[j];
            card->value = values[i];
            deck->cards[k++] = card;
        }
    }
}

// function to shuffle the deck of cards
void shuffle_deck(Deck* deck) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < deck->num_cards; i++) {
        j = rand() % deck->num_cards;
        Card *temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// function to deal a card from the deck to a hand
void deal_card(Deck* deck, Hand* hand) {
    hand->cards[hand->num_cards++] = deck->cards[--deck->num_cards];
}

// function to determine the score of a hand
int score_hand(Hand* hand) {
    int score = 0, num_aces = 0;
    int i;
    for (i = 0; i < hand->num_cards; i++) {
        score += hand->cards[i]->value;
        if (hand->cards[i]->value == 11) {
            num_aces++;
        }
    }
    while (score > 21 && num_aces > 0) {
        score -= 10;
        num_aces--;
    }
    return score;
}

// function to display a hand
void display_hand(Hand* hand) {
    printf("Hand: ");
    int i;
    for (i = 0; i < hand->num_cards; i++) {
        printf("%s of %s ", hand->cards[i]->face, hand->cards[i]->suit);
    }
    printf("\n");
}

int main() {
    //initialize and shuffle deck
    Deck deck;
    initialize_deck(&deck);
    shuffle_deck(&deck);

    //initialize hands for player and dealer
    Hand player_hand = { .num_cards = 0 };
    Hand dealer_hand = { .num_cards = 0 };

    //deal initial cards
    deal_card(&deck, &player_hand);
    deal_card(&deck, &dealer_hand);
    deal_card(&deck, &player_hand);
    deal_card(&deck, &dealer_hand);

    printf("Dealer shows: %s of %s\n", dealer_hand.cards[0]->face, dealer_hand.cards[0]->suit);
    display_hand(&player_hand);

    //player's turn
    while (score_hand(&player_hand) < 21) {
        char choice;
        printf("Do you want to hit or stand? (h/s)\n");
        scanf(" %c", &choice);
        if (choice == 'h') {
            deal_card(&deck, &player_hand);
            display_hand(&player_hand);
        } else if (choice == 's') {
            break;
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    //dealer's turn
    while (score_hand(&dealer_hand) < 17) {
        deal_card(&deck, &dealer_hand);
    }

    //display final hands and scores
    display_hand(&dealer_hand);
    int player_score = score_hand(&player_hand);
    int dealer_score = score_hand(&dealer_hand);
    printf("Player score: %d\n", player_score);
    printf("Dealer score: %d\n", dealer_score);

    if (player_score > 21 || dealer_score > player_score && dealer_score <= 21) {
        printf("Dealer wins!\n");
    } else if (dealer_score > 21 || player_score > dealer_score) {
        printf("Player wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}