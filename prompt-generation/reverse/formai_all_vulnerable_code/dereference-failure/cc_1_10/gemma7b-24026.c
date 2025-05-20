//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char type;
  char value[MAX_TOKENS];
  struct Token* next;
} Token;

Token* createToken(char type, char* value) {
  Token* token = malloc(sizeof(Token));
  token->type = type;
  strcpy(token->value, value);
  token->next = NULL;
  return token;
}

int main() {
  char input[] = "int x = 10; float y = 3.14;";
  Token* tokens = NULL;
  char* p = input;

  while (*p) {
    switch (*p) {
      case '(':
      case ')':
      case '{':
      case '}':
      case ';':
      case ',':
      case '"':
      case '\'':
      case '.':
      case '-':
      case '+':
      case '!=':
      case '==':
      case '<':
      case '>':
      case '=':
        tokens = createToken(*p, p);
        break;
      default:
        p++;
    }
  }

  Token* token = tokens;
  while (token) {
    printf("Token type: %c, Value: %s\n", token->type, token->value);
    token = token->next;
  }

  return 0;
}