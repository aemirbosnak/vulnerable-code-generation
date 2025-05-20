//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2

typedef struct {
    char suit[9]; // Char array for suits: Hearts, Diamonds, Clubs, Spades
    char value[3]; // Char array for values: 2-10, J, Q, K, A
} Card;

typedef struct {
    Card* hand;
    int hand_size;
} Player;

Card* deck;
Player players[NUM_PLAYERS];
int top_card_index;

void create_deck() {
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    deck = (Card*)malloc(NUM_CARDS * sizeof(Card));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(deck[i * 13 + j].suit, suits[i]);
            strcpy(deck[i * 13 + j].value, values[j]);
        }
    }
    top_card_index = 0;
}

void shuffle_deck() {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

Card deal_card() {
    if (top_card_index >= NUM_CARDS) {
        printf("No more cards in the deck.\n");
        exit(1);
    }
    return deck[top_card_index++];
}

void initialize_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].hand = (Card*)malloc(5 * sizeof(Card)); // Each player can have up to 5 cards
        players[i].hand_size = 0;
    }
}

void free_memory() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        free(players[i].hand);
    }
    free(deck);
}

void display_hand(Player player) {
    for (int i = 0; i < player.hand_size; i++) {
        printf("%s of %s\n", player.hand[i].value, player.hand[i].suit);
    }
}

int calculate_score(Player player) {
    int score = 0;
    for (int i = 0; i < player.hand_size; i++) {
        if (strcmp(player.hand[i].value, "J") == 0 || strcmp(player.hand[i].value, "Q") == 0 || strcmp(player.hand[i].value, "K") == 0) {
            score += 10;
        } else if (strcmp(player.hand[i].value, "A") == 0) {
            score += 11; // Simplified for Ace. Could be 1 or 11 depending on other cards.
        } else {
            score += atoi(player.hand[i].value);
        }
    }
    return score;
}

void play_game() {
    for (int round = 0; round < 5; round++) { // 5 rounds of drawing cards
        for (int i = 0; i < NUM_PLAYERS; i++) {
            players[i].hand[players[i].hand_size++] = deal_card();
            printf("Player %d's hand after round %d:\n", i + 1, round + 1);
            display_hand(players[i]);
        }
        printf("\n");
    }

    int player1_score = calculate_score(players[0]);
    int player2_score = calculate_score(players[1]);

    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);

    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    srand(time(NULL));
    create_deck();
    shuffle_deck();
    initialize_players();
    
    printf("Welcome to the Poker Game!\n");
    play_game();
    
    free_memory();
    return 0;
}