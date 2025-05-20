//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 20

// Function to generate a random word
char *generate_random_word(void) {
  char word[20];
  sprintf(word, "word%d", rand() % 1000);
  return word;
}

// Function to generate a random sentence
char *generate_random_sentence(void) {
  char sentence[1024];
  int word_count = rand() % 5 + 2;
  for (int i = 0; i < word_count; i++) {
    sentence[i] = generate_random_word();
  }
  sentence[word_count] = '\0';
  return sentence;
}

int main(void) {
  // Generate a random sentence
  char *sentence = generate_random_sentence();

  // Print the sentence with a nice formatting
  printf(" '%s'\n", sentence);

  // Print the sentence with a different formatting
  printf("  %s\n", sentence);

  // Print the sentence with a yet another formatting
  printf("   %s\n", sentence);

  // Print the sentence with a random word replaced with asterisk
  char *asterisk = "*";
  for (int i = 0; i < strlen(sentence); i++) {
    if (rand() % 2) {
      sentence[i] = asterisk;
    }
  }
  printf("  %s\n", sentence);

  // Print the sentence with a random word replaced with a question mark
  char *question_mark = "?";
  for (int i = 0; i < strlen(sentence); i++) {
    if (rand() % 2) {
      sentence[i] = question_mark;
    }
  }
  printf("  %s\n", sentence);

  // Print the sentence with a random word replaced with an exclamation mark
  char *exclamation_mark = "!";
  for (int i = 0; i < strlen(sentence); i++) {
    if (rand() % 2) {
      sentence[i] = exclamation_mark;
    }
  }
  printf("  %s\n", sentence);

  // Print the sentence with a random word replaced with a dollar sign
  char *dollar_sign = "$";
  for (int i = 0; i < strlen(sentence); i++) {
    if (rand() % 2) {
      sentence[i] = dollar_sign;
    }
  }
  printf("  %s\n", sentence);

  // Print the sentence with a random word replaced with a percent sign
  char *percent_sign = "%";
  for (int i = 0; i < strlen(sentence); i++) {
    if (rand() % 2) {
      sentence[i] = percent_sign;
    }
  }
  printf("  %s\n", sentence);

  return 0;
}