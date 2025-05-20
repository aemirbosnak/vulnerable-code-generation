//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

// Function to generate a random number between min and max
int random_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to check if a number is in an array
int in_array(int num, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == num) {
      return 1;
    }
  }
  return 0;
}

// Function to print a bingo card
void print_card(int **card, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }
}

// Function to play a game of bingo
void play_bingo(int **card, int size) {
  int numbers[BINGO_SIZE * BINGO_SIZE];
  int drawn_numbers[BINGO_SIZE * BINGO_SIZE];
  int drawn_count = 0;

  // Initialize the numbers array
  for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
    numbers[i] = i + 1;
  }

  // Initialize the drawn_numbers array
  for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
    drawn_numbers[i] = -1;
  }

  // Start the game
  while (drawn_count < BINGO_SIZE * BINGO_SIZE) {
    // Draw a random number
    int num = random_range(1, BINGO_SIZE * BINGO_SIZE);

    // Check if the number has already been drawn
    if (!in_array(num, drawn_numbers, drawn_count)) {
      // Mark the number as drawn
      drawn_numbers[drawn_count] = num;
      drawn_count++;

      // Check if the number is on the player's card
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if (card[i][j] == num) {
            // Mark the number on the player's card as drawn
            card[i][j] = -1;

            // Check if the player has won
            if (check_win(card, size)) {
              printf("You win!\n");
              return;
            }
          }
        }
      }
    }
  }

  // The player did not win
  printf("You lose!\n");
}

// Function to check if a player has won
int check_win(int **card, int size) {
  int win = 1;

  // Check rows
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (card[i][j] == -1) {
        count++;
      }
    }
    if (count != size) {
      win = 0;
    }
  }

  // Check columns
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (card[j][i] == -1) {
        count++;
      }
    }
    if (count != size) {
      win = 0;
    }
  }

  // Check diagonals
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < size; i++) {
    if (card[i][i] == -1) {
      count1++;
    }
    if (card[i][size - i - 1] == -1) {
      count2++;
    }
  }
  if (count1 != size && count2 != size) {
    win = 0;
  }

  return win;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a bingo card
  int **card = (int **)malloc(BINGO_SIZE * sizeof(int *));
  for (int i = 0; i < BINGO_SIZE; i++) {
    card[i] = (int *)malloc(BINGO_SIZE * sizeof(int));
  }

  // Generate the bingo card
  for (int i = 0; i < BINGO_SIZE; i++) {
    for (int j = 0; j < BINGO_SIZE; j++) {
      card[i][j] = random_range(1, BINGO_SIZE * BINGO_SIZE);
    }
  }

  // Print the bingo card
  printf("Your bingo card:\n");
  print_card(card, BINGO_SIZE);

  // Play the game
  play_bingo(card, BINGO_SIZE);

  // Free the memory allocated for the bingo card
  for (int i = 0; i < BINGO_SIZE; i++) {
    free(card[i]);
  }
  free(card);

  return 0;
}