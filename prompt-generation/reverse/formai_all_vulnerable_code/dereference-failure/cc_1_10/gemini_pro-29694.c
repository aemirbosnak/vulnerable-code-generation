//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 100
#define WORD_LENGTH 10

char *words[NUM_WORDS];
int word_lengths[NUM_WORDS];
int target_word_index;
char *target_word;
int target_word_length;
int start_time;
int end_time;

void generate_words() {
  FILE *file = fopen("words.txt", "r");
  if (file == NULL) {
    printf("Error opening file words.txt\n");
    exit(1);
  }
  char line[100];
  int i = 0;
  while (fgets(line, 100, file)) {
    if (strlen(line) > 0 && strlen(line) < WORD_LENGTH) {
      words[i] = malloc(strlen(line) + 1);
      strcpy(words[i], line);
      word_lengths[i] = strlen(line) - 1;
      i++;
    }
  }
  fclose(file);
}

void choose_target_word() {
  srand(time(NULL));
  target_word_index = rand() % NUM_WORDS;
  target_word = words[target_word_index];
  target_word_length = word_lengths[target_word_index];
}

void start_timer() {
  start_time = time(NULL);
}

void end_timer() {
  end_time = time(NULL);
}

int calculate_speed(int num_characters) {
  return (num_characters / 5) * 60 / (end_time - start_time);
}

void display_results(int speed) {
  printf("Your typing speed is: %d words per minute\n", speed);
}

int main() {
  generate_words();
  choose_target_word();

  printf("Type the following word as quickly as possible:\n");
  printf("%s\n", target_word);

  start_timer();
  char input[WORD_LENGTH + 1];
  scanf("%s", input);
  end_timer();

  int num_errors = 0;
  for (int i = 0; i < target_word_length; i++) {
    if (input[i] != target_word[i]) {
      num_errors++;
    }
  }

  int speed = calculate_speed(target_word_length - num_errors);
  display_results(speed);

  return 0;
}