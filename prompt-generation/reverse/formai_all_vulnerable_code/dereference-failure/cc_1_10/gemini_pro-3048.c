//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_WORDS 100     // Maximum number of words in the word list
#define MAX_WORD_LENGTH 20 // Maximum length of a word
#define TEST_DURATION 60   // Test duration in seconds

// Global variables
char *word_list[MAX_WORDS]; // Array of words
int word_count;              // Number of words in the word list
int current_word_index;      // Index of the current word being typed
char *current_word;          // Pointer to the current word being typed
char user_input[MAX_WORD_LENGTH]; // Buffer for user input

// Function prototypes
void load_word_list(char *filename);
void start_test();
void display_results();

int main() {
  // Load the word list from a file
  load_word_list("words.txt");

  // Start the test
  start_test();

  // Display the results
  display_results();

  return 0;
}

// Loads the word list from a file
void load_word_list(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening the word list file.\n");
    exit(1);
  }

  // Read the words from the file
  while (fgets(word_list[word_count], MAX_WORD_LENGTH, fp) != NULL) {
    word_count++;
  }

  fclose(fp);
}

// Starts the test
void start_test() {
  // Initialize the variables
  current_word_index = 0;
  current_word = word_list[current_word_index];
  time_t start_time = time(NULL);

  // Loop until the test duration is reached
  while (difftime(time(NULL), start_time) < TEST_DURATION) {
    // Display the current word
    printf("%s\n", current_word);

    // Get the user's input
    scanf("%s", user_input);

    // Check if the user's input matches the current word
    if (strcmp(user_input, current_word) == 0) {
      // The user typed the word correctly
      current_word_index++;
      current_word = word_list[current_word_index];
    } else {
      // The user typed the word incorrectly
      printf("Incorrect!\n");
    }
  }
}

// Displays the results of the test
void display_results() {
  // Calculate the number of words typed per minute
  int wpm = (current_word_index / TEST_DURATION) * 60;

  // Print the results
  printf("Words typed per minute: %d\n", wpm);
}