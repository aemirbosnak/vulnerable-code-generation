//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store a word and its frequency
typedef struct {
  char *word;
  int frequency;
} Word;

// Define a function to compare two words
int compareWords(const void *a, const void *b) {
  return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

// Define a function to print a word and its frequency
void printWord(Word *word) {
  printf("%s: %d\n", word->word, word->frequency);
}

// Define a function to count the number of words in a string
int countWords(char *string) {
  int count = 0;
  char *token = strtok(string, " ");
  while (token != NULL) {
    count++;
    token = strtok(NULL, " ");
  }
  return count;
}

// Define a function to create an array of words from a string
Word *createWordArray(char *string) {
  // Count the number of words in the string
  int count = countWords(string);

  // Allocate memory for the array of words
  Word *words = malloc(count * sizeof(Word));

  // Tokenize the string and store each word in the array
  char *token = strtok(string, " ");
  int i = 0;
  while (token != NULL) {
    words[i].word = token;
    words[i].frequency = 1;
    i++;
    token = strtok(NULL, " ");
  }

  return words;
}

// Define a function to count the frequency of each word in an array of words
void countWordFrequencies(Word *words, int count) {
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      if (strcmp(words[i].word, words[j].word) == 0) {
        words[i].frequency++;
        words[j].word = NULL;
      }
    }
  }
}

// Define a function to sort an array of words by frequency
void sortWordsByFrequency(Word *words, int count) {
  qsort(words, count, sizeof(Word), compareWords);
}

// Define a function to print the top n most frequent words in an array of words
void printTopNWords(Word *words, int count, int n) {
  for (int i = 0; i < n; i++) {
    if (words[i].word != NULL) {
      printWord(&words[i]);
    }
  }
}

int main() {
  // Get the input string from the user
  char *string = malloc(1024);
  printf("Enter a string: ");
  gets(string);

  // Create an array of words from the input string
  Word *words = createWordArray(string);

  // Count the frequency of each word in the array
  int count = countWords(string);
  countWordFrequencies(words, count);

  // Sort the array of words by frequency
  sortWordsByFrequency(words, count);

  // Print the top 10 most frequent words
  int n = 10;
  printTopNWords(words, count, n);

  // Free the memory allocated for the array of words
  free(words);

  return 0;
}