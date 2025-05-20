//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int value;
    char suit;
} Card;

typedef struct {
    Card* cards;
    int size;
} Deck;

typedef struct {
    Deck* deck;
    int player1Score;
    int player2Score;
} Game;

void initDeck(Deck* deck) {
    deck->cards = (Card*) malloc(52 * sizeof(Card));
    deck->size = 52;
    for (int i = 0; i < 52; i++) {
        deck->cards[i].value = (rand() % 13) + 1;
        deck->cards[i].suit = (rand() % 4) + 1;
    }
}

void shuffleDeck(Deck* deck) {
    for (int i = 0; i < deck->size - 1; i++) {
        int j = rand() % (deck->size - i);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void printDeck(Deck* deck) {
    for (int i = 0; i < deck->size; i++) {
        printf("%d of %c\n", deck->cards[i].value, deck->cards[i].suit);
    }
}

void dealCard(Deck* deck, int* player1, int* player2) {
    (*player1)++;
    (*player2)++;
    Card card = deck->cards[(*player1)];
    deck->cards[(*player1)] = deck->cards[(*player2)];
    deck->cards[(*player2)] = card;
}

void dealCards(Deck* deck, Game* game) {
    game->player1Score = 0;
    game->player2Score = 0;
    int player1 = 0;
    int player2 = 0;
    while (game->player1Score < 5 || game->player2Score < 5) {
        dealCard(deck, &player1, &player2);
        dealCard(deck, &player1, &player2);
        dealCard(deck, &player1, &player2);
        dealCard(deck, &player1, &player2);
        dealCard(deck, &player1, &player2);
    }
}

int compareCards(Card* card1, Card* card2) {
    if (card1->value > card2->value) {
        return 1;
    } else if (card1->value < card2->value) {
        return -1;
    } else if (card1->suit > card2->suit) {
        return 1;
    } else if (card1->suit < card2->suit) {
        return -1;
    } else {
        return 0;
    }
}

int comparePlayers(Game* game) {
    for (int i = 0; i < 5; i++) {
        Card card1 = game->deck->cards[game->player1Score + i];
        Card card2 = game->deck->cards[game->player2Score + i];
        int result = compareCards(&card1, &card2);
        if (result == 1) {
            game->player1Score++;
        } else if (result == -1) {
            game->player2Score++;
        } else {
            game->player1Score = 0;
            game->player2Score = 0;
        }
    }
    return (game->player1Score > game->player2Score)? 1 : -1;
}

int main() {
    Deck deck;
    Game game;
    initDeck(&deck);
    shuffleDeck(&deck);
    printDeck(&deck);
    dealCards(&deck, &game);
    printf("Player 1 Score: %d\nPlayer 2 Score: %d\n", game.player1Score, game.player2Score);
    printf("Game result: %d\n", comparePlayers(&game));
    return 0;
}