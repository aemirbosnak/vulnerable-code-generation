//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char* lexeme;
  int line_num;
  struct Token* next;
} Token;

Token* parser(char* source) {
  // Allocate memory for the token list
  Token* tokens = malloc(sizeof(Token) * MAX_TOKENS);

  // Tokenize the source code
  char* token_stream = strtok(source, " ");

  // Create a token for each token in the stream
  Token* current_token = tokens;
  while (token_stream) {
    current_token->lexeme = strdup(token_stream);
    current_token->line_num = 1; // TODO: get line number from source
    current_token->next = NULL;

    // Allocate memory for the next token
    if (current_token->next == NULL) {
      current_token->next = malloc(sizeof(Token) * MAX_TOKENS);
    }

    current_token = current_token->next;
    token_stream = strtok(NULL, " ");
  }

  // Return the token list
  return tokens;
}

int main() {
  char* source = "The quick brown fox jumps over the lazy dog.";

  Token* tokens = parser(source);

  // Print the tokens
  for (Token* token = tokens; token; token = token->next) {
    printf("%s (line %d)\n", token->lexeme, token->line_num);
  }

  return 0;
}