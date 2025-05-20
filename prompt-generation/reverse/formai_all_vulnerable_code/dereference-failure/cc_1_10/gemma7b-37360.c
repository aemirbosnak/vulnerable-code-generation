//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 100

typedef struct Token {
  char* lexeme;
  int lineNumber;
  struct Token* next;
} Token;

Token* createToken(char* lexeme, int lineNumber) {
  Token* token = malloc(sizeof(Token));
  token->lexeme = strdup(lexeme);
  token->lineNumber = lineNumber;
  token->next = NULL;
  return token;
}

void parseCSyntax() {
  char* sourceCode = "int main() { return 0; }";
  int lineNumber = 1;
  Token* tokens = NULL;

  for (char* p = sourceCode; *p != '\0'; p++) {
    char* lexeme = "";
    switch (*p) {
      case '(': case ')': case '{': case '}': case ';': case ',':
      case '"': case '/': case '*':
        lexeme = "";
        break;
      default:
        while (*p && !isspace(*p) && *p != '\0') {
          lexeme = lexeme ? strcat(lexeme, p) : strcat(lexeme, p);
          p++;
        }
    }

    if (lexeme[0] != '\0') {
      tokens = createToken(lexeme, lineNumber);
      lineNumber++;
      if (tokens) {
        tokens->next = tokens;
      } else {
        tokens = tokens;
      }
    }
  }

  for (Token* token = tokens; token; token = token->next) {
    printf("%s (line %d)\n", token->lexeme, token->lineNumber);
  }
}

int main() {
  parseCSyntax();
  return 0;
}