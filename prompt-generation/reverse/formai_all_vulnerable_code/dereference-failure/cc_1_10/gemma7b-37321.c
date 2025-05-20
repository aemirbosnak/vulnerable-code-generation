//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <time.h>

int main() {

  // Define the number of words to be typed
  int num_words = 10;

  // Allocate memory for the words
  char **words = (char **)malloc(num_words * sizeof(char *));

  // Fill the words with random text
  for (int i = 0; i < num_words; i++) {
    words[i] = (char *)malloc(20 * sizeof(char));
    for (int j = 0; j < 20; j++) {
      words[i][j] = (rand() % 26) + 'a';
    }
  }

  // Start the timer
  clock_t start_time = clock();

  // Prompt the user to type the words
  for (int i = 0; i < num_words; i++) {
    printf("Type the following word: %s\n", words[i]);
    char user_word[20];
    scanf("%s", user_word);

    // Check if the user's word is correct
    if (strcmp(user_word, words[i]) == 0) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The correct word is: %s\n", words[i]);
    }
  }

  // Stop the timer
  clock_t end_time = clock();

  // Calculate the time taken to complete the test
  double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  // Print the results
  printf("Your typing speed is: %.2f words per second\n", (double)num_words / time_taken);

  // Free the memory allocated for the words
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  free(words);

  return 0;
}