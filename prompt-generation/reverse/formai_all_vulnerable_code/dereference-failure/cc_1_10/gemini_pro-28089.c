//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Define some constants
#define MAX_WORDS 100
#define MAX_SENTENCES 10
#define MAX_CHARS 1000

// Define a struct to store a word and its sentiment value
typedef struct {
  char *word;
  int sentiment;
} Word;

// Define a struct to store a sentence and its sentiment value
typedef struct {
  char *sentence;
  int sentiment;
} Sentence;

// Create an array of words and their sentiment values
Word words[] = {
  { "amazing", 5 },
  { "awesome", 5 },
  { "beautiful", 5 },
  { "great", 5 },
  { "happy", 5 },
  { "love", 5 },
  { "nice", 5 },
  { "wonderful", 5 },
  { "bad", -5 },
  { "boring", -5 },
  { "awful", -5 },
  { "terrible", -5 },
  { "sad", -5 },
  { "hate", -5 },
  { "ugly", -5 },
  { "horrible", -5 }
};

// Create an array of sentences and their sentiment values
Sentence sentences[] = {
  { "I love this movie!", 5 },
  { "This movie is so boring!", -5 },
  { "This movie is okay.", 0 },
  { "I hate this movie!", -5 },
  { "This movie is amazing!", 5 }
};

// Function to tokenize a string into words
char **tokenize(char *string) {
  char **tokens = malloc(MAX_WORDS * sizeof(char *));
  char *token;
  int i = 0;

  token = strtok(string, " ");
  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, " ");
  }

  return tokens;
}

// Function to calculate the sentiment value of a sentence
int calculate_sentiment(char *sentence) {
  int sentiment = 0;
  char **tokens = tokenize(sentence);

  for (int i = 0; i < MAX_WORDS; i++) {
    if (strcmp(tokens[i], words[i].word) == 0) {
      sentiment += words[i].sentiment;
    }
  }

  return sentiment;
}

// Function to print the sentiment value of a sentence
void print_sentiment(Sentence sentence) {
  printf("Sentence: %s\n", sentence.sentence);
  printf("Sentiment: %d\n\n", sentence.sentiment);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get a random sentence from the array
  int index = rand() % MAX_SENTENCES;
  Sentence sentence = sentences[index];

  // Calculate the sentiment value of the sentence
  sentence.sentiment = calculate_sentiment(sentence.sentence);

  // Print the sentiment value of the sentence
  print_sentiment(sentence);

  return 0;
}