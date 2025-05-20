//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 30

// Function to generate random words
char *get_random_word() {
  static const char *words[] = {"apple", "banana", "orange", "pineapple", "grape", "lemon", "watermelon", "kiwi", "pear", "mango"};
  static const int num_words = sizeof(words) / sizeof(words[0]);
  int idx = rand() % num_words;
  return strdup(words[idx]);
}

// Function to calculate typing speed
void calculate_typing_speed(double elapsed_time, int num_words) {
  double wpm = (double) (num_words * 60) / elapsed_time;
  printf("\nTyping speed: %.2f words per minute\n", wpm);
}

int main() {
  char *words[MAX_WORDS];
  clock_t start_time, end_time;
  double elapsed_time;
  int num_words = 0;
  
  printf("Welcome to Typing Speed Test!\n");
  printf("Type the following words:\n");
  
  // Generate random words
  for(int i = 0; i < MAX_WORDS; i++) {
    words[i] = get_random_word();
    printf("%s ", words[i]);
  }
  
  // Start timer
  start_time = clock();
  
  // Prompt user to type the words
  printf("\n\nType the words above and press enter:\n");
  for(int i = 0; i < MAX_WORDS; i++) {
    char input[MAX_WORD_LEN];
    scanf("%s", input);
    if(strcmp(input, words[i]) == 0) {
      num_words++;
    }
  }
  
  // End the timer
  end_time = clock();
  
  // Calculate elapsed time
  elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
  
  // Print typing speed
  calculate_typing_speed(elapsed_time, num_words);
  
  // Free allocated memory
  for(int i = 0; i < MAX_WORDS; i++) {
    free(words[i]);
  }
  
  return 0;
}