//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[5];
    int rank;
} Hand;

//Returns a random number between min and max, inclusive
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

//Returns a new shuffled deck of cards
Card* get_shuffled_deck() {
    Card* deck = malloc(sizeof(Card) * 52);
    int rank = 1;
    int suit = 1;
    int index = 0;

    //Create unshuffled deck
    for(int i = 0; i < 52; i++) {
        deck[i].rank = rank;
        deck[i].suit = suit;

        rank++;
        if(rank > 13) {
            rank = 1;
            suit++;
        }
    }

    //Shuffle deck using Fisher–Yates shuffle algorithm
    for(int i = 51; i > 0; i--) {
        int j = get_random_number(0, i);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    return deck;
}

//Prints a single card in human-readable format
void print_card(Card c) {
    char* rank_text;
    switch (c.rank) {
        case 1:
            rank_text = "Ace";
            break;
        case 11:
            rank_text = "Jack";
            break;
        case 12:
            rank_text = "Queen";
            break;
        case 13:
            rank_text = "King";
            break;
        default:
            rank_text = malloc(sizeof(char) * 3);
            sprintf(rank_text, "%d", c.rank);
            break;
    }

    char* suit_text;
    switch (c.suit) {
        case 1:
            suit_text = "Clubs";
            break;
        case 2:
            suit_text = "Diamonds";
            break;
        case 3:
            suit_text = "Hearts";
            break;
        case 4:
            suit_text = "Spades";
            break;
    }

    printf("%s of %s\n", rank_text, suit_text);
}

//Prints a hand of cards
void print_hand(Hand h) {
    for(int i = 0; i < 5; i++) {
        print_card(h.cards[i]);
    }
}

//Counts the number of cards with the same rank in a hand
int count_rank(Hand h, int rank) {
    int count = 0;
    for(int i = 0; i < 5; i++) {
        if(h.cards[i].rank == rank) {
            count++;
        }
    }
    return count;
}

//Checks if a hand contains a flush (all cards have the same suit)
int is_flush(Hand h) {
    for(int i = 1; i < 5; i++) {
        if(h.cards[i].suit != h.cards[0].suit) {
            return 0;
        }
    }
    return 1;
}

//Checks if a hand contains a straight (all cards have consecutive ranks)
int is_straight(Hand h) {
    //Sort hand by rank
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(h.cards[j].rank < h.cards[i].rank) {
                Card temp = h.cards[i];
                h.cards[i] = h.cards[j];
                h.cards[j] = temp;
            }
        }
    }

    //Check if hand is sequential
    for(int i = 1; i < 5; i++) {
        if(h.cards[i].rank != h.cards[i-1].rank + 1) {
            return 0;
        }
    }

    return 1;
}

//Evaluates a hand and returns its rank
int evaluate_hand(Hand h) {
    int ranks[13] = {0};

    //Count number of each rank
    for(int i = 0; i < 5; i++) {
        ranks[h.cards[i].rank - 1]++;
    }

    //Check for flushes and straights
    int flush = is_flush(h);
    int straight = is_straight(h);

    //Royal Flush
    if(flush && straight && h.cards[0].rank == 1 && h.cards[4].rank == 13) {
        return 10;
    }

    //Straight Flush
    if(flush && straight) {
        return 9;
    }

    //Four of a Kind
    for(int i = 0; i < 13; i++) {
        if(ranks[i] == 4) {
            return 8;
        }
    }

    //Full House
    int has_three_of_a_kind = 0;
    int has_pair = 0;
    for(int i = 0; i < 13; i++) {
        if(ranks[i] == 3) {
            has_three_of_a_kind = 1;
        } else if(ranks[i] == 2) {
            has_pair = 1;
        }
    }

    if(has_three_of_a_kind && has_pair) {
        return 7;
    }

    //Flush
    if(flush) {
        return 6;
    }

    //Straight
    if(straight) {
        return 5;
    }

    //Three of a Kind
    for(int i = 0; i < 13; i++) {
        if(ranks[i] == 3) {
            return 4;
        }
    }

    //Two Pair
    int pair_count = 0;
    for(int i = 0; i < 13; i++) {
        if(ranks[i] == 2) {
            pair_count++;
        }
    }

    if(pair_count == 2) {
        return 3;
    }

    //One Pair
    if(has_pair) {
        return 2;
    }

    //High Card
    return 1;
}

int main() {
    srand(time(NULL));

    Card* deck = get_shuffled_deck();

    //Deal hands
    Hand player_hand;
    Hand dealer_hand;
    for(int i = 0; i < 5; i++) {
        player_hand.cards[i] = deck[i*2];
        dealer_hand.cards[i] = deck[i*2 + 1];
    }

    printf("Your Hand:\n");
    print_hand(player_hand);

    printf("Dealer Hand:\n");
    print_hand(dealer_hand);

    int player_rank = evaluate_hand(player_hand);
    int dealer_rank = evaluate_hand(dealer_hand);

    if(player_rank > dealer_rank) {
        printf("You win!\n");
    } else if(player_rank < dealer_rank) {
        printf("You lose.\n");
    } else {
        printf("Tie game.\n");
    }

    return 0;
}