//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct _SpamFilter {
  int wordCount;
  int spamCount;
  char** spamWords;
  int* spamFreq;
} SpamFilter;

SpamFilter* createFilter(FILE* f) {
  SpamFilter* filter = calloc(1, sizeof(SpamFilter));
  char buf[1024];
  while (fgets(buf, sizeof(buf), f)) {
    int len = strlen(buf);
    int start = -1, end = -1;
    for (int i = 0; i < len; i++) {
      char c = buf[i];
      if (isalpha(c)) {
        if (start == -1) start = i;
        end = i;
      } else if (start != -1) {
        int wordLen = end - start + 1;
        if (filter->wordCount == 0 ||
          strncmp(buf + start, filter->spamWords[filter->wordCount - 1], wordLen)) {
          filter->spamCount++;
          filter->spamWords = realloc(filter->spamWords, sizeof(char*) * (filter->wordCount+1));
          filter->spamWords[filter->wordCount] = calloc(1, wordLen+1);
          filter->spamFreq = realloc(filter->spamFreq, sizeof(int) * (filter->wordCount+1));
          filter->spamFreq[filter->wordCount++] = 1;
          strncpy(filter->spamWords[filter->wordCount-1], buf + start, wordLen);
        } else {
          filter->spamFreq[filter->wordCount-1]++;
        }
        start = -1;
        end = -1;
      }
    }
  }
  return filter;
}

void freeFilter(SpamFilter* filter) {
  for (int i = 0; i < filter->wordCount; i++) {
    free(filter->spamWords[i]);
  }
  free(filter->spamWords);
  free(filter->spamFreq);
  free(filter);
}
int main() {
  SpamFilter* filter = createFilter(fopen("spam-words.txt", "r"));
  char buf[1024];
  while (fgets(buf, sizeof(buf), stdin)) {
    int len = strlen(buf);
    int start = -1, end = -1;
    int spamScore = 0;
    for (int i = 0; i < len; i++) {
      char c = buf[i];
      if (isalpha(c)) {
        if (start == -1) start = i;
        end = i;
      } else if (start != -1) {
        int wordLen = end - start + 1;
        for (int j = 0; j < filter->wordCount; j++) {
          if (!strncmp(buf + start, filter->spamWords[j], wordLen)) {
            spamScore += filter->spamFreq[j];
            break;
          }
        }
        start = -1;
        end = -1;
      }
    }
    if (spamScore > 5) {
      printf("SPAM: %s\n", buf);
    } else {
      printf("NOT SPAM: %s\n", buf);
    }
  }
  freeFilter(filter);
  return 0;
}