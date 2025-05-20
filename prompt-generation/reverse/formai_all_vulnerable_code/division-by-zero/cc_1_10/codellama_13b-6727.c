//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
// A Sherlock Holmes-style sentiment analysis tool in C
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

// Function to check if a character is a vowel
int is_vowel(char c) {
  char vowels[] = "aeiouAEIOU";
  for (int i = 0; i < sizeof(vowels); i++) {
    if (c == vowels[i]) {
      return 1;
    }
  }
  return 0;
}

// Function to check if a character is a consonant
int is_consonant(char c) {
  char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
  for (int i = 0; i < sizeof(consonants); i++) {
    if (c == consonants[i]) {
      return 1;
    }
  }
  return 0;
}

// Function to calculate the sentiment score of a sentence
int calculate_sentiment(char *sentence) {
  int score = 0;
  int word_count = 0;
  int pos_count = 0;
  int neg_count = 0;
  char word[MAX_SENTENCE_LENGTH];
  char *token;

  // Split the sentence into individual words
  token = strtok(sentence, " ");
  while (token != NULL) {
    strcpy(word, token);
    token = strtok(NULL, " ");
    word_count++;

    // Check if the word is positive or negative
    if (is_vowel(word[0]) && is_consonant(word[1])) {
      pos_count++;
    } else if (is_consonant(word[0]) && is_vowel(word[1])) {
      neg_count++;
    }
  }

  // Calculate the sentiment score
  score = (pos_count - neg_count) * 100 / word_count;

  return score;
}

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  int score;

  // Prompt the user to enter a sentence
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  // Calculate the sentiment score of the sentence
  score = calculate_sentiment(sentence);

  // Print the sentiment score
  printf("Sentiment score: %d\n", score);

  return 0;
}