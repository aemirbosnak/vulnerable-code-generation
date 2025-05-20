//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORDS 100
#define MAX_KEYWORDS_LENGTH 100

typedef struct {
  char *keyword;
  int count;
} keyword_t;

keyword_t keywords[MAX_KEYWORDS];
int num_keywords = 0;

void load_keywords() {
  FILE *fp = fopen("keywords.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening keywords file\n");
    exit(1);
  }

  char buffer[MAX_KEYWORDS_LENGTH];
  while (fgets(buffer, MAX_KEYWORDS_LENGTH, fp) != NULL) {
    keywords[num_keywords].keyword = malloc(strlen(buffer) + 1);
    strcpy(keywords[num_keywords].keyword, buffer);
    keywords[num_keywords].count = 0;
    num_keywords++;
  }

  fclose(fp);
}

int check_spam(char *message) {
  int score = 0;

  char *token = strtok(message, " ");
  while (token != NULL) {
    for (int i = 0; i < num_keywords; i++) {
      if (strcmp(token, keywords[i].keyword) == 0) {
        keywords[i].count++;
        score++;
      }
    }

    token = strtok(NULL, " ");
  }

  return score;
}

int main() {
  load_keywords();

  char *message = "This is a spam message. Click here to win a free prize.";

  int score = check_spam(message);

  if (score > 5) {
    printf("This message is probably spam.\n");
  } else {
    printf("This message is probably not spam.\n");
  }

  return 0;
}