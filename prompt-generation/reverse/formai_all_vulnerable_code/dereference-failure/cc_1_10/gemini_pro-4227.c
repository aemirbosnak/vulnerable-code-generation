//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON types
#define JSON_NULL 0
#define JSON_STRING 1
#define JSON_NUMBER 2
#define JSON_OBJECT 3
#define JSON_ARRAY 4

// Define the JSON parser states
#define JSON_PARSE_START 0
#define JSON_PARSE_KEY 1
#define JSON_PARSE_COLON 2
#define JSON_PARSE_VALUE 3
#define JSON_PARSE_COMMA 4
#define JSON_PARSE_END 5

// Define the JSON parser errors
#define JSON_ERROR_NONE 0
#define JSON_ERROR_SYNTAX 1
#define JSON_ERROR_UNEXPECTED_EOF 2

// Define the JSON parser context
typedef struct {
  const char *json;
  int index;
  int length;
  int state;
  int error;
  char *key;
  char *value;
} JSONParserContext;

// Define the JSON parser functions
int JSONParserInit(JSONParserContext *context, const char *json);
int JSONParserParse(JSONParserContext *context);
int JSONParserGetKey(JSONParserContext *context, char **key);
int JSONParserGetValue(JSONParserContext *context, char **value);
int JSONParserError(JSONParserContext *context);

// Initialize the JSON parser
int JSONParserInit(JSONParserContext *context, const char *json) {
  context->json = json;
  context->index = 0;
  context->length = strlen(json);
  context->state = JSON_PARSE_START;
  context->error = JSON_ERROR_NONE;
  context->key = NULL;
  context->value = NULL;
  return 0;
}

// Parse the JSON
int JSONParserParse(JSONParserContext *context) {
  while (context->index < context->length) {
    switch (context->state) {
      case JSON_PARSE_START:
        if (context->json[context->index] == '{') {
          context->state = JSON_PARSE_KEY;
        } else if (context->json[context->index] == '[') {
          context->state = JSON_PARSE_VALUE;
        } else {
          context->error = JSON_ERROR_SYNTAX;
          return -1;
        }
        break;
      case JSON_PARSE_KEY:
        if (context->json[context->index] == '"') {
          context->state = JSON_PARSE_VALUE;
          context->key = malloc(1);
          context->key[0] = '\0';
        } else {
          context->error = JSON_ERROR_SYNTAX;
          return -1;
        }
        break;
      case JSON_PARSE_COLON:
        if (context->json[context->index] == ':') {
          context->state = JSON_PARSE_VALUE;
        } else {
          context->error = JSON_ERROR_SYNTAX;
          return -1;
        }
        break;
      case JSON_PARSE_VALUE:
        if (context->json[context->index] == '"') {
          context->state = JSON_PARSE_VALUE;
          context->value = malloc(1);
          context->value[0] = '\0';
        } else if (context->json[context->index] == '{') {
          context->state = JSON_PARSE_KEY;
        } else if (context->json[context->index] == '[') {
          context->state = JSON_PARSE_VALUE;
        } else if (context->json[context->index] == ',' || context->json[context->index] == '}') {
          context->state = JSON_PARSE_COMMA;
        } else if (context->json[context->index] == ']') {
          context->state = JSON_PARSE_END;
        } else {
          context->error = JSON_ERROR_SYNTAX;
          return -1;
        }
        break;
      case JSON_PARSE_COMMA:
        if (context->json[context->index] == ',') {
          context->state = JSON_PARSE_KEY;
        } else if (context->json[context->index] == '}') {
          context->state = JSON_PARSE_END;
        } else {
          context->error = JSON_ERROR_SYNTAX;
          return -1;
        }
        break;
      case JSON_PARSE_END:
        if (context->json[context->index] == '\0') {
          context->state = JSON_PARSE_END;
          return 0;
        } else {
          context->error = JSON_ERROR_UNEXPECTED_EOF;
          return -1;
        }
        break;
      default:
        context->error = JSON_ERROR_SYNTAX;
        return -1;
    }
    context->index++;
  }
  return 0;
}

// Get the JSON key
int JSONParserGetKey(JSONParserContext *context, char **key) {
  if (context->key == NULL) {
    return -1;
  }
  *key = context->key;
  return 0;
}

// Get the JSON value
int JSONParserGetValue(JSONParserContext *context, char **value) {
  if (context->value == NULL) {
    return -1;
  }
  *value = context->value;
  return 0;
}

// Get the JSON parser error
int JSONParserError(JSONParserContext *context) {
  return context->error;
}

// Main function
int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <json>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the JSON parser
  JSONParserContext context;
  JSONParserInit(&context, argv[1]);

  // Parse the JSON
  if (JSONParserParse(&context) != 0) {
    fprintf(stderr, "Error: %s\n", JSONParserError(&context));
    return EXIT_FAILURE;
  }

  // Get the JSON key and value
  char *key;
  char *value;
  if (JSONParserGetKey(&context, &key) != 0) {
    fprintf(stderr, "Error: Could not get JSON key\n");
    return EXIT_FAILURE;
  }
  if (JSONParserGetValue(&context, &value) != 0) {
    fprintf(stderr, "Error: Could not get JSON value\n");
    return EXIT_FAILURE;
  }

  // Print the JSON key and value
  printf("Key: %s\n", key);
  printf("Value: %s\n", value);

  // Free the JSON key and value
  free(key);
  free(value);

  return EXIT_SUCCESS;
}