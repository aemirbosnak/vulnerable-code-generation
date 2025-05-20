//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct Token {
  enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_PUNCTUATOR,
    TOKEN_OPERATOR,
  } type;
  char *value;
};

struct Tokenizer {
  char *input;
  int position;
  int line;
  int column;
};

struct Tokenizer *tokenizer_new(char *input) {
  struct Tokenizer *tokenizer = malloc(sizeof(struct Tokenizer));
  tokenizer->input = input;
  tokenizer->position = 0;
  tokenizer->line = 1;
  tokenizer->column = 1;
  return tokenizer;
}

void tokenizer_free(struct Tokenizer *tokenizer) {
  free(tokenizer->input);
  free(tokenizer);
}

struct Token *tokenizer_next(struct Tokenizer *tokenizer) {
  struct Token *token = malloc(sizeof(struct Token));

  // Skip whitespace
  while (tokenizer->input[tokenizer->position] == ' ' || tokenizer->input[tokenizer->position] == '\t' || tokenizer->input[tokenizer->position] == '\r' || tokenizer->input[tokenizer->position] == '\n') {
    if (tokenizer->input[tokenizer->position] == '\n') {
      tokenizer->line++;
      tokenizer->column = 1;
    } else {
      tokenizer->column++;
    }
    tokenizer->position++;
  }

  // Check for end of file
  if (tokenizer->input[tokenizer->position] == '\0') {
    token->type = TOKEN_EOF;
    token->value = NULL;
    return token;
  }

  // Check for identifiers
  if (isalpha(tokenizer->input[tokenizer->position])) {
    int start = tokenizer->position;
    while (isalnum(tokenizer->input[tokenizer->position])) {
      tokenizer->position++;
    }
    int length = tokenizer->position - start;
    char *value = malloc(length + 1);
    strncpy(value, tokenizer->input + start, length);
    value[length] = '\0';
    token->type = TOKEN_IDENTIFIER;
    token->value = value;
    return token;
  }

  // Check for numbers
  if (isdigit(tokenizer->input[tokenizer->position])) {
    int start = tokenizer->position;
    while (isdigit(tokenizer->input[tokenizer->position])) {
      tokenizer->position++;
    }
    int length = tokenizer->position - start;
    char *value = malloc(length + 1);
    strncpy(value, tokenizer->input + start, length);
    value[length] = '\0';
    token->type = TOKEN_NUMBER;
    token->value = value;
    return token;
  }

  // Check for strings
  if (tokenizer->input[tokenizer->position] == '"') {
    int start = tokenizer->position + 1;
    while (tokenizer->input[tokenizer->position] != '"') {
      tokenizer->position++;
    }
    int length = tokenizer->position - start;
    char *value = malloc(length + 1);
    strncpy(value, tokenizer->input + start, length);
    value[length] = '\0';
    token->type = TOKEN_STRING;
    token->value = value;
    return token;
  }

  // Check for keywords
  static char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
  for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
    int length = strlen(keywords[i]);
    if (strncmp(tokenizer->input + tokenizer->position, keywords[i], length) == 0) {
      token->type = TOKEN_KEYWORD;
      token->value = strdup(keywords[i]);
      tokenizer->position += length;
      return token;
    }
  }

  // Check for punctuators
  static char *punctuators[] = {".", ",", ";", ":", "?", "!", "(", ")", "{", "}", "[", "]", "&", "*", "+", "-", "/", "%", "<", ">", "=", "==", "!=", "<=", ">=", "&=", "|=", "^=", "<<=", ">>=", "+=", "-="};
  for (int i = 0; i < sizeof(punctuators) / sizeof(char *); i++) {
    int length = strlen(punctuators[i]);
    if (strncmp(tokenizer->input + tokenizer->position, punctuators[i], length) == 0) {
      token->type = TOKEN_PUNCTUATOR;
      token->value = strdup(punctuators[i]);
      tokenizer->position += length;
      return token;
    }
  }

  // Check for operators
  static char *operators[] = {"*", "+", "-", "/", "%", "<", ">", "=", "==", "!=", "<=", ">=", "&", "|", "^", "<<", ">>", "+=", "-="};
  for (int i = 0; i < sizeof(operators) / sizeof(char *); i++) {
    int length = strlen(operators[i]);
    if (strncmp(tokenizer->input + tokenizer->position, operators[i], length) == 0) {
      token->type = TOKEN_OPERATOR;
      token->value = strdup(operators[i]);
      tokenizer->position += length;
      return token;
    }
  }

  // Unknown token
  token->type = TOKEN_EOF;
  token->value = NULL;
  return token;
}

void tokenizer_print_token(struct Token *token) {
  switch (token->type) {
    case TOKEN_EOF:
      printf("EOF\n");
      break;
    case TOKEN_IDENTIFIER:
      printf("IDENTIFIER: %s\n", token->value);
      break;
    case TOKEN_NUMBER:
      printf("NUMBER: %s\n", token->value);
      break;
    case TOKEN_STRING:
      printf("STRING: %s\n", token->value);
      break;
    case TOKEN_KEYWORD:
      printf("KEYWORD: %s\n", token->value);
      break;
    case TOKEN_PUNCTUATOR:
      printf("PUNCTUATOR: %s\n", token->value);
      break;
    case TOKEN_OPERATOR:
      printf("OPERATOR: %s\n", token->value);
      break;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("fopen");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *input = malloc(size + 1);
  fread(input, 1, size, file);
  input[size] = '\0';

  struct Tokenizer *tokenizer = tokenizer_new(input);

  struct Token *token;
  while ((token = tokenizer_next(tokenizer)) != NULL) {
    tokenizer_print_token(token);
    free(token->value);
    free(token);
  }

  tokenizer_free(tokenizer);
  fclose(file);
  free(input);

  return 0;
}