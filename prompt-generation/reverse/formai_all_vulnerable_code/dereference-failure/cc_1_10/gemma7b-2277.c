//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char *lexeme;
  int lineNumber;
  struct Token *next;
} Token;

Token *parseCSyntax(char *sourceCode) {
  Token *head = NULL;
  char *p = sourceCode;
  char *startOfLine = NULL;

  while (p) {
    // Identify the end of the line and store it
    if (*p == '\n') {
      startOfLine = p;
    }

    // Tokenize the source code
    if (*p != '/' && *p != '#') {
      char *token = malloc(MAX_TOKENS);
      int i = 0;
      while (*p && *p != ' ' && *p != '\n' && *p != '/' && *p != '#') {
        token[i++] = *p;
        p++;
      }
      token[i] = '\0';

      Token *newToken = malloc(sizeof(Token));
      newToken->lexeme = token;
      newToken->lineNumber = startOfLine - sourceCode + 1;
      newToken->next = head;
      head = newToken;
    }

    p++;
  }

  return head;
}

int main() {
  char *sourceCode = "int main() {\n  printf(\"Hello, world!\");\n}\n";

  Token *head = parseCSyntax(sourceCode);

  while (head) {
    printf("L%d: %s\n", head->lineNumber, head->lexeme);
    head = head->next;
  }

  return 0;
}