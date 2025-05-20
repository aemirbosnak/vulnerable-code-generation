//FormAI DATASET v1.0 Category: Poker Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

/* Card structure */
typedef struct {
    char* suit;
    char* face;
    int value;
} Card;

/* Hand structure */
typedef struct {
    Card* cards[HAND_SIZE];
} Hand;

/* Deck structure */
typedef struct {
    Card* cards[DECK_SIZE];
    int current_index;
} Deck;

/* Initialize the deck */
void init_deck(Deck* deck) {
    char* suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    char* faces[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int index = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card* card = (Card*)malloc(sizeof(Card));
            card->suit = suits[i];
            card->face = faces[j];
            card->value = values[j];
            deck->cards[index] = card;
            index++;
        }
    }
    deck->current_index = 0;
}

/* Shuffle the deck */
void shuffle_deck(Deck* deck) {
    srand(time(0));
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card* temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

/* Get the next card */
Card* get_card(Deck* deck) {
    Card* card = deck->cards[deck->current_index];
    deck->current_index++;
    return card;
}

/* Initialize the hand */
void init_hand(Hand* hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = NULL;
    }
}

/* Add a card to the hand */
void add_card_to_hand(Hand* hand, Card* card) {
    for(int i = 0; i < HAND_SIZE; i++) {
        if(hand->cards[i] == NULL) {
            hand->cards[i] = card;
            break;
        }
    }
}

/* Calculate the hand value */
int calculate_hand_value(Hand* hand) {
    int total_value = 0;
    int num_aces = 0;
    for(int i = 0; i < HAND_SIZE; i++) {
        Card* card = hand->cards[i];
        if(card != NULL) {
            total_value += card->value;
            if(card->value == 11) {
                num_aces++;
            }
        }
    }
    while(num_aces > 0 && total_value > 21) {
        total_value -= 10;
        num_aces--;
    }
    return total_value;
}

/* Print the hand */
void print_hand(Hand* hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        Card* card = hand->cards[i];
        if(card != NULL) {
            printf("%s of %s\n", card->face, card->suit);
        }
    }
}

/* Play a round of poker */
void play_round() {
    Deck deck;
    Hand player_hand;
    Hand dealer_hand;
    init_deck(&deck);
    shuffle_deck(&deck);
    init_hand(&player_hand);
    init_hand(&dealer_hand);
    add_card_to_hand(&player_hand, get_card(&deck));
    add_card_to_hand(&dealer_hand, get_card(&deck));
    add_card_to_hand(&player_hand, get_card(&deck));
    add_card_to_hand(&dealer_hand, get_card(&deck));
    printf("Your hand:\n");
    print_hand(&player_hand);
    printf("Dealer's hand:\n");
    printf("Unknown card\n");
    Card* dealer_second_card = dealer_hand.cards[1];
    int player_total_value = calculate_hand_value(&player_hand);
    int dealer_total_value = dealer_second_card->value;
    while(player_total_value < 21) {
        char hit_or_stand;
        printf("Hit or stand? (h/s)\n");
        scanf(" %c", &hit_or_stand);
        if(hit_or_stand == 'h') {
            add_card_to_hand(&player_hand, get_card(&deck));
            printf("Your hand:\n");
            print_hand(&player_hand);
            player_total_value = calculate_hand_value(&player_hand);
        } else {
            printf("Your hand:\n");
            print_hand(&player_hand);
            break;
        }
    }
    if(player_total_value > 21) {
        printf("Bust! Dealer wins.\n");
        return;
    }
    printf("Dealer's hand:\n");
    print_hand(&dealer_hand);
    dealer_total_value += calculate_hand_value(&dealer_hand);
    if(dealer_total_value < 17) {
        while(dealer_total_value < 17) {
            add_card_to_hand(&dealer_hand, get_card(&deck));
            dealer_total_value += calculate_hand_value(&dealer_hand);
        }
        printf("Dealer's final hand:\n");
        print_hand(&dealer_hand);
    }
    if(dealer_total_value > 21) {
        printf("Dealer busts! You win.\n");
        return;
    }
    if(player_total_value > dealer_total_value) {
        printf("You win!\n");
    } else if(player_total_value == dealer_total_value) {
        printf("Push.\n");
    } else {
        printf("Dealer wins.\n");
    }
}

/* Main function */
int main() {
    printf("Welcome to Poker!\n");
    char play_again = 'y';
    while(play_again == 'y') {
        play_round();
        printf("Play again? (y/n)\n");
        scanf(" %c", &play_again);
    }
    return 0;
}