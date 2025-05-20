//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

// Function prototypes
char* translate(char* sentence);
char* translateWord(char* word);

int main() {
  printf("Welcome to the C Cat Language Translator!\n");

  // User input
  printf("Enter a sentence to translate: ");
  char sentence[100];
  fgets(sentence, 100, stdin);
  sentence[strcspn(sentence, "\n")] = 0; // Remove newline char

  // Translate sentence
  char* translatedSentence = translate(sentence);

  // Output translation
  printf("Translation: %s\n", translatedSentence);

  return 0;
}

/* Translates a sentence from English to C Cat Language */
char* translate(char* sentence) {
  char* translated = "";
  char* word = strtok(sentence, " ");
  while (word != NULL) {
    char* translatedWord = translateWord(word);
    translated = strcat(translated, translatedWord);
    translated = strcat(translated, " ");
    word = strtok(NULL, " ");
  }
  return translated;
}

/* Translates a single word from English to C Cat Language */
char* translateWord(char* word) {
  int length = strlen(word);
  char* translatedWord = "";
  if (length >= 3 && word[0] == 'c' && word[1] == 'a' && word[2] == 't') {
    // If word starts with "cat", translate to "nya"
    translatedWord = "nya";
    if (length > 3) {
      // Preserve capitalization of remainder of word
      for (int i = 3; i < length; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
          translatedWord[i-1] = word[i] + 32;
        } else {
          translatedWord[i-1] = word[i];
        }
      }
    }
  } else {
    // If word does not start with "cat", simply copy to translatedWord
    translatedWord = word;
  }
  return translatedWord;
}