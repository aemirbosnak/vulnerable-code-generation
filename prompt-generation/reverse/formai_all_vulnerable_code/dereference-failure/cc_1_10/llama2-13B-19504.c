//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_COUNT 1000

// Function to count the number of words in a given string
int wordCount(const char *str) {
  int wordCount = 0;
  char *word = strtok(str, " ");
  while (word != NULL) {
    wordCount++;
    word = strtok(NULL, " ");
  }
  return wordCount;
}

// Function to print the word count and the average word length
void printWordCount(const char *str, int wordCount) {
  printf("Word Count: %d\n", wordCount);
  printf("Average Word Length: %f\n", (float)wordCount / (float)strlen(str));
}

int main() {
  // Test strings
  const char *testStrings[] = {
    "The quick brown fox jumps over the lazy dog",
    "A big black cat purred contentedly on my lap",
    "The five little monkeys jumped on the bed",
    "How much wood would a woodchuck chuck if a woodchuck could chuck wood?",
    "The rain in Spain stays mainly in the plain"
  };

  // Count the number of words in each test string
  int wordCounts[] = {
    wordCount(testStrings[0]),
    wordCount(testStrings[1]),
    wordCount(testStrings[2]),
    wordCount(testStrings[3]),
    wordCount(testStrings[4])
  };

  // Print the word count and average word length for each test string
  for (int i = 0; i < sizeof(testStrings) / sizeof(testStrings[0]); i++) {
    printWordCount(testStrings[i], wordCounts[i]);
  }

  // Get the current time and print it
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  printf("Current time: %ld.%09ld seconds\n", ts.tv_sec, ts.tv_nsec);

  return 0;
}