//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MIN_NUM 1
#define MAX_NUM 6
#define MAX_ROUNDS 10

typedef enum {
  PLAYER_ONE,
  PLAYER_TWO,
  TIE,
  INVALID
} player_t;

typedef struct {
  int value;
  bool hidden;
} card_t;

typedef struct {
  card_t *cards;
  int num_cards;
} player_hand_t;

void print_card(card_t card) {
  printf("%s%d", card.hidden ? "[]" : "", card.value);
}

void print_hand(player_hand_t hand) {
  for (int i = 0; i < hand.num_cards; i++) {
    print_card(hand.cards[i]);
    printf(" ");
  }
  printf("\n");
}

int roll_dice() {
  return MIN_NUM + (rand() % (MAX_NUM - MIN_NUM));
}

player_t check_winner(player_hand_t hand1, player_hand_t hand2) {
  int sum1 = 0;
  int sum2 = 0;

  for (int i = 0; i < hand1.num_cards; i++) {
    sum1 += hand1.cards[i].value;
  }

  for (int i = 0; i < hand2.num_cards; i++) {
    sum2 += hand2.cards[i].value;
  }

  if (sum1 == sum2) {
    return TIE;
  } else if (sum1 > sum2) {
    return PLAYER_ONE;
  } else {
    return PLAYER_TWO;
  }
}

int main() {
  srand(time(NULL));

  player_hand_t player1_hand;
  player_hand_t player2_hand;

  player1_hand.cards = malloc(sizeof(card_t) * MAX_ROUNDS);
  player1_hand.num_cards = 0;

  player2_hand.cards = malloc(sizeof(card_t) * MAX_ROUNDS);
  player2_hand.num_cards = 0;

  bool game_over = false;
  int round = 1;

  while (!game_over && round <= MAX_ROUNDS) {
    printf("Round %d\n", round);

    // Player 1's turn
    printf("Player 1's turn:\n");
    card_t card;
    card.value = roll_dice();
    card.hidden = true;
    player1_hand.cards[player1_hand.num_cards++] = card;
    print_hand(player1_hand);

    // Player 2's turn
    printf("Player 2's turn:\n");
    card.value = roll_dice();
    card.hidden = true;
    player2_hand.cards[player2_hand.num_cards++] = card;
    print_hand(player2_hand);

    // Check winner
    player_t winner = check_winner(player1_hand, player2_hand);
    if (winner != INVALID) {
      game_over = true;

      if (winner == TIE) {
        printf("Tie!\n");
      } else if (winner == PLAYER_ONE) {
        printf("Player 1 wins!\n");
      } else if (winner == PLAYER_TWO) {
        printf("Player 2 wins!\n");
      }
    }

    round++;
  }

  if (!game_over) {
    printf("No winner after %d rounds. It's a draw!\n", MAX_ROUNDS);
  }

  free(player1_hand.cards);
  free(player2_hand.cards);

  return 0;
}