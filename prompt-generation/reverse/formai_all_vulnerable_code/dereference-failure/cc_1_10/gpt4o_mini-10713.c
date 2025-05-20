//GPT-4o-mini DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_CARDS 52
#define HAND_SIZE 5
#define NUM_PLAYERS 2
#define MAX_NAME_LEN 30

typedef struct {
    char *name;
    int *hand;
} Player;

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

void initializeDeck(int *deck);
void shuffleDeck(int *deck);
void dealCards(int *deck, Player *players);
void displayHand(Player player);
int evaluateHand(int *hand);
void displayResult(Player *players);
void cleanExit(Player *players);

int main() {
    srand(time(NULL));  // Seed the random number generator

    Player players[NUM_PLAYERS];
    
    // Initializing players
    for(int i = 0; i < NUM_PLAYERS; i++) {
        players[i].name = (char *)malloc(MAX_NAME_LEN * sizeof(char));
        printf("Enter player %d name: ", i + 1);
        fgets(players[i].name, MAX_NAME_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove trailing newline
        players[i].hand = (int *)malloc(HAND_SIZE * sizeof(int));
    }

    int deck[NUM_CARDS];
    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, players);
    
    printf("\n--- Player Hands ---\n");
    for(int i = 0; i < NUM_PLAYERS; i++) {
        displayHand(players[i]);
    }

    displayResult(players);

    cleanExit(players);
    return 0;
}

void initializeDeck(int *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
}

void shuffleDeck(int *deck) {
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(int *deck, Player *players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[i * HAND_SIZE + j];
        }
    }
}

void displayHand(Player player) {
    printf("%s's hand: ", player.name);
    for (int i = 0; i < HAND_SIZE; i++) {
        int card = player.hand[i];
        printf("%s of %s, ", ranks[card % 13], suits[card / 13]);
    }
    printf("\n");
}

int evaluateHand(int *hand) {
    // Simplistic evaluation: higher card values are better.
    int highest = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        highest = (hand[i] % 13 > highest) ? (hand[i] % 13) : highest;
    }
    return highest;
}

void displayResult(Player *players) {
    int highestScore = -1;
    int winnerIndex = -1;
    
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int score = evaluateHand(players[i].hand);
        printf("%s has score: %d\n", players[i].name, score);
        if (score > highestScore) {
            highestScore = score;
            winnerIndex = i;
        }
    }
    
    printf("The winner is: %s!\n", players[winnerIndex].name);
}

void cleanExit(Player *players) {
    for(int i = 0; i < NUM_PLAYERS; i++) {
        free(players[i].name);
        free(players[i].hand);
    }
}