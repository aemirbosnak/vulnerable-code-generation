//FormAI DATASET v1.0 Category: Poker Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the deck of cards
char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Define the hand struct
struct Hand {
  char *cards[5];
};

// Function to generate a random card from the deck
char *get_card() {
  int suit = rand() % 4;
  int rank = rand() % 13;
  char *card = (char *) malloc(20 * sizeof(char));
  sprintf(card, "%s of %s", ranks[rank], suits[suit]);
  return card;
}

// Function to deal a hand of cards
void deal_hand(struct Hand *hand) {
  for (int i = 0; i < 5; i++) {
    hand->cards[i] = get_card();
  }
}

// Function to print a hand of cards
void print_hand(struct Hand *hand) {
  for (int i = 0; i < 5; i++) {
    printf("%s\n", hand->cards[i]);
  }
}

// Function to determine the value of a hand
int hand_value(struct Hand *hand) {
  int value = 0;
  for (int i = 0; i < 5; i++) {
    char *card = hand->cards[i];
    char rank = card[strlen(card) - 3];
    switch (rank) {
      case 'A':
        value += 14;
        break;
      case 'K':
        value += 13;
        break;
      case 'Q':
        value += 12;
        break;
      case 'J':
        value += 11;
        break;
      case '1':
        value += 10;
        break;
      default:
        value += rank - '0';
    }
  }
  return value;
}

// Main function to play the game
int main() {
  srand(time(NULL));
  printf("Welcome to the C Poker Game!\n");
  printf("Dealing your hand...\n");
  struct Hand *hand = (struct Hand *) malloc(sizeof(struct Hand));
  deal_hand(hand);
  print_hand(hand);
  int value = hand_value(hand);
  printf("Your hand has a value of %d.\n", value);
  printf("Thanks for playing!\n");
  return 0;
}