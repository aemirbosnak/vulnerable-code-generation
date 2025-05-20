//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
//This is a program that performs text processing and prints out the words that are in the string more than once.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

void print_duplicate_words(char *text){
  char *words[MAX_WORDS];
  int word_count[MAX_WORDS] = {0};

  //Tokenize the input string into separate words using strtok_r. 
  char *word = strtok_r(text, " \n\t", &text);
  while (word != NULL) {
    //Check if the word already exists in the words array.
    int i;
    for (i = 0; i < MAX_WORDS && words[i] != NULL; i++) {
      if (strcmp(words[i], word) == 0) {
        word_count[i]++;
        break;
      }
    }

    //If the word is not in the words array, add it.
    if (i == MAX_WORDS || words[i] == NULL) {
      int len = strlen(word);
      if (len > MAX_WORD_LEN) {
        len = MAX_WORD_LEN;
      }
      words[i] = malloc(len + 1);
      strncpy(words[i], word, len);
      words[i][len] = '\0';
      word_count[i] = 1;
    }

    //Get the next word in the input string.
    word = strtok_r(NULL, " \n\t", &text);
  }

  //Print out the words that were found more than once.
  for (int i = 0; i < MAX_WORDS && words[i] != NULL; i++) {
    if (word_count[i] > 1) {
      printf("%s : %d\n", words[i], word_count[i]);
    }
    free(words[i]);
  }
}

int main(){
  char input[] = "The quick brown fox jumps over the lazy dog. The lazy dog then jumps over the quick brown fox.";
  print_duplicate_words(input);
  return 0;
}