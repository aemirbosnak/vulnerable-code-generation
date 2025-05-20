//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 50
#define NUM_OF_WORDS 10000

int isAlpha(char c) {
  if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return 1;
  }
  return 0;
}

int isNumeric(char c) {
  if(c >=48 && c <= 57) {
    return 1;
  }
  return 0;
}

void lowercase(char *word) {
  int len = strlen(word);
  for(int i=0; i<len; i++) {
    if(word[i] >= 'A' && word[i] <= 'Z') {
      word[i] = word[i] - 'A' + 'a';
    }
  }
}

int binarySearch(char list[][MAX_WORD_LEN+1], char *searchWord, int numWords) {
  int left=0, right=numWords-1, mid;
  while(left <= right) {
    mid = (left+right)/2;
    if(strcmp(searchWord, list[mid]) == 0) {
      return 1;
    }
    if(strcmp(searchWord, list[mid]) < 0) {
      right = mid-1;
    }
    else {
      left = mid+1;
    }
  }
  return 0;
}

void addWordToList(char list[][MAX_WORD_LEN+1], char *word, int *numWords) {
  strcpy(list[*numWords], word);
  (*numWords)++;
}

void loadDictFromFile(char list[][MAX_WORD_LEN+1], int *numWords) {
  FILE *fp;
  fp = fopen("cyberpunk_dict.txt", "r");
  char *line = NULL;
  size_t len = 0;

  while(getline(&line, &len, fp) != -1) {
    int lineLen = strlen(line);
    if(line[lineLen-1] == '\n') {
      line[lineLen-1] = '\0';
    }
    strcpy(list[*numWords], line);
    (*numWords)++;
  }
  fclose(fp);
}

void printError(char *word, int lineNum, int wordNum) {
  printf("\033[1m\033[31mError:\033[0m %s (line %d, word %d)\n", word, lineNum, wordNum);
}

int main() {
  char text[NUM_OF_WORDS][MAX_WORD_LEN+1];
  char dict[NUM_OF_WORDS][MAX_WORD_LEN+1];
  int numWords = 0;
  int numDictWords = 0;

  loadDictFromFile(dict, &numDictWords);

  FILE *fp;
  fp = fopen("cyberpunk_text.txt", "r");
  char *line = NULL;
  size_t len = 0;
  int lineNum = 1;
  int wordNum = 1;

  while(getline(&line, &len, fp) != -1) {
    int lineLen = strlen(line);
    if(line[lineLen-1] == '\n') {
      line[lineLen-1] = '\0';
    }
    int i=0, j=0;
    while(i <= lineLen) {
      char c = line[i];
      if(isAlpha(c) || isNumeric(c) || c == '.' || c == '\'' || c == '-') {
        text[numWords][j] = tolower(c);
        i++;
        j++;
      }
      else {
        if(j > 0) {
          text[numWords][j] = '\0';
          if(!binarySearch(dict, text[numWords], numDictWords)) {
            printError(text[numWords], lineNum, wordNum);
          }
          numWords++;
          j = 0;
          wordNum++;
        }
        i++;
      }
    }
    lineNum++;
    wordNum = 1;
  }
  fclose(fp);
  return 0;
}