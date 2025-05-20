//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of sentiment classes
#define NUM_SENTIMENT_CLASSES 3

// Define the sentiment classes
char *sentiment_classes[NUM_SENTIMENT_CLASSES] = {"positive", "neutral", "negative"};

// Define the sentiment scores for each word
int word_scores[256];

// Load the sentiment scores from a file
void load_sentiment_scores() {
  FILE *file = fopen("sentiment_scores.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening sentiment scores file\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, 256, file)) {
    char *word = strtok(line, " ");
    char *score = strtok(NULL, " ");
    word_scores[(int)word[0]] = atoi(score);
  }

  fclose(file);
}

// Tokenize a sentence into words
char **tokenize_sentence(char *sentence) {
  char **tokens = malloc(sizeof(char *) * MAX_SENTENCE_LENGTH);
  int num_tokens = 0;

  char *token = strtok(sentence, " ");
  while (token != NULL) {
    tokens[num_tokens] = token;
    num_tokens++;
    token = strtok(NULL, " ");
  }

  return tokens;
}

// Calculate the sentiment score of a sentence
int calculate_sentiment_score(char **tokens, int num_tokens) {
  int score = 0;
  for (int i = 0; i < num_tokens; i++) {
    score += word_scores[(int)tokens[i][0]];
  }

  return score;
}

// Classify the sentiment of a sentence
char *classify_sentiment(int score) {
  if (score > 0) {
    return sentiment_classes[0];
  } else if (score == 0) {
    return sentiment_classes[1];
  } else {
    return sentiment_classes[2];
  }
}

// Print the sentiment analysis results
void print_results(char *sentence, char *sentiment) {
  printf("Sentence: %s\n", sentence);
  printf("Sentiment: %s\n", sentiment);
}

// Main function
int main() {
  // Load the sentiment scores
  load_sentiment_scores();

  // Get the input sentence from the user
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  gets(sentence);

  // Tokenize the sentence
  char **tokens = tokenize_sentence(sentence);

  // Calculate the sentiment score
  int score = calculate_sentiment_score(tokens, strlen(tokens));

  // Classify the sentiment
  char *sentiment = classify_sentiment(score);

  // Print the results
  print_results(sentence, sentiment);

  return 0;
}