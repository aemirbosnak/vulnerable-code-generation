//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANGUAGE_LEN 26

// Alien language to English dictionary
char alien_to_english[ALIEN_LANGUAGE_LEN] = {
   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
   'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
   'U', 'V', 'W', 'X', 'Y', 'Z'
};

// English to Alien language dictionary
char english_to_alien[ALIEN_LANGUAGE_LEN] = {
   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
   'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
   'u', 'v', 'w', 'x', 'y', 'z'
};

// Function to translate a word from Alien language to English
char *alien_to_english_word(char *word) {
   int len = strlen(word);
   char *english_word = malloc(len + 1);
   for (int i = 0; i < len; i++) {
      english_word[i] = alien_to_english[word[i] - 'A'];
   }
   english_word[len] = '\0';
   return english_word;
}

// Function to translate a word from English to Alien language
char *english_to_alien_word(char *word) {
   int len = strlen(word);
   char *alien_word = malloc(len + 1);
   for (int i = 0; i < len; i++) {
      alien_word[i] = english_to_alien[word[i] - 'a'];
   }
   alien_word[len] = '\0';
   return alien_word;
}

// Function to translate a sentence from Alien language to English
char *alien_to_english_sentence(char *sentence) {
   int len = strlen(sentence);
   char *english_sentence = malloc(len + 1);
   int word_start = 0;
   int word_end = 0;
   for (int i = 0; i < len; i++) {
      if (sentence[i] == ' ') {
         word_end = i;
         char *word = malloc(word_end - word_start + 1);
         strncpy(word, sentence + word_start, word_end - word_start);
         word[word_end - word_start] = '\0';
         char *english_word = alien_to_english_word(word);
         strcat(english_sentence, english_word);
         strcat(english_sentence, " ");
         free(word);
         word_start = i + 1;
      }
   }
   char *word = malloc(len - word_start + 1);
   strncpy(word, sentence + word_start, len - word_start);
   word[len - word_start] = '\0';
   char *english_word = alien_to_english_word(word);
   strcat(english_sentence, english_word);
   free(word);
   return english_sentence;
}

// Function to translate a sentence from English to Alien language
char *english_to_alien_sentence(char *sentence) {
   int len = strlen(sentence);
   char *alien_sentence = malloc(len + 1);
   int word_start = 0;
   int word_end = 0;
   for (int i = 0; i < len; i++) {
      if (sentence[i] == ' ') {
         word_end = i;
         char *word = malloc(word_end - word_start + 1);
         strncpy(word, sentence + word_start, word_end - word_start);
         word[word_end - word_start] = '\0';
         char *alien_word = english_to_alien_word(word);
         strcat(alien_sentence, alien_word);
         strcat(alien_sentence, " ");
         free(word);
         word_start = i + 1;
      }
   }
   char *word = malloc(len - word_start + 1);
   strncpy(word, sentence + word_start, len - word_start);
   word[len - word_start] = '\0';
   char *alien_word = english_to_alien_word(word);
   strcat(alien_sentence, alien_word);
   free(word);
   return alien_sentence;
}

int main() {
   char *alien_word = "XYZ";
   char *english_word = "xyz";
   printf("Alien word: %s\n", alien_word);
   printf("English word: %s\n", english_word);
   printf("\n");

   char *alien_sentence = "XYZ ABC DEF";
   char *english_sentence = "xyz abc def";
   printf("Alien sentence: %s\n", alien_sentence);
   printf("English sentence: %s\n", english_sentence);
   printf("\n");

   char *translated_alien_word = alien_to_english_word(alien_word);
   printf("Translated Alien word: %s\n", translated_alien_word);
   free(translated_alien_word);

   char *translated_english_word = english_to_alien_word(english_word);
   printf("Translated English word: %s\n", translated_english_word);
   free(translated_english_word);

   char *translated_alien_sentence = alien_to_english_sentence(alien_sentence);
   printf("Translated Alien sentence: %s\n", translated_alien_sentence);
   free(translated_alien_sentence);

   char *translated_english_sentence = english_to_alien_sentence(english_sentence);
   printf("Translated English sentence: %s\n", translated_english_sentence);
   free(translated_english_sentence);

   return 0;
}