//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word and its sentiment score
typedef struct {
  char* word;
  int score;
} Word;

// Create a new word with the given word and sentiment score
Word* new_word(char* word, int score) {
  Word* w = malloc(sizeof(Word));
  w->word = word;
  w->score = score;
  return w;
}

// Free the memory allocated for the given word
void free_word(Word* w) {
  free(w->word);
  free(w);
}

// Create a new sentiment analysis tool
typedef struct {
  // An array of all the words and their sentiment scores
  Word** words;
  // The number of words in the array
  int num_words;
} SentimentAnalysisTool;

// Create a new sentiment analysis tool
SentimentAnalysisTool* new_sentiment_analysis_tool() {
  SentimentAnalysisTool* sat = malloc(sizeof(SentimentAnalysisTool));
  sat->words = NULL;
  sat->num_words = 0;
  return sat;
}

// Free the memory allocated for the given sentiment analysis tool
void free_sentiment_analysis_tool(SentimentAnalysisTool* sat) {
  for (int i = 0; i < sat->num_words; i++) {
    free_word(sat->words[i]);
  }
  free(sat->words);
  free(sat);
}

// Add a new word to the sentiment analysis tool
void add_word(SentimentAnalysisTool* sat, char* word, int score) {
  sat->words = realloc(sat->words, (sat->num_words + 1) * sizeof(Word*));
  sat->words[sat->num_words] = new_word(word, score);
  sat->num_words++;
}

// Analyze the sentiment of the given text
int analyze_sentiment(SentimentAnalysisTool* sat, char* text) {
  // Tokenize the text into words
  char* tokens[100];
  int num_tokens = 0;
  char* token = strtok(text, " ");
  while (token != NULL) {
    tokens[num_tokens] = token;
    num_tokens++;
    token = strtok(NULL, " ");
  }

  // Calculate the total sentiment score of the text
  int total_score = 0;
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < sat->num_words; j++) {
      if (strcmp(tokens[i], sat->words[j]->word) == 0) {
        total_score += sat->words[j]->score;
        break;
      }
    }
  }

  // Return the total sentiment score
  return total_score;
}

// Main function
int main() {
  // Create a new sentiment analysis tool
  SentimentAnalysisTool* sat = new_sentiment_analysis_tool();

  // Add some words to the sentiment analysis tool
  add_word(sat, "good", 1);
  add_word(sat, "bad", -1);
  add_word(sat, "neutral", 0);

  // Analyze the sentiment of some text
  char* text = "This is a good movie!";
  int score = analyze_sentiment(sat, text);

  // Print the sentiment score
  printf("The sentiment score of the text is: %d\n", score);

  // Free the memory allocated for the sentiment analysis tool
  free_sentiment_analysis_tool(sat);

  return 0;
}