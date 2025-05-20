//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_WORDS 100
#define WORD_LENGTH 10

char *words[NUM_WORDS];
int word_lengths[NUM_WORDS];
int target_word_index;
char target_word[WORD_LENGTH + 1];
char user_input[WORD_LENGTH + 1];
int num_correct_words;
int num_incorrect_words;
int num_errors;
int start_time;

void init_words() {
  FILE *f = fopen("/usr/share/dict/words", "r");
  assert(f != NULL);
  for (int i = 0; i < NUM_WORDS; i++) {
    words[i] = malloc(WORD_LENGTH + 1);
    assert(words[i] != NULL);
    fscanf(f, "%s", words[i]);
    word_lengths[i] = strlen(words[i]);
  }
  fclose(f);
}

void free_words() {
  for (int i = 0; i < NUM_WORDS; i++) {
    free(words[i]);
  }
}

void select_target_word() {
  target_word_index = rand() % NUM_WORDS;
  strcpy(target_word, words[target_word_index]);
}

void get_user_input() {
  printf("Enter the word: ");
  scanf("%s", user_input);
}

void check_input() {
  if (strcmp(user_input, target_word) == 0) {
    num_correct_words++;
  } else {
    num_incorrect_words++;
    num_errors += abs(strlen(user_input) - word_lengths[target_word_index]);
  }
}

void print_results() {
  int elapsed_time = time(NULL) - start_time;
  printf("\nResults:\n");
  printf("Number of correct words: %d\n", num_correct_words);
  printf("Number of incorrect words: %d\n", num_incorrect_words);
  printf("Number of errors: %d\n", num_errors);
  printf("Elapsed time: %d seconds\n", elapsed_time);
  printf("Typing speed: %.2f words per minute\n",
         (60.0 * num_correct_words) / elapsed_time);
}

int main() {
  srand(time(NULL));
  init_words();
  start_time = time(NULL);
  for (int i = 0; i < NUM_WORDS; i++) {
    select_target_word();
    get_user_input();
    check_input();
  }
  print_results();
  free_words();
  return 0;
}