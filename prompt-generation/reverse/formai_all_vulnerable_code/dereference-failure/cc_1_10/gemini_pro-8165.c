//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a word and its sentiment
typedef struct {
  char *word;
  int sentiment;
} Word;

// Create a new word with the given word and sentiment
Word *new_word(char *word, int sentiment) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->sentiment = sentiment;
  return new_word;
}

// Free the memory allocated for a word
void free_word(Word *word) {
  free(word->word);
  free(word);
}

// Create a new sentiment analysis tool
typedef struct {
  // An array of words and their sentiments
  Word **words;
  // The number of words in the tool
  int num_words;
} SentimentAnalysisTool;

// Create a new sentiment analysis tool
SentimentAnalysisTool *new_sentiment_analysis_tool() {
  SentimentAnalysisTool *tool = malloc(sizeof(SentimentAnalysisTool));
  tool->words = NULL;
  tool->num_words = 0;
  return tool;
}

// Free the memory allocated for a sentiment analysis tool
void free_sentiment_analysis_tool(SentimentAnalysisTool *tool) {
  for (int i = 0; i < tool->num_words; i++) {
    free_word(tool->words[i]);
  }
  free(tool->words);
  free(tool);
}

// Add a new word to the sentiment analysis tool
void add_word(SentimentAnalysisTool *tool, char *word, int sentiment) {
  tool->words = realloc(tool->words, sizeof(Word *) * (tool->num_words + 1));
  tool->words[tool->num_words++] = new_word(word, sentiment);
}

// Analyze the sentiment of a given text
int analyze_sentiment(SentimentAnalysisTool *tool, char *text) {
  int sentiment = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    for (int i = 0; i < tool->num_words; i++) {
      if (strcmp(token, tool->words[i]->word) == 0) {
        sentiment += tool->words[i]->sentiment;
        break;
      }
    }
    token = strtok(NULL, " ");
  }
  return sentiment;
}

int main() {
  // Create a new sentiment analysis tool
  SentimentAnalysisTool *tool = new_sentiment_analysis_tool();

  // Add some words to the tool
  add_word(tool, "good", 1);
  add_word(tool, "bad", -1);
  add_word(tool, "neutral", 0);

  // Analyze the sentiment of some text
  char *text = "This is a good day.";
  int sentiment = analyze_sentiment(tool, text);

  // Print the sentiment
  printf("The sentiment of the text is: %d\n", sentiment);

  // Free the memory allocated for the tool
  free_sentiment_analysis_tool(tool);

  return 0;
}