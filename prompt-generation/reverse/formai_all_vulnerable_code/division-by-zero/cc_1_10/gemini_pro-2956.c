//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function prototypes
void print_intro();
void get_user_input(char *input_string);
int calculate_words_per_minute(char *input_string, int time_taken);
void print_results(int words_per_minute);

// Define the main function
int main() {
  // Print the introduction
  print_intro();

  // Get the user input
  char input_string[100];
  get_user_input(input_string);

  // Calculate the time taken to type the string
  clock_t start_time = clock();
  printf("Press Enter when you are finished typing:\n");
  getchar();
  clock_t end_time = clock();
  int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

  // Calculate the words per minute
  int words_per_minute = calculate_words_per_minute(input_string, time_taken);

  // Print the results
  print_results(words_per_minute);

  return 0;
}

// Define the function to print the introduction
void print_intro() {
  printf("Welcome to the Typing Speed Test!\n");
  printf("Instructions:\n");
  printf("  - Type the following sentence as quickly and accurately as possible:\n");
  printf("    The quick brown fox jumps over the lazy dog.\n");
  printf("  - Press Enter when you are finished typing.\n");
}

// Define the function to get the user input
void get_user_input(char *input_string) {
  printf("Type the following sentence:\n");
  printf("The quick brown fox jumps over the lazy dog.\n");
  fgets(input_string, 100, stdin);
}

// Define the function to calculate the words per minute
int calculate_words_per_minute(char *input_string, int time_taken) {
  // Count the number of words in the input string
  int word_count = 0;
  char *word = strtok(input_string, " ");
  while (word != NULL) {
    word_count++;
    word = strtok(NULL, " ");
  }

  // Calculate the words per minute
  int words_per_minute = (word_count / time_taken) * 60;

  return words_per_minute;
}

// Define the function to print the results
void print_results(int words_per_minute) {
  printf("Your typing speed is %d words per minute.\n", words_per_minute);
}