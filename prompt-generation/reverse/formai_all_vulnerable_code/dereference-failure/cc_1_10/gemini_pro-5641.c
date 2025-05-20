//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 4

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
} Deck;

typedef struct {
    Card cards[MAX_CARDS];
    int num_cards;
} Hand;

typedef struct {
    char name[20];
    Hand hand;
} Player;

// Function to create a new deck of cards
Deck* create_deck() {
    Deck* deck = malloc(sizeof(Deck));
    deck->num_cards = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 2; j <= 14; j++) {
            Card card;
            card.value = j;
            card.suit = "SHDC"[i];
            deck->cards[deck->num_cards++] = card;
        }
    }

    return deck;
}

// Function to shuffle a deck of cards
void shuffle_deck(Deck* deck) {
    for (int i = 0; i < deck->num_cards; i++) {
        int j = rand() % deck->num_cards;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Function to deal a hand of cards to a player
void deal_hand(Deck* deck, Hand* hand, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        hand->cards[hand->num_cards++] = deck->cards[deck->num_cards--];
    }
}

// Function to print a card
void print_card(Card card) {
    switch (card.value) {
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        case 14:
            printf("Ace");
            break;
        default:
            printf("%d", card.value);
    }
    printf(" of %c", card.suit);
}

// Function to print a hand of cards
void print_hand(Hand hand) {
    for (int i = 0; i < hand.num_cards; i++) {
        print_card(hand.cards[i]);
        printf(" ");
    }
    printf("\n");
}

// Function to get the value of a card
int get_card_value(Card card) {
    switch (card.value) {
        case 11:
        case 12:
        case 13:
            return 10;
        case 14:
            return 11;
        default:
            return card.value;
    }
}

// Function to get the score of a hand
int get_hand_score(Hand hand) {
    int score = 0;
    int num_aces = 0;

    for (int i = 0; i < hand.num_cards; i++) {
        int card_value = get_card_value(hand.cards[i]);
        score += card_value;
        if (card_value == 11) {
            num_aces++;
        }
    }

    // Adjust the score for aces
    while (num_aces > 0 && score > 21) {
        score -= 10;
        num_aces--;
    }

    return score;
}

// Function to check if a hand is a blackjack
int is_blackjack(Hand hand) {
    return hand.num_cards == 2 && get_hand_score(hand) == 21;
}

// Function to check if a hand is a bust
int is_bust(Hand hand) {
    return get_hand_score(hand) > 21;
}

// Function to play a round of blackjack
void play_round(Deck* deck, Player* players, int num_players) {
    // Deal two cards to each player
    for (int i = 0; i < num_players; i++) {
        deal_hand(deck, &players[i].hand, 2);
    }

    // Print the dealer's hand
    printf("Dealer's hand: ");
    print_card(players[0].hand.cards[0]);
    printf(" [hidden]\n");

    // Get the player's actions
    for (int i = 1; i < num_players; i++) {
        printf("%s's hand: ", players[i].name);
        print_hand(players[i].hand);

        while (1) {
            printf("Hit (h) or stand (s)? ");
            char action;
            scanf(" %c", &action);

            if (action == 'h') {
                // Deal a card to the player
                deal_hand(deck, &players[i].hand, 1);
                print_card(players[i].hand.cards[players[i].hand.num_cards - 1]);
                printf("\n");
            } else if (action == 's') {
                // The player stands
                break;
            } else {
                // Invalid action
                printf("Invalid action. Please enter h or s.\n");
            }

            // Check if the player is bust
            if (is_bust(players[i].hand)) {
                printf("%s busts!\n", players[i].name);
                break;
            }
        }
    }

    // Reveal the dealer's hidden card
    printf("Dealer's hand: ");
    print_hand(players[0].hand);

    // Get the dealer's action
    while (get_hand_score(players[0].hand) < 17) {
        // Deal a card to the dealer
        deal_hand(deck, &players[0].hand, 1);
        print_card(players[0].hand.cards[players[0].hand.num_cards - 1]);
        printf("\n");
    }

    // Check if the dealer is bust
    if (is_bust(players[0].hand)) {
        printf("Dealer busts!\n");
    }

    // Determine the winner
    int winning_score = 0;
    for (int i = 0; i < num_players; i++) {
        int hand_score = get_hand_score(players[i].hand);
        if (hand_score > winning_score && hand_score <= 21) {
            winning_score = hand_score;
        }
    }

    for (int i = 0; i < num_players; i++) {
        int hand_score = get_hand_score(players[i].hand);
        if (hand_score == winning_score) {
            printf("%s wins!\n", players[i].name);
        } else if (is_bust(players[i].hand)) {
            printf("%s busts!\n", players[i].name);
        } else {
            printf("%s loses!\n", players[i].name);
        }
    }
}

// Function to play the game
void play_game() {
    // Create a deck of cards
    Deck* deck = create_deck();

    // Shuffle the deck
    shuffle_deck(deck);

    // Get the number of players
    int num_players;
    printf("Enter the number of players (2-4): ");
    scanf("%d", &num_players);

    // Create the players
    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Play multiple rounds
    while (1) {
        play_round(deck, players, num_players);

        // Check if the player wants to play another round
        printf("Play another round (y/n)? ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'n') {
            break;
        }
    }

    // Free the deck
    free(deck);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}