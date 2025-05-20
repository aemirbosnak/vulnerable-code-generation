//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to hold the word and its count
typedef struct {
  char* word;
  int count;
} WordCount;

// Define a compare function for sorting the WordCount structs
int compare(const void* a, const void* b) {
  WordCount* w1 = (WordCount*)a;
  WordCount* w2 = (WordCount*)b;
  return strcmp(w1->word, w2->word);
}

// Main function
int main() {
  // Declare an array of WordCount structs to hold the word counts
  WordCount wordCounts[10000];
  int wordCount = 0;

  // Read the input file
  FILE* file = fopen("input.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return -1;
  }

  // Read each line from the file
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Split the line into words
    char* words[1000];
    int wordCount = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
      words[wordCount++] = token;
      token = strtok(NULL, " ");
    }

    // Count the occurrences of each word
    for (int i = 0; i < wordCount; i++) {
      // Check if the word is already in the array
      int found = 0;
      for (int j = 0; j < wordCount; j++) {
        if (strcmp(words[i], wordCounts[j].word) == 0) {
          wordCounts[j].count++;
          found = 1;
          break;
        }
      }

      // If the word is not in the array, add it
      if (!found) {
        wordCounts[wordCount].word = words[i];
        wordCounts[wordCount].count = 1;
        wordCount++;
      }
    }
  }

  // Sort the array of WordCount structs
  qsort(wordCounts, wordCount, sizeof(WordCount), compare);

  // Print the word counts
  for (int i = 0; i < wordCount; i++) {
    printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
  }

  // Free the memory allocated for the word counts
  for (int i = 0; i < wordCount; i++) {
    free(wordCounts[i].word);
  }

  // Close the file
  fclose(file);

  return 0;
}