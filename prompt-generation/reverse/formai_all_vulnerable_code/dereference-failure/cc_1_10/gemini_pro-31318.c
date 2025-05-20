//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the list of positive and negative words
char *positive_words[] = {"good", "great", "super", "awesome", "excellent"};
char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

// Function to analyze the sentiment of a string
int analyze_sentiment(char *str) {
  // Initialize the sentiment score to 0
  int score = 0;

  // Convert the string to lowercase
  char *lower_str = strdup(str);
  for (int i = 0; i < strlen(lower_str); i++) {
    lower_str[i] = tolower(lower_str[i]);
  }

  // Iterate over the list of positive words and increment the score if the word is found in the string
  for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
    if (strstr(lower_str, positive_words[i]) != NULL) {
      score++;
    }
  }

  // Iterate over the list of negative words and decrement the score if the word is found in the string
  for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
    if (strstr(lower_str, negative_words[i]) != NULL) {
      score--;
    }
  }

  // Free the memory allocated for the lowercase string
  free(lower_str);

  // Return the sentiment score
  return score;
}

// Main function
int main() {
  // Get the input string from the user
  char str[1024];
  printf("Enter a string: ");
  scanf("%s", str);

  // Analyze the sentiment of the string
  int score = analyze_sentiment(str);

  // Print the sentiment score
  if (score > 0) {
    printf("The sentiment of the string is positive.\n");
  } else if (score < 0) {
    printf("The sentiment of the string is negative.\n");
  } else {
    printf("The sentiment of the string is neutral.\n");
  }

  return 0;
}