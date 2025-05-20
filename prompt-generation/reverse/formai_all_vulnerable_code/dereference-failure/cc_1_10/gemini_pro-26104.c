//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: safe
// Cat Language Translator: Say Meow with Confidence!

#include <stdio.h>
#include <string.h>

// Constants for Cat Language Phrases
#define MEOW "Meow!"
#define PURR "Purr..."
#define HISS "Hiss!"

// Function to Translate a Human Phrase to Cat Language
char *cat_translate(char *human_phrase) {
  // Determine the Length of the Input Phrase
  int len = strlen(human_phrase);

  // Allocate Memory for the Translated Phrase
  char *cat_phrase = malloc(len + 1);

  // Translate the Phrase Character by Character
  for (int i = 0; i < len; i++) {
    switch (human_phrase[i]) {
      case 'a':
        cat_phrase[i] = 'm';
        break;
      case 'e':
        cat_phrase[i] = 'o';
        break;
      case 'i':
        cat_phrase[i] = 'w';
        break;
      case 'o':
        cat_phrase[i] = 'e';
        break;
      case 'u':
        cat_phrase[i] = 'a';
        break;
      default:
        cat_phrase[i] = human_phrase[i];
        break;
    }
  }

  // Terminate the Translated Phrase
  cat_phrase[len] = '\0';

  // Return the Translated Phrase
  return cat_phrase;
}

// Function to Determine the Cat's Mood from its Phrase
char *cat_mood(char *cat_phrase) {
  // Check for Different Phrases and Return Corresponding Moods
  if (strcmp(cat_phrase, MEOW) == 0) {
    return "Curious or Hungry";
  } else if (strcmp(cat_phrase, PURR) == 0) {
    return "Content or Affectionate";
  } else if (strcmp(cat_phrase, HISS) == 0) {
    return "Threatened or Angry";
  } else {
    return "Unknown";
  }
}

// Main Function
int main() {
  // Sample Human Phrase to Translate
  char *human_phrase = "Hello, Kitty!";

  // Translate the Human Phrase to Cat Language
  char *cat_phrase = cat_translate(human_phrase);

  // Display the Translated Phrase
  printf("Cat Language Translation: %s\n", cat_phrase);

  // Determine the Cat's Mood from the Translated Phrase
  char *cat_mood_desc = cat_mood(cat_phrase);

  // Display the Cat's Mood
  printf("Cat's Mood: %s\n", cat_mood_desc);

  // Free the Allocated Memory
  free(cat_phrase);

  return 0;
}