//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a word and its sentiment value
struct word_sentiment {
  char word[50];
  int sentiment;
};

// Function to load the sentiment dictionary from a file
int load_sentiment_dict(struct word_sentiment **dict_ptr, char *filename) {
  FILE *file_ptr = fopen(filename, "r");
  if (file_ptr == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    return 0;
  }

  // Allocate initial memory for the dictionary
  struct word_sentiment *dict = (struct word_sentiment *) malloc(sizeof(struct word_sentiment));
  int size = 1; // Number of words in the dictionary
  int index = 0; // Current index in the dictionary

  // Loop through the file and load each word and its sentiment
  char line[100]; // Buffer to hold a line from the file
  while (fgets(line, sizeof(line), file_ptr) != NULL) {
    // Remove newline character at end of line
    line[strlen(line) - 1] = '\0';

    // Split the line into word and sentiment
    char *word = strtok(line, ",");
    char *sentiment_str = strtok(NULL, ",");

    // Convert the sentiment to an int
    int sentiment = strtol(sentiment_str, NULL, 10);

    // Add the word and sentiment to the dictionary
    dict[index].sentiment = sentiment;
    strcpy(dict[index].word, word);
    index++;

    // Resize the dictionary if necessary
    if (index >= size) {
      size *= 2;
      dict = (struct word_sentiment *) realloc(dict, size * sizeof(struct word_sentiment));
    }
  }

  // Resize the dictionary to the exact size needed
  dict = (struct word_sentiment *) realloc(dict, index * sizeof(struct word_sentiment));

  // Close the file and set the dictionary pointer to the loaded dictionary
  fclose(file_ptr);
  *dict_ptr = dict;

  return index;
}

// Function to analyze the sentiment of a sentence
int analyze_sentence(char *sentence, struct word_sentiment *dict, int dict_size) {
  int sentiment = 0; // Final sentiment score of the sentence
  char *word = strtok(sentence, " "); // Get the first word in the sentence

  // Loop through all the words in the sentence
  while (word != NULL) {
    // Remove any punctuation from the word
    if (word[strlen(word) - 1] == '.' || word[strlen(word) - 1] == ',' || word[strlen(word) - 1] == '!' || word[strlen(word) - 1] == '?') {
      word[strlen(word) - 1] = '\0';
    }

    // Search the dictionary for the word
    for (int i = 0; i < dict_size; i++) {
      if (strcmp(word, dict[i].word) == 0) { // Found the word in the dictionary
        sentiment += dict[i].sentiment;
        break;
      }
    }

    // Get the next word in the sentence
    word = strtok(NULL, " ");
  }

  return sentiment;
}

int main() {
  struct word_sentiment *dict; // Pointer to the sentiment dictionary
  int dict_size = load_sentiment_dict(&dict, "sentiment_dict.csv"); // Load the sentiment dictionary from file

  // Get a sentence from the user and analyze its sentiment
  char sentence[500];
  printf("Enter a sentence to analyze its sentiment: ");
  fgets(sentence, sizeof(sentence), stdin);
  sentence[strlen(sentence) - 1] = '\0';
  int sentiment = analyze_sentence(sentence, dict, dict_size);

  // Print the sentiment score
  printf("Sentiment: %d\n", sentiment);

  // Free the memory used by the sentiment dictionary
  free(dict);

  return 0;
}