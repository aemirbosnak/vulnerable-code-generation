//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of a word
#define MAX_WORD_SIZE 255

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 100

// Define the number of sentiment scores
#define NUM_SENTIMENT_SCORES 3

// Define the sentiment scores
#define SENTIMENT_SCORE_POSITIVE 1
#define SENTIMENT_SCORE_NEGATIVE -1
#define SENTIMENT_SCORE_NEUTRAL 0

// Define the sentiment score labels
const char *sentiment_score_labels[] = {"Positive", "Negative", "Neutral"};

// Define the stop words
const char *stop_words[] = {"a", "an", "the", "and", "or", "but", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "will", "would", "shall", "should", "may", "might", "can", "could", "must", "ought", "of", "to", "from", "by", "for", "with", "in", "on", "at", "over", "under", "up", "down", "out", "into", "on", "to", "from", "by", "for", "with", "in", "on", "at", "over", "under", "up", "down", "out", "into", "of", "the", "a", "an"};
const int num_stop_words = sizeof(stop_words) / sizeof(char *);

// Define the sentiment dictionary
const char *sentiment_dictionary[] = {"good", "great", "excellent", "wonderful", "amazing", "superb", "awesome", "fantastic", "terrific", "marvelous", "bad", "terrible", "awful", "horrible", "dreadful", "atrocious", "abysmal", "dismal", "lousy", "awful"};
const int num_sentiment_words = sizeof(sentiment_dictionary) / sizeof(char *);

// Get the sentiment score of a word
int get_sentiment_score(const char *word) {
  for (int i = 0; i < num_sentiment_words; i++) {
    if (strcmp(word, sentiment_dictionary[i]) == 0) {
      return SENTIMENT_SCORE_POSITIVE;
    }
  }
  for (int i = 0; i < num_sentiment_words; i++) {
    if (strcmp(word, sentiment_dictionary[i]) == 0) {
      return SENTIMENT_SCORE_NEGATIVE;
    }
  }
  return SENTIMENT_SCORE_NEUTRAL;
}

// Get the sentiment score of a sentence
int get_sentiment_score_of_sentence(const char *sentence) {
  // Tokenize the sentence
  char *words[MAX_WORDS_IN_SENTENCE];
  int num_words = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment score of the sentence
  int sentiment_score = 0;
  for (int i = 0; i < num_words; i++) {
    // Convert the word to lowercase
    char *word = strdup(words[i]);
    for (int j = 0; word[j] != '\0'; j++) {
      word[j] = tolower(word[j]);
    }

    // Check if the word is a stop word
    int is_stop_word = 0;
    for (int j = 0; j < num_stop_words; j++) {
      if (strcmp(word, stop_words[j]) == 0) {
        is_stop_word = 1;
        break;
      }
    }
    if (is_stop_word) {
      continue;
    }

    // Get the sentiment score of the word
    int word_sentiment_score = get_sentiment_score(word);

    // Add the sentiment score of the word to the sentiment score of the sentence
    sentiment_score += word_sentiment_score;

    // Free the memory allocated for the word
    free(word);
  }

  // Return the sentiment score of the sentence
  return sentiment_score;
}

// Get the sentiment score of a text
int get_sentiment_score_of_text(const char *text) {
  // Tokenize the text into sentences
  char *sentences[100];
  int num_sentences = 0;
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[num_sentences++] = token;
    token = strtok(NULL, ".");
  }

  // Calculate the sentiment score of the text
  int sentiment_score = 0;
  for (int i = 0; i < num_sentences; i++) {
    // Get the sentiment score of the sentence
    int sentence_sentiment_score = get_sentiment_score_of_sentence(sentences[i]);

    // Add the sentiment score of the sentence to the sentiment score of the text
    sentiment_score += sentence_sentiment_score;
  }

  // Return the sentiment score of the text
  return sentiment_score;
}

// Print the sentiment score of a text
void print_sentiment_score(const char *text) {
  // Get the sentiment score of the text
  int sentiment_score = get_sentiment_score_of_text(text);

  // Print the sentiment score of the text
  printf("The sentiment score of the text is %d\n", sentiment_score);

  // Print the sentiment score label of the text
  printf("The sentiment score label of the text is %s\n", sentiment_score_labels[sentiment_score + 1]);
}

// Main function
int main() {
  // Get the text from the user
  char text[10000];
  printf("Enter the text: ");
  scanf("%[^\n]%*c", text);

  // Print the sentiment score of the text
  print_sentiment_score(text);

  return 0;
}