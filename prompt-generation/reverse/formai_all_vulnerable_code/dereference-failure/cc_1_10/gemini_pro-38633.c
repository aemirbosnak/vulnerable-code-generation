//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

// Define the Galactic Alphabet
char galactic_alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+=-`~";

// Define the Earth Alphabet
char earth_alphabet[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+=-`~";

// Function to translate a word from Galactic to Earth
char* translate_word(char* word) {
  // Allocate memory for the translated word
  char* translated_word = malloc(strlen(word) + 1);

  // Translate the word one character at a time
  int i;
  for (i = 0; i < strlen(word); i++) {
    // Find the index of the character in the Galactic Alphabet
    int galactic_index = strchr(galactic_alphabet, word[i]) - galactic_alphabet;

    // Get the corresponding character in the Earth Alphabet
    char earth_char = earth_alphabet[galactic_index];

    // Append the translated character to the translated word
    translated_word[i] = earth_char;
  }

  // Null-terminate the translated word
  translated_word[i] = '\0';

  // Return the translated word
  return translated_word;
}

// Function to translate a sentence from Galactic to Earth
char* translate_sentence(char* sentence) {
  // Allocate memory for the translated sentence
  char* translated_sentence = malloc(strlen(sentence) + 1);

  // Translate the sentence one word at a time
  int i;
  char* word = strtok(sentence, " ");
  while (word != NULL) {
    // Translate the word
    char* translated_word = translate_word(word);

    // Append the translated word to the translated sentence
    strcat(translated_sentence, translated_word);

    // Add a space to the translated sentence
    strcat(translated_sentence, " ");

    // Get the next word
    word = strtok(NULL, " ");
  }

  // Null-terminate the translated sentence
  translated_sentence[strlen(translated_sentence) - 1] = '\0';

  // Return the translated sentence
  return translated_sentence;
}

int main() {
  // Get the Galactic sentence from the user
  char galactic_sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence in Galactic: ");
  fgets(galactic_sentence, MAX_SENTENCE_LENGTH, stdin);

  // Translate the sentence from Galactic to Earth
  char* earth_sentence = translate_sentence(galactic_sentence);

  // Print the translated sentence
  printf("The sentence in Earth: %s\n", earth_sentence);

  // Free the memory allocated for the translated sentence
  free(earth_sentence);

  return 0;
}