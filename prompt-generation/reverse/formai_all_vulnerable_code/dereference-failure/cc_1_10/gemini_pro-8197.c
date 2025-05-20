//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a word
typedef struct word {
  char *str;
  int len;
} word;

// Define a function to allocate a new word
word *new_word(char *str) {
  word *w = malloc(sizeof(word));
  w->str = strdup(str);
  w->len = strlen(str);
  return w;
}

// Define a function to free a word
void free_word(word *w) {
  free(w->str);
  free(w);
}

// Define a function to compare two words
int compare_words(const void *a, const void *b) {
  word *wa = (word *)a;
  word *wb = (word *)b;
  return strcmp(wa->str, wb->str);
}

// Define a function to print a word
void print_word(word *w) {
  printf("%s", w->str);
}

// Define a function to generate a random word
word *generate_random_word() {
  char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int len = rand() % 10 + 1;
  char *str = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    str[i] = chars[rand() % strlen(chars)];
  }
  str[len] = '\0';
  return new_word(str);
}

// Define a function to generate a random sentence
char *generate_random_sentence() {
  int len = rand() % 100 + 1;
  char *str = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    str[i] = ' ';
  }
  str[len] = '\0';
  int num_words = rand() % 10 + 1;
  for (int i = 0; i < num_words; i++) {
    word *w = generate_random_word();
    strcat(str, w->str);
    strcat(str, " ");
    free_word(w);
  }
  return str;
}

// Define a function to main
int main() {
  // Generate a random sentence
  char *sentence = generate_random_sentence();

  // Tokenize the sentence into an array of words
  char *words[100];
  int num_words = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    words[num_words] = token;
    num_words++;
    token = strtok(NULL, " ");
  }

  // Sort the words in alphabetical order
  qsort(words, num_words, sizeof(char *), compare_words);

  // Print the sorted words
  for (int i = 0; i < num_words; i++) {
    print_word(words[i]);
    printf(" ");
  }
  printf("\n");

  // Free the words
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }

  // Free the sentence
  free(sentence);

  return 0;
}