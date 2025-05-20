//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a lexicon of positive and negative words
char *positive_words[] = {
  "good", "great", "amazing", "awesome", "superb", "wonderful"
};
char *negative_words[] = {
  "bad", "terrible", "awful", "horrible", "dreadful", "最悪"
};

// Define a function to analyze the sentiment of a sentence
int analyze_sentiment(char *sentence) {
  // Tokenize the sentence into words
  char *tokens[100];  // Assume a maximum of 100 words in a sentence
  int num_tokens = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Count the number of positive and negative words in the sentence
  int positive_count = 0;
  int negative_count = 0;
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
      if (strcmp(tokens[i], positive_words[j]) == 0) {
        positive_count++;
      }
    }
    for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
      if (strcmp(tokens[i], negative_words[j]) == 0) {
        negative_count++;
      }
    }
  }

  // Determine the sentiment of the sentence
  int sentiment;
  if (positive_count > negative_count) {
    sentiment = 1;  // Positive
  } else if (negative_count > positive_count) {
    sentiment = -1;  // Negative
  } else {
    sentiment = 0;  // Neutral
  }

  return sentiment;
}

// Define a function to test the sentiment analysis tool
void test_sentiment_analysis() {
  // Test sentences
  char *sentences[] = {
    "This is a great movie!",
    "This movie is terrible!",
    "I'm not sure how I feel about this movie.",
  };

  // Analyze the sentiment of each sentence
  int sentiments[sizeof(sentences) / sizeof(char *)];
  for (int i = 0; i < sizeof(sentences) / sizeof(char *); i++) {
    sentiments[i] = analyze_sentiment(sentences[i]);
  }

  // Print the results
  for (int i = 0; i < sizeof(sentences) / sizeof(char *); i++) {
    printf("Sentence: %s\n", sentences[i]);
    printf("Sentiment: ");
    switch (sentiments[i]) {
      case 1:
        printf("Positive\n");
        break;
      case -1:
        printf("Negative\n");
        break;
      case 0:
        printf("Neutral\n");
        break;
    }
  }
}

// Main function
int main() {
  // Test the sentiment analysis tool
  test_sentiment_analysis();

  return 0;
}