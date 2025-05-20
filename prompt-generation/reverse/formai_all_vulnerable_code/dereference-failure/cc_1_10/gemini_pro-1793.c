//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef enum {
  TOK_EOF,
  TOK_IDENT,
  TOK_NUMBER,
  TOK_STRING,
  TOK_OPERATOR,
  TOK_KEYWORD,
  TOK_PUNCTUATOR,
  TOK_COMMENT
} TokenKind;

typedef struct {
  TokenKind kind;
  char *value;
} Token;

typedef struct {
  char *code;
  int line;
  int column;
} Source;

static Token *tokenize(Source *source) {
  Token *tokens = NULL;
  int num_tokens = 0;

  while (source->code != NULL) {
    char *start = source->code;

    while (*source->code == ' ' || *source->code == '\t' || *source->code == '\n') {
      if (*source->code == '\n') {
        source->line++;
        source->column = 0;
      } else {
        source->column++;
      }

      source->code++;
    }

    if (*source->code == '\0') {
      break;
    }

    if (isalpha(*source->code) || *source->code == '_') {
      // Identifier
      while (isalnum(*source->code) || *source->code == '_') {
        source->code++;
      }

      Token token;
      token.kind = TOK_IDENT;
      token.value = strndup(start, source->code - start);

      tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token));
      tokens[num_tokens++] = token;
    } else if (isdigit(*source->code)) {
      // Number
      while (isdigit(*source->code)) {
        source->code++;
      }

      if (*source->code == '.') {
        source->code++;

        while (isdigit(*source->code)) {
          source->code++;
        }
      }

      Token token;
      token.kind = TOK_NUMBER;
      token.value = strndup(start, source->code - start);

      tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token));
      tokens[num_tokens++] = token;
    } else if (*source->code == '"') {
      // String
      source->code++;

      while (*source->code != '"') {
        if (*source->code == '\0') {
          fprintf(stderr, "Unterminated string at line %d, column %d\n", source->line, source->column);
          exit(1);
        }

        source->code++;
      }

      source->code++;

      Token token;
      token.kind = TOK_STRING;
      token.value = strndup(start + 1, source->code - start - 2);

      tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token));
      tokens[num_tokens++] = token;
    } else if (*source->code == '/' && source->code[1] == '/') {
      // Comment
      while (*source->code != '\n') {
        if (*source->code == '\0') {
          break;
        }

        source->code++;
      }

      source->code++;
    } else {
      // Operator, keyword, or punctuator
      Token token;
      token.kind = TOK_OPERATOR;
      token.value = strndup(source->code, 1);

      tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token));
      tokens[num_tokens++] = token;

      source->code++;
    }
  }

  // Add an EOF token at the end
  Token eof_token;
  eof_token.kind = TOK_EOF;
  eof_token.value = NULL;

  tokens = realloc(tokens, (num_tokens + 1) * sizeof(Token));
  tokens[num_tokens++] = eof_token;

  return tokens;
}

static void print_tokens(Token *tokens) {
  int i;

  for (i = 0; tokens[i].kind != TOK_EOF; i++) {
    switch (tokens[i].kind) {
    case TOK_IDENT:
      printf("Identifier: %s\n", tokens[i].value);
      break;
    case TOK_NUMBER:
      printf("Number: %s\n", tokens[i].value);
      break;
    case TOK_STRING:
      printf("String: %s\n", tokens[i].value);
      break;
    case TOK_OPERATOR:
      printf("Operator: %s\n", tokens[i].value);
      break;
    case TOK_KEYWORD:
      printf("Keyword: %s\n", tokens[i].value);
      break;
    case TOK_PUNCTUATOR:
      printf("Punctuator: %s\n", tokens[i].value);
      break;
    case TOK_COMMENT:
      printf("Comment: %s\n", tokens[i].value);
      break;
    case TOK_EOF:
      printf("EOF\n");
      break;
    }
  }
}

static void free_tokens(Token *tokens) {
  int i;

  for (i = 0; tokens[i].kind != TOK_EOF; i++) {
    free(tokens[i].value);
  }

  free(tokens);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <source code file>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *code = malloc(size + 1);
  fread(code, 1, size, fp);
  fclose(fp);

  Source source;
  source.code = code;
  source.line = 1;
  source.column = 0;

  Token *tokens = tokenize(&source);
  print_tokens(tokens);
  free_tokens(tokens);

  free(code);

  return 0;
}