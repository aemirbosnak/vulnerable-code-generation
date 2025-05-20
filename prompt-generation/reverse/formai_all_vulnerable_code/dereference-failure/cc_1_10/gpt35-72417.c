//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  char* word;
  char* filename = argv[1];
  int freq[26] = {0};
  FILE* file;
  int c;
  int i;
  int total_words = 0;
  int len;
  
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  
  file = fopen(filename, "r");
  
  if (file == NULL) {
    printf("Error: Could not open file %s\n", filename);
    return 1;
  }
  
  while ((c = fgetc(file)) != EOF) {
    if (!isalpha(c)) {
      if (word != NULL) {
        len = strlen(word);
        
        if (len > 0) {
          freq[tolower(word[0]) - 'a']++;
          total_words++;
        }
        
        free(word);
        word = NULL;
      }
    }
    else {
      if (word == NULL) {
        word = (char*) malloc(2);
        word[0] = c;
        word[1] = '\0';
      }
      else {
        len = strlen(word);
        word = (char*) realloc(word, len + 2);
        word[len] = c;
        word[len + 1] = '\0';
      }
    }
  }
  
  printf("Total words: %d\n", total_words);
  printf("Words Frequency:\n");
  
  for (i = 0; i < 26; i++) {
    printf("%c: %d\n", 'a' + i, freq[i]);
  }
  
  fclose(file);
  
  return 0;
}