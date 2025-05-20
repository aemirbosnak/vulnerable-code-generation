//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {

  char str[1000];
  printf("Enter a sentence: ");
  fgets(str, 1000, stdin);

  int sentiment = sentiment_analysis(str);

  if (sentiment == 0) {
    printf("Neutral\n");
  } else if (sentiment == 1) {
    printf("Positive\n");
  } else if (sentiment == -1) {
    printf("Negative\n");
  }

  return 0;
}

int sentiment_analysis(char *sentence) {
  // Count the number of positive and negative words in the sentence
  int num_positive = count_positive_words(sentence);
  int num_negative = count_negative_words(sentence);

  // Calculate the sentiment score
  int sentiment = (num_positive - num_negative) / (num_positive + num_negative);

  return sentiment;
}

int count_positive_words(char *sentence) {
  // Create an array of positive words
  char *positive_words[] = {"happy", "joy", "love", "good", "excellent", "fantastic"};

  // Iterate over the sentence and count the number of positive words
  int num_positive = 0;
  for (int i = 0; i < 6; i++) {
    if (strstr(sentence, positive_words[i]) != NULL) {
      num_positive++;
    }
  }

  return num_positive;
}

int count_negative_words(char *sentence) {
  // Create an array of negative words
  char *negative_words[] = {"sad", "angry", "hate", "bad", "terrible", "awful"};

  // Iterate over the sentence and count the number of negative words
  int num_negative = 0;
  for (int i = 0; i < 6; i++) {
    if (strstr(sentence, negative_words[i]) != NULL) {
      num_negative++;
    }
  }

  return num_negative;
}