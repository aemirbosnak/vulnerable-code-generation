//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of words to be analyzed
#define NUM_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 25

// Initialize the list of words and their sentiment scores
char *words[NUM_WORDS];
int sentiment_scores[NUM_WORDS];

// Load the list of words and their sentiment scores from a file
void load_words() {
  FILE *file = fopen("words.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char line[MAX_WORD_LENGTH + 1];
  int i = 0;
  while (fgets(line, MAX_WORD_LENGTH + 1, file)) {
    // Remove the newline character from the line
    line[strlen(line) - 1] = '\0';

    // Split the line into the word and its sentiment score
    char *word = strtok(line, ",");
    int sentiment_score = atoi(strtok(NULL, ","));

    // Store the word and its sentiment score in the list
    words[i] = strdup(word);
    sentiment_scores[i] = sentiment_score;
    i++;
  }

  fclose(file);
}

// Analyze the sentiment of a given text
int analyze_sentiment(char *text) {
  // Tokenize the text into words
  char *tokens[NUM_WORDS];
  int num_tokens = tokenize(text, tokens);

  // Compute the sentiment score for each word
  int sentiment_score = 0;
  for (int i = 0; i < num_tokens; i++) {
    // Find the word in the list of words
    int index = find_word(tokens[i]);

    // If the word is found, add its sentiment score to the total
    if (index != -1) {
      sentiment_score += sentiment_scores[index];
    }
  }

  // Return the total sentiment score
  return sentiment_score;
}

// Tokenize a given text into words
int tokenize(char *text, char **tokens) {
  // Allocate memory for the tokens
  for (int i = 0; i < NUM_WORDS; i++) {
    tokens[i] = malloc(MAX_WORD_LENGTH + 1);
  }

  // Tokenize the text into words
  int num_tokens = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    strcpy(tokens[num_tokens], token);
    num_tokens++;
    token = strtok(NULL, " ");
  }

  // Return the number of tokens
  return num_tokens;
}

// Find the index of a given word in the list of words
int find_word(char *word) {
  for (int i = 0; i < NUM_WORDS; i++) {
    if (strcmp(word, words[i]) == 0) {
      return i;
    }
  }

  // Return -1 if the word is not found
  return -1;
}

// Print the results of the sentiment analysis
void print_results(int sentiment_score) {
  if (sentiment_score > 0) {
    printf("The text has a positive sentiment.\n");
  } else if (sentiment_score < 0) {
    printf("The text has a negative sentiment.\n");
  } else {
    printf("The text has a neutral sentiment.\n");
  }
}

// Main function
int main() {
  // Load the list of words and their sentiment scores
  load_words();

  // Get the text to be analyzed from the user
  char text[1024];
  printf("Enter the text to be analyzed: ");
  fgets(text, 1024, stdin);

  // Analyze the sentiment of the text
  int sentiment_score = analyze_sentiment(text);

  // Print the results of the sentiment analysis
  print_results(sentiment_score);

  return 0;
}