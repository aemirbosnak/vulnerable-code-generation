//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY 5
#define NUM_WORDS 10

char **words;
char **guesses;
int memory_size;

void initialize_game() {
  words = malloc(NUM_WORDS * MAX_MEMORY * sizeof(char *));
  guesses = malloc(NUM_WORDS * MAX_MEMORY * sizeof(char *));
  memory_size = MAX_MEMORY;
  srand(time(NULL));
}

void play_round() {
  int target_word_index = rand() % NUM_WORDS;
  char target_word = words[target_word_index][0];
  int guess_count = 0;

  for (int i = 0; i < memory_size; i++) {
    guesses[i] = NULL;
  }

  while (guess_count < memory_size) {
    char guess;
    printf("Guess a letter: ");
    scanf("%c", &guess);

    for (int j = 0; j < memory_size; j++) {
      if (guesses[j] == NULL && guess == words[target_word_index][j]) {
        guesses[j] = guess;
        guess_count++;
      }
    }

    if (guess_count == memory_size) {
      printf("Congratulations, you win!\n");
    } else {
      printf("Sorry, that letter is not correct.\n");
    }
  }
}

int main() {
  initialize_game();
  play_round();

  return 0;
}