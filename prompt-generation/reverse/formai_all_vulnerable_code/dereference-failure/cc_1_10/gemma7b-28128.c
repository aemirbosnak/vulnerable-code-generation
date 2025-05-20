//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_ROW 5

typedef struct Word {
  char **words;
  int current_row;
  int current_column;
} Word;

Word *create_word_game() {
  Word *word_game = malloc(sizeof(Word));
  word_game->words = malloc(sizeof(char *) * MAX_WORDS);
  for (int i = 0; i < MAX_WORDS; i++) {
    word_game->words[i] = malloc(sizeof(char) * WORDS_PER_ROW);
  }
  word_game->current_row = 0;
  word_game->current_column = 0;
  return word_game;
}

void play_word_game(Word *word_game) {
  char guess_word[WORDS_PER_ROW];
  printf("Enter a word: ");
  scanf("%s", guess_word);

  int is_word_found = 0;
  for (int r = 0; r < word_game->current_row; r++) {
    for (int c = 0; c < word_game->current_column; c++) {
      if (strcmp(guess_word, word_game->words[r][c]) == 0) {
        is_word_found = 1;
      }
    }
  }

  if (is_word_found) {
    printf("Word found!\n");
  } else {
    printf("Word not found.\n");
  }
}

int main() {
  Word *word_game = create_word_game();

  // Fill the word game with words
  word_game->words[0][0] = "apple";
  word_game->words[0][1] = "banana";
  word_game->words[0][2] = "orange";
  word_game->words[0][3] = "grape";
  word_game->words[0][4] = "apricot";

  word_game->words[1][0] = "mango";
  word_game->words[1][1] = "watermelon";
  word_game->words[1][2] = "grapes";
  word_game->words[1][3] = "peach";
  word_game->words[1][4] = "apricot";

  // Play the word game
  play_word_game(word_game);

  return 0;
}