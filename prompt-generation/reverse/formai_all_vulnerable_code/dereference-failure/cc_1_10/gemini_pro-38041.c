//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

// generate a random word
char *generate_word() {
  char *word = malloc(MAX_WORD_LEN);
  int len = rand() % MAX_WORD_LEN + 1;
  for (int i = 0; i < len; i++) {
    word[i] = 'a' + rand() % 26;
  }
  word[len] = '\0';
  return word;
}

// generate a list of random words
char **generate_words(int num_words) {
  char **words = malloc(num_words * sizeof(char *));
  for (int i = 0; i < num_words; i++) {
    words[i] = generate_word();
  }
  return words;
}

// free a list of words
void free_words(char **words, int num_words) {
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }
  free(words);
}

// get the time in milliseconds
long get_time() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// run a typing speed test
void run_test(char **words, int num_words) {
  printf("Type the following words as quickly as you can:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");

  long start_time = get_time();

  char input[MAX_WORDS * MAX_WORD_LEN];
  scanf("%s", input);

  long end_time = get_time();

  int correct = 0;
  for (int i = 0; i < num_words; i++) {
    if (strcmp(input + i * MAX_WORD_LEN, words[i]) == 0) {
      correct++;
    }
  }

  double time_taken = (double)(end_time - start_time) / 1000;
  double speed = (double)correct / time_taken;

  printf("You typed %d words correctly in %.3f seconds.\n", correct, time_taken);
  printf("Your typing speed is %.2f words per minute.\n", speed * 60);
}

int main() {
  srand(time(NULL));

  int num_words = 100;
  char **words = generate_words(num_words);

  run_test(words, num_words);

  free_words(words, num_words);

  return 0;
}