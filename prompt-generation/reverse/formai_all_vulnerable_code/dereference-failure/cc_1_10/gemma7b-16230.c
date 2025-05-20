//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char* name;
  char* value;
  struct Token* next;
} Token;

Token* extract_metadata(char* text) {
  Token* head = NULL;
  char* token_start = text;
  char* token_end = NULL;

  while (token_start) {
    token_end = strchr(token_start, ':');
    if (!token_end) break;
    char* token_name = malloc(token_end - token_start + 1);
    memcpy(token_name, token_start, token_end - token_start);
    token_name[token_end - token_start] = '\0';

    char* token_value = malloc(MAX_TOKENS);
    token_value[0] = '\0';

    char* value_start = token_end + 1;
    char* value_end = strchr(value_start, ';');
    if (value_end) {
      memcpy(token_value, value_start, value_end - value_start);
      token_value[value_end - value_start] = '\0';
    }

    Token* new_token = malloc(sizeof(Token));
    new_token->name = token_name;
    new_token->value = token_value;
    new_token->next = head;
    head = new_token;
    token_start = value_end + 1;
  }

  return head;
}

int main() {
  char* text = "name: John Doe, email: john.doe@example.com, age: 30";
  Token* tokens = extract_metadata(text);

  for (Token* token = tokens; token; token = token->next) {
    printf("%s: %s\n", token->name, token->value);
  }

  return 0;
}