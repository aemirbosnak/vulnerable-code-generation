//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_SIZE 100

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a list of 100 random words
  char *words[MAX_WORDS];
  for (int i = 0; i < MAX_WORDS; i++) {
    int word_length = rand() % MAX_WORD_SIZE + 1;
    words[i] = malloc(word_length + 1);
    for (int j = 0; j < word_length; j++) {
      words[i][j] = 'a' + (rand() % 26);
    }
    words[i][word_length] = '\0';
  }

  // Print the instructions
  printf("Welcome to the Retro Typing Speed Test!\n");
  printf("Type the words as they appear on the screen.\n");
  printf("Press any key to start.\n");
  getchar();

  // Start the timer
  clock_t start_time = clock();

  // Display the words one at a time
  for (int i = 0; i < MAX_WORDS; i++) {
    printf("%s ", words[i]);
  }

  // Stop the timer
  clock_t end_time = clock();

  // Calculate the typing speed
  float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;
  float words_per_minute = MAX_WORDS / time_taken;

  // Print the results
  printf("\nYour typing speed is %.2f words per minute.\n", words_per_minute);

  // Free the memory allocated for the words
  for (int i = 0; i < MAX_WORDS; i++) {
    free(words[i]);
  }

  return 0;
}