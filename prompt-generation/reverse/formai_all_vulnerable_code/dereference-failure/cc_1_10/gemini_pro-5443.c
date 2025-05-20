//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the suits and ranks
enum suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

// Define the card structure
struct card {
  enum suit suit;
  enum rank rank;
};

// Define the hand structure
struct hand {
  struct card cards[5];
};

// Create a new deck of cards
struct card *create_deck() {
  struct card *deck = malloc(sizeof(struct card) * 52);

  int i = 0;
  for (enum suit suit = HEARTS; suit <= SPADES; suit++) {
    for (enum rank rank = TWO; rank <= ACE; rank++) {
      deck[i].suit = suit;
      deck[i].rank = rank;
      i++;
    }
  }

  return deck;
}

// Shuffle the deck of cards
void shuffle_deck(struct card *deck) {
  srand(time(NULL));

  for (int i = 0; i < 52; i++) {
    int r = rand() % 52;

    struct card temp = deck[i];
    deck[i] = deck[r];
    deck[r] = temp;
  }
}

// Deal a hand of cards
void deal_hand(struct card *deck, struct hand *hand) {
  for (int i = 0; i < 5; i++) {
    hand->cards[i] = deck[i];
  }
}

// Evaluate a hand
int evaluate_hand(struct hand *hand) {
  // Check for a royal flush
  if (hand->cards[0].rank == ACE && hand->cards[1].rank == KING && hand->cards[2].rank == QUEEN && hand->cards[3].rank == JACK && hand->cards[4].rank == TEN && hand->cards[0].suit == hand->cards[1].suit && hand->cards[0].suit == hand->cards[2].suit && hand->cards[0].suit == hand->cards[3].suit && hand->cards[0].suit == hand->cards[4].suit) {
    return 10;
  }

  // Check for a straight flush
  if (hand->cards[0].rank == hand->cards[1].rank - 1 && hand->cards[0].rank == hand->cards[2].rank - 2 && hand->cards[0].rank == hand->cards[3].rank - 3 && hand->cards[0].rank == hand->cards[4].rank - 4 && hand->cards[0].suit == hand->cards[1].suit && hand->cards[0].suit == hand->cards[2].suit && hand->cards[0].suit == hand->cards[3].suit && hand->cards[0].suit == hand->cards[4].suit) {
    return 9;
  }

  // Check for a four of a kind
  if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[0].rank == hand->cards[2].rank && hand->cards[0].rank == hand->cards[3].rank) {
    return 8;
  }

  // Check for a full house
  if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[0].rank == hand->cards[2].rank && hand->cards[3].rank == hand->cards[4].rank) {
    return 7;
  }

  // Check for a flush
  if (hand->cards[0].suit == hand->cards[1].suit && hand->cards[0].suit == hand->cards[2].suit && hand->cards[0].suit == hand->cards[3].suit && hand->cards[0].suit == hand->cards[4].suit) {
    return 6;
  }

  // Check for a straight
  if (hand->cards[0].rank == hand->cards[1].rank - 1 && hand->cards[0].rank == hand->cards[2].rank - 2 && hand->cards[0].rank == hand->cards[3].rank - 3 && hand->cards[0].rank == hand->cards[4].rank - 4) {
    return 5;
  }

  // Check for a three of a kind
  if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[0].rank == hand->cards[2].rank) {
    return 4;
  }

  // Check for two pair
  if (hand->cards[0].rank == hand->cards[1].rank && hand->cards[2].rank == hand->cards[3].rank) {
    return 3;
  }

  // Check for one pair
  if (hand->cards[0].rank == hand->cards[1].rank) {
    return 2;
  }

  // Otherwise, it's a high card
  return 1;
}

// Print a hand
void print_hand(struct hand *hand) {
  for (int i = 0; i < 5; i++) {
    switch (hand->cards[i].rank) {
      case TWO:
        printf("Two of ");
        break;
      case THREE:
        printf("Three of ");
        break;
      case FOUR:
        printf("Four of ");
        break;
      case FIVE:
        printf("Five of ");
        break;
      case SIX:
        printf("Six of ");
        break;
      case SEVEN:
        printf("Seven of ");
        break;
      case EIGHT:
        printf("Eight of ");
        break;
      case NINE:
        printf("Nine of ");
        break;
      case TEN:
        printf("Ten of ");
        break;
      case JACK:
        printf("Jack of ");
        break;
      case QUEEN:
        printf("Queen of ");
        break;
      case KING:
        printf("King of ");
        break;
      case ACE:
        printf("Ace of ");
        break;
    }

    switch (hand->cards[i].suit) {
      case HEARTS:
        printf("Hearts\n");
        break;
      case DIAMONDS:
        printf("Diamonds\n");
        break;
      case CLUBS:
        printf("Clubs\n");
        break;
      case SPADES:
        printf("Spades\n");
        break;
    }
  }
}

// Compare two hands
int compare_hands(struct hand *hand1, struct hand *hand2) {
  int hand1_value = evaluate_hand(hand1);
  int hand2_value = evaluate_hand(hand2);

  if (hand1_value > hand2_value) {
    return 1;
  } else if (hand1_value < hand2_value) {
    return -1;
  } else {
    return 0;
  }
}

// Play a game of poker
void play_poker() {
  // Create a deck of cards
  struct card *deck = create_deck();

  // Shuffle the deck
  shuffle_deck(deck);

  // Deal two hands
  struct hand hand1;
  struct hand hand2;
  deal_hand(deck, &hand1);
  deal_hand(deck, &hand2);

  // Print the hands
  printf("Player 1's hand:\n");
  print_hand(&hand1);
  printf("Player 2's hand:\n");
  print_hand(&hand2);

  // Compare the hands
  int result = compare_hands(&hand1, &hand2);

  // Print the result
  if (result == 1) {
    printf("Player 1 wins!\n");
  } else if (result == -1) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  // Free the deck of cards
  free(deck);
}

int main() {
  play_poker();

  return 0;
}