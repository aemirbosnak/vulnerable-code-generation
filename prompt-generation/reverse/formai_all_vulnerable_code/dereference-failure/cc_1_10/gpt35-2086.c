//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of words in the input text
#define MAX_WORDS 1000

// define the maximum length of a word
#define MAX_LENGTH 50

// function to remove any non-alphabetic characters from a word
void clean_word(char *word) {
   int len = strlen(word);
   if (len == 0) {
      return;
   }
   int i, j = 0;
   for (i = 0; i < len; i++) {
      if (isalpha(word[i])) {
         word[j++] = tolower(word[i]);
      }
   }
   word[j] = '\0';
}

// function to count the frequency of each word
void count_words(char *input, int word_count[], char *words[]) {
   char *word;
   word = strtok(input, " ");
   int word_index = 0;
   while (word != NULL && word_index < MAX_WORDS) {
      clean_word(word);
      if (strlen(word) > 0) {
         int i, found = 0;
         for (i = 0; i < word_index; i++) {
            if (strcmp(words[i], word) == 0) {
               found = 1;
               word_count[i]++;
            }
         }
         if (!found) {
            words[word_index] = strdup(word);
            word_count[word_index] = 1;
            word_index++;
         }
      }
      word = strtok(NULL, " ");
   }
}

// function to sort the words and their corresponding counts
void sort_words(int word_count[], char *words[], int count) {
   int i, j;
   for (i = 0; i < count - 1; i++) {
      for (j = i + 1; j < count; j++) {
         if (word_count[i] < word_count[j]) {
            int temp_count = word_count[i];
            word_count[i] = word_count[j];
            word_count[j] = temp_count;
            char *temp_word = words[i];
            words[i] = words[j];
            words[j] = temp_word;
         }
      }
   }
}

int main() {
   char input[5000];
   int word_count[MAX_WORDS];
   char *words[MAX_WORDS];
   int i, count = 0;

   printf("Please enter the text to analyze:\n");
   fgets(input, sizeof(input), stdin);

   count_words(input, word_count, words);

   while (count < MAX_WORDS && word_count[count] > 0) {
      count++;
   }

   sort_words(word_count, words, count);

   printf("\nWord frequency count:\n\n");

   for (i = 0; i < count; i++) {
      printf("%-20s %5d\n", words[i], word_count[i]);
   }

   return 0;
}