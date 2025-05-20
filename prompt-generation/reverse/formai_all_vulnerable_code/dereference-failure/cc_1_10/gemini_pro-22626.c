//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_TOKEN_LEN 1024

typedef struct {
  char *json;
  int pos;
  char token[JSON_MAX_TOKEN_LEN];
  int token_len;
} json_parser_t;

void json_parser_init(json_parser_t *parser, char *json) {
  parser->json = json;
  parser->pos = 0;
  parser->token_len = 0;
}

int json_parser_next_token(json_parser_t *parser) {
  char c;

  while (parser->json[parser->pos] == ' ' || parser->json[parser->pos] == '\n' || parser->json[parser->pos] == '\r' || parser->json[parser->pos] == '\t') {
    parser->pos++;
  }

  if (parser->json[parser->pos] == '\0') {
    return 0;
  }

  c = parser->json[parser->pos];

  if (c == '"' || c == '\'') {
    parser->token_len = 0;
    parser->pos++;
    while (parser->json[parser->pos] != c) {
      parser->token[parser->token_len++] = parser->json[parser->pos++];
    }
    parser->pos++;
    parser->token[parser->token_len] = '\0';
    return 1;
  } else if (c == '{') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else if (c == '}') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else if (c == '[') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else if (c == ']') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else if (c == ',') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else if (c == ':') {
    parser->token_len = 1;
    parser->token[0] = c;
    parser->token[1] = '\0';
    parser->pos++;
    return 1;
  } else {
    parser->token_len = 0;
    while (parser->json[parser->pos] != ' ' && parser->json[parser->pos] != '\n' && parser->json[parser->pos] != '\r' && parser->json[parser->pos] != '\t' && parser->json[parser->pos] != '\0') {
      parser->token[parser->token_len++] = parser->json[parser->pos++];
    }
    parser->token[parser->token_len] = '\0';
    return 1;
  }
}

int main(int argc, char **argv) {
  json_parser_t parser;
  int token_type;

  json_parser_init(&parser, argv[1]);

  while ((token_type = json_parser_next_token(&parser)) != 0) {
    printf("Token type: %d, Token: %s\n", token_type, parser.token);
  }

  return 0;
}