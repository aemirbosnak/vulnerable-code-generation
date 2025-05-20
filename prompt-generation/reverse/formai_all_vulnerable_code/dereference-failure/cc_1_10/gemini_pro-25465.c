//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef enum {
  TOKEN_EOF,
  TOKEN_IDENTIFIER,
  TOKEN_NUMBER,
  TOKEN_STRING,
  TOKEN_KEYWORD,
  TOKEN_OPERATOR,
  TOKEN_PUNCTUATOR,
  TOKEN_COMMENT,
  TOKEN_WHITESPACE
} token_type;

typedef struct {
  token_type type;
  char *value;
} token;

typedef struct {
  token tokens[MAX_TOKENS];
  int num_tokens;
} token_stream;

void init_token_stream(token_stream *stream) {
  stream->num_tokens = 0;
}

void add_token(token_stream *stream, token_type type, char *value) {
  if (stream->num_tokens >= MAX_TOKENS) {
    fprintf(stderr, "Error: too many tokens.\n");
    exit(1);
  }

  stream->tokens[stream->num_tokens].type = type;
  stream->tokens[stream->num_tokens].value = value;
  stream->num_tokens++;
}

void free_token_stream(token_stream *stream) {
  for (int i = 0; i < stream->num_tokens; i++) {
    free(stream->tokens[i].value);
  }
}

int main() {
  char *input = "int main() { return 0; }";

  token_stream stream;
  init_token_stream(&stream);

  char *start = input;
  char *end = input;

  while (*end != '\0') {
    if (isspace(*end)) {
      if (end > start) {
        add_token(&stream, TOKEN_WHITESPACE, strndup(start, end - start));
      }

      start = end + 1;
      end = start;

    } else if (isdigit(*end)) {
      end++;

      while (isdigit(*end)) {
        end++;
      }

      add_token(&stream, TOKEN_NUMBER, strndup(start, end - start));
      start = end;

    } else if (*end == '"') {
      end++;

      while (*end != '"') {
        end++;
      }

      add_token(&stream, TOKEN_STRING, strndup(start + 1, end - start - 1));
      start = end + 1;
      end = start;

    } else if (*end == '/' && *(end + 1) == '/') {
      end += 2;

      while (*end != '\n') {
        end++;
      }

      add_token(&stream, TOKEN_COMMENT, strndup(start, end - start));
      start = end + 1;
      end = start;

    } else if (strchr("+-*/%^&|<>=!", *end)) {
      add_token(&stream, TOKEN_OPERATOR, strndup(end, 1));
      start = end + 1;
      end = start;

    } else if (strchr("(){}[];,", *end)) {
      add_token(&stream, TOKEN_PUNCTUATOR, strndup(end, 1));
      start = end + 1;
      end = start;

    } else if (isalpha(*end)) {
      end++;

      while (isalnum(*end)) {
        end++;
      }

      add_token(&stream, TOKEN_IDENTIFIER, strndup(start, end - start));
      start = end;

    } else {
      fprintf(stderr, "Error: unexpected character '%c'.\n", *end);
      exit(1);
    }
  }

  if (end > start) {
    add_token(&stream, TOKEN_WHITESPACE, strndup(start, end - start));
  }

  add_token(&stream, TOKEN_EOF, NULL);

  for (int i = 0; i < stream.num_tokens; i++) {
    switch (stream.tokens[i].type) {
      case TOKEN_EOF:
        printf("EOF\n");
        break;

      case TOKEN_IDENTIFIER:
        printf("Identifier: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_NUMBER:
        printf("Number: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_STRING:
        printf("String: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_KEYWORD:
        printf("Keyword: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_OPERATOR:
        printf("Operator: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_PUNCTUATOR:
        printf("Punctuator: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_COMMENT:
        printf("Comment: %s\n", stream.tokens[i].value);
        break;

      case TOKEN_WHITESPACE:
        printf("Whitespace: %s\n", stream.tokens[i].value);
        break;
    }
  }

  free_token_stream(&stream);

  return 0;
}