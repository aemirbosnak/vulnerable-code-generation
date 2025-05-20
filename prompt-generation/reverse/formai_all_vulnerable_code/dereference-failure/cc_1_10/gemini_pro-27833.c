//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON token types
typedef enum {
  JSON_NULL,
  JSON_BOOLEAN,
  JSON_NUMBER,
  JSON_STRING,
  JSON_ARRAY,
  JSON_OBJECT,
  JSON_EOF
} JSON_TOKEN;

// Define the JSON parser struct
typedef struct {
  char *json;
  int pos;
  int len;
  JSON_TOKEN token;
  char *value;
} JSON_PARSER;

// Create a new JSON parser
JSON_PARSER *json_parser_new(char *json) {
  JSON_PARSER *parser = malloc(sizeof(JSON_PARSER));
  parser->json = json;
  parser->pos = 0;
  parser->len = strlen(json);
  parser->token = JSON_EOF;
  parser->value = NULL;
  return parser;
}

// Free a JSON parser
void json_parser_free(JSON_PARSER *parser) {
  free(parser->value);
  free(parser);
}

// Get the next JSON token
JSON_TOKEN json_parser_next(JSON_PARSER *parser) {
  // Skip whitespace
  while (parser->pos < parser->len && isspace(parser->json[parser->pos])) parser->pos++;

  // Check for end of file
  if (parser->pos == parser->len) {
    parser->token = JSON_EOF;
    return JSON_EOF;
  }

  // Get the next character
  char ch = parser->json[parser->pos++];

  // Determine the token type
  switch (ch) {
    case 'n':
      if (strncmp(parser->json + parser->pos - 1, "null", 4) == 0) {
        parser->token = JSON_NULL;
        parser->value = NULL;
        parser->pos += 3;
      }
      break;
    case 't':
      if (strncmp(parser->json + parser->pos - 1, "true", 4) == 0) {
        parser->token = JSON_BOOLEAN;
        parser->value = "true";
        parser->pos += 3;
      }
      break;
    case 'f':
      if (strncmp(parser->json + parser->pos - 1, "false", 5) == 0) {
        parser->token = JSON_BOOLEAN;
        parser->value = "false";
        parser->pos += 4;
      }
      break;
    case '"':
      parser->token = JSON_STRING;
      parser->value = malloc(parser->len - parser->pos);
      int i = 0;
      while (parser->pos < parser->len && parser->json[parser->pos] != '"') {
        parser->value[i++] = parser->json[parser->pos++];
      }
      parser->value[i] = '\0';
      parser->pos++;
      break;
    case '[':
      parser->token = JSON_ARRAY;
      parser->pos++;
      break;
    case '{':
      parser->token = JSON_OBJECT;
      parser->pos++;
      break;
    case ',':
      parser->token = JSON_EOF;
      parser->pos++;
      break;
    default:
      // Check for a number
      if (isdigit(ch) || ch == '-' || ch == '+') {
        parser->token = JSON_NUMBER;
        parser->value = malloc(parser->len - parser->pos);
        int i = 0;
        while (parser->pos < parser->len && isdigit(parser->json[parser->pos])) {
          parser->value[i++] = parser->json[parser->pos++];
        }
        if (parser->pos < parser->len && parser->json[parser->pos] == '.') {
          parser->value[i++] = parser->json[parser->pos++];
          while (parser->pos < parser->len && isdigit(parser->json[parser->pos])) {
            parser->value[i++] = parser->json[parser->pos++];
          }
        }
        parser->value[i] = '\0';
      }
      break;
  }

  return parser->token;
}

// Get the value of the current JSON token
char *json_parser_get_value(JSON_PARSER *parser) {
  return parser->value;
}

// Parse a JSON string
JSON_PARSER *json_parse(char *json) {
  JSON_PARSER *parser = json_parser_new(json);
  while (json_parser_next(parser) != JSON_EOF) {}
  return parser;
}

// Print a JSON parser
void json_parser_print(JSON_PARSER *parser) {
  printf("JSON:\n");
  JSON_TOKEN token = json_parser_next(parser);
  while (token != JSON_EOF) {
    switch (token) {
      case JSON_NULL:
        printf("  null\n");
        break;
      case JSON_BOOLEAN:
        printf("  %s\n", json_parser_get_value(parser));
        break;
      case JSON_NUMBER:
        printf("  %s\n", json_parser_get_value(parser));
        break;
      case JSON_STRING:
        printf("  \"%s\"\n", json_parser_get_value(parser));
        break;
      case JSON_ARRAY:
        printf("  [\n");
        while (json_parser_next(parser) != JSON_EOF) {
          json_parser_print(parser);
        }
        printf("  ]\n");
        break;
      case JSON_OBJECT:
        printf("  {\n");
        while (json_parser_next(parser) != JSON_EOF) {
          json_parser_print(parser);
        }
        printf("  }\n");
        break;
    }
    token = json_parser_next(parser);
  }
}

int main() {
  char *json = "{\"name\": \"John Doe\", \"age\": 30, \"email\": \"john@doe.com\"}";
  JSON_PARSER *parser = json_parse(json);
  json_parser_print(parser);
  json_parser_free(parser);
  return 0;
}