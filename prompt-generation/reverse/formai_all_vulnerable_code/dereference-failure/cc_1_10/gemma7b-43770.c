//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDLES 5
#define MAX_PILES 3

typedef struct Candle {
  int burning;
  struct Candle* next;
} Candle;

typedef struct Pile {
  int numCandles;
  struct Pile* next;
} Pile;

Candle* createCandle(int burning) {
  Candle* candle = malloc(sizeof(Candle));
  candle->burning = burning;
  candle->next = NULL;
  return candle;
}

Pile* createPile(int numCandles) {
  Pile* pile = malloc(sizeof(Pile));
  pile->numCandles = numCandles;
  pile->next = NULL;
  return pile;
}

int main() {
  // Create a list of candles
  Candle* head = createCandle(1);
  head->next = createCandle(2);
  head->next->next = createCandle(3);
  head->next->next->next = createCandle(4);
  head->next->next->next->next = createCandle(5);

  // Create a list of piles
  Pile* tail = createPile(3);
  tail->next = createPile(2);
  tail->next->next = createPile(1);

  // Play the game
  int round = 0;
  while (!head->next || tail->numCandles) {
    // Light a candle
    Candle* candle = head;
    while (candle->burning) {
      candle = candle->next;
    }
    candle->burning = 1;

    // Blow out a candle
    Pile* pile = tail;
    while (pile->numCandles) {
      if (pile->numCandles == 1) {
        pile->numCandles = 0;
      } else {
        pile->numCandles--;
      }
      pile = pile->next;
    }

    // Increment the round
    round++;

    // Print the round number
    printf("Round %d:\n", round);

    // Print the remaining candles
    candle = head;
    while (candle) {
      printf("  Candle: %d (%s)\n", candle->burning, candle->burning ? "Burning" : "Not Burning");
      candle = candle->next;
    }

    // Print the remaining piles
    pile = tail;
    while (pile) {
      printf("  Pile: %d Candles\n", pile->numCandles);
      pile = pile->next;
    }
  }

  return 0;
}