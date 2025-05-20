//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// A structure to represent a word and its sentiment score
typedef struct {
  char *word;
  int score;
} Word;

// A list of positive and negative words
Word positiveWords[] = {
  { "good", 1 },
  { "great", 1 },
  { "excellent", 1 },
  { "amazing", 1 },
  { "wonderful", 1 }
};

Word negativeWords[] = {
  { "bad", -1 },
  { "terrible", -1 },
  { "awful", -1 },
  { "horrible", -1 },
  { "dreadful", -1 }
};

// Calculate the sentiment score of a string
int calculateSentiment(char *text) {
  // Tokenize the text into words
  char *tokens[50];
  int numTokens = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    tokens[numTokens++] = token;
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment score of each word
  int sentimentScore = 0;
  for (int i = 0; i < numTokens; i++) {
    // Check if the word is in the list of positive words
    for (int j = 0; j < ARRAY_SIZE(positiveWords); j++) {
      if (strcmp(tokens[i], positiveWords[j].word) == 0) {
        sentimentScore += positiveWords[j].score;
        break;
      }
    }

    // Check if the word is in the list of negative words
    for (int j = 0; j < ARRAY_SIZE(negativeWords); j++) {
      if (strcmp(tokens[i], negativeWords[j].word) == 0) {
        sentimentScore += negativeWords[j].score;
        break;
      }
    }
  }

  return sentimentScore;
}

// Print the sentiment score of a string
void printSentiment(char *text) {
  int sentimentScore = calculateSentiment(text);

  if (sentimentScore > 0) {
    printf("The sentiment of the text is positive.\n");
  } else if (sentimentScore < 0) {
    printf("The sentiment of the text is negative.\n");
  } else {
    printf("The sentiment of the text is neutral.\n");
  }
}

// Get a string from the user
char *getString() {
  char *text = (char *)malloc(100);
  printf("Enter a string: ");
  scanf("%s", text);
  return text;
}

// Main function
int main() {
  // Get a string from the user
  char *text = getString();

  // Print the sentiment score of the string
  printSentiment(text);

  return 0;
}