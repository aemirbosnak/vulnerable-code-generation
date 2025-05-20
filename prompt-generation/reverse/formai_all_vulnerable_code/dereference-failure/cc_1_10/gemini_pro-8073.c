//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Cat Language dictionary
char *cat_dict[] = {"meow", "purr", "hiss", "chirp", "trill"};
// Declare the English Language dictionary
char *eng_dict[] = {"Hello", "Thank you", "No", "Yes", "I love you"};

// Function to translate Cat Language to English
char *translate_to_english(char *cat_phrase) {
  // Allocate memory for the translated phrase
  char *eng_phrase = malloc(strlen(cat_phrase) + 1);

  // Iterate over the Cat Language words
  for (int i = 0; i < strlen(cat_phrase); i++) {
    // Find the corresponding English word
    for (int j = 0; j < sizeof(cat_dict) / sizeof(char *); j++) {
      if (strcmp(cat_phrase[i], cat_dict[j]) == 0) {
        // Append the English word to the translated phrase
        strcat(eng_phrase, eng_dict[j]);
        break;
      }
    }
  }

  // Return the translated phrase
  return eng_phrase;
}

// Function to translate English to Cat Language
char *translate_to_cat(char *eng_phrase) {
  // Allocate memory for the translated phrase
  char *cat_phrase = malloc(strlen(eng_phrase) + 1);

  // Iterate over the English words
  for (int i = 0; i < strlen(eng_phrase); i++) {
    // Find the corresponding Cat Language word
    for (int j = 0; j < sizeof(eng_dict) / sizeof(char *); j++) {
      if (strcmp(eng_phrase[i], eng_dict[j]) == 0) {
        // Append the Cat Language word to the translated phrase
        strcat(cat_phrase, cat_dict[j]);
        break;
      }
    }
  }

  // Return the translated phrase
  return cat_phrase;
}

// Main function
int main() {
  // Get the input phrase from the user
  char *input_phrase;
  printf("Enter a phrase in Cat Language or English: ");
  scanf(" %[^\n]%*c", &input_phrase);

  // Determine the language of the input phrase
  int is_cat_language = 0;
  for (int i = 0; i < strlen(input_phrase); i++) {
    int found = 0;
    for (int j = 0; j < sizeof(cat_dict) / sizeof(char *); j++) {
      if (strcmp(input_phrase[i], cat_dict[j]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      is_cat_language = 0;
      break;
    } else {
      is_cat_language = 1;
    }
  }

  // Translate the phrase accordingly
  char *translated_phrase;
  if (is_cat_language) {
    translated_phrase = translate_to_english(input_phrase);
  } else {
    translated_phrase = translate_to_cat(input_phrase);
  }

  // Print the translated phrase
  printf("Translated phrase: %s\n", translated_phrase);

  // Free the allocated memory
  free(input_phrase);
  free(translated_phrase);

  return 0;
}