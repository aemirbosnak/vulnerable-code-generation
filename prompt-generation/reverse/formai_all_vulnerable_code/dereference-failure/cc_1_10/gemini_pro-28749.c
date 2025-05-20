//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
  TOKEN_EOF,
  TOKEN_IDENTIFIER,
  TOKEN_KEYWORD,
  TOKEN_PUNCTUATOR,
  TOKEN_LITERAL,
  TOKEN_OPERATOR,
} token_type;

typedef struct {
  token_type type;
  char *value;
} token;

typedef struct {
  char *line;
  int line_number;
  int position;
} lexer_state;

int is_whitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int is_alpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
  return c >= '0' && c <= '9';
}

int is_punct(char c) {
  return strchr(".,:;+-*/()[]{}", c) != NULL;
}

int is_keyword(char *str) {
  // TODO: Implement keyword lookup.
  return 0;
}

token *lexer_next_token(lexer_state *state) {
  token *tok = malloc(sizeof(token));
  while (state->position < strlen(state->line)) {
    char c = state->line[state->position];
    if (is_whitespace(c)) {
      state->position++;
      continue;
    } else if (is_alpha(c)) {
      int start_position = state->position;
      while (is_alpha(state->line[state->position]) || is_digit(state->line[state->position])) {
        state->position++;
      }
      int length = state->position - start_position;
      char *value = malloc(length + 1);
      strncpy(value, state->line + start_position, length);
      value[length] = '\0';
      if (is_keyword(value)) {
        tok->type = TOKEN_KEYWORD;
      } else {
        tok->type = TOKEN_IDENTIFIER;
      }
      tok->value = value;
      return tok;
    } else if (is_digit(c)) {
      int start_position = state->position;
      while (is_digit(state->line[state->position])) {
        state->position++;
      }
      int length = state->position - start_position;
      char *value = malloc(length + 1);
      strncpy(value, state->line + start_position, length);
      value[length] = '\0';
      tok->type = TOKEN_LITERAL;
      tok->value = value;
      return tok;
    } else if (is_punct(c)) {
      int length = 1;
      char *value = malloc(length + 1);
      strncpy(value, state->line + state->position, length);
      value[length] = '\0';
      tok->type = TOKEN_PUNCTUATOR;
      tok->value = value;
      state->position++;
      return tok;
    } else {
      // TODO: Handle errors.
      state->position++;
    }
  }
  tok->type = TOKEN_EOF;
  tok->value = NULL;
  return tok;
}

void lexer_free_token(token *tok) {
  free(tok->value);
  free(tok);
}

int main() {
  char *line = malloc(MAX_LINE_LENGTH);
  lexer_state state = {line, 1, 0};
  while (1) {
    token *tok = lexer_next_token(&state);
    if (tok->type == TOKEN_EOF) {
      break;
    }
    printf("%s\n", tok->value);
    lexer_free_token(tok);
  }
  free(line);
  return 0;
}