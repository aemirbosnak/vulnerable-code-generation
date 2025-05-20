//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: grateful
// Welcome to the C Alien Language Translator!

#include<stdio.h>
#include<string.h>

// Function to translate alien language to English
char* translate (char* alienSentence) {
  char* englishSentence = "";
  
  // Loop through each character of the alienSentence and translate
  for (int i = 0; i < strlen(alienSentence); i++) {
    char currentChar = alienSentence[i];
    // Check if the current character is an alien letter
    switch (currentChar) {
      case '1':
        englishSentence = strcat(englishSentence, "a");
        break;
      case '2':
        englishSentence = strcat(englishSentence, "b");
        break;
      case '3':
        englishSentence = strcat(englishSentence, "c");
        break;
      case '4':
        englishSentence = strcat(englishSentence, "d");
        break;
      case '5':
        englishSentence = strcat(englishSentence, "e");
        break;
      case '6':
        englishSentence = strcat(englishSentence, "f");
        break;
      case '7':
        englishSentence = strcat(englishSentence, "g");
        break;
      case '8':
        englishSentence = strcat(englishSentence, "h");
        break;
      case '9':
        englishSentence = strcat(englishSentence, "i");
        break;
      case '0':
        englishSentence = strcat(englishSentence, " ");
        break;
      default:
        englishSentence = strcat(englishSentence, "?");
    }
  }
  return englishSentence;
}

int main() {
  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please enter an alien sentence:\n");
  
  char userSentence[1000];
  fgets(userSentence, 1000, stdin);

  printf("Your sentence in English is:\n");

  char* englishTranslation = translate(userSentence);
  
  // Print the English translation of the alien sentence
  printf("%s\n", englishTranslation);
  
  return 0;
}