//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 256

typedef struct Token {
  char *lexeme;
  int line_num;
  struct Token *next;
} Token;

Token *parse_metadata(char *source) {
  Token *head = NULL;
  char *p = source;
  char token[MAX_TOKEN_LEN];

  while (p) {
    // Eat whitespace and comments
    while (isspace(*p) || *p == '/' || *p == '#') {
      p++;
    }

    // Extract token
    token[0] = '\0';
    int i = 0;
    while (*p && !isspace(*p) && *p != '/' && *p != '#') {
      token[i++] = *p;
      p++;
    }

    // Create token and add to list
    Token *new_token = malloc(sizeof(Token));
    new_token->lexeme = strdup(token);
    new_token->line_num = 1; // TODO: actual line number extraction
    new_token->next = head;
    head = new_token;
  }

  return head;
}

int main() {
  char source[] = "This is a document with some metadata.\n\n"
    "**Author:** Donald Knuth\n"
    "**Version:** 1.0\n"
    "**Keywords:** C, Programming Languages\n";

  Token *tokens = parse_metadata(source);

  for (Token *token = tokens; token; token = token->next) {
    printf("Lexeme: %s, Line Number: %d\n", token->lexeme, token->line_num);
  }

  return 0;
}