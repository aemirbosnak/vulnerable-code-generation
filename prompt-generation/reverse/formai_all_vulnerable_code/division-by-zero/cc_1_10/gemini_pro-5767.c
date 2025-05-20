//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int words_per_minute = 0;
  int characters_per_minute = 0;
  int errors = 0;
  int start_time = time(NULL);
  int end_time = 0;
  int test_duration;
  char input[1000];
  char test_text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  // Print instructions
  printf("Typing Speed Test\n");
  printf("Instructions:\n");
  printf("1. Type the following text as accurately and quickly as possible:\n");
  printf("%s\n", test_text);
  printf("2. Press Enter when you have finished typing.\n");

  // Get input from user
  printf("\nType the text above: ");
  fgets(input, sizeof(input), stdin);

  // Calculate end time and test duration
  end_time = time(NULL);
  test_duration = end_time - start_time;

  // Count words and characters
  int words = 0;
  int characters = 0;
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      words++;
    } else {
      characters++;
    }
  }

  // Calculate words per minute and characters per minute
  words_per_minute = (words / test_duration) * 60;
  characters_per_minute = (characters / test_duration) * 60;

  // Calculate errors
  errors = strlen(test_text) - strlen(input);

  // Print results
  printf("\nResults:\n");
  printf("Words per minute: %d\n", words_per_minute);
  printf("Characters per minute: %d\n", characters_per_minute);
  printf("Errors: %d\n", errors);

  return 0;
}