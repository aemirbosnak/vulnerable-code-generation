//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Global variables
int spam_count = 0;
int ham_count = 0;
double spam_probability;
double ham_probability;

// Spam detection function
int is_spam(char *message) {
  // Calculate the probability of the message being spam
  double spam_prob = 1.0;
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == '!') {
      spam_prob *= 1.5;
    } else if (message[i] == '?') {
      spam_prob *= 1.25;
    } else if (message[i] == '$') {
      spam_prob *= 1.75;
    } else if (message[i] == '!') {
      spam_prob *= 2.0;
    }
  }

  // Compare the probability to the threshold
  return (spam_prob > 0.5);
}

// Main function
int main() {
  // Read the training data
  FILE *fp = fopen("training_data.txt", "r");
  if (fp == NULL) {
    printf("Error opening training data file!\n");
    return 1;
  }

  char line[1024];
  while (fgets(line, 1024, fp) != NULL) {
    // Parse the line
    char *label = strtok(line, " ");
    char *message = strtok(NULL, "\n");

    // Increment the count of spam or ham messages
    if (strcmp(label, "spam") == 0) {
      spam_count++;
    } else if (strcmp(label, "ham") == 0) {
      ham_count++;
    }
  }

  fclose(fp);

  // Calculate the probability of spam and ham
  spam_probability = (double)spam_count / (spam_count + ham_count);
  ham_probability = (double)ham_count / (spam_count + ham_count);

  // Read the input message
  printf("Enter the message you want to check for spam:\n");
  char input[1024];
  fgets(input, 1024, stdin);

  // Determine if the message is spam
  int is_spam_result = is_spam(input);

  // Print the result
  if (is_spam_result) {
    printf("The message is spam.\n");
  } else {
    printf("The message is not spam.\n");
  }

  return 0;
}