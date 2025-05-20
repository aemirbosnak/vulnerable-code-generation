//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
    char suit;
    char rank;
} Card;

typedef struct hand {
    Card cards[5];
    int hand_value;
} Hand;

void shuffle_deck(Card deck[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int get_card_value(Card card) {
    switch (card.rank) {
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'T':
            return 10;
        case 'J':
            return 10;
        case 'Q':
            return 10;
        case 'K':
            return 10;
        case 'A':
            return 11;
        default:
            return 0;
    }
}

int get_hand_value(Hand hand) {
    int value = 0;
    int count_aces = 0;
    for (int i = 0; i < 5; i++) {
        value += get_card_value(hand.cards[i]);
        if (hand.cards[i].rank == 'A') {
            count_aces++;
        }
    }
    while (value > 21 && count_aces > 0) {
        value -= 10;
        count_aces--;
    }
    return value;
}

void print_hand(Hand hand) {
    for (int i = 0; i < 5; i++) {
        printf("%c%c ", hand.cards[i].suit, hand.cards[i].rank);
    }
    printf("\n");
}

void deal_card(Card deck[], int n, Hand *hand) {
    Card card = deck[--n];
    hand->cards[hand->hand_value] = card;
    hand->hand_value++;
}

int main() {
    srand(time(NULL));
    Card deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i].suit = 'H';
        deck[i].rank = 'A' + i % 13;
    }
    shuffle_deck(deck, 52);
    Hand player_hand, dealer_hand;
    for (int i = 0; i < 2; i++) {
        deal_card(deck, 52, &player_hand);
    }
    for (int i = 0; i < 2; i++) {
        deal_card(deck, 52, &dealer_hand);
    }
    int player_value = get_hand_value(player_hand);
    int dealer_value = get_hand_value(dealer_hand);
    if (player_value > 21) {
        printf("You bust! Dealer wins.\n");
        return 0;
    }
    if (dealer_value > 21) {
        printf("Dealer busts! You win!\n");
        return 0;
    }
    if (player_value > dealer_value) {
        printf("You win!\n");
    } else if (player_value < dealer_value) {
        printf("You lose.\n");
    } else {
        printf("It's a tie.\n");
    }
    return 0;
}