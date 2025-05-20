//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

typedef struct Word {
  char* word;
  int count;
} Word;

typedef struct SpamDetector {
  Word* words;
  int num_words;
  int threshold;
} SpamDetector;

// Create a new word
Word* create_word(char* word) {
  Word* new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->count = 1;
  return new_word;
}

// Create a new spam detector
SpamDetector* create_spam_detector(int threshold) {
  SpamDetector* detector = malloc(sizeof(SpamDetector));
  detector->words = malloc(sizeof(Word) * MAX_WORDS);
  detector->num_words = 0;
  detector->threshold = threshold;
  return detector;
}

// Parse input and update word counts
void parse_input(SpamDetector* detector, char* input) {
  char* token = strtok(input, " ");
  while (token != NULL) {
    int found = 0;
    for (int i = 0; i < detector->num_words; i++) {
      if (strcmp(detector->words[i].word, token) == 0) {
        detector->words[i].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      detector->words[detector->num_words++] = *create_word(token);
    }
    token = strtok(NULL, " ");
  }
}

// Check if the input is spam
int is_spam(SpamDetector* detector, char* input) {
  // Parse the input
  parse_input(detector, input);

  // Calculate the spam score
  int score = 0;
  for (int i = 0; i < detector->num_words; i++) {
    score += detector->words[i].count;
  }

  // Check if the score exceeds the threshold
  return score > detector->threshold;
}

// Free the resources allocated by the spam detector
void free_spam_detector(SpamDetector* detector) {
  for (int i = 0; i < detector->num_words; i++) {
    free(detector->words[i].word);
  }
  free(detector->words);
  free(detector);
}

int main() {
  // Create a new spam detector with a threshold of 5
  SpamDetector* detector = create_spam_detector(5);

  // Parse input from the user
  char input[MAX_LEN];
  printf("Enter your text: ");
  fgets(input, MAX_LEN, stdin);

  // Check if the input is spam
  int result = is_spam(detector, input);

  // Print the result
  if (result) {
    printf("Your message is spam.\n");
  } else {
    printf("Your message is not spam.\n");
  }

  // Free the resources allocated by the spam detector
  free_spam_detector(detector);

  return 0;
}