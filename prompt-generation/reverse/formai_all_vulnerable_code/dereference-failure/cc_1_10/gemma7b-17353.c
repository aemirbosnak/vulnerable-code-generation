//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char **oracle_cards = NULL;
  int num_cards = 0;
  int fortune_num = 0;
  int i = 0;

  oracle_cards = malloc(sizeof(char *) * 5);
  for (i = 0; i < 5; i++) {
    oracle_cards[i] = malloc(sizeof(char) * 20);
  }

  num_cards = generate_oracle_cards(oracle_cards);
  fortune_num = predict_fortune(oracle_cards, num_cards);

  printf("Your fortune is: %d", fortune_num);

  free(oracle_cards);

  return 0;
}

int generate_oracle_cards(char **cards) {
  int num_cards = 0;

  cards = malloc(sizeof(char *) * 5);
  for (int i = 0; i < 5; i++) {
    cards[i] = malloc(sizeof(char) * 20);
  }

  srand(time(NULL));

  for (int i = 0; i < 5; i++) {
    cards[i][0] = 'A' + rand() % 26;
    cards[i][1] = rand() % 10 + '0';
  }

  num_cards = 5;

  return num_cards;
}

int predict_fortune(char **cards, int num_cards) {
  int fortune_num = 0;

  for (int i = 0; i < num_cards; i++) {
    fortune_num += cards[i][0] - 'A' + cards[i][1] - '0';
  }

  fortune_num %= 3;

  return fortune_num;
}