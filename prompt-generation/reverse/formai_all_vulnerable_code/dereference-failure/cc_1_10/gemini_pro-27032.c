//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// Initialize the sentiment scores for each word
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
const char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful"};
int positive_scores[] = {1, 2, 3, 4, 5};
int negative_scores[] = {-1, -2, -3, -4, -5};

// Compute the sentiment score for a given sentence
int compute_sentiment_score(char *sentence) {
  int score = 0;

  // Tokenize the sentence and iterate over each word
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    // Check if the word is in the positive or negative word list
    int i;
    for (i = 0; i < 5; i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        score += positive_scores[i];
        break;
      } else if (strcmp(token, negative_words[i]) == 0) {
        score += negative_scores[i];
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  return score;
}

// Get the sentiment of a sentence from the user
char *get_sentence_from_user() {
  char *sentence = malloc(MAX_SENTENCE_LENGTH);
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
  return sentence;
}

// Print the sentiment score for a given sentence
void print_sentiment_score(int score) {
  if (score > 0) {
    printf("The sentence has a positive sentiment.\n");
  } else if (score < 0) {
    printf("The sentence has a negative sentiment.\n");
  } else {
    printf("The sentence has a neutral sentiment.\n");
  }
}

// Main function
int main() {
  char *sentence = get_sentence_from_user();
  int score = compute_sentiment_score(sentence);
  print_sentiment_score(score);
  free(sentence);
  return 0;
}