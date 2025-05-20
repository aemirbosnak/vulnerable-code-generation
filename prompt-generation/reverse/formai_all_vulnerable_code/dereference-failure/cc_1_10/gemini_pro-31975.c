//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define NUM_WORDS 100
#define MAX_WORD_LENGTH 20

// Function prototypes
int main(void);
void print_words(char **words, int num_words);
void get_user_input(char *input, int max_length);
int calculate_speed(int num_words, int elapsed_time);

// Main function
int main(void) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a list of words
  char *words[NUM_WORDS];
  for (int i = 0; i < NUM_WORDS; i++) {
    // Generate a random word length
    int word_length = rand() % (MAX_WORD_LENGTH - 1) + 1;

    // Allocate memory for the word
    words[i] = malloc(word_length + 1);

    // Generate a random word
    for (int j = 0; j < word_length; j++) {
      words[i][j] = 'a' + rand() % 26;
    }
    words[i][word_length] = '\0';
  }

  // Print the words to the screen
  print_words(words, NUM_WORDS);

  // Get the user's input
  char input[NUM_WORDS * MAX_WORD_LENGTH];
  get_user_input(input, NUM_WORDS * MAX_WORD_LENGTH);

  // Calculate the elapsed time
  time_t start_time = time(NULL);
  time_t end_time = time(NULL);
  int elapsed_time = end_time - start_time;

  // Calculate the typing speed
  int speed = calculate_speed(NUM_WORDS, elapsed_time);

  // Print the typing speed to the screen
  printf("Your typing speed is %d words per minute.\n", speed);

  // Free the memory allocated for the words
  for (int i = 0; i < NUM_WORDS; i++) {
    free(words[i]);
  }

  return 0;
}

// Function to print the words to the screen
void print_words(char **words, int num_words) {
  for (int i = 0; i < num_words; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");
}

// Function to get the user's input
void get_user_input(char *input, int max_length) {
  fgets(input, max_length, stdin);
}

// Function to calculate the typing speed
int calculate_speed(int num_words, int elapsed_time) {
  return (num_words * 60) / elapsed_time;
}