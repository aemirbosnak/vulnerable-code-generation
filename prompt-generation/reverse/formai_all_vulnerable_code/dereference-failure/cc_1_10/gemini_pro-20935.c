//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove stop words from a string
char *removeStopWords(char *str) {
  char *stopWords[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "yet", "so",
                        "at", "by", "from", "in", "into", "near", "of", "on", "to", "with",
                        "as", "because", "for", "since", "than", "though", "until", "while"};
  int numStopWords = sizeof(stopWords) / sizeof(char *);

  // Create a new string to store the result
  char *result = malloc(strlen(str) + 1);
  strcpy(result, str);

  // Iterate over the stop words and remove them from the result string
  for (int i = 0; i < numStopWords; i++) {
    char *stopWord = stopWords[i];
    int stopWordLen = strlen(stopWord);

    char *ptr = result;
    while ((ptr = strstr(ptr, stopWord)) != NULL) {
      memmove(ptr, ptr + stopWordLen, strlen(ptr + stopWordLen) + 1);
    }
  }

  // Return the result string
  return result;
}

// Function to summarize a text using the Edmundson method
char *summarizeEdmundson(char *text, int numSentences) {
  // Tokenize the text into sentences
  char **sentences = malloc(sizeof(char *) * 100);
  int numTokens = 0;
  char *token = strtok(text, ".");
  while (token != NULL) {
    sentences[numTokens++] = token;
    token = strtok(NULL, ".");
  }

  // Calculate the importance score for each sentence
  int *importanceScores = malloc(sizeof(int) * numTokens);
  for (int i = 0; i < numTokens; i++) {
    char *sentence = sentences[i];
    int score = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
      score += 1;
      word = strtok(NULL, " ");
    }
    importanceScores[i] = score;
  }

  // Sort the sentences by importance score
  for (int i = 0; i < numTokens; i++) {
    for (int j = i + 1; j < numTokens; j++) {
      if (importanceScores[i] < importanceScores[j]) {
        int temp = importanceScores[i];
        importanceScores[i] = importanceScores[j];
        importanceScores[j] = temp;

        char *tempSentence = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = tempSentence;
      }
    }
  }

  // Create a new string to store the summary
  char *summary = malloc(strlen(text) + 1);
  strcpy(summary, "");

  // Add the first numSentences sentences to the summary
  for (int i = 0; i < numSentences; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, ". ");
  }

  // Return the summary
  return summary;
}

int main() {
  // Get the text to be summarized from the user
  char *text = malloc(1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Remove stop words from the text
  char *cleanedText = removeStopWords(text);

  // Summarize the text using the Edmundson method
  char *summary = summarizeEdmundson(cleanedText, 3);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the allocated memory
  free(text);
  free(cleanedText);
  free(summary);
  return 0;
}