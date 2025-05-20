//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 500
#define POSITIVE_WORDS_FILE "positive_words.txt"
#define NEGATIVE_WORDS_FILE "negative_words.txt"

// Function to read file into an array
char** read_file(char* file_path) {
  char** word_list = malloc(sizeof(char*) * MAX_CHARS);
  FILE* file = fopen(file_path, "r");

  int i = 0;
  char* line = malloc(sizeof(char) * MAX_CHARS);

  while(fgets(line, MAX_CHARS, file) != NULL) {
    // Remove newline character
    line[strcspn(line, "\n")] = 0;

    word_list[i] = malloc(sizeof(char) * MAX_CHARS);
    strcpy(word_list[i], line);
    i++;
  }

  free(line);
  fclose(file);
  return word_list;
}

// Function to get the sentiment score of a sentence
float get_sentiment_score(char* sentence, char** pos_word_list, char** neg_word_list) {
  float score = 0;
  char* word = strtok(sentence, " ");

  while(word != NULL) {
    // Check if word is in positive or negative list
    for(int i = 0; i < MAX_CHARS; i++) {
      if(pos_word_list[i] != NULL) {
        if(strcmp(pos_word_list[i], word) == 0) {
          score++;
          break;
        }
      }
      
      if(neg_word_list[i] != NULL) {
        if(strcmp(neg_word_list[i], word) == 0) {
          score--;
          break;
        }
      }
    }

    word = strtok(NULL, " ");
  }

  return score;
}

int main() {
  // Read in positive and negative words files
  char** pos_word_list = read_file(POSITIVE_WORDS_FILE);
  char** neg_word_list = read_file(NEGATIVE_WORDS_FILE);

  char sentence[MAX_CHARS];
  printf("Enter a sentence to get its sentiment score:\n");
  fgets(sentence, MAX_CHARS, stdin);

  float score = get_sentiment_score(sentence, pos_word_list, neg_word_list);
  printf("Sentiment Score: %0.1f\n", score);

  // Free allocated memory
  for(int i = 0; i < MAX_CHARS; i++) {
    if(pos_word_list[i] != NULL) {
      free(pos_word_list[i]);
    }

    if(neg_word_list[i] != NULL) {
      free(neg_word_list[i]);
    }
  }

  free(pos_word_list);
  free(neg_word_list);

  return 0;
}