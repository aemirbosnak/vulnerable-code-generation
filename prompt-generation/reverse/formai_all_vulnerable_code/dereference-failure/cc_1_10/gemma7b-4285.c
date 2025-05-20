//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
  time_t start, end;
  double seconds;
  int i, words, characters, speed;

  // Allocate memory for the text
  char *text = malloc(1000);

  // Get the start time
  start = time(NULL);

  // Prompt the user to enter text
  printf("Enter text: ");
  fgets(text, 1000, stdin);

  // Get the end time
  end = time(NULL);

  // Calculate the number of words and characters
  words = words_count(text);
  characters = characters_count(text);

  // Calculate the time taken in seconds
  seconds = (double)(end - start) / CLOCKS_PER_SEC;

  // Calculate the typing speed in characters per second
  speed = (characters / seconds) * 60;

  // Print the results
  printf("Number of words: %d\n", words);
  printf("Number of characters: %d\n", characters);
  printf("Time taken: %.2lf seconds\n", seconds);
  printf("Typing speed: %d characters per second\n", speed);

  // Free the memory allocated for the text
  free(text);

  return 0;
}

int words_count(char *text) {
  int words = 0;
  char *word = NULL;

  word = strtok(text, " \n\t");

  while (word) {
    words++;
    word = strtok(NULL, " \n\t");
  }

  return words;
}

int characters_count(char *text) {
  int characters = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    characters++;
  }

  return characters;
}