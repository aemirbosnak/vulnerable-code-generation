//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1000]; //input string
  int positive_count = 0; //number of positive words
  int negative_count = 0; //number of negative words
  double sentiment_score; //sentiment score
  double positive_percentage; //percentage of positive words
  double negative_percentage; //percentage of negative words

  // lists of positive and negative words
  char *pos_words[] = {"good", "great", "excellent", "awesome", "outstanding"};
  char *neg_words[] = {"bad", "terrible", "horrible", "awful", "poor"};

  // get input from user
  printf("Enter your text: ");
  fgets(input, 1000, stdin);

  // iterate through input words and count positive and negative words
  char *token = strtok(input, " ");
  while (token != NULL) {
    // convert token to lowercase for easier comparison
    char *lowercase_token = (char *) malloc(strlen(token) + 1);
    for (int i = 0; i < strlen(token); i++) {
      lowercase_token[i] = tolower(token[i]);
    }
    lowercase_token[strlen(token)] = '\0';

    for (int i = 0; i < 5; i++) {
      if (strcmp(lowercase_token, pos_words[i]) == 0) {
        positive_count++;
      } else if (strcmp(lowercase_token, neg_words[i]) == 0) {
        negative_count++;
      }
    }

    token = strtok(NULL, " ");
    free(lowercase_token);
  }

  // calculate sentiment score and percentages
  sentiment_score = (double) (positive_count - negative_count) / (double) (positive_count + negative_count);
  positive_percentage = (double) positive_count / (double) (positive_count + negative_count) * 100;
  negative_percentage = (double) negative_count / (double) (positive_count + negative_count) * 100;

  // print results
  printf("\nSentiment Analysis Results:\n");
  printf("Positive words: %d (%.2f%%)\n", positive_count, positive_percentage);
  printf("Negative words: %d (%.2f%%)\n", negative_count, negative_percentage);
  printf("Sentiment Score: %.2f\n", sentiment_score);

  return 0;
}