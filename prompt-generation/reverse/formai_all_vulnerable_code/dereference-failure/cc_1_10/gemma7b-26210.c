//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int marked[MAX_NUM];
  int cards_drawn;
  struct BingoCard* next;
} BingoCard;

BingoCard* create_bingo_card() {
  BingoCard* card = malloc(sizeof(BingoCard));
  card->numbers[0] = -1;
  card->marked[0] = -1;
  card->cards_drawn = 0;
  card->next = NULL;
  return card;
}

void draw_bingo_ball(BingoCard* card) {
  int number = rand() % MAX_NUM + 1;
  if (card->numbers[number] == -1) {
    card->numbers[number] = 1;
    card->cards_drawn++;
  }
}

void check_bingo(BingoCard* card) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->marked[i] == 1 && card->numbers[i] == 1) {
      printf("Bingo! You have won!\n");
      return;
    }
  }
  printf("No bingo. Try again.\n");
}

int main() {
  BingoCard* head = create_bingo_card();
  head->next = create_bingo_card();
  head->next->next = create_bingo_card();

  for (int i = 0; i < 10; i++) {
    draw_bingo_ball(head);
    check_bingo(head);
  }

  return 0;
}