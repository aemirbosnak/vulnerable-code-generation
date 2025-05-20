//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PLAYERS 4
#define MAX_WORDS 1000

typedef struct {
  char *word;
  int count;
} word_count;

typedef struct {
  int player_id;
  char *input;
  int input_len;
} player_input;

sem_t mutex;
word_count word_counts[MAX_WORDS];
int num_words = 0;

void *player_thread(void *arg) {
  player_input *input = (player_input *)arg;
  char *word;
  int i, found;

  // Tokenize the input into words
  word = strtok(input->input, " ");
  while (word != NULL) {
    // Check if the word is already in the list of words
    found = 0;
    for (i = 0; i < num_words; i++) {
      if (strcmp(word, word_counts[i].word) == 0) {
        word_counts[i].count++;
        found = 1;
        break;
      }
    }

    // If the word is not in the list, add it
    if (!found) {
      word_counts[num_words].word = strdup(word);
      word_counts[num_words].count = 1;
      num_words++;
    }

    // Get the next word
    word = strtok(NULL, " ");
  }

  pthread_exit(NULL);
}

int main() {
  pthread_t players[MAX_PLAYERS];
  player_input player_inputs[MAX_PLAYERS];
  int i;

  sem_init(&mutex, 0, 1);

  // Get the input from the players
  for (i = 0; i < MAX_PLAYERS; i++) {
    player_inputs[i].player_id = i;
    printf("Player %d, enter your input: ", i);
    scanf("%s", player_inputs[i].input);
    player_inputs[i].input_len = strlen(player_inputs[i].input);
  }

  // Create the player threads
  for (i = 0; i < MAX_PLAYERS; i++) {
    pthread_create(&players[i], NULL, player_thread, &player_inputs[i]);
  }

  // Wait for the player threads to finish
  for (i = 0; i < MAX_PLAYERS; i++) {
    pthread_join(players[i], NULL);
  }

  // Print the word counts
  printf("Word counts:\n");
  for (i = 0; i < num_words; i++) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }

  // Clean up
  for (i = 0; i < num_words; i++) {
    free(word_counts[i].word);
  }

  sem_destroy(&mutex);

  return 0;
}