//FormAI DATASET v1.0 Category: Poker Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define card structs
typedef struct card {
    char *suit;
    char *face;
    int value;
} Card;

// Define player struct
typedef struct player {
    char name[50];
    Card hand[5];
    int score;
} Player;

// Function to create deck of cards
Card *createDeck() {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faces[] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
    
    Card *deck = malloc(sizeof(Card) * 52);
    
    int i, j, k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[k].suit = suits[i];
            deck[k].face = faces[j];
            if (j == 0) {
                deck[k].value = 11;
            } else if (j >= 9) {
                deck[k].value = 10;
            } else {
                deck[k].value = j + 1;
            }
            k++;
        }
    }
    
    return deck;
}

// Function to shuffle deck of cards
void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards to player
void dealCards(Card *deck, Player *player) {
    int i;
    for (i = 0; i < 5; i++) {
        player->hand[i] = *deck;
        deck++;
    }
}

// Function to print player's hand
void printHand(Player *player) {
    int i;
    printf("%s's hand:\n", player->name);
    for (i = 0; i < 5; i++) {
        printf("%s of %s\n", player->hand[i].face, player->hand[i].suit);
    }
}

// Function to determine winner
void determineWinner(Player *player1, Player *player2) {
    if (player1->score > player2->score) {
        printf("%s wins!\n", player1->name);
    } else {
        printf("%s wins!\n", player2->name);
    }
}

// Main function
int main() {
    srand(time(NULL));
    
    Card *deck = createDeck();
    shuffleDeck(deck);
    
    Player player1, player2;
    printf("Enter player 1's name: ");
    fgets(player1.name, 50, stdin);
    printf("Enter player 2's name: ");
    fgets(player2.name, 50, stdin);
    player1.name[strcspn(player1.name, "\n")] = 0;
    player2.name[strcspn(player2.name, "\n")] = 0;
    
    dealCards(deck, &player1);
    dealCards(deck, &player2);
    
    printHand(&player1);
    printHand(&player2);
    
    int i;
    for (i = 0; i < 5; i++) {
        player1.score += player1.hand[i].value;
        player2.score += player2.hand[i].value;
    }
    
    determineWinner(&player1, &player2);
    
    free(deck);
    
    return 0;
}