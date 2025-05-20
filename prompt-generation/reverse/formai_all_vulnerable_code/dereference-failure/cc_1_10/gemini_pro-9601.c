//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Function to generate a random word
char *generate_word() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random word length
  int word_length = (rand() % (MAX_WORD_LENGTH - 1)) + 1;

  // Create a buffer to store the word
  char *word = malloc(word_length + 1);

  // Generate a random word
  for (int i = 0; i < word_length; i++) {
    word[i] = (rand() % 26) + 'a';
  }

  // Null-terminate the word
  word[word_length] = '\0';

  return word;
}

// Function to generate a random sentence
char *generate_sentence() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random number of words in the sentence
  int num_words = (rand() % (MAX_WORDS - 1)) + 1;

  // Create a buffer to store the sentence
  char *sentence = malloc(MAX_WORDS * MAX_WORD_LENGTH + 1);

  // Generate a random sentence
  for (int i = 0; i < num_words; i++) {
    // Generate a random word
    char *word = generate_word();

    // Append the word to the sentence
    strcat(sentence, word);

    // Free the word
    free(word);

    // Add a space after the word
    strcat(sentence, " ");
  }

  // Null-terminate the sentence
  sentence[strlen(sentence) - 1] = '\0';

  return sentence;
}

// Function to calculate the typing speed
int calculate_typing_speed(char *sentence, double time) {
  // Calculate the number of characters in the sentence
  int num_characters = strlen(sentence);

  // Calculate the typing speed in words per minute
  int typing_speed = (num_characters / 5) * (60 / time);

  return typing_speed;
}

int main() {
  // Generate a random sentence
  char *sentence = generate_sentence();

  // Print the sentence to the console
  printf("Type the following sentence:\n\n%s\n\n", sentence);

  // Start the timer
  clock_t start_time = clock();

  // Wait for the user to finish typing
  char input[MAX_WORDS * MAX_WORD_LENGTH + 1];
  fgets(input, MAX_WORDS * MAX_WORD_LENGTH + 1, stdin);

  // Stop the timer
  clock_t end_time = clock();

  // Calculate the time taken to type the sentence
  double time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  // Calculate the typing speed
  int typing_speed = calculate_typing_speed(sentence, time);

  // Print the typing speed to the console
  printf("Your typing speed is %d words per minute.\n", typing_speed);

  // Free the sentence
  free(sentence);

  return 0;
}