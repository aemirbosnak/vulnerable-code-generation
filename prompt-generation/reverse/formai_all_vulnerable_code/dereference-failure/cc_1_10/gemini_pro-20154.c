//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a spam message
#define MAX_WORDS 100

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the number of features to use for spam detection
#define NUM_FEATURES 10

// Define the list of features to use for spam detection
char *features[] = {
  "free",
  "money",
  "win",
  "click",
  "subscribe",
  "unsubscribe",
  "offer",
  "sale",
  "discount",
  "guarantee"
};

// Define the weight of each feature for spam detection
int feature_weights[] = {
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10
};

// Define the threshold for spam detection
int spam_threshold = 50;

// Function to read a message from a file
char *read_message(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the message
  char *message = (char *) malloc(1000);

  // Read the message from the file
  fread(message, 1, 1000, file);

  // Close the file
  fclose(file);

  // Return the message
  return message;
}

// Function to tokenize a message into words
char **tokenize_message(char *message) {
  // Allocate memory for the words
  char **words = (char **) malloc(MAX_WORDS * sizeof(char *));

  // Tokenize the message into words
  char *token = strtok(message, " ");
  int i = 0;
  while (token != NULL) {
    words[i] = token;
    i++;
    token = strtok(NULL, " ");
  }

  // Return the words
  return words;
}

// Function to count the number of occurrences of a feature in a message
int count_feature(char *feature, char **words) {
  // Initialize the count to 0
  int count = 0;

  // Iterate over the words in the message
  for (int i = 0; i < MAX_WORDS; i++) {
    // Check if the word is the feature
    if (strcmp(words[i], feature) == 0) {
      // Increment the count
      count++;
    }
  }

  // Return the count
  return count;
}

// Function to calculate the spam score of a message
int calculate_spam_score(char **words) {
  // Initialize the spam score to 0
  int spam_score = 0;

  // Iterate over the features
  for (int i = 0; i < NUM_FEATURES; i++) {
    // Count the number of occurrences of the feature in the message
    int count = count_feature(features[i], words);

    // Add the weighted count to the spam score
    spam_score += count * feature_weights[i];
  }

  // Return the spam score
  return spam_score;
}

// Function to determine if a message is spam
int is_spam(char **words) {
  // Calculate the spam score of the message
  int spam_score = calculate_spam_score(words);

  // Check if the spam score is greater than or equal to the spam threshold
  if (spam_score >= spam_threshold) {
    // The message is spam
    return 1;
  } else {
    // The message is not spam
    return 0;
  }
}

// Main function
int main() {
  // Read the message from a file
  char *message = read_message("message.txt");

  // Tokenize the message into words
  char **words = tokenize_message(message);

  // Determine if the message is spam
  int is_spam_result = is_spam(words);

  // Print the result
  if (is_spam_result) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  // Free the memory allocated for the message and the words
  free(message);
  free(words);

  return 0;
}