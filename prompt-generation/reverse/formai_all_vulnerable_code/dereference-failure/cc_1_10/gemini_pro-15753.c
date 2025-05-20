//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
enum TokenType {
  TOKEN_EOF,
  TOKEN_IDENTIFIER,
  TOKEN_NUMBER,
  TOKEN_STRING,
  TOKEN_KEYWORD,
  TOKEN_OPERATOR,
  TOKEN_PUNCTUATOR,
};

// Token structure
struct Token {
  enum TokenType type;
  char *value;
};

// Lexer structure
struct Lexer {
  char *input;
  int position;
  int length;
};

// Create a new lexer
struct Lexer *new_lexer(char *input) {
  struct Lexer *lexer = malloc(sizeof(struct Lexer));
  lexer->input = input;
  lexer->position = 0;
  lexer->length = strlen(input);
  return lexer;
}

// Get the next token
struct Token *next_token(struct Lexer *lexer) {
  // Check if we're at the end of the input
  if (lexer->position >= lexer->length) {
    return NULL;
  }

  // Skip whitespace
  while (isspace(lexer->input[lexer->position])) {
    lexer->position++;
  }

  // Get the next character
  char c = lexer->input[lexer->position];

  // Check if it's a digit
  if (isdigit(c)) {
    // Get the number
    int number = c - '0';
    lexer->position++;
    while (isdigit(lexer->input[lexer->position])) {
      number *= 10;
      number += lexer->input[lexer->position] - '0';
      lexer->position++;
    }
    // Create a new token
    struct Token *token = malloc(sizeof(struct Token));
    token->type = TOKEN_NUMBER;
    token->value = malloc(sizeof(char) * 100);
    sprintf(token->value, "%d", number);
    return token;
  }

  // Check if it's an alpha character
  if (isalpha(c)) {
    // Get the identifier
    char *identifier = malloc(sizeof(char) * 100);
    int i = 0;
    while (isalpha(lexer->input[lexer->position]) || isdigit(lexer->input[lexer->position])) {
      identifier[i++] = lexer->input[lexer->position++];
    }
    identifier[i] = '\0';
    // Check if it's a keyword
    if (strcmp(identifier, "if") == 0) {
      struct Token *token = malloc(sizeof(struct Token));
      token->type = TOKEN_KEYWORD;
      token->value = strdup("if");
      return token;
    } else if (strcmp(identifier, "else") == 0) {
      struct Token *token = malloc(sizeof(struct Token));
      token->type = TOKEN_KEYWORD;
      token->value = strdup("else");
      return token;
    } else if (strcmp(identifier, "while") == 0) {
      struct Token *token = malloc(sizeof(struct Token));
      token->type = TOKEN_KEYWORD;
      token->value = strdup("while");
      return token;
    } else if (strcmp(identifier, "for") == 0) {
      struct Token *token = malloc(sizeof(struct Token));
      token->type = TOKEN_KEYWORD;
      token->value = strdup("for");
      return token;
    } else {
      // Create a new token
      struct Token *token = malloc(sizeof(struct Token));
      token->type = TOKEN_IDENTIFIER;
      token->value = identifier;
      return token;
    }
  }

  // Check if it's a string
  if (c == '"') {
    // Get the string
    char *string = malloc(sizeof(char) * 100);
    int i = 0;
    lexer->position++;
    while (lexer->input[lexer->position] != '"') {
      string[i++] = lexer->input[lexer->position++];
    }
    string[i] = '\0';
    lexer->position++;
    // Create a new token
    struct Token *token = malloc(sizeof(struct Token));
    token->type = TOKEN_STRING;
    token->value = string;
    return token;
  }

  // Check if it's an operator
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    // Create a new token
    struct Token *token = malloc(sizeof(struct Token));
    token->type = TOKEN_OPERATOR;
    token->value = malloc(sizeof(char) * 2);
    token->value[0] = c;
    token->value[1] = '\0';
    lexer->position++;
    return token;
  }

  // Check if it's a punctuator
  if (c == ';' || c == ',' || c == '(' || c == ')') {
    // Create a new token
    struct Token *token = malloc(sizeof(struct Token));
    token->type = TOKEN_PUNCTUATOR;
    token->value = malloc(sizeof(char) * 2);
    token->value[0] = c;
    token->value[1] = '\0';
    lexer->position++;
    return token;
  }

  // Unknown character
  lexer->position++;
  return NULL;
}

// Free the lexer
void free_lexer(struct Lexer *lexer) {
  free(lexer->input);
  free(lexer);
}

// Free the token
void free_token(struct Token *token) {
  free(token->value);
  free(token);
}

// Main function
int main(int argc, char **argv) {
  // Get the input
  char *input = "int main() {\n  int a = 10;\n  if (a > 5) {\n    printf(\"a is greater than 5\");\n  } else {\n    printf(\"a is less than or equal to 5\");\n  }\n  return 0;\n}";

  // Create a new lexer
  struct Lexer *lexer = new_lexer(input);

  // Get the next token
  struct Token *token;
  while ((token = next_token(lexer)) != NULL) {
    // Print the token
    printf("%s: %s\n", token->type == TOKEN_EOF ? "EOF" : token->type == TOKEN_IDENTIFIER ? "IDENTIFIER" : token->type == TOKEN_NUMBER ? "NUMBER" : token->type == TOKEN_STRING ? "STRING" : token->type == TOKEN_KEYWORD ? "KEYWORD" : token->type == TOKEN_OPERATOR ? "OPERATOR" : token->type == TOKEN_PUNCTUATOR ? "PUNCTUATOR" : "UNKNOWN", token->value);

    // Free the token
    free_token(token);
  }

  // Free the lexer
  free_lexer(lexer);

  return 0;
}