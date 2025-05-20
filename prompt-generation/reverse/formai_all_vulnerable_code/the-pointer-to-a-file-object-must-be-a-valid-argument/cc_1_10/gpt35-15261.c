//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_SPAM_WORDS 100

int isSuspectedSpam(char *line, char **spamList, int numSpamWords) {
  int i, j;
  char copy[MAX_LINE_LEN];
  strcpy(copy, line);

  // convert to lowercase for easier matching
  for(i=0; i<strlen(copy); i++) {
    copy[i] = tolower(copy[i]);
  }

  for(i=0; i<numSpamWords; i++) {
    char *spamWord = spamList[i];
    if(strstr(copy, spamWord) != NULL) {
      // found a matching spam word
      return 1;
    }
  }

  // no matches found
  return 0;
}

int main() {
  char line[MAX_LINE_LEN];
  char *spamList[MAX_SPAM_WORDS];
  int numSpamWords = 0;

  FILE *spamFile = fopen("spamWords.txt", "r");
  while(fgets(line, MAX_LINE_LEN, spamFile) != NULL) {
    // remove newline character
    line[strlen(line)-1] = '\0';

    // allocate memory for the spam word
    spamList[numSpamWords] = malloc(strlen(line)+1);
    strcpy(spamList[numSpamWords], line);

    numSpamWords++;
  }
  fclose(spamFile);

  printf("Enter text to check for spam (type 'q' to quit):\n");
  while(1) {
    fgets(line, MAX_LINE_LEN, stdin);
    if(strcmp(line, "q\n") == 0) {
      break;
    }

    if(isSuspectedSpam(line, spamList, numSpamWords)) {
      printf("Warning: suspected spam detected!\n");
    }
  }

  int i;
  for(i=0; i<numSpamWords; i++) {
    free(spamList[i]);
  }

  return 0;
}