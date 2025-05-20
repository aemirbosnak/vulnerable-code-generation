//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dictionary of sentiment words
const char *positive_words[] = {"good", "great", "excellent", "awesome", "superb", "wonderful", "fantastic", "terrific", "amazing", "incredible"};
const char *negative_words[] = {"bad", "terrible", "horrible", "awful", "dreadful", "atrocious", "abysmal", "deplorable", "pitiful", "miserable"};

// Function to analyze the sentiment of a sentence
int analyze_sentiment(const char *sentence) {
  // Convert the sentence to lowercase
  char *lowercase_sentence = strdup(sentence);
  for (int i = 0; lowercase_sentence[i]; i++) {
    lowercase_sentence[i] = tolower(lowercase_sentence[i]);
  }

  // Initialize the sentiment score
  int sentiment_score = 0;

  // Iterate over the words in the sentence
  char *word = strtok(lowercase_sentence, " ");
  while (word != NULL) {
    // Check if the word is in the dictionary of positive words
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(word, positive_words[i]) == 0) {
        sentiment_score++;
        break;
      }
    }

    // Check if the word is in the dictionary of negative words
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(word, negative_words[i]) == 0) {
        sentiment_score--;
        break;
      }
    }

    // Get the next word in the sentence
    word = strtok(NULL, " ");
  }

  // Free the memory allocated for the lowercase sentence
  free(lowercase_sentence);

  // Return the sentiment score
  return sentiment_score;
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[1024];
  printf("Enter a sentence: ");
  fgets(sentence, sizeof(sentence), stdin);

  // Analyze the sentiment of the sentence
  int sentiment_score = analyze_sentiment(sentence);

  // Print the sentiment score
  printf("The sentiment score is: %d\n", sentiment_score);

  return 0;
}