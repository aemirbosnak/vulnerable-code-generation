//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

// A struct to represent a word and its sentiment score
typedef struct {
  char *word;
  int sentiment;
} Word;

// A struct to represent a sentence and its sentiment score
typedef struct {
  char *sentence;
  int sentiment;
} Sentence;

// A list of positive and negative words
char *positive_words[] = {
  "good", "great", "excellent", "wonderful", "amazing",
  "positive", "optimistic", "hopeful", "cheerful", "happy"
};

char *negative_words[] = {
  "bad", "terrible", "awful", "horrible", "dreadful",
  "negative", "pessimistic", "hopeless", "sad", "unhappy"
};

// A function to tokenize a sentence into words
char **tokenize_sentence(char *sentence) {
  char **words = malloc(sizeof(char *) * MAX_WORDS);
  int num_words = 0;

  char *token = strtok(sentence, " ");
  while (token != NULL) {
    words[num_words] = malloc(strlen(token) + 1);
    strcpy(words[num_words], token);
    num_words++;

    token = strtok(NULL, " ");
  }

  return words;
}

// A function to calculate the sentiment score of a sentence
int calculate_sentence_sentiment(char **words, int num_words) {
  int sentiment = 0;

  for (int i = 0; i < num_words; i++) {
    char *word = words[i];

    // Check if the word is in the list of positive words
    for (int j = 0; j < sizeof(positive_words) / sizeof(char *); j++) {
      if (strcmp(word, positive_words[j]) == 0) {
        sentiment++;
        break;
      }
    }

    // Check if the word is in the list of negative words
    for (int j = 0; j < sizeof(negative_words) / sizeof(char *); j++) {
      if (strcmp(word, negative_words[j]) == 0) {
        sentiment--;
        break;
      }
    }
  }

  return sentiment;
}

// A function to calculate the sentiment score of a text
int calculate_text_sentiment(char *text) {
  char **sentences = malloc(sizeof(char *) * MAX_SENTENCES);
  int num_sentences = 0;

  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences] = malloc(strlen(sentence) + 1);
    strcpy(sentences[num_sentences], sentence);
    num_sentences++;

    sentence = strtok(NULL, ".");
  }

  int sentiment = 0;
  for (int i = 0; i < num_sentences; i++) {
    char **words = tokenize_sentence(sentences[i]);
    int num_words = 0;

    while (words[num_words] != NULL) {
      num_words++;
    }

    sentiment += calculate_sentence_sentiment(words, num_words);

    for (int j = 0; j < num_words; j++) {
      free(words[j]);
    }
    free(words);
  }

  for (int i = 0; i < num_sentences; i++) {
    free(sentences[i]);
  }
  free(sentences);

  return sentiment;
}

int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text you want to analyze:\n");
  gets(text);

  // Calculate the sentiment score of the text
  int sentiment = calculate_text_sentiment(text);

  // Print the sentiment score
  printf("The sentiment score of the text is: %d\n", sentiment);

  return 0;
}