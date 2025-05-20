//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef struct Token {
  char *lexeme;
  int type;
  struct Token *next;
} Token;

void parse_xml(char *xml_data) {
  Token *tokens = NULL;
  char *ptr = xml_data;
  char token[MAX_TOKENS];

  while (*ptr) {
    switch (*ptr) {
      case '<':
        sprintf(token, "OPEN_TAG");
        break;
      case '>':
        sprintf(token, "CLOSE_TAG");
        break;
      case '/':
        sprintf(token, "ATTRIBUTE");
        break;
      case '"':
        sprintf(token, "QUOTE");
        break;
      default:
        sprintf(token, "TEXT");
    }

    Token *new_token = malloc(sizeof(Token));
    new_token->lexeme = strdup(token);
    new_token->type = atoi(token);
    new_token->next = tokens;
    tokens = new_token;
    ptr++;
  }

  // Print the tokens
  for (Token *token = tokens; token; token = token->next) {
    printf("%s (%d)\n", token->lexeme, token->type);
  }
}

int main() {
  parse_xml("<foo bar='baz'>Hello, world!</foo>");
  return 0;
}