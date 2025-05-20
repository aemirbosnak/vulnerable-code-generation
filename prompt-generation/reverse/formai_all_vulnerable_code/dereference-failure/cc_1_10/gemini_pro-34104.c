//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment score for each word
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// Create a dictionary of words and their sentiment scores
char *positiveWords[] = {"good", "great", "excellent", "awesome", "superb", "fantastic", "amazing", "wonderful", "brilliant", "marvelous"};
char *negativeWords[] = {"bad", "terrible", "awful", "horrible", "dreadful", "lousy", "rotten", "awful", "terrible", "disgusting"};
int sentimentScores[] = {POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, POSITIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE, NEGATIVE};

// Get the sentiment score for a given word
int get_sentiment_score(char *word) {
  // Convert the word to lowercase
  for (int i = 0; word[i] != '\0'; i++) {
    word[i] = tolower(word[i]);
  }

  // Check if the word is in the dictionary
  for (int i = 0; i < sizeof(positiveWords) / sizeof(char *); i++) {
    if (strcmp(word, positiveWords[i]) == 0) {
      return POSITIVE;
    }
  }

  for (int i = 0; i < sizeof(negativeWords) / sizeof(char *); i++) {
    if (strcmp(word, negativeWords[i]) == 0) {
      return NEGATIVE;
    }
  }

  // If the word is not in the dictionary, return neutral
  return NEUTRAL;
}

// Get the sentiment score for a given sentence
int get_sentence_sentiment(char *sentence) {
  // Split the sentence into words
  char *words[100];
  int numWords = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Get the sentiment score for each word
  int sentimentScore = 0;
  for (int i = 0; i < numWords; i++) {
    sentimentScore += get_sentiment_score(words[i]);
  }

  // Return the sentiment score for the sentence
  return sentimentScore;
}

// Get the sentiment score for a given file
int get_file_sentiment(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Read the file contents
  char *contents = (char *)malloc(sizeof(char) * 10000);
  fread(contents, 1, 10000, file);
  fclose(file);

  // Get the sentiment score for the file contents
  int sentimentScore = get_sentence_sentiment(contents);

  // Return the sentiment score for the file
  return sentimentScore;
}

// Print the sentiment score for a given file
void print_file_sentiment(char *filename) {
  // Get the sentiment score for the file
  int sentimentScore = get_file_sentiment(filename);

  // Print the sentiment score
  printf("The sentiment score for the file %s is %d\n", filename, sentimentScore);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if a filename was provided
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Get the sentiment score for the file
  print_file_sentiment(argv[1]);

  return 0;
}