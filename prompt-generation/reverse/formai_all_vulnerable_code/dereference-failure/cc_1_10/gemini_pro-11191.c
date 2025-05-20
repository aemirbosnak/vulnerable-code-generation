//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the bingo card size and the number of rows and columns. */
#define BINGO_CARD_SIZE 5
#define BINGO_ROWS 5
#define BINGO_COLS 5

/* Define the bingo ball range (1-75). */
#define BINGO_BALL_MIN 1
#define BINGO_BALL_MAX 75

/* Define the bingo card data structure. */
typedef struct bingo_card {
  int numbers[BINGO_CARD_SIZE][BINGO_CARD_SIZE];
  int marked[BINGO_CARD_SIZE][BINGO_CARD_SIZE];
} bingo_card;

/* Create a new bingo card. */
bingo_card *create_bingo_card() {
  bingo_card *card = (bingo_card *)malloc(sizeof(bingo_card));
  if (!card) {
    return NULL;
  }

  /* Initialize the bingo card with random numbers. */
  for (int i = 0; i < BINGO_ROWS; i++) {
    for (int j = 0; j < BINGO_COLS; j++) {
      card->numbers[i][j] = rand() % (BINGO_BALL_MAX - BINGO_BALL_MIN + 1) + BINGO_BALL_MIN;
    }
  }

  /* Initialize the bingo card with unmarked numbers. */
  for (int i = 0; i < BINGO_ROWS; i++) {
    for (int j = 0; j < BINGO_COLS; j++) {
      card->marked[i][j] = 0;
    }
  }

  return card;
}

/* Print the bingo card. */
void print_bingo_card(bingo_card *card) {
  for (int i = 0; i < BINGO_ROWS; i++) {
    for (int j = 0; j < BINGO_COLS; j++) {
      printf("%d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

/* Check if the bingo card has won. */
int check_bingo_card(bingo_card *card) {
  /* Check for horizontal wins. */
  for (int i = 0; i < BINGO_ROWS; i++) {
    int count = 0;
    for (int j = 0; j < BINGO_COLS; j++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == BINGO_CARD_SIZE) {
      return 1;
    }
  }

  /* Check for vertical wins. */
  for (int j = 0; j < BINGO_COLS; j++) {
    int count = 0;
    for (int i = 0; i < BINGO_ROWS; i++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == BINGO_CARD_SIZE) {
      return 1;
    }
  }

  /* Check for diagonal wins. */
  int count = 0;
  for (int i = 0; i < BINGO_ROWS; i++) {
    if (card->marked[i][i]) {
      count++;
    }
  }
  if (count == BINGO_CARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < BINGO_ROWS; i++) {
    if (card->marked[i][BINGO_COLS - i - 1]) {
      count++;
    }
  }
  if (count == BINGO_CARD_SIZE) {
    return 1;
  }

  return 0;
}

/* Play the bingo game. */
int play_bingo() {
  /* Create a new bingo card. */
  bingo_card *card = create_bingo_card();

  /* Print the bingo card. */
  print_bingo_card(card);

  /* Get the bingo balls. */
  int balls[BINGO_BALL_MAX - BINGO_BALL_MIN + 1];
  for (int i = 0; i < BINGO_BALL_MAX - BINGO_BALL_MIN + 1; i++) {
    balls[i] = i + BINGO_BALL_MIN;
  }

  /* Shuffle the bingo balls. */
  for (int i = 0; i < BINGO_BALL_MAX - BINGO_BALL_MIN + 1; i++) {
    int j = rand() % (BINGO_BALL_MAX - BINGO_BALL_MIN + 1);
    int temp = balls[i];
    balls[i] = balls[j];
    balls[j] = temp;
  }

  /* Draw the bingo balls and mark the bingo card. */
  for (int i = 0; i < BINGO_BALL_MAX - BINGO_BALL_MIN + 1; i++) {
    /* Get the next bingo ball. */
    int ball = balls[i];

    /* Mark the bingo card. */
    for (int j = 0; j < BINGO_ROWS; j++) {
      for (int k = 0; k < BINGO_COLS; k++) {
        if (card->numbers[j][k] == ball) {
          card->marked[j][k] = 1;
        }
      }
    }

    /* Print the bingo card. */
    print_bingo_card(card);

    /* Check if the bingo card has won. */
    if (check_bingo_card(card)) {
      printf("Bingo!\n");
      return 0;
    }
  }

  printf("No winner.\n");
  return 1;
}

/* Main function. */
int main() {
  /* Initialize the random number generator. */
  srand(time(NULL));

  /* Play the bingo game. */
  play_bingo();

  return 0;
}