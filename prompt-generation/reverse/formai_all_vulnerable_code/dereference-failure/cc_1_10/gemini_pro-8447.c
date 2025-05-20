//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct {
  char *str;
  int len;
} Token;

typedef struct {
  Token tokens[MAX_TOKENS];
  int num_tokens;
} TokenList;

TokenList *tokenize(char *str) {
  TokenList *list = malloc(sizeof(TokenList));
  list->num_tokens = 0;

  char *start = str;
  char *end;
  while ((end = strchr(start, ' ')) != NULL) {
    Token token;
    token.len = end - start;
    token.str = malloc(token.len + 1);
    strncpy(token.str, start, token.len);
    token.str[token.len] = '\0';

    list->tokens[list->num_tokens++] = token;
    start = end + 1;
  }

  if (*start != '\0') {
    Token token;
    token.len = strlen(start);
    token.str = malloc(token.len + 1);
    strcpy(token.str, start);
    token.str[token.len] = '\0';

    list->tokens[list->num_tokens++] = token;
  }

  return list;
}

void free_token_list(TokenList *list) {
  for (int i = 0; i < list->num_tokens; i++) {
    free(list->tokens[i].str);
  }
  free(list);
}

int main() {
  char *str = "Hello world! This is a test string.";
  TokenList *list = tokenize(str);

  for (int i = 0; i < list->num_tokens; i++) {
    printf("%s\n", list->tokens[i].str);
  }

  free_token_list(list);
  return 0;
}